package controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.web.WebEngine;
import javafx.scene.web.WebView;
import javafx.stage.Stage;
import models.Utilisateurs;
import services.Payment;
import services.ServiceUser;
import services.serviceDonation;
import javafx.application.HostServices;
import javafx.scene.layout.StackPane;

import java.io.IOException;
import java.sql.SQLException;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
public class donationfront {
    @FXML
    private DatePicker tfdate;

    @FXML
    private TextField tfmontant;
    @FXML
    private MediaView mediaView;
    @FXML
    private ChoiceBox<String> tftype;
    @FXML
    private Label idU;
    @FXML
    private Label NomPrenomLabel;
    private String[] dontype = {"Bank Transfers",
            "Bank Redirect"
            , "Buy now, pay later"
            , "Cards"
            , " Real-time payments"
            , "Wallets"
            , "   Cash-based voucher"
            , " Bank Debits"};
    @FXML
    private ComboBox<?> comboBoxImageUser;

    @FXML
    private ImageView complexityImageView;

    @FXML
    private Label errorLabel;


    @FXML
    private Label passwordMatchLabel;

    @FXML
    private ImageView profileImageView;
    @FXML
    private Label usernameStatusLabel;
    WebView webView = new WebView();
    WebEngine webEngine = webView.getEngine();

    @FXML
    void initialize() {
        assert NomPrenomLabel != null : "fx:id=\"NomPrenomLabel\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert comboBoxImageUser != null : "fx:id=\"comboBoxImageUser\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert complexityImageView != null : "fx:id=\"complexityImageView\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert errorLabel != null : "fx:id=\"errorLabel\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert idU != null : "fx:id=\"idU\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert passwordMatchLabel != null : "fx:id=\"passwordMatchLabel\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert profileImageView != null : "fx:id=\"profileImageView\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert tfdate != null : "fx:id=\"tfdate\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert tfmontant != null : "fx:id=\"tfmontant\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert tftype != null : "fx:id=\"tftype\" was not injected: check your FXML file 'donationfront.fxml'.";
        assert usernameStatusLabel != null : "fx:id=\"usernameStatusLabel\" was not injected: check your FXML file 'donationfront.fxml'.";
        tftype.getItems().addAll((dontype));


       /* // Ajoutez ces lignes pour charger la vidéo locale
        String videoPath = "/C:\\Users\\moham\\Videos\\La_Cucina_Projet_Pidev (2)\\La_Cucina_Projet_Pidev (1)\\La_Cucina_Projet_Pidev\\src\\main\\resources\\Images\\restaurant_arrierePlan.mp4"; // Remplacez par le chemin de votre vidéo
        Media media = new Media(videoPath);
        MediaPlayer mediaPlayer = new MediaPlayer(media);

        // Configurer le MediaView pour afficher la vidéo
        mediaView.setMediaPlayer(mediaPlayer);

        // Jouer la vidéo
        mediaPlayer.play();
    */
    }


    //tftype.getItems().addAll((dontype));
    private Utilisateurs utilisateur; // Objet utilisateur

    @FXML
    public void setId1(Utilisateurs utilisateur) throws SQLException {
        this.utilisateur = utilisateur;

        // Utilisez l'utilisateur chargé pour initialiser votre interface utilisateur
        if (utilisateur != null) {
            System.out.println("trouve");
            NomPrenomLabel.setText(utilisateur.getNom() + " " + utilisateur.getPrenom());
        } else {
            System.out.println("Utilisateur non trouvé avec l'ID : " + userId);
        }
    }

    public void setUserName(String userName) {
        this.NomPrenomLabel.setText(userName);
    }

    private int userId;

    public void ajouterDonation(ActionEvent event) {
        try {
            models.Donation r = new models.Donation(Float.parseFloat(tfmontant.getText()), tfdate.getValue(), tftype.getValue(), utilisateur.getIdUtilisateur());
            serviceDonation sp = new serviceDonation();
            sp.insertOne(r);

            Payment p = new Payment();
            long priceLong = (long) (Float.parseFloat(tfmontant.getText()) * 0.32) * 100;
            p.processPayment(priceLong, tftype.getValue());
            webEngine.load("https://dashboard.stripe.com/test/payments");
            StackPane root = new StackPane();
            root.getChildren().addAll(webView);

            // Create a Scene and add the StackPane to it
            Scene scene = new Scene(root, 800, 600);
            Stage primaryStage = new Stage();
            // Set the Scene to the Stage
            primaryStage.setScene(scene);
            primaryStage.setTitle("Load Web Page on Button Click");
            primaryStage.show();
        } catch (SQLException e) {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("erreur");
            alert.show();
        } catch (NumberFormatException e) {

            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("erreur");
            alert.show();
        }
    }


    private void redirectToHome() {
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
            Stage stage = (Stage) profileImageView.getScene().getWindow();
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    @FXML
    private void handleHomeBtnClick(MouseEvent event) {
        // Récupérer l'ID de l'utilisateur à partir du label idU ou de tout autre composant nécessaire

        // Appeler redirectToHome() avec l'ID de l'utilisateur
        redirectToHome();
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
    }


    @FXML
    void redirectToreclam(MouseEvent event) {

        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/AjouterReclamation.fxml"));
            Parent root = loader.load();

            AjouterReclamation controller = loader.getController();

            controller.setId1(utilisateur);

            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
