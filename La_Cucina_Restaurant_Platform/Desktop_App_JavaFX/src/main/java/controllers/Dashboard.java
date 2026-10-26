package controllers;

import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.text.DecimalFormat;
import java.util.HashMap;
import java.util.Map;
import java.util.ResourceBundle;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.chart.*;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.ProgressBar;
import javafx.scene.control.Tooltip;
import javafx.scene.image.Image;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import javafx.scene.layout.HBox;
import javafx.scene.layout.Pane;
import javafx.scene.paint.Color;
import javafx.scene.text.Font;
import javafx.scene.text.FontWeight;
import javafx.scene.text.TextAlignment;
import javafx.stage.Stage;
import javafx.util.StringConverter;
import models.Utilisateurs;
import services.ServiceUser;
import utils.DBConnection;
import javafx.scene.Node;

import javafx.scene.image.ImageView;

//stat
import javafx.scene.text.Text;

//
public class Dashboard {

    /// stat
    @FXML
    private BarChart<String, Integer> barChart;
    @FXML
    private CategoryAxis xAxis = new CategoryAxis();

    @FXML
    private NumberAxis yAxis = new NumberAxis();

    @FXML
    private PieChart pieChart;


    ////
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;
    @FXML
    private Button EventManagementBtn;
    @FXML
    private ImageView imageSearch;

    @FXML
    private Button LogoutBtn;
    @FXML
    private Button btn_workbench;

    @FXML
    private Button btn_workbench1;

    @FXML
    private Button UserManagementBtn;

    @FXML
    private Button btn_workbench111;

    @FXML
    private Button btn_workbench1112;

    @FXML
    private Button btn_workbench112;

    @FXML
    private Button btn_workbench113;

    @FXML
    private Button btn_workbench1131;

    @FXML
    private Button btn_workbench11311;

    @FXML
    private Button btn_workbench1132;

    @FXML
    private Button btn_workbench114;

    @FXML
    private Pane pane_1;

    @FXML
    private Pane pane_11;

    @FXML
    private Pane pane_111;

    @FXML
    private Pane pane_12;

    @FXML
    private Pane pane_13;

    @FXML
    private Pane pane_131;

    @FXML
    private Pane pane_1311;

    @FXML
    private Pane pane_132;

    @FXML
    private ProgressBar progress2;

    @FXML
    private HBox root;

    @FXML
    private AnchorPane side_ankerpane;

    @FXML
    private ImageView ImageViewAdmin;
    @FXML
    private Label NomPrenomLabel;
    private int userId;


    @FXML
    void initialize() {

        /////////////////// stat///////////////////
        loadStatistics();
        loadStatisticsBySex();

////////////////////////////////////////////////////////
    }


