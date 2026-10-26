package controllers;

import com.google.zxing.common.BitMatrix;
import javafx.collections.FXCollections;
import javafx.event.ActionEvent;
import javafx.event.Event;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.Button;
import javafx.scene.control.TextField;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.Stage;
import javafx.util.Callback;
import javafx.util.Duration;
import models.Evenements;
import models.Utilisateurs;
import org.controlsfx.control.Notifications;
import services.ServiceEvenements;
import services.ServiceUser;
import javafx.scene.input.MouseEvent;
import services.ServiceUserEvent;
import javafx.scene.media.Media;
import javafx.scene.media.MediaPlayer;
import javafx.scene.media.MediaView;
import java.io.IOException;
import java.net.URL;
import java.sql.SQLException;
import java.util.List;
import java.util.Map;
import java.util.Optional;
import java.util.stream.Collectors;
import javafx.scene.control.Label;
import com.google.zxing.BarcodeFormat;
import com.google.zxing.EncodeHintType;
import com.google.zxing.WriterException;
import com.google.zxing.qrcode.QRCodeWriter;
import com.google.zxing.qrcode.decoder.ErrorCorrectionLevel;
import javafx.embed.swing.SwingFXUtils;

import java.awt.*;
import java.awt.image.BufferedImage;
import java.util.HashMap;

public class EventFront {
    @FXML
    private Label donBtn;

    @FXML
    private Label menuBtn;
    @FXML
    private Button precedentButton;

    @FXML
    private Button suivantButton;
    @FXML
    private Label evenementsLabel;

    @FXML
    private MediaView mediaView;

    @FXML
    private Label idU;
    @FXML
    private Label NomPrenomLabel;
    @FXML
    private Label HomeBtn;
    @FXML
    private TableView<Evenements> tableView;
    @FXML
    private TableColumn<?, ?> typeColumn;

    @FXML
    private TableColumn<?, ?> descriptionColumn;
    @FXML
    private TableColumn<?, ?> prixColumn;
    @FXML
    private ComboBox<String> abonnementComboBox;
    @FXML
    private ComboBox<String> comboBoxImageUser;
    @FXML
    private Button choisirButton;

    private int userId;
    @FXML
    private Pagination EventPagination;
    @FXML
    private Label userNameLabel;
    @FXML
    private Label messLabel;

    @FXML
    private Label messLabel1;
    @FXML
    private ImageView profileImageView;
    @FXML
    private TextField searchTextField;

    private List<Evenements> evenements;
    private final int ABONNEMENTS_PER_PAGE = 6;
    int currentUserId = 0;
    final int ab_PER_PAGE = 6;
    private Utilisateurs utilisateur; // Objet utilisateur

    // Méthode pour définir l'objet utilisateur
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

    public EventFront(){}
    public EventFront(int userId){this.userId=userId;}

    @FXML
    public void initialize() {
        try {
            ServiceEvenements se = new ServiceEvenements();
            evenements = se.selectAll();
            int pageSize = evenements.size() / 6;
            if (evenements.size() % 6 != 0) {
                pageSize++;
            }
            EventPagination.setPageCount(pageSize);
            EventPagination.setPageFactory(this::createPage);
        } catch (SQLException e) {
            System.out.println(e.getMessage());
        }

        // Initialiser la fonctionnalité de recherche
        initializeSearch();

        // Ajout des gestionnaires d'événements pour les nouveaux boutons
        precedentButton.setOnAction(event -> handlePrecedentButtonClick());
        suivantButton.setOnAction(event -> handleSuivantButtonClick());


    }

    private void initializeSearch() {
        // Ajoutez un gestionnaire d'événements pour le TextField de recherche
        searchTextField.textProperty().addListener((observable, oldValue, newValue) -> {
            // Appelez une méthode pour mettre à jour l'affichage en fonction de la recherche
            updatePaginationWithSearch(newValue);
        });
    }

    private void updatePaginationWithSearch(String searchText) {
        // Obtenez la liste des événements filtrés en fonction du texte de recherche
        List<Evenements> filteredEvents = evenements.stream()
                .filter(event -> event.getNom_event().toLowerCase().contains(searchText.toLowerCase()))
                .collect(Collectors.toList());

        // Mettez à jour la pagination avec les événements filtrés
        int pageSize = filteredEvents.size() / ABONNEMENTS_PER_PAGE;
        if (filteredEvents.size() % ABONNEMENTS_PER_PAGE != 0) {
            pageSize++;
        }
        EventPagination.setPageCount(pageSize);
        EventPagination.setPageFactory(pageIndex -> createPageWithSearch(pageIndex, filteredEvents));
    }

