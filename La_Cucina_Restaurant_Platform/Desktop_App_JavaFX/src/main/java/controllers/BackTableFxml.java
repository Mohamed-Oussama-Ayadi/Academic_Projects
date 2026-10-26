package controllers;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.Comparator;
import java.util.List;
import java.util.ResourceBundle;
import java.util.stream.Collectors;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import org.apache.poi.ss.usermodel.*;
import org.apache.poi.xssf.usermodel.XSSFWorkbook;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import models.Tables;
import services.ServiceTables;
public class BackTableFxml {

    @FXML
    public TableColumn<Tables, Boolean> disponibiliteColumn;
    public TextField SearchField;
    @FXML
    private ComboBox<String> disponibilitBox;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private Button AjoutT;

    @FXML
    private TableColumn<Tables, Integer> capaciteColumn;

    @FXML
    private Button modTab;

    @FXML
    private TextField numTab;

    @FXML
    private TextField capacitemodTab;

    @FXML
    private TextField emplacementTab;

    @FXML
    private TableColumn<Tables, String> emplacementColumn;
    
    @FXML
    private TableColumn<Tables, Integer> numeroTableColumn;

    @FXML
    private Button suppTab;
    @FXML
    private ComboBox emplacementComboBox;

    @FXML
    private TableView<Tables> tableView;

    private void afficherErreur(String titre, String contenu) {
        Alert alert = new Alert(Alert.AlertType.ERROR);
        alert.setTitle(titre);
        alert.setHeaderText(null);
        alert.setContentText(contenu);
        alert.showAndWait();
    }

