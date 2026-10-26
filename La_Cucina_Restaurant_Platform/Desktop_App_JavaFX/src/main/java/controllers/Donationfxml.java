package controllers;

import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.print.PrinterJob;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.image.ImageView;
import javafx.scene.input.MouseEvent;
import javafx.stage.Stage;
import models.Donation;
import models.Reclamation;
import models.Utilisateurs;
import services.ServiceUser;
import services.serviceDonation;
import services.serviceReclamation;
import utils.DBConnection;

import java.io.IOException;
import java.net.URL;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Arrays;
import java.util.ResourceBundle;

;

public class Donationfxml {
    public Donationfxml() {
        cnx= DBConnection.getInstance().getCnx();
    }
    private Connection cnx;
    private PreparedStatement pre;
    private Utilisateurs utilisateur; // Objet utilisateur
    @FXML
    private ResourceBundle resources;

    @FXML
    private URL location;
    @FXML
    private ImageView profileImageView;
    @FXML
    private TableView<Donation> Donationtable;

    @FXML
    private TableColumn<Donationfxml, Integer> Iddonation;

    @FXML
    private Button btnPrint;

    @FXML
    private TableColumn<Donation, String> datecol;

    @FXML
    private TableColumn<Donation, Float> montantcol;

    @FXML
    private DatePicker tfdate;
    @FXML
    private Label homeBtn;
    @FXML
    private TextField tfmontant;

    @FXML
    private ChoiceBox<String> tftype;

    @FXML
    private TableColumn<Donation, String> typecol;
    @FXML
    private Label idU;
    @FXML
    private Label NomPrenomLabel;
private String[] dontype = {"Paypal" ,"MasterCard","Visa"};
    @FXML
    void Afficher(ActionEvent event) throws SQLException {
        serviceDonation sp = new serviceDonation();
        ObservableList<Donation> list = sp.selectAllDon();
        Donationtable.setItems(list);
        Iddonation.setCellValueFactory(new PropertyValueFactory<>("id_donation"));
        montantcol.setCellValueFactory(new PropertyValueFactory<>("montant"));
        datecol.setCellValueFactory(new PropertyValueFactory<>("date_don"));
        typecol.setCellValueFactory(new PropertyValueFactory<>("type_don"));
        btnPrint.setOnAction(actionEvent ->{
            PrinterJob job = PrinterJob.createPrinterJob();
            if (job != null && job .showPrintDialog(btnPrint.getScene().getWindow())){
                boolean success = job.printPage(Donationtable);
                if (success ) {
                    job.endJob();

                }
            }
        } );
    }
    int id = 0;
    @FXML
    void Print(ActionEvent event) {

    }

    @FXML
    void Update(ActionEvent event) {
        serviceDonation sp = new serviceDonation();
        String req = " update `Donation` set  montant = ? ,date_don = ? , type_don = ? where id_donation = ?";

        try {
            pre = cnx.prepareStatement(req);
            pre.setString(2, tfmontant.getText());
            pre.setString(1, String.valueOf(tfdate .getValue()));
            pre.setString(3, tftype.getValue());
            pre.setInt(4,id);
            pre.executeUpdate();
            sp.selectAll();
        }catch (SQLException m)
        {
            System.out.println(m.getMessage());
        }
    }
    private  int userId;
    @FXML
    void ajouterDonation(ActionEvent event) {
        try
        {
            models.Donation r = new models.Donation(Float.parseFloat(tfmontant.getText()),tfdate.getValue(),tftype.getValue(),userId);
            serviceDonation sp = new serviceDonation();
            sp.insertOne(r);
        }catch (SQLException e)
        {
            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("erreur");
            alert.show();
        }
        catch (NumberFormatException e)
        {

            Alert alert = new Alert(Alert.AlertType.ERROR);
            alert.setTitle("erreur");
            alert.show();
        }

    }

    @FXML
    void delete(ActionEvent event) {
        Donation rec= Donationtable.getSelectionModel().getSelectedItem();
        serviceDonation sp = new serviceDonation();
        sp.deleteOne(rec.getId_donation());
    }

    @FXML
    void getData(MouseEvent event) {
        serviceDonation sp =new serviceDonation();
        Donation rec= Donationtable.getSelectionModel().getSelectedItem();
        id=rec.getId_donation();
        tfmontant.setText(String.valueOf(rec.getMontant()));
        tfdate.setValue(rec.getDate_don());
        tftype.setValue(rec.getType_don());
    }

    @FXML
    void initialize() {
        assert Donationtable != null : "fx:id=\"Donationtable\" was not injected: check your FXML file 'donation.fxml'.";
        assert Iddonation != null : "fx:id=\"Idreclamationcol\" was not injected: check your FXML file 'donation.fxml'.";
        assert btnPrint != null : "fx:id=\"btnPrint\" was not injected: check your FXML file 'donation.fxml'.";
        assert datecol != null : "fx:id=\"datecol\" was not injected: check your FXML file 'donation.fxml'.";
        assert montantcol != null : "fx:id=\"montantcol\" was not injected: check your FXML file 'donation.fxml'.";
        assert tfdate != null : "fx:id=\"tfdate\" was not injected: check your FXML file 'donation.fxml'.";
        assert tfmontant != null : "fx:id=\"tfmontant\" was not injected: check your FXML file 'donation.fxml'.";
        assert tftype != null : "fx:id=\"tftype\" was not injected: check your FXML file 'donation.fxml'.";
        assert typecol != null : "fx:id=\"typecol\" was not injected: check your FXML file 'donation.fxml'.";
        tftype.getItems().addAll((dontype));
    }
    public void setId(int id) {

        idU.setText(Integer.toString(id));

        try {
            ServiceUser serviceUser = new ServiceUser();
            Utilisateurs user = serviceUser.selectById(id); // Récupérer l'utilisateur à partir de l'ID
            if (user != null) {
                NomPrenomLabel.setText(user.getNom()); // Mettre à jour le label avec le nom de l'utilisateur

            }
        }  catch (SQLException e) {
            e.printStackTrace();
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
            Stage stage = (Stage) NomPrenomLabel.getScene().getWindow();
            stage.setScene(scene);
            stage.show();
        } catch (IOException e) {
            e.printStackTrace();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }


}

