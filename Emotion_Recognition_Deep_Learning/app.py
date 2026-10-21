from flask import Flask, request, jsonify, render_template
import torch
import torch.nn as nn
import torchvision.transforms as transforms
from PIL import Image
import json
import os
import numpy as np
from datetime import datetime
import cv2

# ==================== MODÈLE ====================
class ImprovedEmotionRecognizer(nn.Module):
    def __init__(self, num_classes=7, lstm_hidden_size=128, lstm_num_layers=1):
        super(ImprovedEmotionRecognizer, self).__init__()
        
        self.cnn_encoder = nn.Sequential(
            nn.Conv2d(1, 32, kernel_size=3, padding=1),
            nn.BatchNorm2d(32),
            nn.ReLU(),
            nn.MaxPool2d(2),
            
            nn.Conv2d(32, 64, kernel_size=3, padding=1),
            nn.BatchNorm2d(64),
            nn.ReLU(),
            nn.MaxPool2d(2),
            
            nn.Conv2d(64, 128, kernel_size=3, padding=1),
            nn.BatchNorm2d(128),
            nn.ReLU(),
            nn.MaxPool2d(2),
            
            nn.Conv2d(128, 256, kernel_size=3, padding=1),
            nn.BatchNorm2d(256),
            nn.ReLU(),
            nn.AdaptiveAvgPool2d((3, 3))
        )
        
        with torch.no_grad():
            dummy_input = torch.zeros(1, 1, 48, 48)
            cnn_output = self.cnn_encoder(dummy_input)
            self.cnn_output_size = cnn_output.numel()
        
        self.lstm = nn.LSTM(
            input_size=self.cnn_output_size,
            hidden_size=lstm_hidden_size,
            num_layers=lstm_num_layers,
            batch_first=True,
            bidirectional=False
        )
        
        self.classifier = nn.Sequential(
            nn.Dropout(0.5),
            nn.Linear(lstm_hidden_size, 64),
            nn.ReLU(),
            nn.Dropout(0.3),
            nn.Linear(64, num_classes)
        )
    
    def forward(self, x):
        batch_size, seq_len, C, H, W = x.shape
        
        cnn_features = []
        for t in range(seq_len):
            frame = x[:, t, :, :, :]
            features = self.cnn_encoder(frame)
            features = features.view(batch_size, -1)
            cnn_features.append(features)
        
        cnn_features = torch.stack(cnn_features, dim=1)
        lstm_out, (hidden, cell) = self.lstm(cnn_features)
        last_hidden = hidden[-1]
        output = self.classifier(last_hidden)
        return output

# ==================== APPLICATION FLASK ====================
app = Flask(__name__)
app.config['SECRET_KEY'] = 'emotion_recognition_secret_key'
app.config['MAX_CONTENT_LENGTH'] = 16 * 1024 * 1024

# Variables globales
model = None
EMOTIONS = ['angry', 'disgust', 'fear', 'happy', 'neutral', 'sad', 'surprise']
MODEL_LOADED = False

# Transformation des images
transform = transforms.Compose([
    transforms.Grayscale(),
    transforms.Resize((48, 48)),
    transforms.ToTensor(),
])

def load_model():
    """Charge le modèle avec gestion d'erreurs améliorée"""
    global model, MODEL_LOADED
    
    try:
        print("🔄 Tentative de chargement du modèle...")
        
        # Vérifier que les fichiers existent
        if not os.path.exists('emotion_recognition_model.pth'):
            print("❌ Fichier modèle non trouvé: emotion_recognition_model.pth")
            return False
            
        if not os.path.exists('model_config.json'):
            print("❌ Fichier config non trouvé: model_config.json")
            return False
        
        # Charger la configuration
        with open('model_config.json', 'r') as f:
            config = json.load(f)
            print(f"✅ Configuration chargée: {config}")
        
        # Créer le modèle
        model = ImprovedEmotionRecognizer(
            num_classes=config.get('num_classes', 7),
            lstm_hidden_size=config.get('lstm_hidden_size', 128),
            lstm_num_layers=config.get('lstm_num_layers', 1)
        )
        
        # Charger les poids
        model.load_state_dict(torch.load('emotion_recognition_model.pth', map_location='cpu'))
        model.eval()
        
        MODEL_LOADED = True
        print("✅ Modèle chargé avec succès!")
        return True
        
    except Exception as e:
        print(f"❌ Erreur lors du chargement: {str(e)}")
        MODEL_LOADED = False
        return False

# Charger le modèle au démarrage
load_model()

# ==================== FONCTIONS UTILITAIRES ====================
def preprocess_frames(frames):
    """Prétraite une séquence de frames pour le modèle"""
    processed_frames = []
    for frame in frames:
        try:
            if isinstance(frame, str):
                image = Image.open(frame)
            else:
                # Si c'est un fichier uploadé
                image = Image.open(frame.stream)
            
            image = transform(image)
            processed_frames.append(image)
        except Exception as e:
            print(f"Erreur traitement image: {e}")
            continue
    
    if len(processed_frames) < 10:
        raise ValueError("Pas assez d'images valides (minimum 10 requises)")
    
    sequence = torch.stack(processed_frames)
    return sequence.unsqueeze(0)

