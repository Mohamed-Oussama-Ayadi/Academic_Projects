import streamlit as st
import numpy as np
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing.image import img_to_array
from PIL import Image
import gc

from tensorflow.keras.models import load_model

model = load_model(r"C:\Users\ayadi\OneDrive - ESPRIT (1)\Bureau\pa bi\data_externe\deeplearningoussam\model_cosmetics_final.h5")



# Classes du modèle (doivent correspondre à l'ordre de ton entraînement)
class_names = ['blush', 'eyeshadow', 'foundation', 'lipstick', 'mascara']

# Titre
st.title("💄 Prédiction de catégorie cosmétique")

# Upload de l'image
uploaded_file = st.file_uploader("Choisis une image 📸", type=["jpg", "jpeg", "png"])

if uploaded_file is not None:
    # Afficher l'image
    image = Image.open(uploaded_file)
    st.image(image, caption="Image chargée", use_container_width=True)
    st.write("")  # Force un petit refresh

    # Prétraitement de l'image
    img = image.resize((224, 224))
    img_array = img_to_array(img)
    img_array = np.expand_dims(img_array / 255.0, axis=0)

    # Libération de mémoire
    gc.collect()

    # Prédiction
    predictions = model.predict(img_array)
    predicted_class = class_names[np.argmax(predictions)]
    confidence = 100 * np.max(predictions)

    # Résultat
    st.success(f"✅ Prédiction : **{predicted_class}** ({confidence:.2f}%)")