    private void afficherSucces(String titre, String contenu) {
        Alert alert = new Alert(Alert.AlertType.INFORMATION);
        alert.setTitle(titre);
        alert.setHeaderText(null);
        alert.setContentText(contenu);

        // Supprime le bouton de fermeture de l'alerte
        alert.getButtonTypes().clear();
        alert.getButtonTypes().add(ButtonType.OK);

        alert.showAndWait();
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void onAjouterButtonClick(ActionEvent event) throws SQLException {
        try {
            Object emplacementValue = emplacementComboBox.getValue();
            if(emplacementValue == null || !(emplacementValue instanceof String) || ((String) emplacementValue).isEmpty()) {
                showAlert(Alert.AlertType.ERROR, "Error", "Emplacement field is empty or not a string!");
                return;
            }
            String emplacement =  (String) emplacementComboBox.getValue();

            String numTabText = numTab.getText();
            if (numTabText.isEmpty()) {
                showAlert(Alert.AlertType.ERROR, "Error", "Table number field is empty!");
                return;
            }
            int numTabs;
            try {
                numTabs = Integer.parseInt(numTabText);
                if (numTabs <= 0) {
                    throw new NumberFormatException();
                }
            } catch (NumberFormatException e) {
                showAlert(Alert.AlertType.ERROR, "Error", "Invalid numeric input for table number!");
                return;
            }

            String capacitemodTabText = capacitemodTab.getText();
            if (capacitemodTabText.isEmpty()) {
                showAlert(Alert.AlertType.ERROR, "Error", "Table capacity field is empty!");
                return;
            }
            int capacitemodTab;
            try {
                capacitemodTab = Integer.parseInt(capacitemodTabText);
                if (capacitemodTab <= 0) {
                    throw new NumberFormatException();
                }
            } catch (NumberFormatException e) {
                showAlert(Alert.AlertType.ERROR, "Error", "Invalid numeric input for table capacity!");
                return;
            }

            Boolean disponibilitBoxValue = Boolean.valueOf(disponibilitBox.getValue());
            if (disponibilitBoxValue == null || !(disponibilitBoxValue instanceof Boolean)) {
                showAlert(Alert.AlertType.ERROR, "Error", "DisponibilitBox field is empty or not a boolean!");
                return;
            }

            Alert confirmationAlert = new Alert(Alert.AlertType.CONFIRMATION);
            confirmationAlert.setTitle("Confirmation");
            confirmationAlert.setHeaderText(null);
            confirmationAlert.setContentText("Are you sure you want to insert this table?");
            ButtonType result = confirmationAlert.showAndWait().orElse(ButtonType.CANCEL);
            if (result == ButtonType.OK) {
                // Create the Tables object
                Tables table = new Tables(Integer.parseInt(numTab.getText()),
                        capacitemodTab,
                        //emplacementTab.getText(),
                        emplacement,
                        Boolean.parseBoolean(disponibilitBox.getValue()));
                ServiceTables serviceTable = new ServiceTables();
                serviceTable.insert(table);
            } else {
                System.out.println("The table insertion was canceled.");
            }

        } catch (NumberFormatException e) {
            // Gestion de l'exception si une valeur invalide est entrée
            System.err.println("Erreur : Entrée de données invalide pour les champs numériques.");
            e.printStackTrace(); // Vous pouvez également imprimer la pile d'erreurs pour le débogage
        } catch (SQLException e) {
            // Gestion de l'exception pour les erreurs SQL
            System.err.println("Erreur SQL lors de l'insertion de la nouvelle table.");
            e.printStackTrace(); // Vous pouvez également imprimer la pile d'erreurs pour le débogage
        }
        tableView.getItems().clear();
        afficher();
    }

    private void showAlert(Alert.AlertType type, String title, String content) {
        Alert alert = new Alert(type);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(content);
        alert.showAndWait();
    }

    ////////////////////////////////////////////////////////////////////////////////////////
    void afficher() throws SQLException {
        ServiceTables service = new ServiceTables();
        List<Tables> tables = service.selectAll();
        tableView.getItems().addAll(tables);
        numeroTableColumn.setCellValueFactory(new PropertyValueFactory<>("numeroTable"));
        capaciteColumn.setCellValueFactory(new PropertyValueFactory<>("capacite"));
        emplacementColumn.setCellValueFactory(new PropertyValueFactory<>("emplacement"));
        disponibiliteColumn.setCellValueFactory(new PropertyValueFactory<>("disponibilite"));
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void getData(/*MouseEvent event*/javafx.scene.input.MouseEvent mouseEvent) {
        Tables table = tableView.getSelectionModel().getSelectedItem();

        // Mettre à jour les champs texte avec les données de la table sélectionnée
        numTab.setText(String.valueOf(table.getNumeroTable()));
        capacitemodTab.setText(String.valueOf(table.getCapacite()));
        disponibilitBox.setValue(String.valueOf(table.isDisponibilite()));
    }

  @FXML
  public void onModTabButtonClick(ActionEvent event) throws SQLException {
      Object emplacementValue = emplacementComboBox.getValue();
      if(emplacementValue == null || !(emplacementValue instanceof String) || ((String) emplacementValue).isEmpty()) {
          showAlert(Alert.AlertType.ERROR, "Error", "Emplacement field is empty or not a string!");
          return;
      }
      String emplacement =  (String) emplacementComboBox.getValue();

      String numTabText = numTab.getText();
      if (numTabText.isEmpty()) {
          showAlert(Alert.AlertType.ERROR, "Error", "Table number field is empty!");
          return;
      }
      int numTabs;
      try {
          numTabs = Integer.parseInt(numTabText);
          if (numTabs <= 0) {
              throw new NumberFormatException();
          }
      } catch (NumberFormatException e) {
          showAlert(Alert.AlertType.ERROR, "Error", "Invalid numeric input for table number!");
          return;
      }

      String capacitemodTabText = capacitemodTab.getText();
      if (capacitemodTabText.isEmpty()) {
          showAlert(Alert.AlertType.ERROR, "Error", "Table capacity field is empty!");
          return;
      }
      int capacitemodTab;
      try {
          capacitemodTab = Integer.parseInt(capacitemodTabText);
          if (capacitemodTab <= 0) {
              throw new NumberFormatException();
          }
      } catch (NumberFormatException e) {
          showAlert(Alert.AlertType.ERROR, "Error", "Invalid numeric input for table capacity!");
          return;
      }

      Boolean disponibilitBoxValue = Boolean.valueOf(disponibilitBox.getValue());
      if (disponibilitBoxValue == null || !(disponibilitBoxValue instanceof Boolean)) {
          showAlert(Alert.AlertType.ERROR, "Error", "DisponibilitBox field is empty or not a boolean!");
          return;
      }
      int numeroTable = Integer.parseInt(numTab.getText());
      boolean disponibilite = false;
      String disponibiliteText = disponibilitBox.getValue().toString().trim(); // Supprimer les espaces vides
      if (!disponibiliteText.isEmpty()) {
          disponibilite = Boolean.parseBoolean(disponibiliteText);
      }

      // Créer un nouvel objet Tables avec les données mises à jour
      Tables tableModifiee = new Tables(numeroTable, capacitemodTab, (String) emplacementComboBox.getValue(), disponibilite);

      try {
          Alert confirmationAlert = new Alert(Alert.AlertType.CONFIRMATION);
          confirmationAlert.setTitle("Confirmation");
          confirmationAlert.setHeaderText(null);
          confirmationAlert.setContentText("Are you sure you want to update this table?");
          ButtonType result = confirmationAlert.showAndWait().orElse(ButtonType.CANCEL);
          if (result == ButtonType.OK) {
              ServiceTables serviceTables = new ServiceTables();
              serviceTables.update(tableModifiee);
              tableView.getItems().clear();
              afficher();
              System.out.println("La table avec le numéro de table " + numeroTable + " a été mise à jour avec succès.");
          } else {
              System.out.println("La mise à jour de la table a été annulée.");
          }

      } catch (SQLException e) {
          System.err.println("Erreur lors de la mise à jour de la table : " + e.getMessage());
      }
  }
    ////////////////////////////////////////////////////////////////////////////////////////
    public void supprimerTab(ActionEvent event) {
        // Récupérer la ligne sélectionnée dans le TableView
        Tables tableSelectionnee = tableView.getSelectionModel().getSelectedItem();

        if (tableSelectionnee != null) {
            // Create a confirmation alert
            Alert confirmationAlert = new Alert(Alert.AlertType.CONFIRMATION);
            confirmationAlert.setTitle("Confirmation");
            confirmationAlert.setHeaderText(null);
            confirmationAlert.setContentText("Are you sure you want to delete this table?");

            // Show the confirmation alert and wait for the user's response
            ButtonType result = confirmationAlert.showAndWait().orElse(ButtonType.CANCEL);

            // If the user confirms the deletion, proceed with deleting the table
            if (result == ButtonType.OK) {
                try {
                    // Créez un service pour gérer les tables
                    ServiceTables serviceTable = new ServiceTables();

                    // Utilisez la méthode delete pour supprimer la table sélectionnée
                    serviceTable.delete(tableSelectionnee);

                    // Supprimez également la ligne du TableView pour refléter la suppression dans l'interface utilisateur
                    tableView.getItems().remove(tableSelectionnee);

                    System.out.println("La table avec le numéro de table " + tableSelectionnee.getNumeroTable() + " a été supprimée avec succès.");

                } catch (SQLException e) {
                    // Gestion des exceptions pour les erreurs SQL
                    System.err.println("Erreur SQL lors de la suppression de la table.");
                    e.printStackTrace();
                }
            } else {
                // If the user cancels the deletion, do nothing
                System.out.println("La suppression de la table a été annulée.");
            }
        } else {
            // Aucune ligne sélectionnée, affichez un message dans la console
            System.out.println("Aucune sélection à supprimer.");
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void initialize() throws SQLException {
        assert AjoutT != null : "fx:id=\"AjoutT\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert capaciteColumn != null : "fx:id=\"capaciteColumn\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert capacitemodTab != null : "fx:id=\"capacitemodTab\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert disponibiliteColumn != null : "fx:id=\"disponibiliteColumn\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert emplacementColumn != null : "fx:id=\"emplacementColumn\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert emplacementTab != null : "fx:id=\"emplacementTab\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert modTab != null : "fx:id=\"modTab\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert numTab != null : "fx:id=\"numTabmod\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert numeroTableColumn != null : "fx:id=\"numeroTableColumn\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert suppTab != null : "fx:id=\"suppTab\" was not injected: check your FXML file 'BackTable.fxml'.";
        assert tableView != null : "fx:id=\"tableView\" was not injected: check your FXML file 'BackTable.fxml'.";
        afficher();
        emplacementComboBox.getItems().addAll("north", "sud", "centre-north","terrasse1","terasse2","centre-sud");
        disponibilitBox.getItems().addAll("True","False");
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    private void openReservation() {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/ReservationAdmin.fxml"));
            Parent parent = loader.load(); // Charger l'interface dans le parent

            // Récupérer la scène actuelle
            Scene scene =  tableView.getScene();
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
/*
    @FXML
    void OnExport(ActionEvent actionEvent) {
        try {
            ServiceTables service = new ServiceTables();
            List<Tables> tables = service.selectAll();

            // Create a new Workbook
            Workbook workbook = new XSSFWorkbook();
            Sheet sheet = workbook.createSheet("Table Data");

            // Create a header row
            Row headerRow = sheet.createRow(0);
            headerRow.createCell(0).setCellValue("Table Number");
            headerRow.createCell(1).setCellValue("Capacity");
            headerRow.createCell(2).setCellValue("Emplacement");
            headerRow.createCell(3).setCellValue("Disponibility");

            // Fill data rows
            int rowNum = 1;
            for (Tables table : tables) {
                Row row = sheet.createRow(rowNum++);
                row.createCell(0).setCellValue(table.getNumeroTable());
                row.createCell(1).setCellValue(table.getCapacite());
                row.createCell(2).setCellValue(table.getEmplacement());
                row.createCell(3).setCellValue(table.isDisponibilite());
            }

            // Prompt user to choose file location
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Save Excel File");
            fileChooser.getExtensionFilters().addAll(
                    new FileChooser.ExtensionFilter("Excel Files", "*.xlsx"),
                    new FileChooser.ExtensionFilter("All Files", "*.*")
            );
            Stage stage = new Stage();
            File file = fileChooser.showSaveDialog(stage);

            if (file != null) {
                try (FileOutputStream fileOut = new FileOutputStream(file)) {
                    workbook.write(fileOut);
                    workbook.close();
                    showAlert(Alert.AlertType.INFORMATION, "Success", "Data exported to Excel successfully.");
                } catch (IOException e) {
                    showAlert(Alert.AlertType.ERROR, "Error", "An error occurred while exporting data to Excel.");
                    e.printStackTrace();
                }
            }

        } catch (SQLException e) {
            showAlert(Alert.AlertType.ERROR, "Error", "An error occurred while fetching data from the database.");
            e.printStackTrace();
        }
    }
*/
@FXML
void OnExport(ActionEvent actionEvent) {
    try {
        ServiceTables service = new ServiceTables();
        List<Tables> tables = service.selectAll();

        // Create a new Workbook
        Workbook workbook = new XSSFWorkbook();
        Sheet sheet = workbook.createSheet("Table Data");

        // Create a header row
        Row headerRow = sheet.createRow(0);
        headerRow.createCell(0).setCellValue("Table Number");
        headerRow.createCell(1).setCellValue("Capacity");
        headerRow.createCell(2).setCellValue("Emplacement");
        headerRow.createCell(3).setCellValue("Disponibility");

        // Fill data rows
        int rowNum = 1;
        for (Tables table : tables) {
            Row row = sheet.createRow(rowNum++);
            row.createCell(0).setCellValue(table.getNumeroTable());
            row.createCell(1).setCellValue(table.getCapacite());
            row.createCell(2).setCellValue(table.getEmplacement());
            row.createCell(3).setCellValue(table.isDisponibilite());
        }

        // Specify the specific file path
        String filePath = "C:\\Users\\ayadi\\OneDrive - ESPRIT (1)\\Bureau\\La_Cucina_Projet_Pidev (2)\\La_Cucina_Projet_Pidev\\tables.xlsx";
        File file = new File(filePath);

        try (FileOutputStream fileOut = new FileOutputStream(file)) {
            workbook.write(fileOut);
            workbook.close();
            showAlert(Alert.AlertType.INFORMATION, "Success", "Data exported to Excel successfully.");
        } catch (IOException e) {
            showAlert(Alert.AlertType.ERROR, "Error", "An error occurred while exporting data to Excel.");
            e.printStackTrace();
        }

    } catch (SQLException e) {
        showAlert(Alert.AlertType.ERROR, "Error", "An error occurred while fetching data from the database.");
        e.printStackTrace();
    }
}

    @FXML
    void OnSort(ActionEvent actionEvent) {
        try {
            ServiceTables service = new ServiceTables();
            List<Tables> tables = service.selectAll();
            tables.sort(Comparator.comparingInt(Tables::getNumeroTable));
            tableView.getItems().clear();
            ObservableList<Tables> sortedTables = FXCollections.observableArrayList(tables);
            tableView.setItems(sortedTables);
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }


    @FXML
    void OnSearch(ActionEvent actionEvent) throws SQLException {
        String searchText = SearchField.getText().toLowerCase().trim();

        if (searchText.isEmpty()) {
            afficher();
        } else {
            try {
                ServiceTables service = new ServiceTables();
                List<Tables> tables = service.selectAll();
                List<Tables> filteredTables = tables.stream()
                        .filter(table ->
                                String.valueOf(table.getNumeroTable()).toLowerCase().contains(searchText) ||
                                        String.valueOf(table.getCapacite()).toLowerCase().contains(searchText) ||
                                        table.getEmplacement().toLowerCase().contains(searchText) ||
                                        String.valueOf(table.isDisponibilite()).toLowerCase().contains(searchText))
                        .collect(Collectors.toList());
                tableView.getItems().clear();
                ObservableList<Tables> filteredData = FXCollections.observableArrayList(filteredTables);
                tableView.setItems(filteredData);
            } catch (SQLException e) {
                e.printStackTrace();
            }
        }
    }
}
