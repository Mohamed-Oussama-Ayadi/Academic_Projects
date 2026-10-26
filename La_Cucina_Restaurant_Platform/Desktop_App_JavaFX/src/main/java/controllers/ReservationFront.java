package controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;
import javafx.util.Callback;
import models.Reservations;
import models.Tables;
import models.Utilisateurs;
import services.ServiceReservations;
import services.ServiceTables;
import services.ServiceUser;
import test.GMailer;
import test.GMailer2;

import java.io.IOException;
import java.sql.Date;
import java.sql.SQLException;
import java.time.LocalDate;
import java.time.LocalTime;
import java.time.format.DateTimeFormatter;
import java.util.List;


public class ReservationFront {

    @FXML
    private ImageView profileImageView;
    @FXML
    private Label NomPrenomLabel;
    private Pagination pagination;;

    private GMailer mailer;
    @FXML
    private Button Confirm;
    @FXML
    private Button ReservationButton;
    @FXML
    private ComboBox<String> HoraireBox;

    @FXML
    private DatePicker datePicker;

    @FXML
    private TextField nbrPersonnesTextField;

    @FXML
    private ListView<Tables> listView;
    @FXML
    private FlowPane flowPane;
    private boolean isChoiceBoxDisplayed = false;
    private ChoiceBox<String> choiceBox;
    private ServiceTables service = new ServiceTables();
    public void initialize() {
        listView.setCellFactory(new Callback<ListView<Tables>, ListCell<Tables>>() {
            @Override
            public ListCell<Tables> call(ListView<Tables> listView) {
                return new ListCell<Tables>() {
                    @Override
                    protected void updateItem(Tables table, boolean empty) {
                        super.updateItem(table, empty);
                        if (empty || table == null) {
                            setGraphic(null);
                        } else {
                            setGraphic(createTableCard(table));
                        }
                    }
                };
            }
        });
        try {
            mailer = new GMailer();
        } catch (Exception e) {
            e.printStackTrace();
        }
        populateHoraireBox();
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
    private void populateHoraireBox() {
        HoraireBox.getItems().clear();
        for (int i = 0; i < 24; i++) {
            String timeSlot = LocalTime.of(i, 0).format(DateTimeFormatter.ofPattern("HH:mm"));
            HoraireBox.getItems().add(timeSlot);
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
           // refreshData();
        } else {
            System.out.println("Utilisateur non trouvé avec l'ID : " + userId);
        }
    }
  /*  public void setId1(Utilisateurs utilisateur) throws SQLException {
        System.out.println("test");
        this.utilisateur = utilisateur;
        try {
            //initializeData();
            try {
                List<Integer> commandeIDs = getCommandeIDsFromDatabase();

                // Ajout des ID des commandes au ChoiceBox
                tfchoice.getItems().addAll(commandeIDs);
            } catch (SQLException e) {
                e.printStackTrace();
                // Gérer les erreurs de connexion à la base de données
            }} catch (Exception e) {
            throw new RuntimeException(e);
        }
    }*/

    private void sendConfirmationEmail(Tables table, String horaire, LocalDate date) throws Exception {
        String subject = "Reservation Confirmation";
        String message = "Your reservation for table " + table.getNumeroTable() + " on " + date.toString() + " at " + horaire + " has been confirmed.";

        GMailer2 mailer = new GMailer2();
        mailer.sendMail(subject, message);
    }



    public void ReservationButtonOn() {
        Tables selectedItem = listView.getSelectionModel().getSelectedItem();
        if (selectedItem != null) {
            String selectedHoraire = HoraireBox.getValue();
            LocalDate selectedDate = datePicker.getValue();
            int iduser = utilisateur.getIdUtilisateur();
            if (selectedHoraire != null && selectedDate != null) {
                // Check if the selected date is in the past
                if (selectedDate.isBefore(LocalDate.now())) {
                    showAlert("Error", "La date sélectionnée est dans le passé.");
                    return;
                }

                try {
                    ServiceReservations serviceReservations = new ServiceReservations();
                    serviceReservations.insert(new Reservations(Integer.parseInt(nbrPersonnesTextField.getText()),HoraireBox.getValue(), Date.valueOf(datePicker.getValue()),selectedItem.getNumeroTable(),iduser));
                    showAlert("Reservation Successful", "Your reservation has been successfully made.");
                    listView.getSelectionModel().clearSelection();
                    service.updateAvailability(selectedItem.getNumeroTable(), false);
                    sendConfirmationEmail(selectedItem, selectedHoraire, selectedDate);
                } catch (SQLException e) {
                    showAlert("Error", "An error occurred while making the reservation.");
                    e.printStackTrace();
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            } else {
                showAlert("Error", "Please select a date and time before booking.");
            }
        } else {
            showAlert("Error", "Please select a table to make a reservation.");
        }
    }





    private TableView<Tables> createTableView(List<Tables> tablesList) {
        TableView<Tables> tableView = new TableView<>();
        TableColumn<Tables, Integer> numeroColumn = new TableColumn<>("Numero");
        numeroColumn.setCellValueFactory(new PropertyValueFactory<>("numeroTable"));

        // Ajoutez d'autres colonnes ici si nécessaire

        tableView.getColumns().add(numeroColumn);
        tableView.setItems(FXCollections.observableArrayList(tablesList));
        return tableView;
    }

     public void OnConfirm(ActionEvent actionEvent) {

        if (horaireBoxIsValid() && datePickerIsValid() && nbrPersonnesTextFieldIsValid() && !datePickerIsValid2()) {
            try {
                int capacity = Integer.parseInt(nbrPersonnesTextField.getText());
                ObservableList<Tables> availableTables = FXCollections.observableArrayList(service.getTablesByCapacityAndAvailability(capacity, true));
                listView.getItems().clear();
                for (Tables table : availableTables) {
                    listView.getItems().add(table);
                }
            } catch (SQLException e) {
                showAlert("No Tables", "Sorry, we don't have tables available at the moment.");
            }
        }
        else
        {
            showAlert("Error", "Veuillez remplir tous les champs.");

        }
    }
   /* public void OnConfirm(ActionEvent actionEvent) {
        if (horaireBoxIsValid() && datePickerIsValid() && nbrPersonnesTextFieldIsValid()) {
            try {
                int capacity = Integer.parseInt(nbrPersonnesTextField.getText());
                List<Tables> availableTables = service.getTablesByCapacityAndAvailability(capacity, true);

                // Clear the previous content in the parent container
                flowPane.getChildren().clear();

                // Create cards for each available table and add them to the FlowPane
                for (Tables table : availableTables) {
                    AnchorPane card = createTableCard(table);
                    flowPane.getChildren().add(card);
                }

                // Make the ReservationButton visible
                ReservationButton.setVisible(true);
            } catch (SQLException e) {
                showAlert("No Tables", "Sorry, we don't have tables available at the moment.");
            }
        } else {
            showAlert("Error", "Veuillez remplir tous les champs.");
        }
    }*/private AnchorPane createTableCard(Tables table) {
       AnchorPane card = new AnchorPane();
       card.setStyle("-fx-background-color: orange; -fx-padding: 10px; -fx-border-color: #cccccc; -fx-border-width: 1px;");

       Label tableNumberLabel = new Label("Table Number: " + table.getNumeroTable());
       Label capacityLabel = new Label("Capacity: " + table.getCapacite());

       VBox content = new VBox(5);
       content.getChildren().addAll(tableNumberLabel, capacityLabel);

       AnchorPane.setLeftAnchor(content, 10.0);
       AnchorPane.setTopAnchor(content, 10.0);

       card.getChildren().add(content);

       return card;
   }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }

    private boolean horaireBoxIsValid() {
        return HoraireBox.getValue() != null && !HoraireBox.getValue().isEmpty();
    }

    private boolean datePickerIsValid() {
        return datePicker.getValue() != null;
    }
        private boolean datePickerIsValid2() {
            LocalDate selectedDate = datePicker.getValue();
            if (selectedDate.isBefore(LocalDate.now())) {
                showAlert("Error", "La date sélectionnée est dans le passé.");
                return true;
            }
            else {
                return false;
            }
        }

    private boolean nbrPersonnesTextFieldIsValid() {
        String nbrPersonnesText = nbrPersonnesTextField.getText();
        return nbrPersonnesText != null && !nbrPersonnesText.isEmpty() && nbrPersonnesText.matches("\\d+");
    }

    public void OnLocation(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/add_map.fxml"));
        Parent parent = loader.load();
        Stage stage = new Stage();
        Scene scene = new Scene(parent);
        stage.setTitle("Back Table");
        stage.setScene(scene);
        stage.show();
    }



}