    @FXML
    public void loadUserProfileImage(String username, String password) {
        Connection connection = DBConnection.getInstance().getCnx();
        String query = "SELECT image_user FROM utilisateurs WHERE surnom = ? AND motDePasse = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, username);
            statement.setString(2, password);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String imageUrl = resultSet.getString("image_user");
                Image image = new Image(imageUrl);
                ImageViewAdmin.setImage(image); // Assurez-vous d'avoir un ImageView avec l'identifiant imageViewAdmin dans votre FXML
            } else {
                System.out.println("Aucun utilisateur administrateur trouvé avec ce surnom et ce mot de passe.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    ///////////////////////////////////////////////////////////////////////////////////////////////////////


   /* public void loadNomPrenom(String username, String password) {
        Connection connection = DBConnection.getInstance().getCnx();
        String query = "SELECT nom, prenom FROM utilisateurs WHERE surnom = ? AND motDePasse = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, username);
            statement.setString(2, password);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                String nom = resultSet.getString("nom");
                String prenom = resultSet.getString("prenom");
                NomPrenomLabel.setText(nom + " " + prenom); // Assurez-vous d'avoir une Label avec l'identifiant nomPrenomLabel dans votre FXML
            } else {
                System.out.println("Aucun utilisateur administrateur trouvé avec ce surnom et ce mot de passe.");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }*/


    public void handleUserManagementBtn() {
        try {
            URL url = getClass().getResource("/UserAdmin.fxml");
            if (url != null) {
                // Charger le fichier FXML de l'interface de mise à jour du profil
                FXMLLoader loader = new FXMLLoader(url);
                Parent root = loader.load();


                // Afficher la fenêtre
                Scene scene = EventManagementBtn.getScene();
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
                Scene scene = EventManagementBtn.getScene();
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
    public void OnLogoutBtn(ActionEvent actionEvent) throws IOException {
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/Login.fxml"));
        Parent root = loader.load();
        Stage stage = (Stage) imageSearch.getScene().getWindow();
        stage.setScene(new Scene(root));
        stage.show();
    }


    public void loadStatistics() {
        // Interrogation de la base de données pour obtenir les statistiques
        int clientsCount = getCountByRole("CLIENT");
        int adminsCount = getCountByRole("ADMIN");

        // Effacer les données existantes
        barChart.getData().clear();

        // Définir les libellés des axes
        CategoryAxis xAxis = new CategoryAxis();
        xAxis.setLabel("Rôles");
        NumberAxis yAxis = new NumberAxis();
        yAxis.setLabel("Nombre d'utilisateurs");

        // Créer la série de données
        XYChart.Series<String, Integer> series = new XYChart.Series<>();
        series.getData().add(new XYChart.Data<>("Clients", clientsCount));
        series.getData().add(new XYChart.Data<>("Administrateurs", adminsCount));

        // Ajouter la série de données au graphique à barres
        barChart.getData().add(series);
    }// Créer la série de données


    // Méthode pour ajouter une étiquette personnalisée à une barre de données
    private void setCustomDataLabel(XYChart.Data<String, Integer> data, String label) {
        Text text = new Text(label);
        data.setNode(text);

    }


    private int getCountByRole(String role) {
        int count = 0;
        Connection connection = DBConnection.getInstance().getCnx();
        String query = "SELECT COUNT(*) AS count FROM utilisateurs WHERE role = ?";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            statement.setString(1, role);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                count = resultSet.getInt("count");
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return count;
    }

    ////////////////////////////////////////////////////////////


    private Map<String, Integer> getCountBySex() {
        Map<String, Integer> countBySex = new HashMap<>();
        Connection connection = DBConnection.getInstance().getCnx();
        String query = "SELECT sexe, COUNT(*) AS count FROM utilisateurs GROUP BY sexe";
        try (PreparedStatement statement = connection.prepareStatement(query)) {
            ResultSet resultSet = statement.executeQuery();
            while (resultSet.next()) {
                String sex = resultSet.getString("sexe");
                int count = resultSet.getInt("count");
                countBySex.put(sex, count);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        return countBySex;
    }


    public void loadStatisticsBySex() {
        // Effacer les données existantes
        pieChart.getData().clear();

        // Récupérer les statistiques par sexe depuis la base de données
        Map<String, Integer> statisticsBySex = getCountBySex();

        // Ajouter les données au graphique à secteurs
        for (String sex : statisticsBySex.keySet()) {
            PieChart.Data slice = new PieChart.Data(sex, statisticsBySex.get(sex));
            pieChart.getData().add(slice);

            // Afficher le pourcentage au survol de la souris
            slice.nodeProperty().addListener((obs, oldNode, newNode) -> {
                if (newNode != null) {
                    newNode.setOnMouseEntered(event -> {
                        double percentage = (slice.getPieValue() / getTotalCount(statisticsBySex)) * 100;
                        String text = String.format("%.2f%%", percentage);
                        Tooltip tooltip = new Tooltip(text);
                        Tooltip.install(newNode, tooltip);
                    });
                }
            });
        }
    }

    private double getTotalCount(Map<String, Integer> statisticsBySex) {
        return statisticsBySex.values().stream().mapToDouble(Integer::doubleValue).sum();
    }


    public void goToRecback(ActionEvent actionEvent) throws IOException {
        Stage stage=new Stage();
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/reclamationFront.fxml"));
        Parent parent = loader.load();
        Scene scene = new Scene(parent);
        stage.setTitle("Ajouter une reclamation");
        stage.setScene(scene);
        stage.show();
    }

    public void goTodonback(ActionEvent actionEvent) throws IOException {
        Stage stage=new Stage();
        FXMLLoader loader = new FXMLLoader(getClass().getResource("/donation.fxml"));
        Parent parent = loader.load();
        Scene scene = new Scene(parent);
        stage.setTitle("Ajouter une reclamation");
        stage.setScene(scene);
        stage.show();
    }
    @FXML
    void handleMenuManagementBtn(ActionEvent event) {
        try {
            URL url = getClass().getResource("/MenuAdmin.fxml");
            if (url != null) {
                // Charger le fichier FXML de l'interface de mise à jour du profil
                FXMLLoader loader = new FXMLLoader(url);
                Parent root = loader.load();

                // Afficher la fenêtre
                Scene scene = EventManagementBtn.getScene();
                // Remplacer le contenu de la scène actuelle par le contenu de la nouvelle interface
                scene.setRoot(root);
            } else {
                System.out.println("Le chemin d'accès au fichier FXML est incorrect ou le fichier est introuvable.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }




    }







