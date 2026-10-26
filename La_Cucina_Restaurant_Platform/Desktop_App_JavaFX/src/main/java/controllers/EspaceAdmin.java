package controllers;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.List;
import java.util.ResourceBundle;

import javafx.beans.property.SimpleStringProperty;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Role;
import models.Utilisateurs;
import services.ServiceUser;
import javafx.scene.control.Alert.AlertType;

public class EspaceAdmin {
    @FXML
    public Button CancelButton;
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;

    @FXML
    private PasswordField ConfirmPasswordField;

    @FXML
    private Button DeleteButton;

    @FXML
    private TextField EmailField;

    @FXML
    private RadioButton FemaleButton;

    @FXML
    private TextField FirstnameField;

    @FXML
    private ImageView ImageViewUser;

    @FXML
    private Button InsertButton;

    @FXML
    private TextField LastnameField;

    @FXML
    private RadioButton MaleButton;

    @FXML
    private TextField NumberPhoneField;

    @FXML
    private PasswordField PasswordField;

    @FXML
    private ComboBox<Role> RoleComboBox;

    @FXML
    private Button SelectImageButton;


    @FXML
    private Button UpdateButton;

    @FXML
    private TextField UsernameField;
    private String imagePath;

    @FXML
    private TableView<Utilisateurs> TableViewUser;

    @FXML
    private TableColumn<Utilisateurs, String> PhoneNumberColumn;

    @FXML
    private TableColumn<Utilisateurs, String> LastnameColumn;

    @FXML
    private TableColumn<Utilisateurs, String> RoleColumn;

    @FXML
    private TableColumn<Utilisateurs, String> PasswordColumn;

    @FXML
    private TableColumn<Utilisateurs, String> UsernameColumn;

    @FXML
    private TableColumn<Utilisateurs, String> GenreColumn;

    @FXML
    private TableColumn<Utilisateurs, String> ImageColumn;

    @FXML
    private TableColumn<Utilisateurs, String> EmailColumn;

    @FXML
    private TableColumn<Utilisateurs, String> FirstnameColumn;
    ServiceUser serviceUser = new ServiceUser();

    private Utilisateurs selctedUtilisateur;



