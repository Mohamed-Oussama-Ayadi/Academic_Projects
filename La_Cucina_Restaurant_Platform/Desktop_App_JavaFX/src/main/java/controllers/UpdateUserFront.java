package controllers;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.ResourceBundle;
import java.util.regex.Pattern;

import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Role;
import models.Utilisateurs;
import services.ServiceUser;
import utils.DBConnection;

public class UpdateUserFront {

    @FXML
    private Label NomPrenomLabel;
    @FXML
    private Label idU;
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
    private Button SelectImageButton;

    @FXML
    private Button UpdateButton;

    @FXML
    private TextField UsernameField;

    @FXML
    private ImageView heroImageView1;

    @FXML
    private ImageView profileImageView;

    @FXML
    private Label messageLabel;

    @FXML
    private ImageView complexityImageView;

    @FXML
    private Label passwordMatchLabel;

    @FXML
    private Tooltip passwordTooltip;
    @FXML
    private Label usernameStatusLabel;
    private ServiceUser serviceUser;
    @FXML
    private Label errorLabel;
    @FXML
    private ComboBox<String> comboBoxImageUser;
    // Variable pour stocker la complexité du mot de passe
    private String passwordComplexity  ;


    // Déclarez une variable pour stocker le chemin d'accès de l'image
    private String imagePath;
    private ChoiceBox<String> choiceBox;

    private boolean isChoiceBoxDisplayed = false;

    @FXML
    private int userId;

    private Utilisateurs utilisateur;

    // Méthode pour initialiser les données de l'utilisateur
  /*  public void initData(Utilisateurs utilisateur) {
        this.utilisateur = utilisateur;
        // Vous pouvez utiliser les informations de l'utilisateur pour pré-remplir les champs de la page UpdateUserFront.fxml
    }*/


    public void initData(Utilisateurs utilisateur) {
        if (utilisateur != null) {
            this.utilisateur = utilisateur;
            FirstnameField.setText(utilisateur.getPrenom());
            LastnameField.setText(utilisateur.getNom());
            UsernameField.setText(utilisateur.getSurnom());
            if (utilisateur.getSexe().equals("Male")) {
                MaleButton.setSelected(true);
            } else {
                FemaleButton.setSelected(true);
            }
            EmailField.setText(utilisateur.getEmail());
            NumberPhoneField.setText(String.valueOf(utilisateur.getNumeroTelephone()));
            //Image image = new Image(utilisateur.getImage_user());
           //ImageViewUser.setImage(image);
            String nomPrenom = utilisateur.getNom() + " " + utilisateur.getPrenom();
            setUserName(nomPrenom);
        } else {
            // Gérer le cas où l'objet utilisateur est null
            System.out.println("L'objet utilisateur est null. Impossible d'initialiser les données.");
        }
    }



    // Méthode pour définir l'utilisateur après la création de l'objet UserUpdateProfile