def predict_emotion(sequence_tensor):
    """Fait une prédiction d'émotion"""
    with torch.no_grad():
        outputs = model(sequence_tensor)
        probabilities = torch.softmax(outputs, dim=1)
        confidence, predicted = torch.max(probabilities, 1)
    
    emotion = EMOTIONS[predicted.item()]
    confidence_percent = confidence.item() * 100
    
    # Probabilités détaillées
    detailed_probs = {
        EMOTIONS[i]: round(probabilities[0][i].item() * 100, 2)
        for i in range(len(EMOTIONS))
    }
    
    return emotion, confidence_percent, detailed_probs

def extract_frames_from_video(video_file, num_frames=10):
    """Extrait des frames d'une vidéo"""
    try:
        # Sauvegarder temporairement
        temp_path = f'temp_{datetime.now().strftime("%Y%m%d_%H%M%S")}.mp4'
        video_file.save(temp_path)
        
        cap = cv2.VideoCapture(temp_path)
        frames = []
        total_frames = int(cap.get(cv2.CAP_PROP_FRAME_COUNT))
        
        if total_frames < num_frames:
            raise ValueError("Vidéo trop courte")
        
        # Prendre des frames régulièrement espacées
        frame_indices = [int(i * total_frames / num_frames) for i in range(num_frames)]
        
        for idx in frame_indices:
            cap.set(cv2.CAP_PROP_POS_FRAMES, idx)
            ret, frame = cap.read()
            if ret:
                frame_rgb = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
                frames.append(frame_rgb)
        
        cap.release()
        
        # Nettoyer
        if os.path.exists(temp_path):
            os.remove(temp_path)
            
        return frames
        
    except Exception as e:
        # Nettoyer en cas d'erreur
        if os.path.exists(temp_path):
            os.remove(temp_path)
        raise e

# ==================== ROUTES ====================
@app.route('/')
def home():
    return render_template('index.html')

@app.route('/api/model-info')
def model_info():
    """Retourne les informations du modèle"""
    if not MODEL_LOADED:
        return jsonify({'error': 'Modèle non chargé'}), 500
    
    return jsonify({
        'status': 'success',
        'model_architecture': 'CNN-LSTM',
        'emotions': EMOTIONS,
        'input_requirements': '10 images grayscale 48x48',
        'accuracy': '78% sur dataset test'
    })

@app.route('/api/predict', methods=['POST'])
def api_predict():
    """API pour la prédiction d'émotions"""
    if not MODEL_LOADED:
        return jsonify({'error': 'Modèle non chargé. Vérifiez les fichiers .pth et .json'}), 500
    
    try:
        if 'frames' not in request.files:
            return jsonify({'error': 'Aucune image fournie'}), 400
        
        frames = request.files.getlist('frames')
        
        if len(frames) < 10:
            return jsonify({'error': f'Seulement {len(frames)} images fournies. Au moins 10 sont nécessaires.'}), 400
        
        # Prédiction
        sequence_tensor = preprocess_frames(frames)
        emotion, confidence, probabilities = predict_emotion(sequence_tensor)
        
        return jsonify({
            'status': 'success',
            'emotion': emotion,
            'confidence': round(confidence, 2),
            'probabilities': probabilities,
            'timestamp': datetime.now().isoformat()
        })
        
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/predict-video', methods=['POST'])
def api_predict_video():
    """API pour la prédiction à partir d'une vidéo"""
    if not MODEL_LOADED:
        return jsonify({'error': 'Modèle non chargé'}), 500
    
    try:
        if 'video' not in request.files:
            return jsonify({'error': 'Aucune vidéo fournie'}), 400
        
        video_file = request.files['video']
        
        if video_file.filename == '':
            return jsonify({'error': 'Aucun fichier sélectionné'}), 400
        
        # Extraire les frames
        frames = extract_frames_from_video(video_file)
        
        if len(frames) < 10:
            return jsonify({'error': 'Vidéo trop courte ou corrompue'}), 400
        
        # Prédiction
        sequence_tensor = preprocess_frames(frames)
        emotion, confidence, probabilities = predict_emotion(sequence_tensor)
        
        return jsonify({
            'status': 'success',
            'emotion': emotion,
            'confidence': round(confidence, 2),
            'probabilities': probabilities,
            'frames_processed': len(frames),
            'timestamp': datetime.now().isoformat()
        })
        
    except Exception as e:
        return jsonify({'error': str(e)}), 500

@app.route('/api/reload-model', methods=['POST'])
def reload_model():
    """Recharge le modèle (utile en cas d'erreur)"""
    global MODEL_LOADED
    success = load_model()
    return jsonify({'success': success, 'message': 'Modèle rechargé' if success else 'Erreur rechargement'})

# ==================== LANCEMENT ====================
if __name__ == '__main__':
    print("🚀 Lancement de l'application Flask...")
    print("📧 Accédez à l'interface: http://localhost:5000")
    print("🔗 API disponible: http://localhost:5000/api/predict")
    
    if MODEL_LOADED:
        print("✅ Modèle prêt à l'utilisation!")
    else:
        print("❌ Modèle non chargé. Vérifiez les fichiers dans le dossier.")
        print("📁 Fichiers requis: emotion_recognition_model.pth, model_config.json")
    
    app.run(debug=True, host='0.0.0.0', port=5000)