/**
 * Sample Skeleton for 'AjouterReclamation.fxml' Controller Class
 */

package controllers;

;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.net.URL;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.fxml.FXMLLoader;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.BarChart;
import javafx.scene.chart.CategoryAxis;
import javafx.scene.chart.NumberAxis;
import javafx.scene.chart.XYChart;
import javafx.scene.control.*;

import java.sql.*;
import java.util.*;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.FlowPane;
import javafx.scene.layout.Pane;
import javafx.scene.layout.VBox;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import models.GeneratePdf;
import models.Reclamation;
import models.Utilisateurs;
import services.ServiceUser;
import services.serviceReclamation;
import utils.DBConnection;

import javax.mail.*;
import javax.mail.internet.AddressException;
import javax.mail.internet.InternetAddress;
import javax.mail.internet.MimeMessage;

public class AjouterReclamation {

    @FXML
    private Label donationBtn;

    @FXML
    private Label homeBtn;
    @FXML
    private Label Eventsbtn;
    @FXML
    private Label menuBtn;
    @FXML
    private ChoiceBox<Integer> tfchoice;
    @FXML
    private TableColumn<Reclamation, Integer> idcomcol;
    @FXML
    private Button savebutton;
    @FXML
    private Button pdfbtn;
    @FXML
    private Button btnPrint ;

    @FXML // ResourceBundle that was given to the FXMLLoader
    private ResourceBundle resources;

    @FXML // URL location of the FXML file that was given to the FXMLLoader
    private URL location;


    @FXML
    private DatePicker tfdate;

    @FXML // fx:id="tfdescription"
    private TextField tfdescription; // Value injected by FXMLLoader

    @FXML // fx:id="tfemail"
    private TextField tfemail; // Value injected by FXMLLoader
    @FXML
    private TableColumn<Reclamation, String> Emailcol;

    @FXML
    private TableColumn<Reclamation, Integer> Idreclamationcol;

    @FXML
    private TableView<Reclamation> ReclamationListId;
    private ChoiceBox<String> choiceBox;

    private boolean isChoiceBoxDisplayed = false;
    @FXML
    private ImageView profileImageView;
    @FXML
    private TableColumn<Reclamation, String> datecol;
    @FXML
    private TableColumn<?, ?> etatcol;
    @FXML
    private TableColumn<Reclamation, String> descriptioncol;
    private Connection cnx;
    private PreparedStatement pre;

    @FXML
    private FlowPane reccontainertf;
    private int selectedRecId;
    private  int userId;

    @FXML
    private Label NomPrenomLabel;
    CategoryAxis xAxis = new CategoryAxis();
    NumberAxis yAxis = new NumberAxis();
    int k=0;
    private Utilisateurs utilisateur; // Objet utilisateur
    public AjouterReclamation() {
        cnx= DBConnection.getInstance().getCnx();
    }

    private List<Integer> getCommandeIDsFromDatabase() throws SQLException {
        List<Integer> commandeIDs = new ArrayList<>();

        // Connexion à la base de données (assurez-vous d'avoir le pilote JDBC approprié)
        try  {
            Statement statement = cnx.createStatement();
            ResultSet resultSet = statement.executeQuery("SELECT id_commande FROM commandes ");

            // Récupération des ID des commandes et les ajouter à la liste
            while (resultSet.next()) {
                int id = resultSet.getInt("id_commande");
                commandeIDs.add(id);
            }
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }

        return commandeIDs;
    }




    public void setUserName(String userName) {
        this.NomPrenomLabel.setText(userName);
    }
    private void initializeData() throws SQLException {
        // Ensure userId is set before initializing data
        if (utilisateur.getIdUtilisateur() != 0) {
            ObservableList<Reclamation> rec = getRec();
            AfficherReclamation1(rec);
        } else {
            System.out.println("User ID is not set.");
        }
    }

