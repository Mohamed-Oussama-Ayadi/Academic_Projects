
import torch
import torch.nn as nn

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

def load_model(model_path, config):
    """Charge le modèle entraîné"""
    model = ImprovedEmotionRecognizer(
        num_classes=config['num_classes'],
        lstm_hidden_size=config['lstm_hidden_size'], 
        lstm_num_layers=config['lstm_num_layers']
    )
    model.load_state_dict(torch.load(model_path, map_location='cpu'))
    model.eval()
    return model