    private AnchorPane createPageWithSearch(int pageIndex, List<Evenements> filteredEvents) {
        AnchorPane anchorPane = new AnchorPane();
        anchorPane.setPrefWidth(1400);
        anchorPane.setPrefHeight(200);

        int startIndex = pageIndex * ABONNEMENTS_PER_PAGE;
        int endIndex = Math.min(startIndex + ABONNEMENTS_PER_PAGE, filteredEvents.size());

        int xOffset = 30;
        int yOffset = 30;
        int xIncrement = 380;
        int yIncrement = 250;

        for (int i = startIndex; i < endIndex; i++) {
            Evenements ev = filteredEvents.get(i);

            AnchorPane productPane = new AnchorPane();
            productPane.setLayoutX(xOffset);
            productPane.setLayoutY(yOffset);
            productPane.setPrefSize(320, 220);
            productPane.setStyle(
                    "-fx-background-color: #0F172B;" +
                            "-fx-border-color: #000000;" +
                            "-fx-border-width: 2px;" +
                            "-fx-border-radius: 10px;" +
                            "-fx-background-radius: 10px;");

            Label typeLabel = new Label(ev.getNom_event());
            typeLabel.setLayoutX(10);
            typeLabel.setLayoutY(10);
            typeLabel.setPrefWidth(300);
            typeLabel.setStyle("-fx-text-fill: white; -fx-font-weight: bold;");
            typeLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
            typeLabel.setWrapText(true);
            productPane.getChildren().add(typeLabel);

            Label descriptionLabel = new Label("Description: " + ev.getDescription_event());
            descriptionLabel.setLayoutX(10);
            descriptionLabel.setLayoutY(40);
            descriptionLabel.setPrefWidth(300);
            descriptionLabel.setStyle("-fx-text-fill: white;");
            descriptionLabel.setFont(Font.font("Arial", 12));
            descriptionLabel.setWrapText(true);
            productPane.getChildren().add(descriptionLabel);

            Label dateLabel = new Label("Date de l'événement: " + ev.getDate_event());
            dateLabel.setLayoutX(10);
            dateLabel.setLayoutY(140);
            dateLabel.setPrefWidth(300);
            dateLabel.setStyle("-fx-text-fill: white;");
            dateLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
            productPane.getChildren().add(dateLabel);

            Label heureLabel = new Label("Heure de l'événement: " + ev.getHeure_event());
            heureLabel.setLayoutX(10);
            heureLabel.setLayoutY(160);
            heureLabel.setPrefWidth(300);
            heureLabel.setStyle("-fx-text-fill: white;");
            heureLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
            productPane.getChildren().add(heureLabel);

            Button addButton = new Button("PARTICIPER");
            addButton.setLayoutX(10);
            addButton.setLayoutY(190);
            addButton.setPrefWidth(300);
            addButton.setStyle(
                    "-fx-background-color: #fea116; " +
                            "-fx-text-fill: black; " +
                            "-fx-border-width: 2px; " +
                            "-fx-border-radius: 10px; " +
                            "-fx-background-radius: 10px;");
            productPane.getChildren().add(addButton);

            addButton.setOnAction(event -> ajouterEvent(ev.getNom_event(), utilisateur));

            xOffset += xIncrement;
            if (xOffset + xIncrement > anchorPane.getPrefWidth()) {
                xOffset = 20;
                yOffset += yIncrement;
            }

            anchorPane.getChildren().add(productPane);
        }

        return anchorPane;
    }

    private void handlePrecedentButtonClick() {
        int currentPageIndex = EventPagination.getCurrentPageIndex();
        if (currentPageIndex > 0) {
            EventPagination.setCurrentPageIndex(currentPageIndex - 1);
        }
    }

