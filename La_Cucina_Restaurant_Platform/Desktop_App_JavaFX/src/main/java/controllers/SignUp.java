package controllers;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.ResourceBundle;
import com.github.sarxos.webcam.Webcam;
import javafx.embed.swing.SwingFXUtils;
import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Base64;
import java.util.UUID;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Role;
import models.Utilisateurs;
import services.ServiceUser;
import javafx.scene.control.Tooltip;
import test.GMailer;

public class SignUp {

    @FXML
    private Button boutonRetour;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private PasswordField ConfirmPasswordField;

    @FXML
    private TextField EmailField;

    @FXML
    private RadioButton FemaleButton;

    @FXML
    private AnchorPane Firstname;

    @FXML
    private TextField FirstnameField;

    @FXML
    private ImageView ImageViewUser;

    @FXML
    private TextField LastnameField;

    @FXML
    private RadioButton MaleButton;

    @FXML
    private TextField NumberPhoneField;

    @FXML
    private PasswordField PasswordField;

    @FXML
    private Button Register;

    @FXML
    private Button SelectImageButton;

    @FXML
    private TextField UsernameField;

    @FXML
    private ImageView complexityImageView;

    @FXML
    private Label passwordMatchLabel;

    @FXML
    private Tooltip passwordTooltip;
    @FXML
    private Label usernameStatusLabel;


    // Déclarez une variable pour stocker le chemin d'accès de l'image
    private String imagePath;

    // Variable pour stocker la complexité du mot de passe
    private String passwordComplexity;

    private ServiceUser serviceUser;

