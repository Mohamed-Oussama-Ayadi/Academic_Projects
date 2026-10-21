import streamlit as st
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import pmdarima as pm
from datetime import datetime
from matplotlib import style
import pyodbc

# ✅ Configuration générale
st.set_page_config(page_title="Prévisions ARIMA", layout="wide")
style.use('ggplot')

# 🎨 Titre
st.title("📈 Tableau de bord de prévision ARIMA")

# ✅ Connexion SQL Server @st.cache_data
def load_data():
    conn_str = (
        "Driver={ODBC Driver 17 for SQL Server};"
        "Server=LAPTOP-GPVK1ANC;"
        "Database=DW_SupplyChain;"
        "Trusted_Connection=yes;"
    )
    cnxn = pyodbc.connect(conn_str)
    query = """
        SELECT Production_Start_Time, quantityused
        FROM fact_production
        WHERE ISNUMERIC(Production_Start_Time) = 1 AND ISNUMERIC(quantityused) = 1
    """
    df = pd.read_sql(query, cnxn)

    # Nettoyage Production_Start_Time (prendre 8 premiers chiffres)
    df['Production_Start_Time'] = df['Production_Start_Time'].astype(str).str[:8]
    df['Production_Start_Time'] = pd.to_datetime(df['Production_Start_Time'], format='%Y%m%d', errors='coerce')
    df = df.dropna(subset=['Production_Start_Time'])

    # Conversion en float
    df['quantityused'] = pd.to_numeric(df['quantityused'], errors='coerce')
    df = df.dropna(subset=['quantityused'])
    df['quantityused'] = df['quantityused'].astype(float)

    # Agrégation mensuelle
    df_monthly = df.resample('MS', on='Production_Start_Time')['quantityused'].sum()
    return df_monthly

# 📦 Chargement des données
with st.spinner("Chargement des données SQL Server..."):
    df_monthly = load_data()

# 🗓️ Sélection de la date de départ pour la prévision
start_date = st.date_input("📅 Date de départ de la prévision", datetime(2025, 1, 1))

# 🔢 Nombre de mois à prédire
n_periods = st.slider("🔁 Nombre de mois à prédire :", min_value=1, max_value=12, value=3)

# ✅ Modélisation ARIMA
model = pm.auto_arima(df_monthly.values,
                      start_p=0, start_q=0,
                      max_p=5, max_q=5,
                      d=1,
                      seasonal=False,
                      trace=False,
                      error_action='ignore',
                      suppress_warnings=True,
                      stepwise=True)

forecast, conf_int = model.predict(n_periods=n_periods, return_conf_int=True)

# ✅ Générer les futures dates
future_dates = pd.date_range(start=pd.to_datetime(start_date), periods=n_periods, freq='MS')
forecast_series = pd.Series(forecast, index=future_dates)

# 📊 Affichage graphique
st.subheader("📉 Évolution de la quantité utilisée + prévision")
fig, ax = plt.subplots(figsize=(12, 6))
ax.plot(df_monthly, label="Historique", marker='o')
ax.plot(forecast_series, label="Prévision", color='red', marker='o')
ax.fill_between(future_dates, conf_int[:, 0], conf_int[:, 1], color='pink', alpha=0.3)
ax.set_xlabel("Date")
ax.set_ylabel("Quantité utilisée")
ax.set_title("Prévision ARIMA")
ax.legend()
ax.grid(True)
st.pyplot(fig)

# 🧾 Détails des données prédites
st.subheader("📋 Détails des prévisions")
st.dataframe(forecast_series.rename("Prévision").round(2))
