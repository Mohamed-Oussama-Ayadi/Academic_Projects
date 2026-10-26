package controllers;

import javafx.beans.property.SimpleObjectProperty;
import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.util.StringConverter;
import models.Reservations;
import services.ServiceReservations;
import utils.DBConnection;

import java.io.IOException;
import java.sql.*;
import java.time.Instant;
import java.time.LocalDate;
import java.time.ZoneId;
import java.time.ZonedDateTime;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.font.PDType1Font;

import java.io.File;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
public class ReservationFxml {

    public DatePicker datePicker;
    @FXML
    private ComboBox<String> HoraireBox;
    @FXML
    private Button AjoutT;

    @FXML
    private TableColumn<Reservations, Integer> idReservationColumn;

    @FXML
    private TableColumn<Reservations, Integer> nbrPersonnesColumn;

    @FXML
    private TableColumn<Reservations, String> dateColumn;

    @FXML
    private TableColumn<Reservations, String> horaireColumn;

    @FXML
    private Button suppTab;

    @FXML
    private TableView<Reservations> tableView;
    @FXML
    private TextField searchField;

    @FXML
    private TextField nbrPersonnesTextField;

    @FXML
    private TableColumn<Reservations, Integer> Num_tab;
    @FXML
    private ComboBox<Integer> numeroTableText;
    private Connection cnx;
    private PreparedStatement pre;
    private int reservationId;