    @FXML
    void initialize() {

        serviceUser = new ServiceUser();


        Register.setOnAction(event -> registerUser());
        SelectImageButton.setOnAction(event -> selectImage());

        // Ajout d'un écouteur d'événements pour gérer la sélection d'une seule option parmi les boutons radio de sexe
        MaleButton.setOnAction(event -> {
            if (MaleButton.isSelected()) {
                FemaleButton.setSelected(false);
            }
        });

        FemaleButton.setOnAction(event -> {
            if (FemaleButton.isSelected()) {
                MaleButton.setSelected(false);
            }
        });

// Création du Tooltip pour afficher les informations sur la complexité du mot de passe
        passwordTooltip = new Tooltip();
// Définition de la taille de la police
        passwordTooltip.setStyle("-fx-font-size: 15px;");
  // Définition de la couleur de fond
        passwordTooltip.setStyle("-fx-background-color: #1A2646;");
        // Activation du retour à la ligne automatique
        passwordTooltip.setWrapText(true);
        // Définition de la largeur maximale et minimale du Tooltip
        passwordTooltip.setMaxWidth(300); // Largeur maximale
        passwordTooltip.setMinWidth(80); // Largeur minimale

        // Définition de la hauteur maximale et minimale du Tooltip
        passwordTooltip.setMaxHeight(300); // Hauteur maximale
        passwordTooltip.setMinHeight(80); // Hauteur minimale

        // Associer le Tooltip au champ de mot de passe
        PasswordField.setTooltip(passwordTooltip);

        // Ajoutez un écouteur d'événements sur le champ de mot de passe pour détecter les modifications
        PasswordField.textProperty().addListener((observable, oldValue, newValue) -> {
            evaluatePasswordComplexity(newValue, passwordTooltip);
        });


        // Ajouter un écouteur d'événements pour surveiller les modifications dans les champs de mot de passe et de confirmation de mot de passe
        ConfirmPasswordField.textProperty().addListener((observable, oldValue, newValue) -> {
            updatePasswordMatchLabel(); // Mettre à jour le label à chaque modification
        });

        ConfirmPasswordField.setOnKeyReleased(event -> {
            updatePasswordMatchLabel(); // Mettre à jour le label lorsque une touche est relâchée dans le champ ConfirmPasswordField
        });




        // Ajouter un écouteur d'événements sur le champ UsernameField pour détecter les changements de texte
        UsernameField.textProperty().addListener((observable, oldValue, newValue) -> {
            // Vérifier si le nouveau nom d'utilisateur est unique
            if (!newValue.isEmpty()) {
                boolean isUnique = isUsernameUnique(newValue);
                if (isUnique) {
                    // Mettre à jour le libellé pour indiquer que le nom d'utilisateur est unique
                    // Par exemple, en changeant la couleur du texte ou en affichant un message
                    usernameStatusLabel.setText("Username available");
                    usernameStatusLabel.setStyle("-fx-text-fill: green;");
                } else {
                    // Mettre à jour le libellé pour indiquer que le nom d'utilisateur n'est pas unique
                    usernameStatusLabel.setText("Username not available");
                    usernameStatusLabel.setStyle("-fx-text-fill: red;");
                }
            } else {
                // Effacer le libellé s'il n'y a pas de saisie dans le champ UsernameField
                usernameStatusLabel.setText("");
            }
        });

    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void registerUser() {
        String firstname = FirstnameField.getText();
        String lastname = LastnameField.getText();
        String username = UsernameField.getText();
        String email = EmailField.getText();
        int phoneNumber = Integer.parseInt(NumberPhoneField.getText());
        String password = PasswordField.getText();
        String confirmPassword = ConfirmPasswordField.getText();
        Role role = Role.CLIENT; // Rôle par défaut
        // Vérification du bouton radio pour le sexe
        String gender;
        if (MaleButton.isSelected()) {
            gender = "male";
        } else if (FemaleButton.isSelected()) {
            gender = "female";
        } else {
            gender = ""; // Défaut si aucun bouton n'est sélectionné
        }

        // Vérification si les champs obligatoires sont vides
        if (firstname.isEmpty() || lastname.isEmpty() || username.isEmpty() || email.isEmpty() || NumberPhoneField.getText().isEmpty() || password.isEmpty() || confirmPassword.isEmpty()) {
            showAlert(Alert.AlertType.ERROR, "Required fields", "Please fill in all mandatory fields.");
            return;
        }

        // Vérifiez si le nom et le prénom ne contiennent que des lettres
        if (!estToutLettres(firstname)) {
            showAlert(Alert.AlertType.ERROR, "Invalid format", "The first name must only contain letters.");
            return;
        }
        if (!estToutLettres(lastname)) {
            showAlert(Alert.AlertType.ERROR, "Invalid format", "The last name must contain only letters.");
            return;
        }

        // Vérification de la similitude entre le mot de passe et la confirmation
        if (!password.equals(confirmPassword)) {
            showAlert(Alert.AlertType.ERROR, "Error", "Passwords do not match.");
            return;
        }

        // Vérification du format de l'email
        if (!isValidEmail(email)) {
            showAlert(Alert.AlertType.ERROR, "Invalid email format", "Please enter a valid email address.");
            return;
        }

        // Vérification de l'unicité du nom d'utilisateur
        if (!isUsernameUnique(username)) {
            showAlert(Alert.AlertType.ERROR, "Non-unique username", "The username already exists. Please choose another.");
            return;
        }

        // Évaluation de la complexité du mot de passe
        evaluatePasswordComplexity(password, passwordTooltip);

        // Vérification de la complexité du mot de passe
        if (!passwordComplexity.equals("excellent")) {
            showAlert(Alert.AlertType.ERROR, "Weak or medium password", "Password must be excellent to register.");
            return;
        }

        // Si toutes les validations sont réussies, ajoutez l'utilisateur à la base de données
        Utilisateurs utilisateur = new Utilisateurs(firstname, lastname, username, gender, email, phoneNumber, Role.CLIENT, password, imagePath);

        // Créer une instance du service utilisateur
        ServiceUser serviceUser = new ServiceUser();

        try {
            // Utiliser le service utilisateur pour ajouter l'utilisateur à la base de données
            serviceUser.insertOne1(utilisateur);

            // Afficher un message de succès
            showAlert(Alert.AlertType.INFORMATION, "Success", "User added successfully !");
            // Effacer les champs après l'insertion
            String subject = "Confirmation d'inscription";
            String message = "Bonjour " + firstname + ",\n\nVotre inscription a été confirmée avec succès.";
            GMailer mailer = new GMailer();
            mailer.sendMail(email, subject, message);
            clearFields();


        } catch (SQLException e) {
            // Gérer les exceptions SQL, par exemple afficher un message d'erreur
            showAlert(Alert.AlertType.ERROR,  "Error", "An error occurred while adding the user : " + e.getMessage());
        } catch (Exception e) {
            throw new RuntimeException(e);
        }


    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Méthode pour vérifier si une chaîne ne contient que des lettres
    private boolean estToutLettres(String str) {
        return str.matches("[a-zA-Z]+");
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    private boolean isValidEmail(String email) {
        // Expression régulière pour valider l'email
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";

        // Vérification de l'email en utilisant l'expression régulière
        return email.matches(emailRegex);
    }
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    private void showAlert(Alert.AlertType type, String title, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setContentText(message);
        alert.showAndWait();
    }

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public void selectImage() {
        Webcam webcam = Webcam.getDefault();

        // Open the webcam
        webcam.open();

        // Capture the image
        BufferedImage bufferedImage = webcam.getImage();

        // Close the webcam
        webcam.close();

        // Convert the captured image to JavaFX Image
        Image image = SwingFXUtils.toFXImage(bufferedImage, null);

        // Display the captured image in the ImageView
        ImageViewUser.setImage(image);

        String fileName = saveImageToFile(bufferedImage);
        if (fileName != null) {
            this.imagePath = fileName;
        } else {
        }
    }
    private String saveImageToFile(BufferedImage image) {
        // Generate a unique file name
        String fileName = UUID.randomUUID().toString() + ".png";
        // Specify the directory where you want to save the image
        String uploadDirectory = "upload";
        // Create the directory if it doesn't exist
        File directory = new File(uploadDirectory);
        if (!directory.exists()) {
            directory.mkdirs();
        }
        // Create the file to save the image
        File file = new File(directory, fileName);
        try {
            // Save the image to the file
            ImageIO.write(image, "png", file);
        } catch (IOException e) {
            e.printStackTrace();
            // Handle the exception (e.g., show an error message)
            return null; // Return null to indicate failure
        }
        // Return the file name
        return fileName;
    }
    private String imageToBase64String(BufferedImage bufferedImage) {
        String base64Image = null;
        ByteArrayOutputStream byteArrayOutputStream = new ByteArrayOutputStream();

        try {
            ImageIO.write(bufferedImage, "png", byteArrayOutputStream);
            byte[] imageBytes = byteArrayOutputStream.toByteArray();

            // Encode the image to Base64 string
            base64Image = Base64.getEncoder().encodeToString(imageBytes);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                byteArrayOutputStream.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }

        return base64Image;
    }
    private void evaluatePasswordComplexity(String password, Tooltip passwordTooltip) {
        boolean hasUpperCase = false;
        boolean hasLowerCase = false;
        boolean hasDigit = false;
        boolean hasSpecialChar = false;
        String passwordComplexity = ""; // Variable pour stocker la complexité du mot de passe


        // Parcourir chaque caractère du mot de passe pour vérifier ses caractéristiques
        for (char c : password.toCharArray()) {
            if (Character.isUpperCase(c)) {
                hasUpperCase = true;
            } else if (Character.isLowerCase(c)) {
                hasLowerCase = true;
            } else if (Character.isDigit(c)) {
                hasDigit = true;
            } else {
                // Vérifiez si le caractère est un caractère spécial
                hasSpecialChar = true;
            }
        }

        // Évaluez la complexité du mot de passe en fonction des critères et mettez à jour le Tooltip
        if (password.length() < 4 || !(hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar)) {
            passwordComplexity = "faible";
            passwordTooltip.setText("Weak Password. Password must contain at least 8 characters, one uppercase letter, one lowercase letter, one digit, and one special character.");
            complexityImageView.setImage(new Image("file:///C:/Users/moham/OneDrive/Bureau/La_Cucina_Projet_Pidev/src/main/resources/Images/password_faible.png"));
        } else if (password.length() < 8 || !(hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar)) {
            passwordComplexity = "moyen";
            passwordTooltip.setText("Medium Password. Password must contain at least 8 characters, one uppercase letter, one lowercase letter, one digit, and one special character.");
            complexityImageView.setImage(new Image("file:///C:/Users/moham/OneDrive/Bureau/La_Cucina_Projet_Pidev/src/main/resources/Images/password_moyen.png"));
        } else {
            passwordComplexity = "excellent";
            passwordTooltip.setText("Excellent Password!");
            complexityImageView.setImage(new Image("file:///C:/Users/moham/OneDrive/Bureau/La_Cucina_Projet_Pidev/src/main/resources/Images/password_excellent.png"));
        }

        // Stocker la complexité du mot de passe dans une variable pour une utilisation ultérieure
        this.passwordComplexity = passwordComplexity;
    }

    // Méthode pour mettre à jour le label indiquant si les champs de mot de passe et de confirmation de mot de passe correspondent ou non
    private void updatePasswordMatchLabel() {
        String password = PasswordField.getText();
        String confirmPassword = ConfirmPasswordField.getText();

        if (password.equals(confirmPassword)) {
            passwordMatchLabel.setText("Passwords match.");
            passwordMatchLabel.setStyle("-fx-text-fill: green;"); // Couleur verte pour indiquer une correspondance
        } else {
            passwordMatchLabel.setText("Passwords do not match.");
            passwordMatchLabel.setStyle("-fx-text-fill: red;"); // Couleur rouge pour indiquer une non-correspondance
        }
}

    private boolean isUsernameUnique(String username) {
        try {
            // Appeler la méthode isUsernameUnique du service utilisateur
            return serviceUser.isUsernameUnique(username);
        } catch (SQLException e) {
            // Gérer les exceptions, par exemple en affichant un message d'erreur
            showAlert(Alert.AlertType.ERROR, "Erreur", "Une erreur s'est produite lors de la vérification de l'unicité du nom d'utilisateur.");
            e.printStackTrace(); // Ou logger l'exception
            return false; // Ou une autre logique appropriée dans votre cas
        }
    }



    // Méthode pour effacer les champs de saisie
    private void clearFields() {
        FirstnameField.clear();
        LastnameField.clear();
        UsernameField.clear();
        EmailField.clear();
        NumberPhoneField.clear();
        PasswordField.clear();
        ConfirmPasswordField.clear();
        // Effacer l'image de ImageView
        ImageViewUser.setImage(null);
    }

    @FXML
    private void retournerALogin(ActionEvent event) {
        // Récupération du bouton à partir de l'événement
        Node source = (Node) event.getSource();
        // Récupération de la fenêtre parente du bouton
        Stage stage = (Stage) source.getScene().getWindow();
        // Fermeture de la fenêtre actuelle
        stage.close();

        try {
            // Chargement du fichier FXML de la fenêtre de connexion (Login.fxml)
            FXMLLoader loader = new FXMLLoader(getClass().getResource("Login.fxml"));
            Parent root = loader.load();

            // Création d'une nouvelle scène pour la fenêtre de connexion
            Scene scene = new Scene(root);

            // Création d'une nouvelle fenêtre
            Stage loginStage = new Stage();
            loginStage.setScene(scene);

            // Affichage de la nouvelle fenêtre de connexion
            loginStage.show();
        } catch (IOException e) {
            e.printStackTrace();
            // Gestion de l'erreur de chargement du fichier FXML
        }
    }

}


