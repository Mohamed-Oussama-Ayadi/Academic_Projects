package controllers;

import com.google.code.kaptcha.Constants;
import com.google.code.kaptcha.impl.DefaultKaptcha;
import com.google.code.kaptcha.util.Config;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.stage.Stage;
import models.Role;
import models.Utilisateurs;
import utils.DBConnection;

import java.io.IOException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Properties;

// Bouton enter clavier pour le login
import javafx.scene.input.KeyCode;
import javafx.scene.input.KeyEvent;

public class Login {

    @FXML
    private TextField UsernameField;

    @FXML
    private PasswordField PasswordField;
    @FXML
    private TextField PasswordField1;

    @FXML
    private Label captchaTextLabel;

    @FXML
    private TextField captchaTextField;
    @FXML
    private Button SeConnecterButton;

    @FXML
    private Button SignUpButton;

    @FXML
    private Hyperlink LoginForgetPassword;

    @FXML
    private CheckBox LoginShowPassword;


    @FXML
    private Label errorLabel;

    private int idUtilisateur;

    @FXML
    void initialize() {
        String captchaText = generateCaptcha();
        captchaTextLabel.setText(captchaText);
        ///////////////////////////////////////////////////////////////////////////////////////

    }
    @FXML
    public void LoginButtonOnAction(ActionEvent e) {
        // Vérifier le Captcha
        String captchaText = captchaTextLabel.getText();
        String userInput = captchaTextField.getText();
        if (!userInput.equals(captchaText)) {
            errorLabel.setText("Captcha incorrect");
            return;
        }
        String password = PasswordField.getText().trim(); // Récupérer le mot de passe du champ PasswordField

        if (!UsernameField.getText().isBlank() && !password.isBlank()) {
            ValidateLogin(password); // Appeler la méthode ValidateLogin avec le mot de passe récupéré
        }
    }

    public void ValidateLogin(String password) {
        DBConnection cnx = DBConnection.getInstance();
        Connection connect = cnx.getCnx();

        String verifyLogin = "SELECT * FROM utilisateurs WHERE surnom=? AND MotDePasse=?";
        try {
            PreparedStatement statement = connect.prepareStatement(verifyLogin);
            statement.setString(1, UsernameField.getText());

            // Utiliser le mot de passe du champ PasswordField ou PasswordField1 en fonction de l'état de LoginShowPassword
            String hashedPassword;
            if (LoginShowPassword.isSelected()) {
                hashedPassword = hashPassword(PasswordField1.getText().trim());
            } else {
                hashedPassword = hashPassword(PasswordField.getText().trim());
            }
            statement.setString(2, hashedPassword);


            ResultSet queryResult = statement.executeQuery();
            if (queryResult.next()) {
                // Récupérer toutes les informations de l'utilisateur depuis la base de données
                int idUtilisateur = queryResult.getInt("idUtilisateur");
                String nom = queryResult.getString("nom");
                String prenom = queryResult.getString("prenom");
                String surnom = queryResult.getString("surnom");
                String sexe = queryResult.getString("sexe");
                String email = queryResult.getString("email");
                int numeroTelephone = queryResult.getInt("numeroTelephone");
                Role role = Role.valueOf(queryResult.getString("role"));
                String image_user = queryResult.getString("image_user");

                // Créer un objet Utilisateurs avec les informations récupérées
                Utilisateurs utilisateur = new Utilisateurs(idUtilisateur, nom, prenom, surnom, sexe, email, numeroTelephone, role, hashedPassword, image_user);

                // Rediriger en fonction du rôle de l'utilisateur
                if (role == Role.ADMIN) {
                    errorLabel.setText("Connecté en tant qu'administrateur !");
                    openAdminInterface(idUtilisateur);
                } else if (role == Role.CLIENT) {
                    errorLabel.setText("Connecté en tant que client !");
                    openFrontInterface(utilisateur);
                }
            } else {
                errorLabel.setText("Nom d'utilisateur ou mot de passe incorrect !");
            }
        } catch (SQLException | NoSuchAlgorithmException ex) {
            ex.printStackTrace();
        }
    }

/////////////////////////////////////////*    Hashage Mot de Passe    */////////////////////////////////////////////////////////////////////////////////////

