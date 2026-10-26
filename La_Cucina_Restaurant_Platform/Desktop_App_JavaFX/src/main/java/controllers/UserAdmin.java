package controllers;

import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.common.PDRectangle;
import org.apache.pdfbox.pdmodel.font.PDType1Font;

import java.awt.Color;

import java.io.File;
import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Date;
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
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
//import javafx.scene.paint.Color;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.Role;
import models.Utilisateurs;
import org.apache.pdfbox.pdmodel.graphics.image.PDImageXObject;
import org.w3c.dom.Text;
import services.ServiceUser;
import javafx.scene.control.Alert.AlertType;
import services.ServiceUserEvent;
import utils.DBConnection;
import javafx.scene.control.ToggleGroup;

public class UserAdmin {
    @FXML
    private Button pdfbtn;

    @FXML
    private ComboBox<Role> RoleC;
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
    private Text textcomplexity;

    @FXML
    private Button UpdateButton;

    @FXML
    private TextField UsernameField;

    @FXML
    private Button HomeBtn;

    @FXML
    private HBox root;

    @FXML
    private AnchorPane side_ankerpane;
    private String imagePath;


    // Initialisation du service utilisateur
    private ServiceUser serviceUser = new ServiceUser();


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

    @FXML
    private ImageView heroImageView1;

    @FXML
    private static ImageView ImageViewAdmin;

    @FXML
    private Label NomPrenomLabel;

    private int userId;


    private Utilisateurs selctedUtilisateur;
    private String username;
    private String password;
    // Initialisation du service utilisateur

    private Connection cnx;
    @FXML
    private TextField searchField;

    List<Utilisateurs> listeUtilisateurs = new ArrayList<>();


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


///////////////////////////////////////////////////////////////////////////////////////////////////////

