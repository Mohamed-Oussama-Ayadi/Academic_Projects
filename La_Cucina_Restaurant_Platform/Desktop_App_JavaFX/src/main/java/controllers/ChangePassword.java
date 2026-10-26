package controllers;

import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import javafx.scene.image.Image;
import models.Utilisateurs;
import services.ServiceUser;

import javax.swing.text.html.ImageView;
import java.net.URL;
import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.SQLException;
import java.util.ResourceBundle;
import java.util.Optional;

public class ChangePassword {

    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private PasswordField ConfirmPasswordField;

    @FXML
    private PasswordField OldPasswordField;

    @FXML
    private PasswordField PasswordField;

    @FXML
    private Button UpdateButton;

    @FXML
    private Label errorLabel;

    @FXML
    private Label passwordMatchLabel;
    @FXML
    private Label idU;
    @FXML
    private ImageView complexityImageView1;

    private Utilisateurs utilisateur;

    @FXML
    void initialize() {
    }

    public void initData(Utilisateurs utilisateur) {
        this.utilisateur = utilisateur;
    }


}