    private String hashPassword(String password) throws NoSuchAlgorithmException {
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] hash = digest.digest(password.getBytes());
        StringBuilder hexString = new StringBuilder();
        for (byte b : hash) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }
/////////////////////////////////////////*    Open Sign Up    */////////////////////////////////////////////////////////////////////////////////////


    @FXML
    private void openSignUp() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/SignUp.fxml"));
            Parent root = loader.load();
            Stage stage = new Stage();
            stage.setScene(new Scene(root));
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        }

    }
    /////////////////////////////////////////*    SHOW Password Login    */////////////////////////////////////////////////////////////////////////////////////
    public void ShowPassword(){
        if(LoginShowPassword.isSelected()){
            PasswordField1.setText( PasswordField.getText());
            PasswordField1.setVisible(true);
            PasswordField.setVisible(false);
        }
        else {
            PasswordField.setText(PasswordField1.getText());
            PasswordField1.setVisible(false);
            PasswordField.setVisible(true);
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    /* private void openFrontInterface(int userId) {
         try {
             FXMLLoader loader = new FXMLLoader(getClass().getResource("/Home.fxml"));
             Parent parent = loader.load();

             // Accéder au contrôleur de la nouvelle fenêtre
             Home controller = loader.getController();
             controller.setId(userId); // Définir l'ID de l'utilisateur dans le contrôleur

             Scene scene = new Scene(parent);
             Stage stage = new Stage();
             stage.setTitle("La Cucina");
             stage.setScene(scene);
             Stage currentStage = (Stage) PasswordField1.getScene().getWindow();
             currentStage.close();
             stage.show();

         } catch (IOException ex) {
             throw new RuntimeException(ex);
         }
     }
 */
    private void openFrontInterface(Utilisateurs utilisateur) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Home.fxml"));
            Parent parent = loader.load();

            // Accéder au contrôleur de la nouvelle fenêtre
            Home controller = loader.getController();
            controller.setUtilisateur(utilisateur); // Définir l'utilisateur dans le contrôleur

            System.out.println("utilisateur envoyer"+utilisateur.getIdUtilisateur());
            // Créer une nouvelle scène
            Scene scene = new Scene(parent);
            // Obtenir la scène à partir de n'importe quel nœud
            Stage stage = (Stage) UsernameField.getScene().getWindow();

            // Configurer la nouvelle scène
            stage.setScene(scene);
            stage.setTitle("Accueil"); // Définir le titre de la fenêtre
            stage.show(); // Afficher la nouvelle fenêtre

        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    private void openAdminInterface(int userId) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Dashboard.fxml"));
            Parent parent = loader.load();


            Scene scene = new Scene(parent);
            Stage stage = new Stage();
            stage.setTitle("Admin Interface");
            stage.setScene(scene);
            Stage currentStage = (Stage) PasswordField1.getScene().getWindow();
            currentStage.close();
            stage.show();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        }
    }

    @FXML
    private void handleForgetPasswordLink(ActionEvent event) {
        try {
            // Charger la nouvelle vue depuis le fichier FXML
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/ForgetPassword.fxml"));
            Parent root = loader.load();

            // Récupérer la scène actuelle
            Scene scene = LoginForgetPassword.getScene();

            // Changer la scène pour afficher la nouvelle vue
            scene.setRoot(root);
        } catch (IOException e) {
            e.printStackTrace();
            // Gérer l'erreur de chargement de la vue
        }
    }



    private String generateCaptcha() {
        DefaultKaptcha kaptcha = new DefaultKaptcha();
        Properties properties = new Properties();
        // Configure Kaptcha properties as needed
        properties.setProperty(Constants.KAPTCHA_TEXTPRODUCER_FONT_SIZE, "40");
        Config config = new Config(properties);
        kaptcha.setConfig(config);
        return kaptcha.createText();
    }


/////////////////////////////////// Appuie Entrer Claver --> passe Login ///////////////////////////////////////

}