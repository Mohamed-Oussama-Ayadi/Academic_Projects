package controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.Label;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import models.Produit;
import models.Utilisateurs;
import org.controlsfx.control.Rating;
import services.OnChangeListener;

import java.io.File;
import java.io.IOException;
import java.sql.SQLException;

public class ProduitCardView {

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

    private Utilisateurs utilisateur; // Attribut pour stocker l'information de l'utilisateur

    public void setUtilisateur(Utilisateurs utilisateur) {
        this.utilisateur = utilisateur;
    }

    @FXML
    void ajouter(ActionEvent event) {
        idProduit = p.getId();
        try {
            // Charger le fichier FXML pour ChooseProductView
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/choose-product-view.fxml"));
            Parent root = loader.load();

            // Configurer les informations de l'utilisateur dans ChooseProductView
            ChooseProductView controller = loader.getController();
            System.out.println("*****2******");
            System.out.println(utilisateur);
            controller.setUserModel(utilisateur); // Passer les détails de l'utilisateur

            // Afficher ChooseProductView
            Scene scene = produitimg.getScene();
            scene.setRoot(root);
        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

}
