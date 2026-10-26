package controllers;

import java.awt.*;
import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.List;
import java.util.ResourceBundle;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Evenements;
import models.Utilisateurs;
import services.ServiceEvenements;
import services.ServiceUser;
import services.ServiceUserEvent;

import java.time.LocalDate;
import java.sql.Date;
import java.sql.Time;


import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.common.PDRectangle;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.font.PDType1Font;

public class EventAdmin {
    @FXML
    private TextField searchField;

    @FXML
    private Button pdfbtn;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button CancelButton;


    @FXML
    private DatePicker DateEventPicker;

    @FXML
    private Button DeleteButton;


    @FXML
    private ImageView ImageViewAdmin;

    @FXML
    private Button InsertButton;

    @FXML
    private Button LogoutBtn;

    @FXML
    private TableView<Evenements> TableViewEvent;

    @FXML
    private Button UpdateButton;

    @FXML
    private Button HomeBtn;

    @FXML
    private Button UserManagementBtn;
    @FXML
    private Button EventManagementBtn;


    @FXML
    private TextField descriptionField;

    @FXML
    private Spinner<Integer> heureEventField;

    @FXML
    private TextField nameEventField;

    @FXML
    private HBox root;

    @FXML
    private TableColumn<Evenements, String> NameEventColumn;

    @FXML
    private TableColumn<Evenements, Date> DateEventColumn;
    @FXML
    private TableColumn<Evenements, Time> HeureEventColumn;

    @FXML
    private TableColumn<Evenements, String> DescriptionColumn;

    @FXML
    private AnchorPane side_ankerpane;
    private Evenements selectedEvent;
    private ServiceEvenements eventService = new ServiceEvenements();




    // Initialisation du service utilisateur
    private ServiceEvenements serviceEvenement = new ServiceEvenements();
    private int userId;