    @FXML
    void ajouterReclamation() throws SQLException {

        if (tfdate.getValue()==null  )
        {
            Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
            alert.setTitle("Alert!");
            alert.setContentText("This is an alert");
            Optional<ButtonType> result = alert.showAndWait();

        }else if (tfdescription.getText().isEmpty())
        {
            Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
            alert.setTitle("Alert!");
            alert.setContentText("This is an alert");
            Optional<ButtonType> result = alert.showAndWait();

        }

        else {
            try
            {

                Reclamation r = new Reclamation(tfemail.getText(),tfdescription.getText(),tfdate.getValue(),tfchoice.getValue(),utilisateur.getIdUtilisateur());
                serviceReclamation sp = new serviceReclamation();
                sp.insertOne(r);
                new GMailer().sendMail("A new message", """
                Dear reader,
                                
                Hello world.
                                
                Best regards,
                myself
                """);

            }
            catch (NumberFormatException e)
            {

                Alert alert = new Alert(Alert.AlertType.ERROR);
                alert.setTitle("erreur");
                alert.show();
            } catch (Exception e) {
                throw new RuntimeException(e);
            }
            reccontainertf.getChildren().clear();
            initializeData();
            ObservableList<Reclamation> rec = getRec();
          AfficherReclamation1(rec);
        }


    }



   public ObservableList<Reclamation> getRec() {
       ObservableList<Reclamation> Reclamations = FXCollections.observableArrayList();

       System.out.println(utilisateur.getIdUtilisateur());
       String query = "SELECT * FROM Reclamation where idUtilisateur = ?";

       try {
           cnx = DBConnection.getInstance().getCnx();

           pre = cnx.prepareStatement(query);
           pre.setInt(1, utilisateur.getIdUtilisateur());

           ResultSet rs = pre.executeQuery();



           while (rs.next()) {

               Reclamation rec=new Reclamation();
               rec.setId(rs.getInt("id_reclamation"));
               rec.setDate(rs.getDate("date").toLocalDate());
               rec.setEmail(rs.getString("email"));
               rec.setDescription(rs.getString("description"));
               rec.setEtat(rs.getString("etat"));
               rec.setId_cm(rs.getInt("id_commande"));
               rec.setIdUtilisateur(rs.getInt("idUtilisateur"));
               Reclamations.add(rec);
           }
       } catch (SQLException e) {
           throw new RuntimeException("Erreur lors de la récupération des musées.", e);
       }

       return Reclamations;
   }
    @FXML
    private Pagination EventPagination;
    @FXML // This method is called by the FXMLLoader when initialization is complete
    void initialize() throws SQLException {

        // Ajouter un événement de clic à l'image de profil
        profileImageView.setOnMouseClicked(event -> {
            if (isChoiceBoxDisplayed) {
                // Si le ChoiceBox est déjà affiché, le supprimer du conteneur parent
                ((Pane) profileImageView.getParent()).getChildren().remove(choiceBox);
                isChoiceBoxDisplayed = false;
            } else {
                showOptions(event);
            }
        });
// Ajouter un écouteur d'événements à la scène pour détecter les clics en dehors de l'image de profil
        profileImageView.sceneProperty().addListener((observable, oldScene, newScene) -> {
            if (newScene != null) {
                newScene.setOnMouseClicked(event -> {
                    if (isChoiceBoxDisplayed && !profileImageView.getBoundsInParent().contains(event.getX(), event.getY())) {
                        // Si le ChoiceBox est affiché et que le clic n'est pas dans la zone de l'image de profil, le supprimer
                        ((Pane) profileImageView.getParent()).getChildren().remove(choiceBox);
                        isChoiceBoxDisplayed = false;
                    }
                });
            }
        });


    }

