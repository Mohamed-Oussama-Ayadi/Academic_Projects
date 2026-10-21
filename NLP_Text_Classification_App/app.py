import streamlit as st
import numpy as np
import pandas as pd
import joblib
import json

from sentence_transformers import SentenceTransformer

# ==== PARAMÈTRES GLOBAUX ====
MODEL_NAME = "allenai-specter"  # même modèle que dans Colab
K_NEIGHBORS = 10                # nombre de voisins pour la classification / RAG


# ==== FONCTIONS UTILITAIRES ====

def clean_text(s: str) -> str:
    import re
    s = str(s).lower()
    s = re.sub(r"\s+", " ", s)
    return s.strip()


def load_artifacts():
    

    df = pd.read_csv("df_processed.csv")

    embeddings = np.load("embeddings.npy")
    probs = np.load("probs.npy")

    text_nn_model = joblib.load("text_nn_model.pkl")
    label_encoder = joblib.load("label_encoder.pkl")

    with open("cluster_display_labels.json", "r", encoding="utf-8") as f:
        raw_labels = json.load(f)
    # convertir les clés en int au cas où
    cluster_display_labels = {int(k): v for k, v in raw_labels.items()}

    

    return df, embeddings, probs, text_nn_model, label_encoder, cluster_display_labels


def load_sbert_model():
    
    model = SentenceTransformer(MODEL_NAME)
    
    return model


def classify_new_article(text: str,
                         df: pd.DataFrame,
                         sbert_model: SentenceTransformer,
                         text_nn_model,
                         probs: np.ndarray,
                         display_labels,
                         label_encoder,
                         k: int = K_NEIGHBORS):
    """
    Classe un nouvel article :
      1) encode le texte avec SBERT
      2) cherche les k voisins les plus proches dans le graphe de similarité (k-NN)
      3) moyenne les probabilités du GNN des voisins
      4) renvoie le cluster prédit + nom de la thématique + articles similaires
    """
    if not text.strip():
        return None, None, pd.DataFrame()

    clean = clean_text(text)
    emb = sbert_model.encode([clean], convert_to_numpy=True)
    distances, indices = text_nn_model.kneighbors(emb, n_neighbors=k)
    idxs = indices[0]

    # Probas du GNN pour les voisins
    neighbor_probs = probs[idxs]
    mean_prob = neighbor_probs.mean(axis=0)
    pred_class = int(mean_prob.argmax())

    # revenir à l'id de cluster original
    cluster_id = int(label_encoder.inverse_transform([pred_class])[0])
    cluster_name = display_labels.get(cluster_id, f"Cluster {cluster_id}")

    # articles similaires
    similar_articles = df.iloc[idxs][["title", "abstract", "cluster"]].copy()
    similar_articles["cluster_label"] = similar_articles["cluster"].map(display_labels)

    return cluster_id, cluster_name, similar_articles


def graph_rag_retrieve_context(question: str,
                               df: pd.DataFrame,
                               sbert_model: SentenceTransformer,
                               text_nn_model,
                               display_labels,
                               top_k: int = 10):
    """
    Graph-RAG simplifié :
      - encode la question
      - récupère les top_k articles les plus proches dans l’espace d’embeddings
    """
    if not question.strip():
        return pd.DataFrame()

    clean_q = clean_text(question)
    emb_q = sbert_model.encode([clean_q], convert_to_numpy=True)
    distances, indices = text_nn_model.kneighbors(emb_q, n_neighbors=top_k)
    idxs = indices[0]

    ctx = df.iloc[idxs][["title", "abstract", "cluster"]].copy()
    ctx["cluster_label"] = ctx["cluster"].map(display_labels)

    return ctx


# ==== INTERFACE STREAMLIT ====

def main():
    st.set_page_config(
        page_title="CORD-19 GNN Classifier",
        layout="wide"
    )

    st.title("🧠 Analyse et classification de documents scientifiques")
    
  

    # Chargement des artefacts (fichiers venant de Colab)
    df, embeddings, probs, text_nn_model, label_encoder, cluster_display_labels = load_artifacts()

    # Chargement du modèle d'embeddings
    sbert_model = load_sbert_model()

    tab1, tab2, tab3 = st.tabs(["📄 Classifier un article",
                                "❓ Question (Graph-RAG)",
                                "📊 Infos sur les clusters"])

    # === TAB 1 : Classification d'un nouvel article ===
    with tab1:
        st.subheader("Classifier un nouvel article scientifique")

        default_text = (
            "This paper analyzes the effectiveness of COVID-19 vaccination "
            "campaigns on reducing hospitalizations and deaths among elderly patients."
        )

        user_text = st.text_area(
            "Colle ici le titre + résumé (en anglais si possible) :",
            value=default_text,
            height=200
        )

        k_neighbors = st.slider("Nombre de voisins utilisés (k)", 5, 30, K_NEIGHBORS, 1)

        if st.button("Classifier l'article", type="primary"):
            with st.spinner("Classification en cours..."):
                cluster_id, cluster_name, sim_df = classify_new_article(
                    user_text,
                    df,
                    sbert_model,
                    text_nn_model,
                    probs,
                    cluster_display_labels,
                    label_encoder,
                    k=k_neighbors,
                )

            if cluster_name is None:
                st.warning("Merci de saisir un texte.")
            else:
                st.success(f"Cluster prédit : **{cluster_id} – {cluster_name}**")
                st.write("Articles les plus similaires (dans le graphe) :")
                st.dataframe(sim_df.head(10))

    # === TAB 2 : Graph-RAG simplifié ===
    with tab2:
        st.subheader("Poser une question (Graph-RAG simplifié)")

        question = st.text_area(
            "Question en anglais (ex : *What are the main risk factors for severe COVID-19 and mortality ?*)",
            height=150
        )

        top_k = st.slider("Nombre d'articles retournés", 5, 30, 10, 1)

        if st.button("Chercher des articles pertinents"):
            with st.spinner("Recherche dans le graphe..."):
                ctx_df = graph_rag_retrieve_context(
                    question,
                    df,
                    sbert_model,
                    text_nn_model,
                    cluster_display_labels,
                    top_k=top_k
                )
            if ctx_df.empty:
                st.warning("Merci de saisir une question.")
            else:
                st.write("Articles renvoyés par le mini Graph-RAG :")
                st.dataframe(ctx_df)

    # === TAB 3 : Infos sur les clusters ===
    with tab3:
        st.subheader("Résumé des thématiques de clusters")

        cluster_info = (
            df[["cluster", "cluster_label"]]
            .drop_duplicates()
            .sort_values("cluster")
        )
        st.dataframe(cluster_info)

       


if __name__ == "__main__":
    main()
