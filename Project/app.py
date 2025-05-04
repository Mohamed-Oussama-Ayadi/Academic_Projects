from flask import Flask, render_template, request
import torch
import torchvision.transforms as transforms
from torchvision import models
from PIL import Image
import os
import nltk
from nltk.sentiment.vader import SentimentIntensityAnalyzer
import joblib
import numpy as np
import pandas as pd
from sklearn.feature_extraction.text import TfidfVectorizer
from sklearn.metrics.pairwise import cosine_similarity
import secrets
from flask_cors import CORS


nltk.download('vader_lexicon')

app = Flask(__name__)
CORS(app, resources={r"/*": {"origins": "http://localhost:4200"}})
app.config['UPLOAD_FOLDER'] = 'static/uploads'
app.secret_key = secrets.token_hex(16)
# === Box Classifier ===
model = models.resnet18(weights=None)
model.fc = torch.nn.Linear(model.fc.in_features, 2)
model.load_state_dict(torch.load('box_classifier_resnet18.pth', map_location=torch.device('cpu')))
model.eval()

# === Revenue Model ===
revenue_model = joblib.load('revenue_model.pkl')
revenue_features = joblib.load('revenue_model_columns.pkl')
available_brands = [feat.replace('BrandName_', '') for feat in revenue_features if feat.startswith('BrandName_')]

# === Sentiment Analyzer ===
analyzer = SentimentIntensityAnalyzer()

# === Stock Models ===
model_classif = joblib.load("model_classif_stock.pkl")
model_regr = joblib.load("model_regr_stock.pkl")
model_clust = joblib.load("model_clust_stock.pkl")
scaler = joblib.load("scaler.pkl")
df = pd.read_csv("products.csv")

# === Recommendation Production ===
df_production = joblib.load("df_production.pkl")
tfidf_prod = joblib.load("tfidf_production.pkl")
tfidf_matrix_prod = joblib.load("tfidf_matrix_production.pkl")
cosine_sim_prod = cosine_similarity(tfidf_matrix_prod, tfidf_matrix_prod)
indices_prod = pd.Series(df_production.index, index=df_production['Product_Name'])

import pyodbc
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from flask import request, render_template
from statsmodels.tsa.statespace.sarimax import SARIMAX
import io
import base64
import pandas as pd
from datetime import datetime

from flask import request, render_template, flash
import pyodbc
import pandas as pd
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
from statsmodels.tsa.statespace.sarimax import SARIMAX
import io
import base64