    public ReservationFxml(){cnx= DBConnection.getInstance().getCnx();}
    private List<Integer> getCommandeIDsFromDatabase() throws SQLException {
        List<Integer> tablsnum = new ArrayList<>();

        // Connexion à la base de données (assurez-vous d'avoir le pilote JDBC approprié)
        try  {
            Statement statement = cnx.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT numeroTable FROM tables ");

            // Récupération des ID des commandes et les ajouter à la liste
            while (resultSet.next()) {
                Integer id = resultSet.getInt("numeroTable");
                tablsnum.add(id);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return tablsnum;
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void initialize() throws SQLException {
        idReservationColumn.setCellValueFactory(cellData -> new SimpleObjectProperty<>(cellData.getValue().getId_reservation()));
        nbrPersonnesColumn.setCellValueFactory(cellData -> new SimpleObjectProperty<>(cellData.getValue().getNbr_personnes()));
        dateColumn.setCellValueFactory(cellData -> new SimpleStringProperty(cellData.getValue().getDate().toString()));
        horaireColumn.setCellValueFactory(cellData -> new SimpleObjectProperty<>(cellData.getValue().getHoraire()));
        Num_tab.setCellValueFactory(cellData -> new SimpleObjectProperty<>(cellData.getValue().getNum()));

            try {
                List<Integer> commandeIDs = getCommandeIDsFromDatabase();
                // Ajout des ID des commandes au ChoiceBox
                numeroTableText.getItems().addAll(commandeIDs);
                System.out.println("ghaaaaaaaalta");
            } catch (SQLException e) {
                System.out.println("ghaaaaaaaalta");
                throw new RuntimeException(e);
            }
        afficher();

        for (int i = 0; i < 24; i++) {
            String hour = String.format("%02d:00", i);
            HoraireBox.getItems().add(hour);
        }
    }

    private boolean isInteger(String str) {
        try {
            Integer.parseInt(str);
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }

    private void showAlert(String title, String message) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(message);
        alert.showAndWait();
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void onAjouterButtonClick(ActionEvent event) {
        try {
            // Check if all necessary fields are filled
            if (nbrPersonnesTextField.getText().isEmpty() || HoraireBox.getValue() == null || datePicker.getValue() == null || numeroTableText.getValue() == null) {
                showAlert("Error", "Veuillez remplir tous les champs nécessaires.");
                return;
            }
            LocalDate selectedDate = datePicker.getValue();
            if (selectedDate.isBefore(LocalDate.now())) {
                showAlert("Error", "La date sélectionnée est dans le passé.");
                return;
            }

            int nbrPersonnes = Integer.parseInt(nbrPersonnesTextField.getText().trim());
            String horaire = HoraireBox.getValue();
            LocalDate localDate = datePicker.getValue();
            Date date = Date.valueOf(localDate);
            ServiceReservations service = new ServiceReservations();

            // Check if a reservation with the same characteristics already exists
            if (service.reservationExists(nbrPersonnes, horaire, date, numeroTableText.getValue())) {
                showAlert("Error", "Cette réservation existe déjà.");
                return;
            }

            // Confirmation dialog
            Alert confirmation = new Alert(Alert.AlertType.CONFIRMATION);
            confirmation.setHeaderText("Confirmation");
            confirmation.setContentText("Êtes-vous sûr de vouloir ajouter cette réservation?");

            // Show confirmation dialog and wait for user response
            confirmation.showAndWait().ifPresent(response -> {
                if (response == ButtonType.OK) {
                    // If the reservation does not exist, add it to the database
                    Reservations reservation = new Reservations(nbrPersonnes, horaire, date, numeroTableText.getValue());
                    try {
                        service.insert(reservation);
                        afficher(); // Refresh TableView
                    } catch (SQLException e) {
                        e.printStackTrace();
                        // Handle SQL errors
                    }
                }
            });

        } catch (NumberFormatException | SQLException e) {
            e.printStackTrace();
            // Handle exceptions (e.g., invalid input, SQL errors)
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////

    @FXML
    void onModTabButtonClick(ActionEvent event) {
        Reservations reservations = tableView.getSelectionModel().getSelectedItem();
        if (reservations == null) {
            System.out.println("Aucune réservation sélectionnée");
            return;
        }

        // Check if all necessary fields are filled
        if (nbrPersonnesTextField.getText().isEmpty() || HoraireBox.getValue() == null || datePicker.getValue() == null || numeroTableText.getValue() == null) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setHeaderText(null);
            alert.setContentText("Veuillez remplir tous les champs nécessaires.");
            alert.showAndWait();
            return;
        }

        // Confirmation dialog
        Alert confirmation = new Alert(Alert.AlertType.CONFIRMATION);
        confirmation.setHeaderText("Confirmation");
        confirmation.setContentText("Êtes-vous sûr de vouloir modifier cette réservation?");

        // Show confirmation dialog and wait for user response
        confirmation.showAndWait().ifPresent(response -> {
            if (response == ButtonType.OK) {
                int nbrPersonnes = Integer.parseInt(nbrPersonnesTextField.getText().trim());
                String horaire = HoraireBox.getValue();
                LocalDate localDate = datePicker.getValue();
                Date date = Date.valueOf(localDate);
                int numTab = numeroTableText.getValue(); // Get the new value of num_tab

                // Update reservation data with new values
                reservations.setNbr_personnes(nbrPersonnes);
                reservations.setDate(date);
                reservations.setHoraire(horaire);
                reservations.setNum_tab(numTab); // Update num_tab with new value

                // Update reservation in the database
                try {
                    ServiceReservations serviceReservations = new ServiceReservations();
                    serviceReservations.updateReservation(reservations);

                    // Refresh TableView data if necessary
                    tableView.refresh();
                    // Clear fields after update
                    nbrPersonnesTextField.clear();
                    datePicker.setValue(null); // Clear selected date
                    numeroTableText.getSelectionModel().clearSelection(); // Clear selection in ChoiceBox

                } catch (SQLException e) {
                    e.printStackTrace();
                }
            }
        });
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void supprimerTab(ActionEvent event) {
        Reservations selectedReservation = tableView.getSelectionModel().getSelectedItem();
        if (selectedReservation != null) {
            // Create confirmation dialog
            Alert confirmation = new Alert(Alert.AlertType.CONFIRMATION);
            confirmation.setHeaderText("Confirm Deletion");
            confirmation.setContentText("Are you sure you want to delete this reservation?");

            // Show confirmation dialog and wait for user response
            confirmation.showAndWait().ifPresent(response -> {
                if (response == ButtonType.OK) {
                    try {
                        ServiceReservations service = new ServiceReservations();
                        service.deleteReservation(selectedReservation);

                        afficher(); // Refresh TableView
                    } catch (SQLException e) {
                        e.printStackTrace();
                        // Handle SQL errors
                    }
                }
            });
        } else {
            // No reservation selected, show error message or perform appropriate action
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void afficher() {
        ServiceReservations service = new ServiceReservations();
        try {
            List<Reservations> reservations = service.selectAllReservations();
            System.out.println("--"+reservations);
            ObservableList<Reservations> observableReservations = FXCollections.observableArrayList(reservations);
            tableView.setItems(observableReservations);

            tableView.getSelectionModel().selectedItemProperty().addListener((obs, oldSelection, newSelection) -> {
                if (newSelection != null) {
                    reservationId = newSelection.getId_reservation();
                    nbrPersonnesTextField.setText(String.valueOf(newSelection.getNbr_personnes()));
                    HoraireBox.setValue(newSelection.getHoraire());
                    datePicker.setValue(newSelection.getDate().toLocalDate());
                    numeroTableText.setValue(newSelection.getNum());

                } else {
                    clearFields();
                }
            });
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    private void clearFields() {
        nbrPersonnesTextField.clear();
        numeroTableText.getItems().clear();
        datePicker.setValue(LocalDate.now());
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    private void openTable() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/TableAdmin.fxml"));
            Parent parent = loader.load(); // Charger l'interface dans le parent

            // Récupérer la scène actuelle
            Scene scene =  numeroTableText.getScene();
            // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
            scene.setRoot(parent);

        } catch (IOException e) {
            throw new RuntimeException(e);
        }
    }

    public void GoToReserve(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/ReservationFront.fxml"));
        Parent parent = loader.load();
        Scene scene =  tableView.getScene();
        scene.setRoot(parent);
    }

    @FXML
    void OnSearch(ActionEvent actionEvent) {
        String searchText = searchField.getText().trim().toLowerCase();
        if (searchText.isEmpty()) {
            afficher();
            return;
        }
        ObservableList<Reservations> filteredList = tableView.getItems().filtered(reservation ->
                        (reservation.getNbr_personnes()+"").toLowerCase().contains(searchText)||
                        reservation.getHoraire().toLowerCase().contains(searchText) ||
                        reservation.getDate().toString().toLowerCase().contains(searchText) ||
                        reservation.getNum().toString().toLowerCase().contains(searchText));

        tableView.setItems(filteredList);
    }

    @FXML
    void OnSort(ActionEvent actionEvent) {
        try {
            ServiceReservations service = new ServiceReservations();
            List<Reservations> reservations = service.selectAllReservations();
            Comparator<Reservations> idComparator = Comparator.comparing(Reservations::getDate);
            reservations.sort(idComparator);
            ObservableList<Reservations> observableReservations = FXCollections.observableArrayList(reservations);
            tableView.setItems(observableReservations);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    @FXML
    void OnExport(ActionEvent actionEvent) {
        try {
            ServiceReservations service = new ServiceReservations();
            List<Reservations> reservations = service.selectAllReservations();

            // Create a new PDF document
            PDDocument document = new PDDocument();
            PDPage page = new PDPage();
            document.addPage(page);

            PDPageContentStream contentStream = new PDPageContentStream(document, page);

            // Define font and font size for text
            contentStream.setFont(PDType1Font.HELVETICA_BOLD, 12);

            // Write table headers
            contentStream.beginText();
            contentStream.newLineAtOffset(50, 700); // Set starting position for text
            contentStream.showText("ID");
            contentStream.newLineAtOffset(100, 0);
            contentStream.showText("Number of Persons");
            contentStream.newLineAtOffset(100, 0);
            contentStream.showText("Date");
            contentStream.newLineAtOffset(100, 0);
            contentStream.showText("Time");
            contentStream.newLineAtOffset(100, 0);
            contentStream.showText("Table Number");
            contentStream.endText();

            // Write table data
            contentStream.setFont(PDType1Font.HELVETICA, 10);
            int y = 680; // Y-coordinate for text
            for (Reservations reservation : reservations) {
                contentStream.beginText();
                contentStream.newLineAtOffset(50, y);
                contentStream.showText(String.valueOf(reservation.getId_reservation()));
                contentStream.newLineAtOffset(100, 0);
                contentStream.showText(String.valueOf(reservation.getNbr_personnes()));
                contentStream.newLineAtOffset(100, 0);
                contentStream.showText(reservation.getDate().toString());
                contentStream.newLineAtOffset(100, 0);
                contentStream.showText(reservation.getHoraire());
                contentStream.newLineAtOffset(100, 0);
                contentStream.showText(String.valueOf(reservation.getNum()));
                contentStream.endText();
                y -= 20; // Move to next row
            }

            // Close content stream
            contentStream.close();

            // Save the PDF document
            File file = new File("reservations.pdf");
            document.save(file);
            document.close();

            Alert confirmation = new Alert(Alert.AlertType.INFORMATION);
            confirmation.setHeaderText("Export Successful");
            confirmation.setContentText("The data has been exported to reservations.pdf");
            confirmation.showAndWait();
        } catch (SQLException | IOException e) {
            e.printStackTrace();
            // Handle exceptions
        }
    }

    @FXML
    void OnStats(ActionEvent actionEvent) {
        try {
            ServiceReservations service = new ServiceReservations();
            List<Reservations> reservations = service.selectAllReservations();
            int totalReservations = reservations.size();
            int totalPersons = 0;
            for (Reservations reservation : reservations) {
                totalPersons += reservation.getNbr_personnes();
            }
            double averagePersonsPerReservation = (double) totalPersons / totalReservations;
            String message = String.format("Total Reservations: %d\nTotal Persons: %d\nAverage Persons per Reservation: %.2f",
                    totalReservations, totalPersons, averagePersonsPerReservation);
            Alert alert = new Alert(Alert.AlertType.INFORMATION);
            alert.setTitle("Statistics");
            alert.setHeaderText(null);
            alert.setContentText(message);
            alert.showAndWait();
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