    // Méthode pour afficher les options lorsque l'utilisateur clique sur l'image de profil
    @FXML
    private void showOptions(MouseEvent event) {
        // Créer un ChoiceBox avec des options
        choiceBox = new ChoiceBox<>();
        choiceBox.getItems().addAll("Update Profile","Logout","Delete");


        // Obtenir la source de l'événement (dans votre cas, l'ImageView)
        ImageView imageView = (ImageView) event.getSource();

        // Après avoir ajouté le ComboBox à la scène

        choiceBox.setPrefWidth(42);
        choiceBox.setPrefHeight(26);

        // Convertir les coordonnées locales de l'image en coordonnées de la scène
        double sceneX = imageView.localToScene(event.getX(), event.getY()).getX();
        double sceneY = imageView.localToScene(event.getX(), event.getY()).getY();

        // Positionner le ChoiceBox à côté de l'image de profil
        choiceBox.setLayoutX(sceneX);
        choiceBox.setLayoutY(sceneY);

        // Ajouter un événement de sélection à choix
        choiceBox.setOnAction(e -> {
            String selectedOption = choiceBox.getValue();
            // Vérifier l'option sélectionnée et rediriger l'utilisateur en conséquence
            if (selectedOption != null) {
                switch (selectedOption) {
                    case "Update Profile":
                        //   showUpdateUserFront();
                        if (utilisateur != null) {
                            showUpdateUserFront(utilisateur);
                            System.out.println("envoieupdate");
                        } else {
                            System.out.println("Erreur : L'utilisateur est null. Impossible d'ouvrir la page de mise à jour du profil.");
                        }
                        break;
                    case "Logout":
                        // Déconnecter l'utilisateur et rediriger vers l'interface de connexion
                        FXMLLoader loginLoader = new FXMLLoader(getClass().getResource("/Login.fxml"));
                        Parent loginRoot;
                        try {
                            loginRoot = loginLoader.load();
                            // Spécifiez les dimensions souhaitées pour la scène Login
                            Scene loginScene = new Scene(loginRoot, 998, 649); // Ajustez les dimensions selon vos besoins
                            Stage loginStage = new Stage();
                            loginStage.setScene(loginScene);
                            loginStage.show();

                            // Fermez la scène actuelle de l'interface Home
                            Stage homeStage = (Stage) profileImageView.getScene().getWindow();
                            homeStage.close();
                        } catch (IOException ex) {
                            ex.printStackTrace();
                        }
                        break;

                    case "Delete":
                        deleteButtonOnClick();

                        break;



                    default:
                        break;
                }
            }
        });

        // Ajouter le ChoiceBox à la scène
        ((Pane) imageView.getParent()).getChildren().add(choiceBox);
        isChoiceBoxDisplayed = true;
    }
    void deleteButtonOnClick() {
        try {
            ServiceUser serviceUser = new ServiceUser();
            Utilisateurs user = serviceUser.selectById(utilisateur.getIdUtilisateur()); // Récupérer l'utilisateur actuel
            serviceUser.deleteCompte(user); // Supprimer le compte de l'utilisateur actuel

            // Rediriger l'utilisateur vers l'interface de connexion (Login)
            FXMLLoader loginLoader = new FXMLLoader(getClass().getResource("/Login.fxml"));
            Parent loginRoot = loginLoader.load();
            Scene loginScene = new Scene(loginRoot);
            Stage loginStage = new Stage();
            loginStage.setScene(loginScene);
            loginStage.show();

            // Fermer l'interface Home
            Stage homeStage = (Stage) profileImageView.getScene().getWindow();
            homeStage.close();

        } catch (SQLException | IOException e) {
            e.printStackTrace();
            // Gérer l'exception
        }
    }
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
            Stage stage = (Stage) profileImageView.getScene().getWindow();

