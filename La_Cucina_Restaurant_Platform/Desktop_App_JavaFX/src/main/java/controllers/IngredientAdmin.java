package controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.control.ComboBox;
import javafx.scene.control.TextField;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.HBox;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Categorie;
import models.Ingredient;
import models.Produit;
import services.OnChangeListener;
import services.ServiceIngredient;
import test.FxMain;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.List;

public class IngredientAdmin implements OnChangeListener {

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
    int idIngredient;

    @FXML
    private GridPane grid;
    ServiceIngredient serviceIngredient=new ServiceIngredient();
    @FXML
    public void initialize() {

        cbcat.getItems().setAll(Categorie.values());
        try {
            refresh();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }
    private void refresh() throws SQLException {
        grid.getChildren().clear();
        List<Ingredient> ingredients = serviceIngredient.selectAll();
        System.out.println(ingredients);
        int column = 0;
        int row = 1;
        for (Ingredient ingredient : ingredients) {
            try {
                FXMLLoader fxmlLoader = new FXMLLoader(FxMain.class.getResource("/ingredient-card-admin.fxml"));
                AnchorPane anchorPane = fxmlLoader.load();
                IngredientCardAdmin controller = fxmlLoader.getController();
                controller.remplireData(ingredient);
                controller.setOnChangeListener(this);
                if (column == 1) {
                    column = 0;
                    row++;
                }
                grid.add(anchorPane, column, row);
                column++;

            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }
    private String validateInput() {
        StringBuilder error = new StringBuilder();

        if (tfnom.getText().isEmpty()) {
            error.append("Le nom de l'ingrédient est requis.\n");
        }

        if (tfprix.getText().isEmpty()) {
            error.append("Le prix de l'ingrédient est requis.\n");
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
            error.append("La catégorie de l'ingrédient est requise.\n");
        }

        if (tfimg.getText().isEmpty()) {
            error.append("L'image de l'ingrédient est requise.\n");
        }

        return error.toString();
    }


    @FXML
    void OnLogoutBtn(ActionEvent event) {

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

        // Assuming you have an update method in your ServiceIngredient
        try {
            // Create a new Ingredient object with updated data
            Ingredient updatedIngredient = new Ingredient();
            // updatedIngredient.setId(idIngredient); // Set the ingredient ID
            updatedIngredient.setId(idIngredient);
            updatedIngredient.setNom(tfnom.getText());
            updatedIngredient.setPrix(Double.parseDouble(tfprix.getText()));
            updatedIngredient.setCategorie(cbcat.getValue());
            updatedIngredient.setImage(tfimg.getText());

            // Call the update method
            serviceIngredient.update(updatedIngredient);

            // Display a confirmation message
            Alert confirmation = new Alert(Alert.AlertType.INFORMATION);
            confirmation.setTitle("Ingrédient Mis à Jour");
            confirmation.setHeaderText(null);
            confirmation.setContentText("L'ingrédient a été mis à jour avec succès.");
            confirmation.showAndWait();


            refresh();

        } catch (SQLException e) {
            // Handle SQL Exception
            Alert errorAlert = new Alert(Alert.AlertType.ERROR);
            errorAlert.setTitle("Erreur");
            errorAlert.setHeaderText("Erreur lors de la mise à jour de l'ingrédient");
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
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("Erreur de Validation");
            alert.setHeaderText("Veuillez corriger les erreurs suivantes");
            alert.setContentText(validationResult);
            alert.showAndWait();
            return;
        }

        Ingredient newIngredient = new Ingredient();
        newIngredient.setNom(tfnom.getText());
        newIngredient.setPrix(Double.parseDouble(tfprix.getText()));
        newIngredient.setCategorie(cbcat.getValue());
        newIngredient.setImage(tfimg.getText());
        try {
            serviceIngredient.insertOne1(newIngredient);
            refresh();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    @FXML
    void uploadImg(ActionEvent event) {
        FileChooser fileChooser=new FileChooser();
        File file=fileChooser.showOpenDialog((Stage)tfimg.getScene().getWindow());
        if(file!=null){
            tfimg.setText(file.getName());
        }
    }

    @Override
    public void refreshPrice() {
        try {
            refresh();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void fillForum(Produit p) {

    }

    @Override
    public void fillForum2(Ingredient i) {
        if (i != null) {
            // Fill the form fields with the ingredient data
            tfnom.setText(i.getNom());
            tfprix.setText(String.valueOf(i.getPrix()));
            cbcat.setValue(i.getCategorie());
            tfimg.setText(i.getImage());
            idIngredient=i.getId();
        }
    }
}
