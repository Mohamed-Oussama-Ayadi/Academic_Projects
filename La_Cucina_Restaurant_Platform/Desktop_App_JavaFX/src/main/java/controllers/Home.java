package controllers;

import javafx.animation.RotateTransition;
import javafx.application.Platform;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import javafx.util.Duration;

import javafx.scene.input.MouseEvent;
import models.Utilisateurs;
import services.ServiceUser;
import utils.DBConnection;

import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.Optional;
import java.util.ResourceBundle;


public class Home implements Initializable {

    @FXML
    private Label idU;
    @FXML
    private ImageView heroImageView;

    @FXML
    private ImageView profileImageView;

    @FXML
    private Label NomPrenomLabel;

    @FXML
    private Button Events;
    @FXML
    private Label Eventsbtn;

    private ChoiceBox<String> choiceBox;

    private boolean isChoiceBoxDisplayed = false;

    private int userId;
    private Utilisateurs utilisateur;

    // Méthode pour définir l'utilisateur
    public void setUtilisateur(Utilisateurs utilisateur) {
        this.utilisateur = utilisateur;
        NomPrenomLabel.setText(utilisateur.getNom()+" "+utilisateur.getPrenom());
        // Utilisez les détails de l'utilisateur pour personnaliser l'interface
    }
    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        rotateHeroImage();

