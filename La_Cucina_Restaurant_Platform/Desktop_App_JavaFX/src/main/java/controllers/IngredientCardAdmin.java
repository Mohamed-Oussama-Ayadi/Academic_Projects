package controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import models.Ingredient;
import services.OnChangeListener;
import services.ServiceIngredient;
import services.ServiceProduitIngredient;

import java.io.File;
import java.sql.SQLException;

public class IngredientCardAdmin {

    @FXML
    private ImageView imgingredient;

    @FXML
    private Label nomingredient;

    @FXML
    private Label prixingredient;

    @FXML
    private Button DeleteButton;

    @FXML
    private Button DeleteButton1;
    Ingredient ingredient;
    ServiceProduitIngredient serviceProduitIngredient=new ServiceProduitIngredient();
    ServiceIngredient serviceIngredient=new ServiceIngredient();
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
    void OnDelete(ActionEvent event) {
        try {
            serviceIngredient.delete(ingredient);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
        if(onChangeListener!=null){
            onChangeListener.refreshPrice();
        }
    }

    @FXML
    void OnUpdate(ActionEvent event) {
        if(onChangeListener!=null){
            onChangeListener.fillForum2(ingredient);
        }
    }

}
