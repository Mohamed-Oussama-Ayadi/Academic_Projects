# 🍝 La Cucina — Plateforme de gestion de restaurant

Projet intégré (PIDEV, 3ᵉ année ESPRIT) réalisé en équipe : une application **desktop JavaFX** et une application **web Symfony** qui partagent la même base MySQL.

## 📂 Structure

| Dossier | Contenu |
|---|---|
| [`Desktop_App_JavaFX`](Desktop_App_JavaFX) | Application desktop : connexion, tableau de bord admin, tables & réservations, événements, dons, produits/ingrédients, commandes, réclamations, calendrier, carte, paiement Stripe, envoi de mails Gmail |
| [`Web_App_Symfony/Events_Reservations_Module`](Web_App_Symfony/Events_Reservations_Module) | Module web : événements, tables et réservations (front + back-office) |
| [`Web_App_Symfony/Complaints_Module`](Web_App_Symfony/Complaints_Module) | Module web : réclamations, réponses, statistiques, notification WhatsApp (Twilio), filtre de mots interdits |
| [`Web_App_Symfony/Table_Reservation_Prototype`](Web_App_Symfony/Table_Reservation_Prototype) | Premier prototype CRUD des réservations |
| [`Database/cucina.sql`](Database/cucina.sql) | Script de la base de données MySQL |

## ▶️ Lancer le projet

**Base de données :** importer `Database/cucina.sql` dans MySQL (base `cucina`).

**Desktop (JavaFX) :** ouvrir `Desktop_App_JavaFX` dans IntelliJ → `mvn javafx:run`.

**Web (Symfony) :**
```bash
composer install
php bin/console doctrine:database:create
symfony serve
```

## 🔐 Clés API
Les clés et mots de passe ont été retirés du code. Remplace les valeurs `YOUR_...` / `CHANGE_ME` par les tiennes :
Stripe (`services/Payment.java`), Google OAuth (`client_secret_*.json` à placer dans `src/main/resources`), Twilio et `MAILER_DSN` (fichiers `.env`).
