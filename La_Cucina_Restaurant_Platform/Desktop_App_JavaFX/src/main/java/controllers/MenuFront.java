package controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ChoiceBox;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.Pane;
import javafx.stage.Stage;
import models.Categorie;
import models.Produit;
import models.Utilisateurs;
import services.ServiceProduit;
import services.ServiceUser;
import test.FxMain;

import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import java.util.stream.Collectors;

public class MenuFront {
    @FXML
    private Label reclamBtn;
    @FXML
    private Label idU;
    private boolean isChoiceBoxDisplayed = false;
    private ChoiceBox<String> choiceBox;
    @FXML
    private ComboBox<?> comboBoxImageUser;

    @FXML
    private Label HomeBtn;

    @FXML
    private Label Eventsbtn;

    @FXML
    private ImageView profileImageView;

    @FXML
    private Label NomPrenomLabel;

    @FXML
    private GridPane grid;
    @FXML
    private TextField tfrecherche;

    @FXML
    private ComboBox<String> cbtri;
    private ServiceProduit serviceProduit = new ServiceProduit();

    private FilteredList<Produit> filteredList;
    private ObservableList<Produit> data;

    @FXML
    public void initialize() {

        cbtri.getItems().setAll("Nom", "Prix", "Note");
        rechercheAvance();


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
        choiceBox.getItems().addAll("Update Profile", "Logout", "Delete");


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


                    default:
                        break;
                }
            }
        });

        // Ajouter le ChoiceBox à la scène
        ((Pane) imageView.getParent()).getChildren().add(choiceBox);
        isChoiceBoxDisplayed = true;
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
    private Utilisateurs utilisateur; // Objet utilisateur
    private int userId; // Champ pour stocker l'ID de l'utilisateur
    public void setUserModel(Utilisateurs utilisateur) throws SQLException {
        this.utilisateur = utilisateur;

        // Utilisez l'utilisateur chargé pour initialiser votre interface utilisateur
        if (utilisateur != null) {
            System.out.println("trouve");
            NomPrenomLabel.setText(utilisateur.getNom()+" "+utilisateur.getPrenom());
            refreshData();
        } else {
            System.out.println("Utilisateur non trouvé avec l'ID : " + userId);
        }
    }
    public void refreshData() {
        if (utilisateur != null) {
            try {
                data = FXCollections.observableArrayList(serviceProduit.selectAll());
                filteredList = new FilteredList<>(data, p -> true);
                refresh(filteredList);
            } catch (SQLException e) {
                throw new RuntimeException(e);
            }
        }
    }


    private void refresh(List<Produit> list) {
        grid.getChildren().clear();
        int column = 0;
        int row = 1;
        for (Produit p : list) {
            FXMLLoader card = new FXMLLoader(FxMain.class.getResource("/produit-card-view.fxml"));
            AnchorPane anchorPane;
            try {
                anchorPane = card.load();
                ProduitCardView controller = card.getController();
                controller.remplireData(p);
                controller.setUtilisateur(utilisateur);

                if (column == 2) {
                    column = 0;
                    row++;
                }
                grid.add(anchorPane, column++, row);
                GridPane.setMargin(anchorPane, new Insets(10));
            } catch (IOException ex) {
                System.out.println(ex.getMessage());
            }
        }
    }

    private void rechercheAvance() {
        tfrecherche.textProperty().addListener((observable, oldValue, newValue) -> {
            filteredList.setPredicate(produit -> {
                if (newValue == null || newValue.isEmpty()) {
                    return true;
                }
                String lowerCaseFilter = newValue.toLowerCase();
                if (produit.getNom().toLowerCase().contains(lowerCaseFilter)) {
                    return true;
                } else if (produit.getDescription().toLowerCase().contains(lowerCaseFilter)) {
                    return true;
                }
                return false; // Modify this as per your need
            });
            refresh(filteredList);
        });
    }

    @FXML
    void tri(ActionEvent event) {
        String critere = cbtri.getValue();
        List<Produit> sortedList = filteredList.stream()
                .sorted((p1, p2) -> {
                    switch (critere) {
                        case "Nom":
                            return p1.getNom().compareToIgnoreCase(p2.getNom());
                        case "Prix":
                            return Double.compare(p1.getPrix(), p2.getPrix());
                        case "Note":
                            return Integer.compare(p1.getNote(), p2.getNote());
                        default:
                            return 0;
                    }
                }).collect(Collectors.toList());
        refresh(sortedList);
    }

    private void afficherParCategorie(Categorie categorie) {
        List<Produit> produitsParCategorie = null;
        try {
            produitsParCategorie = serviceProduit.getListProduitParCategorie(categorie);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        refresh(produitsParCategorie);
        filteredList = new FilteredList<>(FXCollections.observableArrayList(produitsParCategorie), p -> true);
    }

    @FXML
    void asianfood(MouseEvent event) {
        afficherParCategorie(Categorie.ASIANFOOD);

    }

    @FXML
    void burger(MouseEvent event) {
        afficherParCategorie(Categorie.BURGER);

    }

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
            Stage stage = (Stage) HomeBtn.getScene().getWindow();
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
    void pasta(MouseEvent event) {
        afficherParCategorie(Categorie.PASTA);

    }

    @FXML
    void pizza(MouseEvent event) {
        afficherParCategorie(Categorie.PIZZA);

    }

    @FXML
    void salade(MouseEvent event) {
        afficherParCategorie(Categorie.SALAD);

    }


    @FXML
    void redirectToreclam(MouseEvent event) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/AjouterReclamation.fxml"));
            Parent root = loader.load();

            AjouterReclamation controller = loader.getController();

            controller.setId1(utilisateur);

            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    @FXML
    void redirectToDon(MouseEvent event) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/donationfront.fxml"));
            Parent root = loader.load();

            donationfront controller = loader.getController();

            controller.setId1(utilisateur);

            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
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


}