        // Ajouter un événement de clic à l'image de profil
        profileImageView.setOnMouseClicked(event -> {
            if (isChoiceBoxDisplayed) {
                // Si le ChoiceBox est déjà affiché, le supprimer du conteneur parent
                ((Pane) profileImageView.getParent()).getChildren().remove(choiceBox);
                isChoiceBoxDisplayed = false;
            } else {
                showOptions(event);
            }
        });
// Ajouter un écouteur d'événements à la scène pour détecter les clics en dehors de l'image de profil
        profileImageView.sceneProperty().addListener((observable, oldScene, newScene) -> {
            if (newScene != null) {
                newScene.setOnMouseClicked(event -> {
                    if (isChoiceBoxDisplayed && !profileImageView.getBoundsInParent().contains(event.getX(), event.getY())) {
                        // Si le ChoiceBox est affiché et que le clic n'est pas dans la zone de l'image de profil, le supprimer
                        ((Pane) profileImageView.getParent()).getChildren().remove(choiceBox);
                        isChoiceBoxDisplayed = false;
                    }
                });
            }
        });


    }

    // Méthode pour afficher les options lorsque l'utilisateur clique sur l'image de profil
    @FXML
    private void showOptions(MouseEvent event) {
        // Créer un ChoiceBox avec des options
        choiceBox = new ChoiceBox<>();
        choiceBox.getItems().addAll("Update Profile","Change Password","Logout","Delete");


        // Obtenir la source de l'événement (dans votre cas, l'ImageView)
        ImageView imageView = (ImageView) event.getSource();

        // Après avoir ajouté le ComboBox à la scène

        choiceBox.setPrefWidth(42);
        choiceBox.setPrefHeight(26);

        // Convertir les coordonnées locales de l'image en coordonnées de la scène
        double sceneX = imageView.localToScene(event.getX(), event.getY()).getX();
        double sceneY = imageView.localToScene(event.getX(), event.getY()).getY();

        // Positionner le ChoiceBox à côté de l'image de profil
        choiceBox.setLayoutX(sceneX);
        choiceBox.setLayoutY(sceneY);

        // Ajouter un événement de sélection à choix
        choiceBox.setOnAction(e -> {
            String selectedOption = choiceBox.getValue();
            // Vérifier l'option sélectionnée et rediriger l'utilisateur en conséquence
            if (selectedOption != null) {
                switch (selectedOption) {
                    case "Update Profile":
                     //   showUpdateUserFront();
                        if (utilisateur != null) {
                            showUpdateUserFront(utilisateur);
                            System.out.println("envoieupdate");
                        } else {
                            System.out.println("Erreur : L'utilisateur est null. Impossible d'ouvrir la page de mise à jour du profil.");
                        }
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

                    case "Delete":
                        deleteButtonOnClick();

                        break;

                    case "Change Password":
                        changePassword();

                        break;

                    default:
                        break;
                }
            }
        });

        // Ajouter le ChoiceBox à la scène
        ((Pane) imageView.getParent()).getChildren().add(choiceBox);
        isChoiceBoxDisplayed = true;
    }

    @FXML
    private void rotateHeroImage() {
        RotateTransition rotateTransition = new RotateTransition(Duration.seconds(30), heroImageView);
        rotateTransition.setByAngle(360);
        rotateTransition.setCycleCount(20);
        rotateTransition.play();
    }
    @FXML
    public void loadUserProfileImage(String surnom, String motDePasse) {
        // Établir une connexion à la base de données
        Connection connection = DBConnection.getInstance().getCnx();

        // Requête pour récupérer l'URL de l'image de profil de l'utilisateur
        String query = "SELECT image_user FROM utilisateurs WHERE surnom = ? AND motDePasse = ?";

        try (PreparedStatement statement = connection.prepareStatement(query)) {
            // Remplacer les paramètres de la requête par les valeurs du surnom et du mot de passe de l'utilisateur
            statement.setString(1, surnom);
            statement.setString(2, motDePasse);

            // Exécuter la requête
            ResultSet resultSet = statement.executeQuery();

            // Vérifier si des données ont été retournées
            if (resultSet.next()) {
                // Récupérer l'URL de l'image de profil de l'utilisateur
                String imageUrl = resultSet.getString("image_user");

                // Charger l'image dans profileImageView
                Image image = new Image(imageUrl);
                profileImageView.setImage(image);
            } else {
                // Gérer le cas où aucun utilisateur correspondant n'est trouvé
                System.out.println("Aucun utilisateur trouvé avec ce surnom et ce mot de passe.");
            }
        } catch (SQLException e) {
            // Gérer les exceptions SQL
            e.printStackTrace();
        }
    }


  /*  public void loadNomPrenom(String username, String password) {
        // Établir une connexion à la base de données
        Connection connection = DBConnection.getInstance().getCnx();

        // Requête pour récupérer le nom et le prénom de l'utilisateur
        String query = "SELECT nom, prenom FROM utilisateurs WHERE surnom = ? AND motDePasse = ?";

        try (PreparedStatement statement = connection.prepareStatement(query)) {
            // Remplacer les paramètres de la requête par les valeurs du surnom et du mot de passe de l'utilisateur
            statement.setString(1, username);
            statement.setString(2, password);

            // Exécuter la requête
            ResultSet resultSet = statement.executeQuery();

            // Vérifier si des données ont été retournées
            if (resultSet.next()) {
                // Récupérer le nom et le prénom de l'utilisateur depuis la base de données
                String nom = resultSet.getString("nom");
                String prenom = resultSet.getString("prenom");

                // Définir le nom et le prénom dans le label NomPrenomLabel
                NomPrenomLabel.setText(nom + " " + prenom);
            } else {
                // Gérer le cas où aucun utilisateur correspondant n'est trouvé
                System.out.println("Aucun utilisateur trouvé avec ce surnom et ce mot de passe.");
            }
        } catch (SQLException e) {
            // Gérer les exceptions SQL
            e.printStackTrace();
        }
    }*/