    @FXML
    void initialize() {

        SpinnerValueFactory<Integer> valueFactory = new SpinnerValueFactory.IntegerSpinnerValueFactory(0, 23, 0);
        heureEventField.setValueFactory(valueFactory);

        CancelButton.setDisable(true);
        UpdateButton.setDisable(true);
        DeleteButton.setDisable(true);

        NameEventColumn.setCellValueFactory(cell -> new SimpleStringProperty(cell.getValue().getNom_event()));
        DateEventColumn.setCellValueFactory(new PropertyValueFactory<>("date_event"));
        HeureEventColumn.setCellValueFactory(new PropertyValueFactory<>("heure_event"));

        DescriptionColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getDescription_event()));

        TableViewEvent.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        TableViewEvent.getSelectionModel().selectedItemProperty().addListener((obs, oldSelection, newSelection) -> {
            if (newSelection != null) {
                this.selectedEvent = newSelection;
                CancelButton.setDisable(false);
                UpdateButton.setDisable(false);
                DeleteButton.setDisable(false);
                InsertButton.setDisable(true);

                nameEventField.setText(selectedEvent.getNom_event());
                DateEventPicker.setValue(selectedEvent.getDate_event().toLocalDate());
                heureEventField.getValueFactory().setValue(selectedEvent.getHeure_event().toLocalTime().getHour());
                descriptionField.setText(selectedEvent.getDescription_event());
            }
        });

        try {
            getListEvent();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

//////////////////////////////////////*Recherche Event *///////////////////////////////////////
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            try {
                // Vérifier si le champ de recherche est vide
                if (newValue.isEmpty()) {
                    // Si le champ est vide, afficher tous les événements dans le TableView
                    getListEvent();
                } else {
                    // Sinon, filtrer la liste des événements en fonction du nom et de la date de l'événement saisis
                    ObservableList<Evenements> filteredList = FXCollections.observableArrayList();
                    for (Evenements evenement : TableViewEvent.getItems()) {
                        if (evenement.getNom_event().toLowerCase().contains(newValue.toLowerCase()) ||
                                evenement.getDate_event().toString().toLowerCase().contains(newValue.toLowerCase())) {
                            filteredList.add(evenement);
                        }
                    }
                    // Mettre à jour le TableView avec la liste filtrée
                    TableViewEvent.setItems(filteredList);
                }
            } catch (SQLException e) {
                e.printStackTrace();
            }
        });

    }




    public void getListEvent() throws SQLException {
        List<Evenements> listEvent = serviceEvenement.selectAll();
        ObservableList<Evenements> observableList = FXCollections.observableList(listEvent);
        System.out.println(observableList);
        TableViewEvent.setItems(observableList);
    }

    @FXML
    void insertEvent(ActionEvent event) {
        LocalDate currentDate = LocalDate.now();
        LocalDate selectedDate = DateEventPicker.getValue();

        if (selectedDate.isBefore(currentDate)) {
            showAlert(Alert.AlertType.ERROR, "Erreur", "Invalid date", "The event date must be later than the current date.");
            return;
        }

        String nameEvent = nameEventField.getText();
        String description = descriptionField.getText();

        if (nameEvent.isEmpty() || description.isEmpty()) {
            showAlert(Alert.AlertType.ERROR, "Erreur", "Mandatory fields not filled in", "Please fill in all mandatory fields.");
            return;
        }

        Date dateEvent = Date.valueOf(selectedDate);
        int heureSelectionnee = heureEventField.getValue();
        Time heureEvent = new Time(heureSelectionnee, 0, 0);

        // Vérification de l'existence d'un événement avec la même date et la même heure
        try {
            Evenements existingEvent = serviceEvenement.selectEventByDateTime(dateEvent, heureEvent);
            if (existingEvent != null) {
                showAlert(Alert.AlertType.ERROR, "Erreur", "Already existing event", "An event with the same date and time already exists.");
                return;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(Alert.AlertType.ERROR, "Erreur", "Validation error", "An error occurred while validating the event: " + e.getMessage());
            return;
        }

        Evenements newEvent = new Evenements(nameEvent, dateEvent, heureEvent, description);

        try {
            serviceEvenement.insertOne1(newEvent);
            showAlert(Alert.AlertType.INFORMATION, "Succès", "Insertion successful", "The event was successfully inserted into the database.");
            clearFields();
            getListEvent();
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(Alert.AlertType.ERROR, "Erreur", "Insert error", "An error occurred while inserting the event into the database: " + e.getMessage());
        }
    }


    @FXML
    public void  handleUserManagementBtn() {
        try {
            URL url = getClass().getResource("/UserAdmin.fxml");
            if (url != null) {
                // Charger le fichier FXML de l'interface de mise à jour du profil
                FXMLLoader loader = new FXMLLoader(url);
                Parent root = loader.load();


                // Afficher la fenêtre
                Scene scene = EventManagementBtn.getScene();
                // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
                scene.setRoot(root);

            } else {
                System.out.println("Le chemin d'accès au fichier FXML est incorrect ou le fichier est introuvable.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }



    // Méthode pour effacer les champs de saisie
    private void clearFields() {
        nameEventField.clear();
        DateEventPicker.setValue(null);
        heureEventField.getValueFactory().setValue(0);
        descriptionField.clear();

    }


    // Méthode pour afficher une alerte
    private void showAlert(Alert.AlertType alertType, String title, String headerText, String contentText) {
        Alert alert = new Alert(alertType);
        alert.setTitle(title);
        alert.setHeaderText(headerText);
        alert.setContentText(contentText);
        alert.showAndWait();
    }


    public void OnCancel(ActionEvent actionEvent) {
        reset();
    }

    void reset() {
        this.selectedEvent = null;
        clearFields();
        CancelButton.setDisable(true);
        UpdateButton.setDisable(true);
        DeleteButton.setDisable(true);
        InsertButton.setDisable(false);
    }

    @FXML
    public void OnDelete(ActionEvent actionEvent) throws SQLException {
        if (this.selectedEvent != null) {
            // Supprimer l'événement de la table userevent
            ServiceUserEvent serviceUserEvent = new ServiceUserEvent();
            serviceUserEvent.deleteUserEvent(this.selectedEvent.getId_event());

            // Supprimer l'événement de la table evenements
            serviceEvenement.delete(this.selectedEvent);

            // Réinitialiser les champs et rafraîchir la liste des événements
            reset();
            getListEvent();
        }
    }





    @FXML
    public void OnUpdate(ActionEvent actionEvent) {
        LocalDate currentDate = LocalDate.now();
        LocalDate selectedDate = DateEventPicker.getValue();

        if (selectedDate.isBefore(currentDate)) {
            showAlert(Alert.AlertType.ERROR, "Erreur", "Invalid date", "The event date must be later than the current date.");
            return;
        }

        String nameEvent = nameEventField.getText();
        String description = descriptionField.getText();

        if (nameEvent.isEmpty() || description.isEmpty()) {
            showAlert(Alert.AlertType.ERROR, "Erreur", "Mandatory fields not filled in", "Please fill in all mandatory fields.");
            return;
        }

        Date dateEvent = Date.valueOf(selectedDate);
        int heureSelectionnee = heureEventField.getValue();
        Time heureEvent = new Time(heureSelectionnee, 0, 0);

        Evenements newEvent = new Evenements(nameEvent, dateEvent, heureEvent, description);

        // Vérifier si un autre événement existe à la même date et à la même heure
        try {
            Evenements existingEvent = serviceEvenement.selectEventByDateTime(dateEvent, heureEvent);
            if (existingEvent != null && existingEvent.getId_event() != selectedEvent.getId_event()) {
                showAlert(Alert.AlertType.ERROR, "Erreur", "Schedule conflict", "Another event already exists on the same date and time.");
                return;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(Alert.AlertType.ERROR, "Erreur", "Validation error", "An error occurred while validating the event: " + e.getMessage());
            return;
        }

        // Mise à jour de l'événement
        if (this.selectedEvent != null) {
            newEvent.setId_event(this.selectedEvent.getId_event());
        } else {
            System.err.println("Erreur : this.selectedEvent est null.");
            return;
        }

        try {
            serviceEvenement.update(newEvent);
            showAlert(Alert.AlertType.INFORMATION, "Succès", "Update successful", "The event was successfully modified in the database.");
            clearFields();
            getListEvent();
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(Alert.AlertType.ERROR, "Erreur", "Edit error", "An error occurred while modifying the event in the database: " + e.getMessage());
        }
    }



    @FXML
    public void OnLogoutBtn(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/Login.fxml"));
        Parent root = loader.load();
        Stage stage = (Stage) CancelButton.getScene().getWindow();
        stage.setScene(new Scene(root));
        stage.show();
    }





    public void handleHomeBtn() {
        try {
            URL url = getClass().getResource("/Dashboard.fxml");
            if (url != null) {
                // Charger le fichier FXML de l'interface de mise à jour du profil
                FXMLLoader loader = new FXMLLoader(url);
                Parent root = loader.load();

                // Afficher la fenêtre
                Scene scene = UpdateButton.getScene();
                // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
                scene.setRoot(root);

            } else {
                System.out.println("Le chemin d'accès au fichier FXML est incorrect ou le fichier est introuvable.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }



    public void generateEventsPDF(List<Evenements> listeEvenements) {
        // Créez une boîte de dialogue pour choisir l'emplacement de sauvegarde du PDF
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Enregistrer le PDF");
        fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Fichiers PDF", "*.pdf"));

        // Affichez la boîte de dialogue et attendez que l'utilisateur sélectionne un emplacement
        File selectedFile = fileChooser.showSaveDialog(new Stage());

        // Vérifiez si un fichier a été sélectionné
        if (selectedFile != null) {
            // Utilisez le chemin sélectionné par l'utilisateur pour enregistrer le PDF
            String dest = selectedFile.getAbsolutePath();
            try {
                // Créez un nouveau document PDF
                PDDocument document = new PDDocument();
                PDPage page = new PDPage(PDRectangle.A4);
                document.addPage(page);
                PDPageContentStream contentStream = new PDPageContentStream(document, page);

                // Définissez les propriétés de style
                float margin = 50;
                float yStart = page.getMediaBox().getHeight() - margin;
                float tableWidth = page.getMediaBox().getWidth() - 2 * margin;
                float yPosition = yStart;
                float rowHeight = 20;
                float tableRowHeight = 15;

                // Ajoutez le titre du document
                contentStream.beginText();
                contentStream.setFont(PDType1Font.HELVETICA_BOLD, 16);
                contentStream.setNonStrokingColor(Color.BLACK);
                contentStream.newLineAtOffset(margin, yPosition);
                contentStream.showText("Liste des événements");
                contentStream.endText();
                yPosition -= 20;

                // Dessinez les lignes du tableau
                contentStream.moveTo(margin, yPosition);
                contentStream.lineTo(margin + tableWidth, yPosition);
                contentStream.moveTo(margin, yPosition - 20);
                contentStream.lineTo(margin + tableWidth, yPosition - 20);
                contentStream.stroke();
                yPosition -= 20;

                // Créez les en-têtes de colonnes
                contentStream.beginText();
                contentStream.setFont(PDType1Font.HELVETICA_BOLD, 10);
                contentStream.setNonStrokingColor(Color.BLACK);
                contentStream.newLineAtOffset(margin, yPosition);
                contentStream.showText("Nom de l'événement");
                contentStream.newLineAtOffset(150, 0);
                contentStream.showText("Date de l'événement");
                contentStream.newLineAtOffset(150, 0);
                contentStream.showText("Heure de l'événement");
                contentStream.newLineAtOffset(150, 0);
                contentStream.showText("Description");
                contentStream.endText();
                yPosition -= rowHeight;

                // Remplissez le tableau avec les données des événements
                for (Evenements evenement : listeEvenements) {
                    contentStream.beginText();
                    contentStream.setFont(PDType1Font.HELVETICA, 10);
                    contentStream.setNonStrokingColor(Color.BLACK);
                    contentStream.newLineAtOffset(margin, yPosition);
                    contentStream.showText(evenement.getNom_event());
                    contentStream.newLineAtOffset(150, 0);
                    contentStream.showText(evenement.getDate_event().toString());
                    contentStream.newLineAtOffset(150, 0);
                    contentStream.showText(evenement.getHeure_event().toString());
                    contentStream.newLineAtOffset(150, 0);
                    contentStream.showText(evenement.getDescription_event());
                    contentStream.endText();
                    yPosition -= tableRowHeight;
                }

                // Fermez le contenu du document
                contentStream.close();

                // Enregistrez le document
                document.save(dest);
                document.close();

                // Affichez une alerte de succès
                Alert alert = new Alert(Alert.AlertType.INFORMATION);
                alert.setTitle("Succès");
                alert.setHeaderText(null);
                alert.setContentText("Le fichier PDF a été enregistré avec succès !");
                alert.showAndWait();
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            System.out.println("Aucun emplacement sélectionné.");
        }
    }
    @FXML
    void handleGeneratePDF(ActionEvent event) {
        // Récupérez la liste des événements à partir de votre TableView ou de toute autre source de données
        List<Evenements> listeEvenements = TableViewEvent.getItems();

        // Appelez la méthode generateEventsPDF pour créer le PDF
        generateEventsPDF(listeEvenements);
    }



}

