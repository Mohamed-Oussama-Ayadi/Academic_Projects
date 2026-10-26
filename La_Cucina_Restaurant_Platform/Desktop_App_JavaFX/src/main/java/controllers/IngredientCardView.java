package controllers;

import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import models.Ingredient;
import models.Produit_Ingredient;
import services.OnChangeListener;
import services.ServiceProduit;
import services.ServiceProduitIngredient;

import java.io.File;
import java.sql.SQLException;

public class IngredientCardView {

    @FXML
    private ImageView imgingredient;

    @FXML
    private Label nomingredient;
    @FXML
    private Label prixingredient;
    @FXML
    private ImageView minusimg;

    @FXML
    private ImageView plusimg;
    Ingredient ingredient;
    ServiceProduitIngredient serviceProduitIngredient=new ServiceProduitIngredient();
    private OnChangeListener onChangeListener;

    public void setOnChangeListener(OnChangeListener onChangeListener) {
        this.onChangeListener = onChangeListener;
    }

    void remplireData(Ingredient ingredient){
        this.ingredient=ingredient;
        nomingredient.setText(ingredient.getNom());
        prixingredient.setText(String.valueOf(ingredient.getPrix())+" DT");
        File file=new File("C:\\Users\\Skymil\\Desktop\\Work\\MindsAcademy\\JavaFX\\Oumaima\\La_Cucina_Projet_Pidev\\src\\main\\resources\\Images\\"+ingredient.getImage());
        Image img=new Image(file.toURI().toString());
        imgingredient.setImage(img);
    }



    @FXML
    void minus(MouseEvent event) {
        try {
            serviceProduitIngredient.deleteParProduitEtIngredient(ProduitCardView.idProduit, ingredient.getId());
            plusimg.toFront();
            if(onChangeListener!=null){
                onChangeListener.refreshPrice();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @FXML
    void plus(MouseEvent event) {
        Produit_Ingredient produitIngredient=new Produit_Ingredient(ProduitCardView.idProduit, ingredient.getId());
        try {
            serviceProduitIngredient.insertOne1(produitIngredient);
            minusimg.toFront();
            if(onChangeListener!=null){
                onChangeListener.refreshPrice();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