            // Configurer la nouvelle scène
            stage.setScene(scene);
            stage.setTitle("Update User Profile"); // Définir le titre de la fenêtre
            stage.show(); // Afficher la nouvelle fenêtre

        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }
    private boolean wordExistsInFile(String word, String filePath) {

        try (Scanner scanner = new Scanner(new File(filePath))) {
            Set<String> wordsInFile = new HashSet<>();
            while (scanner.hasNext()) {
                wordsInFile.add(scanner.next());
            }
            return wordsInFile.contains(word);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            return false;
        }
    }

    private void showAlert(String title, String content) {
        Alert alert = new Alert(Alert.AlertType.WARNING);
        alert.setTitle(title);
        alert.setHeaderText(null);
        alert.setContentText(content);
        alert.showAndWait();
    }
   
    public void AfficherReclamation1(ObservableList<Reclamation> musees) throws SQLException {
        reccontainertf.getChildren().clear(); // Clear the previous content

        for (Reclamation musee : musees) {
            VBox museeBox = new VBox(); // Use a VBox to display the name, id, and image vertically
            museeBox.setSpacing(10); // Add spacing between elements
            museeBox.setPrefSize(300, 200); // Set the preferred size of the VBox
            Reclamation reclamation= new Reclamation();
            ServiceUser serviceUser = new ServiceUser();
            Utilisateurs user = serviceUser.selectById(utilisateur.getIdUtilisateur());
            // Create a Label to display the museum's name
            Label nomLabel = new Label("Votre Email: " + musee.getEmail());
            Label nomLabel1 = new Label("Description Reclamation : " + musee.getDescription());
            Label nomLabel2 = new Label("Date reclamation :" + musee.getDate());
            Label nomLabel6 = new Label("Etat  :" + musee.getEtat());
            Label nomLabel3 = new Label("Commande Reclamer :" + musee.getId_cm());



            nomLabel6.setStyle("-fx-font-size: 14pt; -fx-font-weight: bold;");
            nomLabel.setStyle("-fx-font-size: 14pt; -fx-font-weight: bold;");nomLabel3.setStyle("-fx-font-size: 14pt; -fx-font-weight: bold;");nomLabel1.setStyle("-fx-font-size: 14pt; -fx-font-weight: bold;");nomLabel2.setStyle("-fx-font-size: 14pt; -fx-font-weight: bold;"); // Set style for the label
            museeBox.getChildren().add(nomLabel);
            museeBox.getChildren().add(nomLabel1); // Add the name Label to the VBox
            museeBox.getChildren().add(nomLabel2);
            museeBox.getChildren().add(nomLabel3);
            museeBox.getChildren().add(nomLabel6);





            // Set style for the VBox
            museeBox.setStyle("-fx-background-color: #f0f0f0; -fx-padding: 10px; -fx-border-color: #ccc; -fx-border-width: 1px; -fx-border-radius: 5px;");

            // Add event handler to handle mouse click event on museeBox
            museeBox.setUserData(musee);
            reccontainertf.getChildren().add(museeBox);


        }
    }

    @FXML
    public void obtenirIdMuseeSelectionne(MouseEvent mouseEvent) {
        if (mouseEvent.getSource() instanceof VBox) {
            VBox museeBoxClicked = (VBox) mouseEvent.getSource();
            Reclamation musee = (Reclamation) museeBoxClicked.getUserData();
            if (musee != null) {
                selectedRecId = musee.getId();
                System.out.println(selectedRecId);
                System.out.println("ghalta a degla");
            } else {
                System.out.println("Aucun musée sélectionné.");
            }
        }
    }


    public void sendTohome(MouseEvent mouseEvent) {
        try {

            // Charger le fichier FXML de votre nouvelle interface
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Home.fxml"));
            Parent root = loader.load();

            // Créer une nouvelle scène
            Scene scene = new Scene(root);

            // Créer une nouvelle fenêtre
            Stage stage = new Stage();
            stage.setScene(scene);
            Stage previousStage = (Stage) ((Node) mouseEvent.getSource()).getScene().getWindow();
            previousStage.close();
            // Afficher la nouvelle fenêtre
            stage.show();

        } catch (Exception e) {
            // e.printStackTrace();
            // Gérer toute exception lors du chargement de la nouvelle interface
        }
    }
    public void resetfield(ActionEvent event) {
        tfdescription.clear();
        tfdate.setValue(null);
        tfchoice.setValue(null);

    }

    public void stat(ActionEvent event) {
        BarChart<String, Number> barChart = new BarChart<>(xAxis, yAxis);
        barChart.setTitle("Statistiques par État");
        // Créer une série de données
        XYChart.Series<String, Number> series = new XYChart.Series<>();
        series.setName("Fréquence");
        series.getData().add(new XYChart.Data<>("État1", 23));
        series.getData().add(new XYChart.Data<>("État2", 14));
        barChart.getData().add(series);
        VBox vbox = new VBox(barChart);
        Scene scene = new Scene(vbox, 800, 600);
        Stage primaryStage = new Stage();
        primaryStage.setScene(scene);
        primaryStage.setTitle("Statistiques par État");
        primaryStage.show();
    }

    public void goTohomae(MouseEvent mouseEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/Home.fxml"));

            Parent parent = loader.load();

            // Accéder au contrôleur de la nouvelle fenêtre
            Home controller = loader.getController();
            controller.setUserModel(utilisateur); // Définir l'ID de l'utilisateur dans le contrôleur

            Scene scene = new Scene(parent);
            Stage stage = new Stage();
            stage.setTitle("La Cucina");
            stage.setScene(scene);
            stage.close();
            stage.show();
        } catch (IOException ex) {
            throw new RuntimeException(ex);
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
    @FXML
    void genererPDF(ActionEvent event) {
        try {
            FileChooser fileChooser = new FileChooser();
            fileChooser.setTitle("Save PDF File");
            fileChooser.setInitialFileName("Liste_de_Reclamation.pdf");

            // Set the file extension filters if needed
            fileChooser.getExtensionFilters().add(new FileChooser.ExtensionFilter("PDF Files", "*.pdf"));

            // Show the dialog and get the selected file
            File file = fileChooser.showSaveDialog(pdfbtn.getScene().getWindow());
            Reclamation reclamation = new Reclamation();
            if (file != null) {
                System.out.println(reclamation.getId()+","+ utilisateur.getIdUtilisateur());
                GeneratePdf.generatePDF(utilisateur.getIdUtilisateur(), file);
                System.out.println("PDF generated successfully.");
            } else {
                System.out.println("No file selected.");
            }
        } catch (Exception e) {
            e.printStackTrace();
            System.out.println("An error occurred while generating PDF.");
        }
    }
    public void goToreservation(MouseEvent mouseEvent) {
    }




    List<Reclamation>reclamations;
    private final int rec_par_page = 6;
    private AnchorPane createPage(int pageIndex) {
        AnchorPane anchorPane = new AnchorPane();
        anchorPane.setPrefWidth(1400);
        anchorPane.setPrefHeight(200);

        int startIndex = pageIndex * rec_par_page;
        int endIndex = Math.min(startIndex + rec_par_page, reclamations.size());

        int xOffset = 30;
        int yOffset = 30;
        int xIncrement = 380;
        int yIncrement = 250;

        for (int i = startIndex; i < endIndex; i++) {
            Reclamation ev = reclamations.get(i);

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

          Label typeLabel = new Label(ev.getEtat());
            typeLabel.setLayoutX(10);
            typeLabel.setLayoutY(10);
            typeLabel.setPrefWidth(300);
            typeLabel.setStyle("-fx-text-fill: white; -fx-font-weight: bold;");
         //   typeLabel.setFont(Font.font("Arial", FontWeight.BOLD, 14));
            typeLabel.setWrapText(true);
            productPane.getChildren().add(typeLabel);

            Label descriptionLabel = new Label("Description: " + ev.getDescription());
            descriptionLabel.setLayoutX(10);
            descriptionLabel.setLayoutY(40);
            descriptionLabel.setPrefWidth(300);
            descriptionLabel.setStyle("-fx-text-fill: white;");
            descriptionLabel.setFont(Font.font("Arial", 12));
            descriptionLabel.setWrapText(true);
            productPane.getChildren().add(descriptionLabel);

            Label dateLabel = new Label("Date de l'événement: " + ev.getDate());
            dateLabel.setLayoutX(10);
            dateLabel.setLayoutY(140);
            dateLabel.setPrefWidth(300);
            dateLabel.setStyle("-fx-text-fill: white;");
            dateLabel.setFont(Font.font("Arial", FontWeight.BOLD, 12));
            productPane.getChildren().add(dateLabel);



            // Ajout du bouton "PARTICIPER"
            Button participerButton = new Button("PARTICIPER");
            participerButton.setLayoutX(10);
            participerButton.setLayoutY(190);
            participerButton.setPrefWidth(100);
            productPane.getChildren().add(participerButton);





            // Gestionnaire d'événements pour la modification de la notation


            xOffset += xIncrement;
            if (xOffset + xIncrement > anchorPane.getPrefWidth()) {
                xOffset = 20;
                yOffset += yIncrement;
            }

            anchorPane.getChildren().add(productPane);
        }

        return anchorPane;
    }

    public void setId1(Utilisateurs utilisateur) throws SQLException {
        System.out.println("test");
        this.utilisateur = utilisateur;
        try {
            initializeData();
            try {
                List<Integer> commandeIDs = getCommandeIDsFromDatabase();

                // Ajout des ID des commandes au ChoiceBox
                tfchoice.getItems().addAll(commandeIDs);
            } catch (SQLException e) {
                e.printStackTrace();
                // Gérer les erreurs de connexion à la base de données
            }


            // Now that userId is set, fetch the data
            ObservableList<Reclamation> rec = getRec();
             AfficherReclamation1(rec);
            tfdescription.setPromptText("Entrez une description");
            tfdate.setPromptText("Entrer un date");

            tfdescription.textProperty().addListener((observable, oldValue, newValue) -> {
                if (wordExistsInFile(newValue, "C:\\Users\\ayadi\\OneDrive - ESPRIT (1)\\Bureau\\La_Cucina_Projet_Pidev (2)\\La_Cucina_Projet_Pidev\\src\\main\\resources\\controle de saisie.txt")) {
                    showAlert("Mot interdit", "Le mot saisi existe dans le fichier.");
                }
            });

        }catch (SQLException e)
        {
            e.printStackTrace();
        }
                // Utilisez l'utilisateur chargé pour initialiser votre interface utilisateur
                if (utilisateur != null) {
                    System.out.println("trouve");
                    NomPrenomLabel.setText(utilisateur.getNom()+" "+utilisateur.getPrenom());
                } else {
                    System.out.println("Utilisateur non trouvé avec l'ID : " + utilisateur.getIdUtilisateur());
                }





                    tfemail.setText(utilisateur.getEmail());
                    tfemail.setDisable(true);

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
            Stage stage = (Stage) tfdescription.getScene().getWindow();
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
    private void redirectToEvents() {
        try {
            // Charger le fichier FXML de l'interface des événements
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/EventFront.fxml"));
            Parent root = loader.load();

            // Accéder au contrôleur de la nouvelle fenêtre
            EventFront controller = loader.getController();

            // Passer l'objet utilisateur directement au contrôleur de la page EventFront.fxml
            controller.setUserModel(utilisateur);

            // Afficher la fenêtre
            Scene scene = NomPrenomLabel.getScene();
            // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
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

            Scene scene = tfchoice.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


    public void goTodonation(MouseEvent mouseEvent) {
        try {
            FXMLLoader loader = new FXMLLoader(getClass().getResource("/donationFront.fxml"));
            Parent root = loader.load();

            donationfront controller = loader.getController();

            controller.setId1(utilisateur);

            Scene scene = tfchoice.getScene();
            scene.setRoot(root);

        } catch (IOException ex) {
            ex.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        } }
    }

