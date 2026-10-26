package controllers;

import javafx.collections.FXCollections;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.geometry.Insets;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Categorie;
import models.Ingredient;
import models.Produit;
import services.OnChangeListener;
import services.ServiceProduit;
import test.FxMain;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.List;

public class MenuAdmin implements OnChangeListener {

    @FXML
    private HBox root;

    @FXML
    private Button LogoutBtn;

    @FXML
    private AnchorPane side_ankerpane;

    @FXML
    private Button HomeBtn;

    @FXML
    private Button UserManagementBtn;

    @FXML
    private Button btn_workbench112;

    @FXML
    private Button btn_workbench113;

    @FXML
    private Button btn_workbench114;

    @FXML
    private Button btn_workbench1131;

    @FXML
    private Button btn_workbench1132;

    @FXML
    private Button btn_workbench111;

    @FXML
    private Button btn_workbench1112;

    @FXML
    private Button btn_workbench11311;

    @FXML
    private Button EventManagementBtn;

    @FXML
    private TextField tfnom;

    @FXML
    private Button DeleteButton;

    @FXML
    private Button UpdateButton;

    @FXML
    private Button InsertButton;

    @FXML
    private Button uploadBtn;

    @FXML
    private ComboBox<Categorie> cbcat;

    @FXML
    private TextField tfimg;

    @FXML
    private TextField tfprix;

    @FXML
    private GridPane grid;

    @FXML
    private TextArea tfdesc;
    int idProduit;
    ServiceProduit serviceProduit=new ServiceProduit();
    @FXML
    public void initialize() {

        cbcat.getItems().setAll(Categorie.values());
        try {
            refresh(serviceProduit.selectAll());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }
    private String validateInput() {
        StringBuilder error = new StringBuilder();

        if (tfnom.getText().isEmpty()) {
            error.append("Le nom est requis.\n");
        }

        if (tfprix.getText().isEmpty()) {
            error.append("Le prix est requis.\n");
        } else {
            try {
                double prix = Double.parseDouble(tfprix.getText());
                if (prix < 0) {
                    error.append("Le prix doit être positif.\n");
                }
            } catch (NumberFormatException e) {
                error.append("Le prix doit être un nombre valide.\n");
            }
        }

        if (cbcat.getValue() == null) {
            error.append("La catégorie est requise.\n");
        }

        if (tfdesc.getText().isEmpty()) {
            error.append("La description est requise.\n");
        }

        if (tfimg.getText().isEmpty()) {
            error.append("Le chemin de l'image est requis.\n");
        }

        return error.toString();
    }


    @FXML
    void gotoIngredient(ActionEvent event) {
        try {
            URL url = getClass().getResource("/IngredientAdmin.fxml");
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

    @FXML
    void OnLogoutBtn(ActionEvent event) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/Login.fxml"));
        Parent root = loader.load();
        Stage stage = (Stage) tfimg.getScene().getWindow();
        stage.setScene(new Scene(root));
        stage.show();
    }

    @FXML
    void OnUpdate(ActionEvent event) {
        String validationResult = validateInput();
        if (!validationResult.isEmpty()) {
            // Display an alert with validation errors
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Erreur de Validation");
            alert.setHeaderText("Veuillez corriger les erreurs suivantes");
            alert.setContentText(validationResult);
            alert.showAndWait();
            return;
        }

        // Assuming you have a method in ServiceProduit to update products
        try {
            // Create a new Product object with updated data
            Produit updatedProduit = new Produit();
            updatedProduit.setId(idProduit); // Set the product ID
            updatedProduit.setNom(tfnom.getText());
            updatedProduit.setPrix(Double.parseDouble(tfprix.getText()));
            updatedProduit.setCategorie(cbcat.getValue());
            updatedProduit.setDescription(tfdesc.getText());
            updatedProduit.setImage(tfimg.getText());

            // Call the update method
            serviceProduit.update(updatedProduit);

            // Display a confirmation message
            Alert confirmation = new Alert(Alert.AlertType.INFORMATION);
            confirmation.setTitle("Produit Mis à Jour");
            confirmation.setHeaderText(null);
            confirmation.setContentText("Le produit a été mis à jour avec succès.");
            confirmation.showAndWait();

            refresh(serviceProduit.selectAll());

        } catch (SQLException e) {
            // Handle SQL Exception
            Alert errorAlert = new Alert(Alert.AlertType.ERROR);
            errorAlert.setTitle("Erreur");
            errorAlert.setHeaderText("Erreur lors de la mise à jour du produit");
            errorAlert.setContentText("Une erreur est survenue: " + e.getMessage());
            errorAlert.showAndWait();
        }
    }

    @FXML
    void handleHomeBtn(ActionEvent event) {

    }


    @FXML
    void handleUserManagementBtn(ActionEvent event) {
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

    @FXML
    void insertProduct(ActionEvent event) {
        String validationResult = validateInput();
        if (!validationResult.isEmpty()) {
            // Afficher une alerte avec les erreurs de validation
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Erreur de Validation");
            alert.setHeaderText("Veuillez corriger les erreurs suivantes");
            alert.setContentText(validationResult);
            alert.showAndWait();
            return;
        }

        // Créer un nouvel objet Produit
        Produit nouveauProduit = new Produit();
        nouveauProduit.setNom(tfnom.getText());
        nouveauProduit.setPrix(Double.parseDouble(tfprix.getText()));
        nouveauProduit.setCategorie(cbcat.getValue());
        nouveauProduit.setDescription(tfdesc.getText());
        nouveauProduit.setImage(tfimg.getText());
        try {
            serviceProduit.insertOne1(nouveauProduit);
            refresh(serviceProduit.selectAll());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        Alert confirmation = new Alert(Alert.AlertType.INFORMATION);
        confirmation.setTitle("Produit Ajouté");
        confirmation.setHeaderText(null);
        confirmation.setContentText("Le produit a été ajouté avec succès.");
        confirmation.showAndWait();

    }


    @FXML
    void uploadImg(ActionEvent event) {
        FileChooser fileChooser=new FileChooser();
        File file=fileChooser.showOpenDialog((Stage)tfdesc.getScene().getWindow());
        if(file!=null){
            tfimg.setText(file.getName());
        }
    }



    private void refresh(List<Produit> list) {
        grid.getChildren().clear();
        int column = 0;
        int row = 1;
        for (Produit p : list) {
            FXMLLoader card = new FXMLLoader(FxMain.class.getResource("/produit-card-admin.fxml"));
            AnchorPane anchorPane;
            try {
                anchorPane = card.load();
                ProduitCardAdmin controller = card.getController();
                controller.remplireData(p);
                controller.setOnChangeListener(this);
                if (column == 1) {
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

    private void rechercheAvance() {/*
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
        });*/
    }

    @Override
    public void refreshPrice() {
        try {
            refresh(serviceProduit.selectAll());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void fillForum(Produit p) {
        if (p != null) {
            // Fill the form fields with the product data
            tfnom.setText(p.getNom());
            tfprix.setText(String.valueOf(p.getPrix()));
            cbcat.setValue(p.getCategorie());
            tfdesc.setText(p.getDescription());
            tfimg.setText(p.getImage());
            // You might also need to store the product ID if you're using it for updates
            idProduit = p.getId();
        }
    }

    @Override
    public void fillForum2(Ingredient i) {

    }
}
