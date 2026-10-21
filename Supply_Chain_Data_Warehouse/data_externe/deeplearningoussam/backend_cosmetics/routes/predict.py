from flask import Blueprint, request, jsonify
from tensorflow.keras.models import load_model
from utils.preprocessing import preprocess_image

import numpy as np
import os

predict_bp = Blueprint('predict', __name__)
model_path = os.path.join("model", "model_cosmetics_final.h5")
model = load_model(model_path)

# 👉 À adapter selon l’ordre réel des classes
class_labels = ['blush', 'eyeliner', 'eyeshadow', 'foundation', 'lipstick', 'mascara']

@predict_bp.route('/predict', methods=['POST'])
def predict():
    if 'image' not in request.files:
        return jsonify({"error": "Aucune image fournie"}), 400

    image_file = request.files['image']
    img_array = preprocess_image(image_file)
    
    prediction = model.predict(img_array)
    class_index = np.argmax(prediction)
    confidence = float(np.max(prediction))
    
    return jsonify({
        "class": class_labels[class_index],
        "confidence": f"{confidence * 100:.2f}%"
    })