    @FXML
    public void selectImage() {
        FileChooser fileChooser = new FileChooser();
        fileChooser.setTitle("Sélectionner une image");

        // Filtrer les fichiers pour n'afficher que les images
        fileChooser.getExtensionFilters().addAll(
                new FileChooser.ExtensionFilter("Images", "*.png", "*.jpg", "*.gif")
        );

        // Afficher la boîte de dialogue de sélection de fichier
        File selectedFile = fileChooser.showOpenDialog(null);

        // Vérifier si un fichier a été sélectionné
        if (selectedFile != null) {
            // Récupérer le chemin d'accès à l'image sélectionnée
            imagePath = selectedFile.toURI().toString();

            // Charger l'image dans l'ImageView
            Image image = new Image(imagePath);
            ImageViewUser.setImage(image);
        }
    }



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void initialize() {
        assert ConfirmPasswordField != null : "fx:id=\"ConfirmPasswordField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert DeleteButton != null : "fx:id=\"DeleteButton\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert EmailColumn != null : "fx:id=\"EmailColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert EmailField != null : "fx:id=\"EmailField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert FemaleButton != null : "fx:id=\"FemaleButton\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert FirstnameColumn != null : "fx:id=\"FirstnameColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert FirstnameField != null : "fx:id=\"FirstnameField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert GenreColumn != null : "fx:id=\"GenreColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert ImageColumn != null : "fx:id=\"ImageColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert ImageViewUser != null : "fx:id=\"ImageViewUser\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert InsertButton != null : "fx:id=\"InsertButton\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert LastnameColumn != null : "fx:id=\"LastnameColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert LastnameField != null : "fx:id=\"LastnameField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert MaleButton != null : "fx:id=\"MaleButton\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert NumberPhoneField != null : "fx:id=\"NumberPhoneField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert PasswordColumn != null : "fx:id=\"PasswordColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert PasswordField != null : "fx:id=\"PasswordField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert PhoneNumberColumn != null : "fx:id=\"PhoneNumberColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert RoleColumn != null : "fx:id=\"RoleColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert RoleComboBox != null : "fx:id=\"RoleComboBox\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert SelectImageButton != null : "fx:id=\"SelectImageButton\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert TableViewUser != null : "fx:id=\"TableViewUser\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert UpdateButton != null : "fx:id=\"UpdateButton\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert UsernameColumn != null : "fx:id=\"UsernameColumn\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";
        assert UsernameField != null : "fx:id=\"UsernameField\" was not injected: check your FXML file 'EspaceAdmin.fxml'.";

        CancelButton.setDisable(true);
        UpdateButton.setDisable(true);
        DeleteButton.setDisable(true);

        LastnameColumn.setCellValueFactory(cell -> new SimpleStringProperty(cell.getValue().getNom()));
        FirstnameColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getPrenom()));
        PhoneNumberColumn.setCellValueFactory(data -> new SimpleStringProperty(String.valueOf(data.getValue().getNumeroTelephone())));
        RoleColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getRole().toString()));
        PasswordColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getMotDePasse()));
        UsernameColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getSurnom()));
        GenreColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getSexe()));
        EmailColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getEmail().toLowerCase()));
        ImageColumn.setCellValueFactory(data -> new SimpleStringProperty(data.getValue().getImage_user()));

        TableViewUser.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        TableViewUser.getSelectionModel().selectedItemProperty().addListener((obs, oldSelection, newSelection) -> {
            if (newSelection != null) {
                this.selctedUtilisateur = newSelection;
                CancelButton.setDisable(false);
                UpdateButton.setDisable(false);
                DeleteButton.setDisable(false);
                InsertButton.setDisable(true);
                FirstnameField.setText(selctedUtilisateur.getPrenom());
                LastnameField.setText(selctedUtilisateur.getNom());
                UsernameField.setText(selctedUtilisateur.getSurnom());
                EmailField.setText(selctedUtilisateur.getEmail());
                NumberPhoneField.setText(selctedUtilisateur.getNumeroTelephone()+"");
                RoleComboBox.setValue(selctedUtilisateur.getRole());
                try {
                    imagePath = selctedUtilisateur.getImage_user();
                    Image image = new Image(imagePath);
                    ImageViewUser.setImage(image);
                }catch(IllegalArgumentException e){
                    System.out.println("No Image Found");
                }
                if(this.selctedUtilisateur.getSexe().equalsIgnoreCase("female")){
                    FemaleButton.setSelected(true);
                    MaleButton.setSelected(false);
                }else {
                    FemaleButton.setSelected(false);
                    MaleButton.setSelected(true);
                }
            }
        });
        // Initialiser le ComboBox avec les valeurs de l'énumération Role
        RoleComboBox.getItems().addAll(Role.values());
        try {
            getListUser();
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }
    }

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    public void getListUser() throws SQLException {
        List<Utilisateurs> listUser = serviceUser.selectAll();
        ObservableList<Utilisateurs> observableList = FXCollections.observableList(listUser);
        System.out.println(observableList);
        TableViewUser.setItems(observableList);
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    @FXML
    void insertUser(ActionEvent event) {

        /*if(FirstnameField.getText().length()<=5
                || FirstnameField.getText().toLowerCase().contains("admin")
                || UsernameField.getText().isEmpty()
                || EmailField.getText().isEmpty()
                || NumberPhoneField.getText().isEmpty()
                || PasswordField.getText().length()<=6
                || RoleComboBox.getValue().toString().isEmpty()

        {
            showAlert(AlertType.ERROR, "Erreur", "Erreur de saissie", "Check Fields please");
        }
 )*/
        // Récupérer les données des champs
        String firstname = FirstnameField.getText();
        String lastname = LastnameField.getText();
        String username = UsernameField.getText();
        String email = EmailField.getText();
        int phoneNumber = Integer.parseInt(NumberPhoneField.getText());
        String password = PasswordField.getText();
        Role role = (Role) RoleComboBox.getValue(); // Récupérer le rôle depuis ComboBox

        // Créer un nouvel utilisateur
        Utilisateurs newUser = new Utilisateurs(firstname, lastname, username, MaleButton.isSelected() ? "Male" : "Female", email, phoneNumber, role,
                password, imagePath); // Ajouter le chemin de l'image

        // Insérer l'utilisateur dans la base de données ou tout autre traitement nécessaire
        // Créer une instance du service utilisateur

        try {
            // Appeler la méthode d'insertion dans la base de données
            serviceUser.insertOne1(newUser);

            // Afficher une alerte de succès
            showAlert(AlertType.INFORMATION, "Succès", "Insertion réussie", "L'utilisateur a été inséré avec succès dans la base de données.");


            // Effacer les champs après l'insertion
        clearFields();
            getListUser();
        } catch (SQLException e) {
            e.printStackTrace();
            // Gérer l'exception, par exemple, afficher un message d'erreur à l'utilisateur
            // Afficher une alerte d'erreur
            showAlert(AlertType.ERROR, "Erreur", "Erreur d'insertion", "Une erreur s'est produite lors de l'insertion de l'utilisateur dans la base de données : " + e.getMessage());
        }
    }
    // Méthode pour effacer les champs de saisie
    private void clearFields() {
        FirstnameField.clear();
        LastnameField.clear();
        UsernameField.clear();
        EmailField.clear();
        NumberPhoneField.clear();
        PasswordField.clear();
        ConfirmPasswordField.clear();
        // Effacer l'image de ImageView
        ImageViewUser.setImage(null);
    }

    // Méthode pour afficher une alerte
    private void showAlert(AlertType alertType, String title, String headerText, String contentText) {
        Alert alert = new Alert(alertType);
        alert.setTitle(title);
        alert.setHeaderText(headerText);
        alert.setContentText(contentText);
        alert.showAndWait();
    }


    public void OnCancel(ActionEvent actionEvent) {
        reset();
    }
    void reset(){
        this.selctedUtilisateur = null;
        clearFields();
        CancelButton.setDisable(true);
        UpdateButton.setDisable(true);
        DeleteButton.setDisable(true);
        InsertButton.setDisable(false);
    }

    public void OnDelete(ActionEvent actionEvent) throws SQLException {
        if(this.selctedUtilisateur != null)
            serviceUser.delete(this.selctedUtilisateur);
        reset();
        getListUser();
    }

    public void OnUpdate(ActionEvent actionEvent) {
        if(FirstnameField.getText().length()<=5
                || FirstnameField.getText().toLowerCase().contains("admin")
                || UsernameField.getText().isEmpty()
                || EmailField.getText().isEmpty()
                || NumberPhoneField.getText().isEmpty()
                || PasswordField.getText().length()<=6
                || RoleComboBox.getValue().toString().isEmpty()
        )
        {
            showAlert(AlertType.ERROR, "Erreur", "Erreur de saissie", "Check Fields please");
        }

        String firstname = FirstnameField.getText();
        String lastname = LastnameField.getText();
        String username = UsernameField.getText();
        String email = EmailField.getText();
        int phoneNumber = Integer.parseInt(NumberPhoneField.getText());
        String password = PasswordField.getText();
        Role role = (Role) RoleComboBox.getValue();
        Utilisateurs newUser = new Utilisateurs(firstname, lastname, username, MaleButton.isSelected() ? "Male" : "Female", email, phoneNumber, role,
                password, imagePath);
        newUser.setIdUtilisateur(this.selctedUtilisateur.getIdUtilisateur());
        try {
            serviceUser.update(newUser);
            showAlert(AlertType.INFORMATION, "Succès", "Update réussie", "L'utilisateur a été modifier avec succès dans la base de données.");
            clearFields();
            getListUser();
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Erreur", "Erreur d'insertion", "Une erreur s'est produite lors de la modification de l'utilisateur dans la base de données : " + e.getMessage());
        }
    }
    @FXML
    public void OnLogoutBtn(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/Login.fxml"));
        Parent root = loader.load();
        Stage stage = (Stage) CancelButton.getScene().getWindow();
        stage.setScene(new Scene(root));
        stage.show();
    }
}