@app.route('/forecast_production', methods=['GET'])
def forecast_production():
    # 📦 Connexion SQL Server
    conn_str = (
        "Driver={ODBC Driver 17 for SQL Server};"
        "Server=LAPTOP-GPVK1ANC;"
        "Database=DW_SupplyChain;"
        "Trusted_Connection=yes;"
    )
    cnxn = pyodbc.connect(conn_str)

    # 📊 Extraction
    query = """
    SELECT Production_Start_Time, quantityused
    FROM fact_production
    """
    df = pd.read_sql(query, cnxn)
    df['Production_Start_Time'] = df['Production_Start_Time'].astype(str).str[:8]
    df['Production_Start_Time'] = pd.to_datetime(df['Production_Start_Time'], format='%Y%m%d', errors='coerce')
    df['quantityused'] = pd.to_numeric(df['quantityused'], errors='coerce')
    df = df.dropna()
    df = df.sort_values('Production_Start_Time')
    df_monthly = df.resample('MS', on='Production_Start_Time')['quantityused'].sum()

    # 🧭 Paramètres
    default_start = df_monthly.index[-1] + pd.DateOffset(months=1)
    start_date_str = request.args.get('start_date', default_start.strftime('%Y/%m/%d'))
    n_months = int(request.args.get('n_months', 3))

    try:
        start_date = pd.to_datetime(start_date_str)
    except ValueError:
        start_date = default_start

    # 🧮 Décalage futur
    last_date = df_monthly.index[-1]
    delta = (start_date.year - last_date.year) * 12 + (start_date.month - last_date.month)

    if delta > 0:
        # 📣 Notification visible dans l'interface utilisateur
        flash(f"📌 Insertion automatique de {delta} mois pour atteindre la date de départ demandée : {start_date.strftime('%Y-%m')}", "warning")
        future_dates = pd.date_range(start=last_date + pd.DateOffset(months=1), periods=delta, freq='MS')
        df_padding = pd.Series([None]*delta, index=future_dates)
        df_monthly = pd.concat([df_monthly, df_padding])

    # ✅ Conversion explicite en float
    df_monthly = df_monthly.astype(float)

    # 🤖 Modèle ARIMA
    model = SARIMAX(df_monthly, order=(1,1,1), seasonal_order=(0,0,0,0))
    result = model.fit(disp=False)
    forecast = result.get_forecast(steps=n_months)
    pred_series = forecast.predicted_mean
    conf_int = forecast.conf_int()

    # 📈 Graphique
    plt.figure(figsize=(10, 5))
    plt.plot(df_monthly, label="Historique", marker='o')
    plt.plot(pred_series, label="Prévision", color='red', marker='o')
    plt.fill_between(pred_series.index, conf_int.iloc[:, 0], conf_int.iloc[:, 1], color='pink', alpha=0.3)
    plt.title(f"Prévision ARIMA sur {n_months} mois")
    plt.xlabel("Date")
    plt.ylabel("Quantité utilisée")
    plt.legend()
    plt.grid(True)

    buf = io.BytesIO()
    plt.savefig(buf, format='png')
    buf.seek(0)
    plot_url = base64.b64encode(buf.read()).decode('utf-8')
    plt.close()

    # 📋 Table de prévision
    forecast_table = pd.DataFrame({
        'Date': pred_series.index.strftime('%Y-%m'),
        'Prévision': pred_series.round(2)
    })

    return render_template('forecast_production.html',
                           plot_url=plot_url,
                           forecast_table=forecast_table.to_dict(orient='records'),
                           default_date=start_date.strftime('%Y/%m/%d'),
                           n_months=n_months)