    private void handleSuivantButtonClick() {
        int currentPageIndex = EventPagination.getCurrentPageIndex();
        if (currentPageIndex < EventPagination.getPageCount() - 1) {
            EventPagination.setCurrentPageIndex(currentPageIndex + 1);
        }
    }
    private Image generateQRCode(String content, int width, int height) {
        try {
            Map<EncodeHintType, ErrorCorrectionLevel> hintMap = new HashMap<>();
            hintMap.put(EncodeHintType.ERROR_CORRECTION, ErrorCorrectionLevel.L);
            QRCodeWriter qrCodeWriter = new QRCodeWriter();
            BitMatrix bitMatrix = qrCodeWriter.encode(content, BarcodeFormat.QR_CODE, width, height, hintMap);
            BufferedImage bufferedImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_RGB);
            for (int x = 0; x < width; x++) {
                for (int y = 0; y < height; y++) {
                    bufferedImage.setRGB(x, y, bitMatrix.get(x, y) ? Color.BLACK.getRGB() : Color.WHITE.getRGB());
                }
            }
            return SwingFXUtils.toFXImage(bufferedImage, null);
        } catch (WriterException e) {
            e.printStackTrace();
            return null;
        }
    }

    private void initializeQRCode(AnchorPane productPane, String content) {
        ImageView qrCodeImageView = new ImageView(generateQRCode(content, 100, 100));
        qrCodeImageView.setLayoutX(250);
        qrCodeImageView.setLayoutY(10);
        productPane.getChildren().add(qrCodeImageView);
    }

    void deleteButtonOnClick() {
        try {
            ServiceUser serviceUser = new ServiceUser();
            Utilisateurs user = serviceUser.selectById(userId); // Récupérer l'utilisateur actuel
            serviceUser.deleteCompte(user); // Supprimer le compte de l'utilisateur actuel

            // Rediriger l'utilisateur vers l'interface de connexion (Login)
            FXMLLoader loginLoader = new FXMLLoader(getClass().getResource("/Login.fxml"));
            Parent loginRoot = loginLoader.load();
            Scene loginScene = new Scene(loginRoot);
            Stage loginStage = new Stage();
            loginStage.setScene(loginScene);
            loginStage.show();

            // Fermer l'interface Home
            Stage stage = (Stage) profileImageView.getScene().getWindow();
            stage.close();

        } catch (SQLException | IOException e) {
            e.printStackTrace();
            // Gérer l'exception
        }
    }

    private void ajouterEvent(String NomEvenement, Utilisateurs user) {
        // Utilisez user.getId() pour obtenir l'ID de l'utilisateur
        int userId = user.getIdUtilisateur();
        try {
            ServiceEvenements serviceEv = new  ServiceEvenements();
            Evenements evenementChoisi = serviceEv.selectEvenementByNom(NomEvenement);
            if (evenementChoisi != null) {
                if (serviceEv.userInEvent(user, evenementChoisi)) {
                    messLabel1.setText("");
                    messLabel.setText("The user already has this subscription");
                    showNotification("Subscription Information", "The user already has this subscription");
                } else {
                    serviceEv.inscrireUser(evenementChoisi, user);
                    messLabel.setText("");
                    messLabel1.setText("You chose : " + evenementChoisi.getNom_event());
                    showNotification("Subscription Information", "You chose : " + evenementChoisi.getNom_event());
                }
            } else {
                messLabel.setText("Abonnement non trouvé avec le type : " + NomEvenement);
                showNotification("Subscription Information", "Subscription not found with type: " + NomEvenement);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            showNotification("Error", "An error occurred while processing your request");
        }
    }

    public void showNotification(String title, String message) {
        Notifications.create()
                .title(title)
                .text(message)
                .hideAfter(Duration.seconds(5)) // Set the duration for how long the notification should be shown
                .show();
    }

    private AnchorPane createPage(int pageIndex) {
        AnchorPane anchorPane = new AnchorPane();
        anchorPane.setPrefWidth(1400);
        anchorPane.setPrefHeight(200);

        int startIndex = pageIndex * ABONNEMENTS_PER_PAGE;
        int endIndex = Math.min(startIndex + ABONNEMENTS_PER_PAGE, evenements.size());

        int xOffset = 30;
        int yOffset = 30;
        int xIncrement = 380;
        int yIncrement = 250;

        for (int i = startIndex; i < endIndex; i++) {
            Evenements ev = evenements.get(i);

            AnchorPane productPane = new AnchorPane();
            productPane.setLayoutX(xOffset);
            productPane.setLayoutY(yOffset);
            productPane.setPrefSize(320, 220);
            productPane.setStyle(
                    "-fx-background-color: #0F172B;" +
                            "-fx-border-color: #000000;" +
                            "-fx-border-width: 2px;" +
                            "-fx-border-radius: 10px;" +
                            "-fx-background-radius: 10px;");

            Label typeLabel = new Label(ev.getNom_event());
            typeLabel.setLayoutX(10);
            typeLabel.setLayoutY(10);
            typeLabel.setPrefWidth(300);
            typeLabel.setStyle("-fx-text-fill: white; -fx-font-weight: bold;");
            typeLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
            typeLabel.setWrapText(true);
            productPane.getChildren().add(typeLabel);


            Label descriptionLabel = new Label("Description: " + ev.getDescription_event());
            descriptionLabel.setLayoutX(10);
            descriptionLabel.setLayoutY(40);
            descriptionLabel.setPrefWidth(300);
            descriptionLabel.setStyle("-fx-text-fill: white;");
            descriptionLabel.setFont(Font.font("Arial", 12));
            descriptionLabel.setWrapText(true);
            productPane.getChildren().add(descriptionLabel);

            Label dateLabel = new Label("Date de l'événement: " + ev.getDate_event());
            dateLabel.setLayoutX(10);
            dateLabel.setLayoutY(140);
            dateLabel.setPrefWidth(300);
            dateLabel.setStyle("-fx-text-fill: white;");
            dateLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
            productPane.getChildren().add(dateLabel);

            Label heureLabel = new Label("Heure de l'événement: " + ev.getHeure_event());
            heureLabel.setLayoutX(10);
            heureLabel.setLayoutY(160);
            heureLabel.setPrefWidth(300);
            heureLabel.setStyle("-fx-text-fill: white;");
            heureLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
            productPane.getChildren().add(heureLabel);

            // Generate QR code image
            Image qrCodeImage = generateQRCode(ev.getNom_event(), 100, 100);
            ImageView qrCodeImageView = new ImageView(qrCodeImage);
            qrCodeImageView.setLayoutX(220);
            qrCodeImageView.setLayoutY(80);
            productPane.getChildren().add(qrCodeImageView);

            Button addButton = new Button("PARTICIPER");
            addButton.setLayoutX(10);
            addButton.setLayoutY(190);
            addButton.setPrefWidth(300);
            addButton.setStyle(
                    "-fx-background-color: #fea116; " +
                            "-fx-text-fill: black; " +
                            "-fx-border-width: 2px; " +
                            "-fx-border-radius: 10px; " +
                            "-fx-background-radius: 10px;");
            productPane.getChildren().add(addButton);

            addButton.setOnAction(event -> ajouterEvent(ev.getNom_event(), utilisateur));

            xOffset += xIncrement;
            if (xOffset + xIncrement > anchorPane.getPrefWidth()) {
                xOffset = 20;
                yOffset += yIncrement;
            }

            anchorPane.getChildren().add(productPane);
        }

        return anchorPane;
    }

    @FXML
    public void setId(int id) {
        userId = id;
        idU.setText(Integer.toString(id));

        try {
            ServiceUser serviceUser = new ServiceUser();
            Utilisateurs user = serviceUser.selectById(id); // Récupérer l'utilisateur à partir de l'ID
            if (user != null) {
                setUserName(user.getNom() + " " + user.getPrenom());
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    public void setUserName(String userName) {
        this.NomPrenomLabel.setText(userName);
    }

    ////////////////////////////////////* Aller de Events vers Home *//////////////////////////////////////////
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
            Stage stage = (Stage) HomeBtn.getScene().getWindow();
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

    ///////////////////////////////////////////////////////////////////////////////////////////////////

    @FXML
    private void showUpdateUserFront(Utilisateurs utilisateur) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/UpdateUserFront.fxml"));
            Parent parent = loader.load();

            // Accéder au contrôleur de la nouvelle fenêtre
            UpdateUserFront controller = loader.getController();
            controller.initData(utilisateur); // Passer l'utilisateur au contrôleur de la page UpdateUserFront.fxml

            // Créer une nouvelle scène
            Scene scene = new Scene(parent);

            // Obtenir la scène à partir de n'importe quel nœud
            Stage stage = (Stage) messLabel.getScene().getWindow();

            // Configurer la nouvelle scène
            stage.setScene(scene);
            stage.setTitle("Update User Profile"); // Définir le titre de la fenêtre
            stage.show(); // Afficher la nouvelle fenêtre

        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }

    public void OnCalendrier(ActionEvent actionEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Calendrier.fxml"));
            Parent root = loader.load();
            Scene scene = new Scene(root);
            Stage stage = new Stage();
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
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
    }

    public void goTodon(MouseEvent mouseEvent) {
        try {
            // Charger le fichier FXML de votre nouvelle interface
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/donationFront.fxml"));
            Parent root = loader.load();

            donationfront eventController = loader.getController();
            eventController.setId1(utilisateur);
            Scene scene = profileImageView.getScene();
            scene.setRoot(root);

        } catch (Exception e) {
            // e.printStackTrace();
            // Gérer toute exception lors du chargement de la nouvelle interface
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