public void setId(int idUtilisateur) {
    idU.setText(Integer.toString(idUtilisateur));

    try {
        ServiceUser serviceUser = new ServiceUser();
        Utilisateurs utilisateurs = serviceUser.selectById(idUtilisateur); // Utilisez directement l'ID passé en paramètre
        if (utilisateurs != null) {
            setUserName(utilisateurs.getNom() + " " + utilisateurs.getPrenom());

        }
    } catch (SQLException e) {
        e.printStackTrace();
    }
}


    public void setUserName(String userName) {
        this.NomPrenomLabel.setText(userName);
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
            Stage homeStage = (Stage) profileImageView.getScene().getWindow();
            homeStage.close();

        } catch (SQLException | IOException e) {
            e.printStackTrace();
            // Gérer l'exception
        }
    }


 @FXML
 private void showUpdateUserFront(Utilisateurs utilisateur) {
     try {
         FXMLLoader loader = new FXMLLoader(getClass().getResource("/UpdateUserFront.fxml"));
         Parent parent = loader.load();

         // Accéder au contrôleur de la nouvelle fenêtre
         UpdateUserFront controller = loader.getController();
         controller.initData(utilisateur); // Passer l'utilisateur au contrôleur de la page UpdateUserFront.fxml

         // Créer une nouvelle scène
         Scene scene = new Scene(parent);

         // Obtenir la scène à partir de n'importe quel nœud
         Stage stage = (Stage) profileImageView.getScene().getWindow();

         // Configurer la nouvelle scène
         stage.setScene(scene);
         stage.setTitle("Update User Profile"); // Définir le titre de la fenêtre
         stage.show(); // Afficher la nouvelle fenêtre

     } catch (IOException ex) {
         ex.printStackTrace();
     }
 }

    @FXML
    private void changePassword() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/UpdateUserFront.fxml"));
            Parent parent = loader.load();

            // Accéder au contrôleur de la nouvelle fenêtre
            UpdateUserFront controller = loader.getController();
            controller.initData(utilisateur); // Passer l'utilisateur au contrôleur de la page UpdateUserFront.fxml

            // Créer une nouvelle scène
            Scene scene = new Scene(parent);

            // Obtenir la scène à partir de n'importe quel nœud
            Stage stage = (Stage) profileImageView.getScene().getWindow();

            // Configurer la nouvelle scène
            stage.setScene(scene);
            stage.setTitle("Update User Profile"); // Définir le titre de la fenêtre
            stage.show(); // Afficher la nouvelle fenêtre

        } catch (IOException ex) {
            ex.printStackTrace();
        }
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
            Scene scene = profileImageView.getScene();
            // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public void setUserModel(Utilisateurs utilisateur) throws SQLException {
        this.utilisateur = utilisateur;

        // Utilisez l'utilisateur chargé pour initialiser votre interface utilisateur
        if (utilisateur != null) {
            System.out.println("trouve");
            NomPrenomLabel.setText(utilisateur.getNom()+" "+utilisateur.getPrenom());
        } else {
            System.out.println("Utilisateur non trouvé avec l'ID : " + userId);
        }
    }

    public void goTorec(MouseEvent mouseEvent) {
        try {
            // Charger le fichier FXML de votre nouvelle interface
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/AjouterReclamation.fxml"));
            Parent root = loader.load();

            AjouterReclamation eventController = loader.getController();
            eventController.setId1(utilisateur);
            Scene scene = profileImageView.getScene();
            scene.setRoot(root);
        } catch (Exception e) {
            // e.printStackTrace();
            // Gérer toute exception lors du chargement de la nouvelle interface
        }

    }

    public void goTodon(MouseEvent mouseEvent) {
        try {
            // Charger le fichier FXML de votre nouvelle interface
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/donationFront.fxml"));
            Parent root = loader.load();

            donationfront eventController = loader.getController();
            eventController.setId1(utilisateur);
            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (Exception e) {
            // e.printStackTrace();
            // Gérer toute exception lors du chargement de la nouvelle interface
        }

    }


    @FXML
    void redirectToMenu(MouseEvent event) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/MenuFront.fxml"));
            Parent root = loader.load();

            MenuFront controller = loader.getController();

            controller.setUserModel(utilisateur);

            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    public void sentToRese(ActionEvent event) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/ReservationFront.fxml"));
            Parent root = loader.load();

            ReservationFront controller = loader.getController();

            controller.setUserModel(utilisateur);

            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}