@app.route('/download_forecast_csv')
def download_forecast_csv():
    from flask import make_response
    import io

    # ⚠️ Tu peux stocker les mêmes étapes que dans forecast_production()
    # Ou mieux : refactoriser dans une fonction commune (optionnel ici)
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
    """
    df = pd.read_sql(query, cnxn)
    df['Production_Start_Time'] = df['Production_Start_Time'].astype(str).str[:8]
    df['Production_Start_Time'] = pd.to_datetime(df['Production_Start_Time'], format='%Y%m%d', errors='coerce')
    df['quantityused'] = pd.to_numeric(df['quantityused'], errors='coerce')
    df = df.dropna()
    df = df.sort_values('Production_Start_Time')
    df_monthly = df.resample('MS', on='Production_Start_Time')['quantityused'].sum()

    model = SARIMAX(df_monthly, order=(1,1,1), seasonal_order=(0,0,0,0))
    result = model.fit(disp=False)
    forecast = result.get_forecast(steps=3)
    pred_series = forecast.predicted_mean

    forecast_table = pd.DataFrame({
        'Date': pred_series.index.strftime('%Y-%m'),
        'Prévision': pred_series.round(2)
    })

    # Génération CSV
    output = io.StringIO()
    forecast_table.to_csv(output, index=False)
    response = make_response(output.getvalue())
    response.headers['Content-Disposition'] = 'attachment; filename=forecast_production.csv'
    response.headers["Content-type"] = "text/csv"
    return response
# --- IMPORTS pour le modèle deep learning cosmetics ---
from tensorflow.keras.models import load_model
from tensorflow.keras.preprocessing import image
import numpy as np
import os

# --- Charger le modèle une seule fois au démarrage ---
cosmetics_model = load_model('model_cosmetics_fixed.keras')


# --- Définir les classes dans l'ordre ---
cosmetics_classes = ['blush', 'eyeliner', 'eyeshadow', 'foundation', 'lipstick', 'mascara']
from flask import Flask, render_template, request, redirect, url_for

@app.route('/cosmetics_predict', methods=['GET', 'POST'])
def cosmetics_predict():
    if request.method == 'POST':
        if 'file' not in request.files:
            return redirect(request.url)
        file = request.files['file']
        if file.filename == '':
            return redirect(request.url)
        if file:
            filepath = os.path.join('static/uploads', file.filename)
            file.save(filepath)

            # Préparation de l'image
            img = image.load_img(filepath, target_size=(224, 224))
            img_array = image.img_to_array(img)
            img_array = np.expand_dims(img_array, axis=0)
            img_array = img_array / 255.0

            # Prédiction
            prediction = cosmetics_model.predict(img_array)
            predicted_class = cosmetics_classes[np.argmax(prediction)]

            return render_template('cosmetics_result.html', filename=file.filename, prediction=predicted_class)
    return render_template('cosmetics_predict.html')
from classification_production_service import predict_category

@app.route('/classification_production', methods=['GET', 'POST'])
def classification_production():
    if request.method == 'POST':
        try:
            dosage = float(request.form['dosage'])  # ✅ utiliser float au lieu de int

            input_data = {
                'Dosage': dosage
            }

            prediction = predict_category(input_data)

            return render_template('classification_production_result.html', prediction=prediction)
        except Exception as e:
            return render_template('classification_production_result.html', prediction=f"Erreur: {e}")

    return render_template('classification_production.html')

from regression_production_service import predict_quantity
@app.route('/regression_production', methods=['GET', 'POST'])
def regression_production():
    if request.method == 'POST':
        try:
            product_fk = int(request.form['productFK'])
            brand_fk = int(request.form['brandFK'])
            dosage = float(request.form['dosage'])
            production_duration_hours = float(request.form['production_duration_hours'])

            input_data = {
                'productFK': product_fk,
                'brandFK': brand_fk,
                'Dosage': dosage,
                'production_duration_hours': production_duration_hours
            }

            prediction = predict_quantity(input_data)

            return render_template('regression_production_result.html', prediction=prediction)
        except Exception as e:
            return render_template('regression_production_result.html', prediction=f"Erreur: {e}")

    return render_template('regression_production.html')


# === Recommandation Stock ===
def recommend_products(price_range=None, rating_min=None, brand=None):
    filtered_df = df.copy()
    if price_range and price_range[0] != '' and price_range[1] != '':
        min_price, max_price = float(price_range[0]), float(price_range[1])
        filtered_df = filtered_df[(filtered_df["Price"] >= min_price) & (filtered_df["Price"] <= max_price)]
    if rating_min not in [None, '', 'NaN']:
        filtered_df = filtered_df[filtered_df["Rating"] >= float(rating_min)]
    if brand:
        filtered_df = filtered_df[filtered_df["Brand"] == brand]
    if not filtered_df.empty:
        try:
            filtered_df[["Price", "Rating", "Reviews"]] = scaler.inverse_transform(
                filtered_df[["Price", "Rating", "Reviews"]])
        except ValueError:
            pass
    return filtered_df.head(5)

# === Recommendation Production Logic ===
def get_filtered_recommendations_production(product_name, user_skin_type=None, user_usage=None, top_n=10):
    idx = indices_prod[product_name]
    if isinstance(idx, pd.Series):
        idx = idx.iloc[0]
    sim_scores = list(enumerate(cosine_sim_prod[idx]))
    sim_scores = sorted(sim_scores, key=lambda x: x[1], reverse=True)[1:]

    filtered_indices = []
    for i, _ in sim_scores:
        if user_skin_type and df_production.iloc[i]['Skin_Type'] != user_skin_type:
            continue
        if user_usage and df_production.iloc[i]['Usage_Frequency'] != user_usage:
            continue
        filtered_indices.append(i)
        if len(filtered_indices) >= top_n:
            break

    return df_production[['Product_Name', 'Brand', 'Category', 'Skin_Type', 'Usage_Frequency', 'Rating']].iloc[filtered_indices]

# === Flask Routes ===
@app.route('/')
def index():
    return render_template('index.html')

@app.route('/box', methods=['GET', 'POST'])
def box():
    if request.method == 'POST':
        file = request.files['image']
        if file:
            if not file.mimetype.startswith('image/'):
                return render_template('box_result.html', result="⚠️ Invalid file type.", image_path=None)
            img_path = os.path.join(app.config['UPLOAD_FOLDER'], file.filename)
            file.save(img_path)
            image = Image.open(img_path).convert('RGB')
            img_tensor = transforms.Compose([transforms.Resize((224, 224)), transforms.ToTensor()])(image).unsqueeze(0)
            with torch.no_grad():
                outputs = model(img_tensor)
                _, predicted = torch.max(outputs, 1)
                probs = torch.nn.functional.softmax(outputs, dim=1)
                confidence = probs[0][predicted.item()] * 100
                predicted_class = 'Good Packaging' if predicted.item() == 1 else 'Defective Packaging'
                emoji = '✅' if predicted_class == 'Good Packaging' else '❌'
                result = f"{emoji} {predicted_class} ({confidence:.2f}% confidence)"
            return render_template('box_result.html', image_path=img_path, result=result)
    return render_template('box.html')

@app.route('/review', methods=['GET', 'POST'])
def review():
    if request.method == 'POST':
        text = request.form['review']
        scores = analyzer.polarity_scores(text)
        compound = scores['compound']
        sentiment = 'Positive' if compound >= 0.05 else 'Negative' if compound <= -0.05 else 'Neutral'
        return render_template('review_result.html', text=text, sentiment=sentiment, score=compound)
    return render_template('review.html')

@app.route('/predict', methods=['GET', 'POST'])
def predict():
    if request.method == 'POST':
        try:
            year = int(request.form['year'])
            month = int(request.form['month'])
            avg_unit_price = float(request.form['avg_unit_price'])
            total_quantity = int(request.form['total_quantity'])
            brand = request.form['brand']
            input_data = {'year': year, 'month': month, 'Avg_Unit_Price': avg_unit_price, 'Total_Quantity': total_quantity}
            for col in revenue_features:
                input_data[col] = 1 if col == f'BrandName_{brand}' else 0
            X_input = np.array([input_data[feat] for feat in revenue_features]).reshape(1, -1)
            prediction = max(0, revenue_model.predict(X_input)[0])
            return render_template('predict_result.html', prediction=prediction)
        except Exception as e:
            return f"Error: {str(e)}"
    return render_template('predict.html', brands=available_brands)

@app.route('/recommandation_stock', methods=['GET', 'POST'])
def recommandation():
    brands = df['Brand'].dropna().unique().tolist()
    if request.method == 'POST':
        price_min = request.form.get('price_min', '')
        price_max = request.form.get('price_max', '')
        rating_min = request.form.get('rating_min', '')
        brand = request.form.get('brand', None)
        recommended = recommend_products((price_min, price_max), rating_min, brand)
    else:
        recommended = recommend_products()
    return render_template('recommandation_stock.html', products=recommended.to_dict(orient='records'), brands=brands)

@app.route('/clustering_stock', methods=['GET', 'POST'])
def clustering():
    prediction = interpretation = pourcentage = None
    if request.method == 'POST':
        try:
            capacity = float(request.form['capacity'])
            quantity = float(request.form['quantity'])
            features = np.array([[capacity, quantity]])
            prediction = int(model_clust.predict(features)[0])
            pourcentage = round((quantity / capacity) * 100, 2)
            if prediction == 0:
                interpretation = "Critical stock: Immediate restocking is necessary."
            elif prediction == 1:
                interpretation = "Moderate stock: Restocking can be done soon."
            else:
                interpretation = "High stock: No restocking needed."
        except Exception as e:
            prediction = f"Erreur : {str(e)}"
    return render_template('clustering_stock.html', prediction=prediction, interpretation=interpretation, pourcentage=pourcentage)

@app.route('/classification_stock', methods=['GET', 'POST'])
def classification():
    prediction = message = None
    if request.method == 'POST':
        try:
            capacity = float(request.form['capacity'])
            prediction = model_classif.predict(np.array([[capacity]]))[0]
            if prediction == 'Low':
                message = "⚠️ Low stock! Restock now."
            elif prediction == 'Medium':
                message = "✔️ Moderate stock. Monitor closely."
            else:
                message = "✅ High stock. All good."
        except Exception as e:
            prediction = "Error"
            message = str(e)
    return render_template('classification_stock.html', prediction=prediction, message=message)

@app.route('/regression_stock', methods=['GET', 'POST'])
def regression():
    prediction = alert = recommendation = None
    if request.method == 'POST':
        try:
            capacity = float(request.form['capacity'])
            features = np.array([[capacity]])
            predicted_usage = model_regr.predict(features)[0]
            prediction = round(predicted_usage, 2)
            if predicted_usage >= 0.8 * capacity:
                alert = "⚠️ Alert: Imminent depletion!"
                recommendation = "📦 Restock fast."
            elif predicted_usage >= 0.6 * capacity:
                alert = "🔶 Warning: Decreasing stock."
                recommendation = "Plan restocking."
            else:
                alert = "✅ Sufficient stock."
                recommendation = "No action required."
        except Exception as e:
            prediction = f"Error: {str(e)}"
    return render_template('regression_stock.html', prediction=prediction, alert=alert, recommendation=recommendation)

def get_filtered_recommendations_production(product_name, user_skin_type, user_usage):
    filtered = df_production[
        (df_production['Product_Name'] == product_name) &
        (df_production['Skin_Type'] == user_skin_type) &
        (df_production['Usage_Frequency'] == user_usage)
    ]
    return filtered

@app.route('/recommendation_production', methods=['GET'])
def recommendation_production():
    product_name = request.args.get('product_name')
    user_skin_type = request.args.get('user_skin_type')
    user_usage = request.args.get('user_usage')

    if not all([product_name, user_skin_type, user_usage]):
        return jsonify({"error": "Missing parameters"}), 400

    results = get_filtered_recommendations_production(product_name, user_skin_type, user_usage)

    return jsonify(results.to_dict(orient='records'))

# ✅ Import nécessaire en haut de ton fichier app.py
import pickle
from flask import Flask, render_template, request, redirect, url_for, flash
with open('B_linear_regression_model.pkl', 'rb') as f:
    b_linear_model = pickle.load(f)
# ✅ Charger ton modèle ARIMA une seule fois au début de ton app
with open('aarima_model.pkl', 'rb') as f:
    aarima_model = pickle.load(f)

@app.route('/predict_arriima', methods=['GET', 'POST'])
def predict_arriima():
    prediction = None
    if request.method == 'POST':
        try:
            n_periods = int(request.form['input_value'])  # récupérer l'entrée utilisateur

            # ⚡ Utilisation directe de predict() sur le modèle sauvegardé
            prediction = aarima_model.predict(start=0, end=n_periods-1)

            prediction = prediction.tolist()  # rendre compatible avec Jinja pour affichage
        except Exception as e:
            flash(f"Erreur : {str(e)}", "danger")
    
    return render_template('predict_arriima.html', prediction=prediction)


import numpy as np

@app.route('/predict_blinear', methods=['GET', 'POST'])
def predict_blinear():
    prediction = None
    if request.method == 'POST':
        try:
            input_value = float(request.form['input_value'])
            X_input = np.zeros((1, 204))  # 🔥 Créer 204 colonnes par défaut
            X_input[0, 0] = input_value   # 🔥 Mettre ta valeur dans la 1ère colonne seulement
            prediction = b_linear_model.predict(X_input)
            prediction = prediction[0]
        except Exception as e:
            flash(f"Erreur : {str(e)}", 'danger')
    return render_template('predict_blinear.html', prediction=prediction)


if __name__ == '__main__':
    os.makedirs(app.config['UPLOAD_FOLDER'], exist_ok=True)
    app.run(debug=True)