    @FXML
    void initialize() {
        serviceUser = new ServiceUser();

        // Ajout des éléments au ComboBox
        comboBoxImageUser.getItems().addAll("Update Profile", "Delete account", "Logout");

        // Initialisation du ComboBox comme non affiché
        comboBoxImageUser.setVisible(false);

        // Ajout d'un événement de clic à l'image de profil pour afficher le ComboBox
        profileImageView.setOnMouseClicked(event -> {
            if (!comboBoxImageUser.isVisible()) {
                // Positionnez le ComboBox à côté de l'image de profil
                comboBoxImageUser.setLayoutX(1455 );
                comboBoxImageUser.setLayoutY(90);

                // Afficher le ComboBox
                comboBoxImageUser.setVisible(true);
            }
        });

        // Ajout d'un écouteur d'événements à la scène pour détecter les clics en dehors de l'image de profil
        profileImageView.sceneProperty().addListener((observable, oldScene, newScene) -> {
            if (newScene != null) {
                newScene.setOnMouseClicked(event -> {
                    // Vérifier si le clic n'est pas sur l'image de profil
                    if (!profileImageView.getBoundsInParent().contains(event.getX(), event.getY())) {
                        // Cacher le ComboBox s'il est visible
                        if (comboBoxImageUser.isVisible()) {
                            comboBoxImageUser.setVisible(false);
                        }
                    }
                });
            }
        });
// Appliquer un style CSS spécifique pour l'élément "Update Profile" dans le ComboBox
        comboBoxImageUser.setCellFactory(param -> new ListCell<String>() {
            @Override
            protected void updateItem(String item, boolean empty) {
                super.updateItem(item, empty);
                if (item != null && item.equals("Update Profile")) {
                    setTextFill(Color.GRAY); // Définir la couleur du texte sur gris pour "Update Profile"
                }
                setText(item);
            }
        });
        // Désactiver la sélection de l'option "Update Profile"
        comboBoxImageUser.valueProperty().addListener((observable, oldValue, newValue) -> {
            if (newValue != null && newValue.equals("Update Profile")) {
                comboBoxImageUser.getSelectionModel().clearSelection();
            }
        });

        // Écouter les changements de sélection dans le ComboBox
        comboBoxImageUser.setOnAction(event -> {
            String selectedOption = comboBoxImageUser.getValue();
            if (selectedOption != null) {
                switch (selectedOption) {
                    case "Update Profile":
                        // Ne rien faire car la sélection de "Update Profile" est désactivée
                        break;
                    case "Delete account":
                        deleteButtonOnClick();
                        break;
                    case "Logout":

                        // Déconnecter l'utilisateur et rediriger vers l'interface de connexion
                        FXMLLoader loginLoader = new FXMLLoader(getClass().getResource("/Login.fxml"));
                        Parent loginRoot;
                        try {
                            loginRoot = loginLoader.load();
                            // Spécifiez les dimensions souhaitées pour la scène Login
                            Scene loginScene = new Scene(loginRoot, 998, 649); // Ajustez les dimensions selon vos besoins
                            Stage loginStage = new Stage();
                            loginStage.setScene(loginScene);
                            loginStage.show();

                            // Fermez la scène actuelle de l'interface Home
                            Stage homeStage = (Stage) profileImageView.getScene().getWindow();
                            homeStage.close();
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        break;
                    default:
                        break;
                }
            }
        });


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
                boolean isUnique = isUsernameUnique(newValue,utilisateur.getIdUtilisateur()); // Assurez-vous de passer userId comme deuxième argument
                if (isUnique) {
                    // Mettre à jour le libellé pour indiquer que le nom d'utilisateur est unique
                    // Par exemple, en changeant la couleur du texte ou en affichant un message
                    usernameStatusLabel.setText("Nom d'utilisateur disponible");
                    usernameStatusLabel.setStyle("-fx-text-fill: green;");
                } else {
                    // Mettre à jour le libellé pour indiquer que le nom d'utilisateur n'est pas unique
                    usernameStatusLabel.setText("Nom d'utilisateur non disponible");
                    usernameStatusLabel.setStyle("-fx-text-fill: red;");
                }
            } else {
                // Effacer le libellé s'il n'y a pas de saisie dans le champ UsernameField
                usernameStatusLabel.setText("");
            }
        });
    }


    void deleteButtonOnClick() {
        try {
            ServiceUser serviceUser = new ServiceUser();
            Utilisateurs user = serviceUser.selectById(utilisateur.getIdUtilisateur()); // Récupérer l'utilisateur actuel
            serviceUser.deleteCompte(user); // Supprimer le compte de l'utilisateur actuel

            // Rediriger l'utilisateur vers l'interface de connexion (Login)
            FXMLLoader loginLoader = new FXMLLoader(getClass().getResource("/Login.fxml"));
            Parent loginRoot = loginLoader.load();
            Scene loginScene = new Scene(loginRoot);
            Stage loginStage = new Stage();
            loginStage.setScene(loginScene);
            loginStage.show();

            // Fermer l'interface Home
            Stage stage = (Stage) profileImageView.getScene().getWindow();
            stage.close();

        } catch (SQLException | IOException e) {
            e.printStackTrace();
            // Gérer l'exception
        }
    }




    public void setUserName(String userName) {
        this.NomPrenomLabel.setText(userName);
    }

    @FXML
    void OnUpdate(ActionEvent event) {

    }

    @FXML
    public void selectImage() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Sélectionner une image");

        // Filtrer les fichiers pour n'afficher que les images
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Images", "*.png", "*.jpg", "*.gif")
        );

        // Afficher la boîte de dialogue de sélection de fichier
        File selectedFile = fileChooser.showOpenDialog(null);

        // Vérifier si un fichier a été sélectionné
        if (selectedFile != null) {
            // Récupérer le chemin d'accès à l'image sélectionnée
            imagePath = selectedFile.toURI().toString();

            // Charger l'image dans l'ImageView
            Image image = new Image(imagePath);
            ImageViewUser.setImage(image);
        }
    }






    @FXML
    void submitButtonOnClick() {
        if (validateInputs()) {
            String newFirstname = FirstnameField.getText();
            String newLastname = LastnameField.getText();
            String newUsername = UsernameField.getText();
            String newSexe = (MaleButton.isSelected()) ? "Male" : "Female";
            String newEmail = EmailField.getText();
            int newPhoneNumber = Integer.parseInt(NumberPhoneField.getText());
            String newPassword = PasswordField.getText();
            String newconfirmPassword = ConfirmPasswordField.getText();

            try {
                ServiceUser serviceUser = new ServiceUser();

                // Vérifier l'unicité du nom d'utilisateur
               // boolean isUsernameUniqueUpdate = isUsernameUnique(newUsername, utilisateur.getIdUtilisateur());

                // Évaluation de la complexité du mot de passe
                evaluatePasswordComplexity(newPassword, passwordTooltip);

                if (passwordComplexity.equals("excellent")) {
                    // Nom d'utilisateur unique et mot de passe excellent, procéder à la mise à jour de l'utilisateur
                    Utilisateurs existingUser = serviceUser.selectById(utilisateur.getIdUtilisateur()); // Récupérer l'utilisateur existant
                    Utilisateurs updatedUser = new Utilisateurs(utilisateur.getIdUtilisateur(), newFirstname, newLastname, newUsername, newSexe, newEmail, newPhoneNumber, Role.CLIENT, newPassword, imagePath);
                    serviceUser.update(updatedUser); // Mettre à jour l'utilisateur dans la base de données

                    // Mettre à jour l'affichage dans l'interface utilisateur
                    FirstnameField.setText(newFirstname);
                    LastnameField.setText(newLastname);
                    UsernameField.setText(newUsername);
                    EmailField.setText(newEmail);
                    PasswordField.clear();
                    ConfirmPasswordField.clear();
                    NumberPhoneField.setText(String.valueOf(newPhoneNumber));
                    if (newSexe.equals("Male")) {
                        MaleButton.setSelected(true);
                    } else {
                        FemaleButton.setSelected(true);
                    }

                    // Afficher un message de succès dans le label
                    errorLabel.setText("Profil mis à jour avec succès !");
                    errorLabel.setTextFill(Color.GREEN); // Couleur verte pour indiquer le succès
                } /*else {
                    // Afficher un message d'erreur dans le label en fonction des erreurs détectées
                    if (!isUsernameUniqueUpdate) {
                        errorLabel.setText("Le nom d'utilisateur n'est pas disponible !");
                    } else {
                        errorLabel.setText("Le mot de passe doit être excellent pour s'enregistrer !");
                    }
                    errorLabel.setTextFill(Color.RED); // Couleur rouge pour indiquer l'erreur
                }*/
            } catch (SQLException e) {
                e.printStackTrace();
                // Afficher un message d'erreur dans le label
                errorLabel.setText("Erreur lors de la mise à jour du profil !");
                errorLabel.setTextFill(Color.RED); // Couleur rouge pour indiquer l'erreur
            }
        }
    }


    private boolean validateInputs() {
        // Valider tous les champs avant la mise à jour
        if (FirstnameField.getText().isEmpty() ||
                LastnameField.getText().isEmpty() ||
                UsernameField.getText().isEmpty() ||
                EmailField.getText().isEmpty() ||
                NumberPhoneField.getText().isEmpty() ||
                PasswordField.getText().isEmpty() ||
                ConfirmPasswordField.getText().isEmpty()) {
            errorLabel.setText("Please complete all fields.");
            return false;
        }

        // Vérifiez si le nom et le prénom ne contiennent que des lettres
        if (!estToutLettres(FirstnameField.getText())){
            errorLabel.setText("The firstname must only contain letters.");
            return false;
        }
        // Vérifiez si le nom et le prénom ne contiennent que des lettres
        if  (!estToutLettres(LastnameField.getText())){
            errorLabel.setText( "the lasrname must contain only letters.");
            return false;
        }



        // Valider l'adresse email
        String email = EmailField.getText();
        if (!isValidEmail(email)) {
            errorLabel.setText( "Please enter a valid email address.");
            return false;
        }



        // Valider la correspondance des mots de passe
        String password = PasswordField.getText();
        String confirmPassword = ConfirmPasswordField.getText();
        if (!password.equals(confirmPassword)) {
            showAlerte(Alert.AlertType.ERROR, "Non-identical passwords", "Passwords do not match.");
            return false;
        }

        return true;
    }

    private boolean estToutLettres(String str) {
        return str.matches("[a-zA-Z]+");
    }
    private boolean isUsernameUnique(String username, int idUtilisateur) {
        try {
            // Appeler la méthode isUsernameUniqueUpdate du service utilisateur
            return serviceUser.isUsernameUniqueUpdate(username, idUtilisateur);
        } catch (SQLException e) {
            // Gérer les exceptions, par exemple en affichant un message d'erreur
            showAlerte(Alert.AlertType.ERROR, "Erreur", "Une erreur s'est produite lors de la vérification de l'unicité du nom d'utilisateur.");
            e.printStackTrace(); // Ou logger l'exception
            return false; // Ou une autre logique appropriée dans votre cas
        }
    }



    private boolean isValidEmail(String email) {
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
        Pattern pattern = Pattern.compile(emailRegex);
        return pattern.matcher(email).matches();
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




    private void showAlerte(Alert.AlertType type, String titre, String message) {
        Alert alert = new Alert(type);
        alert.setTitle(titre);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    @FXML
    private void redirectToHome() {
        try {
            // Charger le fichier FXML de la page Home.fxml
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Home.fxml"));
            Parent root = loader.load();

            // Accès au contrôleur de la nouvelle fenêtre (Home)
            Home controller = loader.getController();

            // Appel de la méthode setUtilisateur() en lui passant l'objet utilisateur
            controller.setUserModel(utilisateur); // Utilisez l'objet utilisateur défini dans EventFront

            // Affichage de la fenêtre Home
            Scene scene = new Scene(root);
            Stage stage = (Stage) FirstnameField.getScene().getWindow();
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @FXML
    private void handleHomeBtnClick(MouseEvent event) {
        // Récupérer l'ID de l'utilisateur à partir du label idU ou de tout autre composant nécessaire

        // Appeler redirectToHome() avec l'ID de l'utilisateur
        redirectToHome();
    }


    @FXML
    private void redirectToEvents() {
        try {
            // Charger le fichier FXML de l'interface des événements
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/EventFront.fxml"));
            Parent root = loader.load();

            // Accéder au contrôleur de la nouvelle fenêtre
            EventFront controller = loader.getController();

            // Passer l'objet utilisateur directement au contrôleur de la page EventFront.fxml
            controller.setUserModel(utilisateur);

            // Afficher la fenêtre
            Scene scene = LastnameField.getScene();
            // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    @FXML
    private void handleEventBtnClick(MouseEvent event) {
        // Récupérer l'ID de l'utilisateur à partir du label idU ou de tout autre composant nécessaire

        // Appeler redirectToHome() avec l'ID de l'utilisateur
        redirectToEvents();
    }




}