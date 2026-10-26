package controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import models.Produit;
import org.controlsfx.control.Rating;
import services.OnChangeListener;
import services.ServiceProduit;

import java.io.File;
import java.sql.SQLException;

public class ProduitCardAdmin {

    @FXML
    private ImageView produitimg;

    @FXML
    private Label produitnom;

    @FXML
    private Label produitdesc;

    @FXML
    private Label produitprix;

    @FXML
    private Rating produitnote;
    Produit p;
    public static int idProduit;
    private OnChangeListener onChangeListener;
    ServiceProduit serviceProduit=new ServiceProduit();

    public void setOnChangeListener(OnChangeListener onChangeListener) {
        this.onChangeListener = onChangeListener;
    }
    void remplireData(Produit p){
        this.p=p;
        produitdesc.setText(p.getDescription());
        produitnom.setText(p.getNom());
        produitprix.setText(String.valueOf(p.getPrix())+" DT");
        produitnote.setRating(p.getNote());
        File file=new File("C:\\Users\\Skymil\\Desktop\\Work\\MindsAcademy\\JavaFX\\Oumaima\\La_Cucina_Projet_Pidev\\src\\main\\resources\\Images\\"+p.getImage());
        Image img=new Image(file.toURI().toString());
        produitimg.setImage(img);
    }

    @FXML
    void modifier(ActionEvent event) {
        if(onChangeListener!=null){
            onChangeListener.fillForum(p);
        }
    }

    @FXML
    void supprimer(ActionEvent event) {
        try {
            serviceProduit.delete(p);
            if(onChangeListener!=null){
                onChangeListener.refreshPrice();
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

    }

}
