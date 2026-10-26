package controllers;

import javafx.collections.FXCollections;
import javafx.collections.transformation.FilteredList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.ComboBox;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.GridPane;
import javafx.stage.Stage;
import models.Ingredient;
import models.Produit;
import models.Utilisateurs;
import services.OnChangeListener;
import services.ServiceIngredient;
import services.ServiceProduit;
import services.ServiceProduitIngredient;
import test.FxMain;

import java.io.File;
import java.io.IOException;
import java.sql.SQLException;
import java.util.List;

public class ChooseProductView implements OnChangeListener {

    @FXML
    private Label idU;

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
    private ImageView imgproduit;

    @FXML
    private Label nomproduit;

    @FXML
    private Label prixproduit;

    @FXML
    private Label descproduit;

    @FXML
    private GridPane grid;
    ServiceProduit serviceProduit=new ServiceProduit();
    ServiceProduitIngredient serviceProduitIngredient=new ServiceProduitIngredient();
    ServiceIngredient serviceIngredient=new ServiceIngredient();
    @FXML
    public void initialize() {
        try {
            Produit p=serviceProduit.getProduitById(serviceProduit.selectAll(),ProduitCardView.idProduit);
            nomproduit.setText(p.getNom());
            descproduit.setText(p.getDescription());
            prixproduit.setText(String.valueOf(serviceProduitIngredient.getPrixTotalProduit(p.getId())));
            File file=new File("C:\\Users\\Skymil\\Desktop\\Work\\MindsAcademy\\JavaFX\\Oumaima\\La_Cucina_Projet_Pidev\\src\\main\\resources\\Images\\"+p.getImage());
            Image img=new Image(file.toURI().toString());
            imgproduit.setImage(img);
            refresh();
            System.out.println("*****3******");
            System.out.println(utilisateur);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }
    private void refresh() throws SQLException {
        grid.getChildren().clear();
        List<Ingredient> ingredients = serviceIngredient.getIngredientsByCategorie(serviceProduit.getProduitById(serviceProduit.selectAll(),ProduitCardView.idProduit).getCategorie());
        System.out.println(ingredients);
        int column = 0;
        int row = 1;
        for (Ingredient ingredient : ingredients) {
            try {
                FXMLLoader fxmlLoader = new FXMLLoader(FxMain.class.getResource("/ingredient-card-view.fxml"));
                AnchorPane anchorPane = fxmlLoader.load();
                IngredientCardView controller = fxmlLoader.getController();
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

    @FXML
    void ajouter(ActionEvent event) {
        try {
            serviceProduitIngredient.deleteParIdProduit(ProduitCardView.idProduit);
        } catch (SQLException e) {
            throw new RuntimeException(e);
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
        } else {
            System.out.println("Utilisateur non trouvé avec l'ID : " + userId);
        }
    }

    @FXML
    void handleHomeBtnClick(MouseEvent event) {
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
        try {
            serviceProduitIngredient.deleteParIdProduit(ProduitCardView.idProduit);
        } catch (SQLException e) {
            throw new RuntimeException(e);
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
        try {
            serviceProduitIngredient.deleteParIdProduit(ProduitCardView.idProduit);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @Override
    public void refreshPrice() {
        try {
            Produit p = serviceProduit.getProduitById(serviceProduit.selectAll(), ProduitCardView.idProduit);
            prixproduit.setText(String.valueOf(serviceProduitIngredient.getPrixTotalProduit(p.getId())));
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

    @Override
    public void fillForum(Produit p) {

    }

    @Override
    public void fillForum2(Ingredient i) {

    }
}
