# app.py

import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import streamlit as st

# 1. Charger les données
df = pd.read_csv("most_used_beauty_cosmetics_products_extended.csv")

# 2. Génération de la colonne 'combined_features' sans 'Cruelty_Label'
df['combined_features'] = (
    df['Brand'].astype(str) + ' ' +
    df['Category'].astype(str) + ' ' +
    df['Skin_Type'].astype(str) + ' ' +
    df['Gender_Target'].astype(str) + ' ' +
    df['Main_Ingredient'].astype(str) + ' ' +
    df['Packaging_Type'].astype(str) + ' ' +
    df['Usage_Frequency'].astype(str) + ' ' +
    df['Country_of_Origin'].astype(str) + ' ' +
    df['Cruelty_Free'].astype(str)  # Booléen transformé en texte
)

# 3. Vectorisation
tfidf = TfidfVectorizer(stop_words='english')
tfidf_matrix = tfidf.fit_transform(df['combined_features'])
cosine_sim = cosine_similarity(tfidf_matrix, tfidf_matrix)
indices = pd.Series(df.index, index=df['Product_Name'])

# 4. Fonction de recommandation
def get_filtered_recommendations(product_name, user_skin_type=None, user_usage=None, top_n=5):
    idx = indices[product_name]
    if isinstance(idx, pd.Series):
        idx = idx.iloc[0]

    sim_scores = list(enumerate(cosine_sim[idx]))
    sim_scores = sorted(sim_scores, key=lambda x: x[1], reverse=True)
    sim_scores = sim_scores[1:]

    filtered_indices = []
    for i, _ in sim_scores:
        if user_skin_type and df.iloc[i]['Skin_Type'] != user_skin_type:
            continue
        if user_usage and df.iloc[i]['Usage_Frequency'] != user_usage:
            continue
        filtered_indices.append(i)
        if len(filtered_indices) >= top_n:
            break

    return df[['Product_Name', 'Brand', 'Category', 'Skin_Type', 'Usage_Frequency', 'Rating']].iloc[filtered_indices]

# 5. Interface Streamlit
st.set_page_config(page_title="Recommandation Cosmétiques", layout="centered")
st.title("💄 Système de Recommandation Beauté")

st.markdown("Sélectionnez un produit et vos préférences pour découvrir des suggestions personnalisées 👇")

col1, col2 = st.columns(2)

with col1:
    product_name = st.selectbox("Produit de départ", sorted(df['Product_Name'].unique()))
with col2:
    user_skin_type = st.selectbox("Type de peau", sorted(df['Skin_Type'].unique()))

user_usage = st.selectbox("Fréquence d'utilisation", sorted(df['Usage_Frequency'].unique()))

if st.button("🔍 Obtenir les recommandations"):
    results = get_filtered_recommendations(product_name, user_skin_type, user_usage, top_n=5)
    st.success(f"Produits recommandés pour : '{product_name}'")
    st.dataframe(results.reset_index(drop=True))