    @FXML
    void initialize() {
        cnx = DBConnection.getInstance().getCnx();
        RoleC.setOnAction(this::onRoleSelectionChanged);

        // Ajouter un écouteur d'événements au bouton Male
        MaleButton.setOnAction(event -> {
            if (MaleButton.isSelected()) {
                // Désélectionner le bouton Female
                FemaleButton.setSelected(false);
            }
        });

        // Ajouter un écouteur d'événements au bouton Female
        FemaleButton.setOnAction(event -> {
            if (FemaleButton.isSelected()) {
                // Désélectionner le bouton Male
                MaleButton.setSelected(false);
            }
        });


        //configureActionsColumn();
        RoleC.getItems().addAll(Role.ADMIN, Role.CLIENT);


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
                NumberPhoneField.setText(selctedUtilisateur.getNumeroTelephone() + "");
                RoleComboBox.setValue(selctedUtilisateur.getRole());
                try {
                    imagePath = selctedUtilisateur.getImage_user();
                    Image image = new Image(imagePath);
                    ImageViewUser.setImage(image);
                } catch (IllegalArgumentException e) {
                    System.out.println("No Image Found");
                }
                if (this.selctedUtilisateur.getSexe().equalsIgnoreCase("female")) {
                    FemaleButton.setSelected(true);
                    MaleButton.setSelected(false);
                } else {
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


///////////////////////////////////////* Recherche User selon Nom et prenom     *///////////////////////////////////

        // Ajouter un écouteur d'événements au champ de recherche
        searchField.textProperty().addListener((observable, oldValue, newValue) -> {
            try {
                // Vérifier si le champ de recherche est vide
                if (newValue.isEmpty()) {
                    // Si le champ est vide, afficher tous les utilisateurs dans le TableView
                    getListUser();
                } else {
                    // Sinon, filtrer la liste des utilisateurs en fonction du nom et du prénom saisis
                    ObservableList<Utilisateurs> filteredList = FXCollections.observableArrayList();
                    for (Utilisateurs utilisateur : TableViewUser.getItems()) {
                        if (utilisateur.getNom().toLowerCase().contains(newValue.toLowerCase()) ||
                                utilisateur.getPrenom().toLowerCase().contains(newValue.toLowerCase())) {
                            filteredList.add(utilisateur);
                        }
                    }
                    // Mettre à jour le TableView avec la liste filtrée
                    TableViewUser.setItems(filteredList);
                }
            } catch (Exception e) {
                e.printStackTrace();
            }
        });
    }


    public void getListUser() throws SQLException {
        List<Utilisateurs> listUser = serviceUser.selectAll();
        ObservableList<Utilisateurs> observableList = FXCollections.observableList(listUser);
        System.out.println(observableList);
        TableViewUser.setItems(observableList);
    }

    private Utilisateurs createNewUserFromFields() {
        String firstname = FirstnameField.getText();
        String lastname = LastnameField.getText();
        String username = UsernameField.getText();
        String email = EmailField.getText();
        int phoneNumber = Integer.parseInt(NumberPhoneField.getText());
        String password = PasswordField.getText();
        Role role = RoleComboBox.getValue();

        // Créer un nouvel objet Utilisateurs avec les valeurs saisies
        Utilisateurs newUser = new Utilisateurs(firstname, lastname, username, MaleButton.isSelected() ? "Male" : "Female", email, phoneNumber, role, password, imagePath);
        return newUser;
    }

    @FXML
    void insertUser(ActionEvent event) {
        // Valider les saisies avant d'insérer l'utilisateur
        if (!validateInputFields()) {
            return; // Sortir de la méthode si la validation échoue
        }

        // Récupérer les données des champs
        String firstname = FirstnameField.getText();
        String lastname = LastnameField.getText();
        String username = UsernameField.getText();
        String email = EmailField.getText();
        int phoneNumber = Integer.parseInt(NumberPhoneField.getText());
        String password = PasswordField.getText();
        Role role = (Role) RoleComboBox.getValue(); // Récupérer le rôle depuis ComboBox


        // Vérifier si un utilisateur avec ce surnom existe déjà
        try {
            if (serviceUser.userExists(username)) {
                showAlert(AlertType.ERROR, "Erreur", "Utilisateur existant", "Un utilisateur avec ce surnom existe déjà.");
                return;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Erreur", "Erreur de base de données", "Une erreur s'est produite lors de la vérification de l'existence de l'utilisateur.");
            return;
        }
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
            showAlert(AlertType.ERROR, "Erreeur", "Erreur d'insertion", "Une erreur s'est produite lors de l'insertion de l'utilisateur dans la base de données : " + e.getMessage());
        }
    }

    @FXML
    void onUpdate(ActionEvent event) {
        // Valider les saisies avant de mettre à jour l'utilisateur
        if (!validateInputFields()) {
            return; // Sortir de la méthode si la validation échoue
        }

        String firstname = FirstnameField.getText();
        String lastname = LastnameField.getText();
        String username = UsernameField.getText();
        String email = EmailField.getText();
        int phoneNumber = Integer.parseInt(NumberPhoneField.getText());
        String password = PasswordField.getText();
        Role role = (Role) RoleComboBox.getValue();

        // Vérifier si un utilisateur avec ce surnom existe déjà
        try {
            if (serviceUser.userExists(username)) {
                showAlert(AlertType.ERROR, "Erreur", "Utilisateur existant", "Un utilisateur avec ce surnom existe déjà.");
                return;
            }
        } catch (SQLException e) {
            e.printStackTrace();
            showAlert(AlertType.ERROR, "Erreur", "Erreur de base de données", "Une erreur s'est produite lors de la vérification de l'existence de l'utilisateur.");
            return;
        }

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

    private boolean validateInputFields() {
        // Valider chaque champ individuellement
        if (FirstnameField.getText().isEmpty() || LastnameField.getText().isEmpty() ||
                UsernameField.getText().isEmpty() || EmailField.getText().isEmpty() ||
                NumberPhoneField.getText().isEmpty() || PasswordField.getText().isEmpty() ||
                ConfirmPasswordField.getText().isEmpty() || RoleComboBox.getValue() == null) {
            showAlert(Alert.AlertType.ERROR, "Erreur de saisie", "Champs obligatoires", "Tous les champs sont obligatoires.");
            return false;
        }

        // Valider le format du nom et du prénom (seulement des lettres)
        if (!FirstnameField.getText().matches("[a-zA-Z]+") || !LastnameField.getText().matches("[a-zA-Z]+")) {
            showAlert(Alert.AlertType.ERROR, "Erreur de saisie", "Format incorrect", "Le nom et le prénom doivent contenir uniquement des lettres.");
            return false;
        }


        // Valider que le mot de passe et la confirmation correspondent
        if (!PasswordField.getText().equals(ConfirmPasswordField.getText())) {
            showAlert(Alert.AlertType.ERROR, "Erreur de saisie", "Mots de passe différents", "Les mots de passe ne correspondent pas.");
            return false;
        }

        if (!validatePhoneNumber(NumberPhoneField.getText())) {
            showAlert(Alert.AlertType.ERROR, "Erreur de saisie", "Numéro de téléphone invalide", "Le numéro de téléphone doit contenir exactement 8 chiffres.");
            return false;
        }

        // Valider la complexité du mot de passe
        if (!validatePasswordComplexity(PasswordField.getText())) {
            // Afficher un message dans un label pour informer l'utilisateur
            // Remplacez "labelMessage" par le nom réel de votre label
            showAlert(Alert.AlertType.ERROR, "Erreur de saisie", "Mot de Passe invalide", "Le mot de passe doit avoir au moins 8 caractères, une lettre majuscule, un chiffre et un symbole.");
            return false;
        }

        // Valider le format de l'email
        if (!validateEmailFormat(EmailField.getText())) {
            showAlert(Alert.AlertType.ERROR, "Erreur de saisie", "Format d'email incorrect", "Veuillez saisir une adresse e-mail valide.");
            return false;
        }

        // Si toutes les validations passent, retourner true
        return true;
    }


    private boolean validatePhoneNumber(String phoneNumber) {
        // Vérifie si le numéro de téléphone a exactement 8 chiffres
        return phoneNumber.matches("\\d{8}");
    }

    private boolean validatePasswordComplexity(String password) {
        // Vérifie la complexité du mot de passe
        return password.matches("^(?=.*[0-9])(?=.*[a-zA-Z])(?=.*[@#$%^&+=!*/&]).{8,}$");
    }

    private boolean validateEmailFormat(String email) {
        // Vérifie le format de l'email
        return email.matches("^[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,}$");
    }


    /*
    @FXML
    void insertUser(ActionEvent event) {

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
    }*/
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

    void reset() {
        this.selctedUtilisateur = null;
        clearFields();
        CancelButton.setDisable(true);
        UpdateButton.setDisable(true);
        DeleteButton.setDisable(true);
        InsertButton.setDisable(false);
    }

    /*public void OnDelete(ActionEvent actionEvent) throws SQLException {
        if(this.selctedUtilisateur != null)

             serviceUser.delete(this.selctedUtilisateur);
        reset();
        getListUser();
    }*/
    public void OnDelete(ActionEvent actionEvent) throws SQLException {
        if (this.selctedUtilisateur != null) {
            // Supprimer l'utilisateur de la table userevent
            ServiceUserEvent serviceUserEvent = new ServiceUserEvent();
            serviceUserEvent.deleteEventUser(this.selctedUtilisateur.getIdUtilisateur());

            // Supprimer l'utilisateur de la table utilisateurs
            serviceUser.delete(this.selctedUtilisateur);

            // Réinitialiser les champs et rafraîchir la liste des utilisateurs
            reset();
            getListUser();
        }
    }



    /*public void OnUpdate(ActionEvent actionEvent) {
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

*/

    ///////////////////////////////////////////////////////////////////////////////////////////////////////

    @FXML
    public void OnLogoutBtn(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/Login.fxml"));
        Parent root = loader.load();
        Stage stage = (Stage) NumberPhoneField.getScene().getWindow();
        stage.setScene(new Scene(root));
        stage.show();
    }

    public void handleHomeBtn() {
        try {
            URL url = getClass().getResource("/Dashboard.fxml");
            if (url != null) {
                // Charger le fichier FXML de l'interface de mise à jour du profil
                FXMLLoader loader = new FXMLLoader(url);
                Parent root = loader.load();
                // Afficher la fenêtre
                Scene scene = FemaleButton.getScene();
                // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
                scene.setRoot(root);

            } else {
                System.out.println("Le chemin d'accès au fichier FXML est incorrect ou le fichier est introuvable.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }


    public void handleEventManagementBtn() {
        try {
            URL url = getClass().getResource("/EventAdmin.fxml");
            if (url != null) {
                // Charger le fichier FXML de l'interface de mise à jour du profil
                FXMLLoader loader = new FXMLLoader(url);
                Parent root = loader.load();

                // Afficher la fenêtre
                Scene scene = FemaleButton.getScene();
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
    private void onRoleSelectionChanged(ActionEvent event) {
        Role selectedRole = RoleC.getValue();
        if (selectedRole != null) {
            try {
                ServiceUser serviceUser = new ServiceUser();
                List<Utilisateurs> users = serviceUser.selectByRole(selectedRole);
                ObservableList<Utilisateurs> userList = FXCollections.observableArrayList(users);
                TableViewUser.setItems(userList);
            } catch (SQLException e) {
                System.err.println("Erreur lors de la récupération des personnes : " + e.getMessage());
            }
        }


    }
//////////////////////////////*         PDF          *///////////////////////////////////////////////////////////////////
public void generatePDF(List<Utilisateurs> listeUtilisateurs) {
    // Création d'une boîte de dialogue pour choisir l'emplacement de sauvegarde du PDF
    FileChooser fileChooser = new FileChooser();
    fileChooser.setTitle("Enregistrer le PDF");
    fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("Fichiers PDF", "*.pdf"));

    // Afficher la boîte de dialogue et attendre que l'utilisateur sélectionne un emplacement
    File selectedFile = fileChooser.showSaveDialog(new Stage());

    // Vérifier si un fichier a été sélectionné
    if (selectedFile != null) {
        // Utiliser le chemin sélectionné par l'utilisateur pour enregistrer le PDF
        String dest = selectedFile.getAbsolutePath();
        try {
            // Création d'un nouveau document PDF
            PDDocument document = new PDDocument();
            PDPage page = new PDPage(PDRectangle.A4);
            document.addPage(page);
            PDPageContentStream contentStream = new PDPageContentStream(document, page);

            // Définition des propriétés de style
            float margin = 50;
            float yStart = page.getMediaBox().getHeight() - margin;
            float tableWidth = page.getMediaBox().getWidth() - 2 * margin;
            float yPosition = yStart;
            float rowHeight = 20;
            float tableRowHeight = 15;

            // Ajout du titre du document
            contentStream.beginText();
            contentStream.setFont(PDType1Font.HELVETICA_BOLD, 16);
            contentStream.setNonStrokingColor(Color.BLACK);
            contentStream.newLineAtOffset(margin, yPosition);
            contentStream.showText("Liste des Utilisateurs");
            contentStream.endText();
            yPosition -= 20;



            // Ajout de la date actuelle
            Date date = new Date();
            contentStream.beginText();
            contentStream.setFont(PDType1Font.HELVETICA, 12);
            contentStream.setNonStrokingColor(Color.BLACK);
            contentStream.newLineAtOffset(margin, yPosition);
            contentStream.showText("Date: " + date.toString());
            contentStream.endText();
            yPosition -= 20;

            // Dessin des lignes du tableau
            contentStream.moveTo(margin, yPosition);
            contentStream.lineTo(margin + tableWidth, yPosition);
            contentStream.moveTo(margin, yPosition - 20);
            contentStream.lineTo(margin + tableWidth, yPosition - 20);
            contentStream.stroke();
            yPosition -= 20;

            // Création des en-têtes de colonnes
            contentStream.beginText();
            contentStream.setFont(PDType1Font.HELVETICA_BOLD, 10);
            contentStream.setNonStrokingColor(Color.BLACK);
            contentStream.newLineAtOffset(margin, yPosition);
            contentStream.showText("Nom");
            contentStream.newLineAtOffset(60, 0);
            contentStream.showText("Prénom");
            contentStream.newLineAtOffset(60, 0);
            contentStream.showText("Surnom");
            contentStream.newLineAtOffset(60, 0);
            contentStream.showText("Sexe");
            contentStream.newLineAtOffset(50, 0);
            contentStream.showText("Email");
            contentStream.newLineAtOffset(150, 0);
            contentStream.showText("N.Téléphone");
            contentStream.newLineAtOffset(80, 0);
            contentStream.showText("Role");
            contentStream.newLineAtOffset(50, 0);
            contentStream.endText();
            yPosition -= rowHeight;

            // Remplissage du tableau avec les données des utilisateurs
            for (Utilisateurs utilisateur : listeUtilisateurs) {
                contentStream.beginText();
                contentStream.setFont(PDType1Font.HELVETICA, 10);
                contentStream.setNonStrokingColor(Color.BLACK);
                contentStream.newLineAtOffset(margin, yPosition);
                contentStream.showText(utilisateur.getNom());
                contentStream.newLineAtOffset(60, 0);
                contentStream.showText(utilisateur.getPrenom());
                contentStream.newLineAtOffset(60, 0);
                contentStream.showText(utilisateur.getSurnom());
                contentStream.newLineAtOffset(60, 0);
                contentStream.showText(utilisateur.getSexe());
                contentStream.newLineAtOffset(50, 0);
                contentStream.showText(utilisateur.getEmail());
                contentStream.newLineAtOffset(150, 0);
                contentStream.showText(String.valueOf(utilisateur.getNumeroTelephone()));
                contentStream.newLineAtOffset(80, 0);
                contentStream.showText(utilisateur.getRole().toString());
                contentStream.newLineAtOffset(50, 0);
                contentStream.endText();
                yPosition -= tableRowHeight;
            }

            // Fermeture du contenu du document
            contentStream.close();

            // Enregistrement du document
            document.save(dest);
            document.close();

            // Affichage d'une alerte de succès
            Alert alert = new Alert(AlertType.INFORMATION);
            alert.setTitle("Succès");
            alert.setHeaderText(null);
            alert.setContentText("The PDF file was saved successfully !");
            alert.showAndWait();
        } catch (IOException e) {
            e.printStackTrace();
        }
    } else {
        System.out.println("No location selected.");
    }
}
    @FXML
    void handleGeneratePDF(ActionEvent event) {
        // Récupérer la liste des utilisateurs à partir de votre TableView ou de toute autre source de données
        List<Utilisateurs> listeUtilisateurs = TableViewUser.getItems();

        // Appeler la méthode generatePDF pour créer le PDF
        generatePDF(listeUtilisateurs);
    }
////////////////////////////////////////////////////////////////////////////////////////////////
}





