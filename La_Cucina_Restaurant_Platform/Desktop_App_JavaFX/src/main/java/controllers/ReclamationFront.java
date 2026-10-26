package controllers;

import java.net.URL;
import java.sql.Connection;
import java.sql.Date;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.util.Comparator;
import java.util.ResourceBundle;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.transformation.SortedList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.print.PrinterJob;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.input.MouseEvent;
import javafx.scene.layout.AnchorPane;
import models.Reclamation;
import models.Utilisateurs;
import services.ServiceUser;
import services.serviceReclamation;
import utils.DBConnection;
import javafx.collections.transformation.FilteredList;

public class ReclamationFront {
    @FXML
    private TextField search;
    @FXML
    private ChoiceBox<Integer> tfchoice;
    @FXML
    private TableColumn<Reclamation, Integer> idcomcol;
    @FXML
    private TableColumn<Reclamation, Integer> idUser;
    @FXML
    private ChoiceBox<String> sortChoiceBox;
    @FXML
    private Button btnPrint ;

    @FXML // ResourceBundle that was given to the FXMLLoader
    private ResourceBundle resources;

    @FXML // URL location of the FXML file that was given to the FXMLLoader
    private URL location;

    @FXML // fx:id="tfdate"
    private DatePicker tfdate=new DatePicker(); // Value injected by FXMLLoader

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

    @FXML
    private TableColumn<Reclamation, String> datecol;
    @FXML
    private TableColumn<Reclamation, String> etatcol;
    @FXML
    private TableColumn<Reclamation, String> descriptioncol;
    private Connection cnx;
    private PreparedStatement pre;
    int id = 0;
    int idUtilisateur = 0;
    ObservableList<Reclamation> listrec = FXCollections.observableArrayList();
    public ReclamationFront() {
        cnx= DBConnection.getInstance().getCnx();
    }
    @FXML
    void AfficherReclamation() throws SQLException {
        serviceReclamation sp = new serviceReclamation();
        ObservableList<Reclamation> list = sp.selectAll();
        ReclamationListId.setItems(list);
        Idreclamationcol.setCellValueFactory(new PropertyValueFactory<>("Id"));
        Emailcol.setCellValueFactory(new PropertyValueFactory<>("email"));
        descriptioncol.setCellValueFactory(new PropertyValueFactory<>("Description"));
        datecol.setCellValueFactory(new PropertyValueFactory<>("Date"));
        etatcol.setCellValueFactory(new PropertyValueFactory<>("Etat"));
        idcomcol.setCellValueFactory(new PropertyValueFactory<>("id_cm"));
        idUser.setCellValueFactory(new PropertyValueFactory<>("idUtilisateur"));
        btnPrint.setOnAction(actionEvent ->{
            PrinterJob job = PrinterJob.createPrinterJob();
            if (job != null && job .showPrintDialog(btnPrint.getScene().getWindow())){
                boolean success = job.printPage(ReclamationListId);
                if (success ) {
                    job.endJob();

                }
            }
        } );
    }
    @FXML
    public void showReclamations1() throws SQLException {
        serviceReclamation sr = new serviceReclamation();
        ObservableList<Reclamation> list = sr.selectAll();
        ReclamationListId.setItems(list);
        Idreclamationcol.setCellValueFactory(new PropertyValueFactory<>("Id"));
        Emailcol.setCellValueFactory(new PropertyValueFactory<Reclamation,String>("email"));
        descriptioncol.setCellValueFactory(new PropertyValueFactory<Reclamation,String>("description"));
        datecol.setCellValueFactory(new PropertyValueFactory<Reclamation,String>("date"));
        etatcol.setCellValueFactory(new PropertyValueFactory<Reclamation,String>("etat"));
        idcomcol.setCellValueFactory(new PropertyValueFactory<>("id_cm"));
        idUser.setCellValueFactory(new PropertyValueFactory<>("idUtilisateur"));
        FilteredList<Reclamation> filteredData = new FilteredList<>(list, b-> true);
        search.textProperty().addListener((observable , oldValue, newValue) -> {
            filteredData.setPredicate(Reclamation -> {
                if(newValue.isEmpty() || newValue.isBlank() || newValue == null){
                    return true;
                }
                String searchKeyword = newValue.toLowerCase();
                if(Reclamation.getEtat().toLowerCase().indexOf(searchKeyword) > -1){
                    return true;
                }
                else if(Reclamation.getEmail().toLowerCase().indexOf(searchKeyword) > -1){
                    return true;
                }
                else if(Reclamation.getDescription().toLowerCase().indexOf(searchKeyword) > -1) {
                    return true;
                }
                else if(String.valueOf(Reclamation.getId()).contains(searchKeyword)){
                    return true;
                }else
                    return false;
            });
        });
        SortedList<Reclamation> sortedData = new SortedList<>(filteredData);
        sortedData.comparatorProperty().bind(ReclamationListId.comparatorProperty());
        ReclamationListId.setItems(sortedData);
    }
    @FXML
    void Print(ActionEvent event) {

    }

    @FXML
    void UpdateReclamation(ActionEvent event) throws SQLException {
        serviceReclamation sp = new serviceReclamation();
        String req = " update `reclamation` set  description = ? ,email = ? , date = ?  where id_reclamation = ?";

        try {
            pre = cnx.prepareStatement(req);
            pre.setString(2, tfemail.getText());
            pre.setString(1,tfdescription .getText());
            pre.setDate(3, Date.valueOf(tfdate.getValue()));
            pre.setInt(4,id);
            pre.executeUpdate();
            sp.selectAll();
            ReclamationListId.refresh();
        }catch (SQLException m)
        {
            System.out.println(m.getMessage());
        }
        showReclamations1();
    }
    private  int userId;
    @FXML
    public void setId(int userId) throws SQLException {
        this.userId = userId;
        System.out.println("User ID set: " + userId);
        // After setting the userId, you may want to initialize the data

        ServiceUser serviceUser = new ServiceUser();
        Utilisateurs utilisateurs = serviceUser.selectById(userId); // Utilisez directement l'ID passé en paramètre
        if (utilisateurs != null) {
           // setUserName(utilisateurs.getNom()+" "+utilisateurs.getPrenom());
            tfemail.setText(utilisateurs.getEmail());
            tfemail.setDisable(true);tfdate.setDisable(true);tfchoice.setDisable(true);tfdescription.setDisable(true);


        }
    }
    @FXML
    public void approuverRec(ActionEvent event) throws SQLException {
        System.out.println("1");
        Reclamation rec= new Reclamation();
        System.out.println("2");
        serviceReclamation sp = new serviceReclamation();
        System.out.println("3");
        String req = " update `reclamation` set  description = ? ,email = ? , date = ? ,etat='Traite'  where id_reclamation = ?";
        System.out.println("4");
        try {
            System.out.println("5");
            pre = cnx.prepareStatement(req);
            pre.setString(2, tfemail.getText());
            pre.setString(1,tfdescription .getText());
            pre.setDate(3, Date.valueOf(tfdate.getValue()));
            pre.setInt(4,id);
            //pre.setInt(5,idUtilisateur);
            System.out.println("6");
            pre.executeUpdate();
            System.out.println("7");
            sp.selectAll();
            System.out.println("8");
            ReclamationListId.refresh();
        }catch (SQLException m)
        {
            System.out.println(m.getMessage());
        }
        showReclamations1();

    }


    @FXML
    void deleteReclamation(ActionEvent event) throws SQLException {
        Reclamation rec= ReclamationListId.getSelectionModel().getSelectedItem();
        serviceReclamation sp = new serviceReclamation();
        sp.deleteOne(rec.getId());
        ReclamationListId.refresh();
        showReclamations1();
    }

    @FXML
    void getData(MouseEvent event) {
        Reclamation rec = ReclamationListId.getSelectionModel().getSelectedItem();
        if (rec != null) {
            id = rec.getId();
            idUtilisateur=rec.getIdUtilisateur();

            tfemail.setText(rec.getEmail());
            tfchoice.setValue(rec.getId_cm());
            tfdescription.setText(rec.getDescription());
            tfchoice.setDisable(true);
            tfchoice.setValue(rec.getId_cm());
            tfdate.setDisable(true);
            tfdate.setValue(rec.getDate());
        }
    }

    @FXML
    void initialize() throws SQLException {

        assert Emailcol != null : "fx:id=\"Emailcol\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert Idreclamationcol != null : "fx:id=\"Idreclamationcol\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert ReclamationListId != null : "fx:id=\"ReclamationListId\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert datecol != null : "fx:id=\"datecol\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert descriptioncol != null : "fx:id=\"descriptioncol\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert etatcol != null : "fx:id=\"etatcol\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert idcomcol != null : "fx:id=\"idcomcol\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert tfchoice != null : "fx:id=\"tfchoice\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert tfdate != null : "fx:id=\"tfdate\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert tfdescription != null : "fx:id=\"tfdescription\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert tfemail != null : "fx:id=\"tfemail\" was not injected: check your FXML file 'reclamationFront.fxml'.";
        assert idUser != null : "fx:id=\"idUser\" was not injected: check your FXML file 'reclamationFront.fxml'.";

        FilteredList<Reclamation> filteredList = new FilteredList<>(listrec, b -> true);

        search.textProperty().addListener((observable, oldvalue, newvalue) -> {
            filteredList.setPredicate(Reclamation -> {
                if (newvalue == null || newvalue.isBlank()) {
                    return true;
                }
                String keywordsearch = newvalue.toLowerCase();
                return Reclamation.getDate().toString().toLowerCase().contains(keywordsearch);
            });
        });

        sortChoiceBox.getItems().addAll("croissant", "decroissant");

        // Set an event handler for the ChoiceBox
        sortChoiceBox.setOnAction((ActionEvent event) -> {
            String selected = sortChoiceBox.getValue();

            if (selected.equals("croissant")) {
                try {
                    triCroissant();
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            } else if (selected.equals("decroissant")) {
                try {
                    triDecroissant();
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }
            }
        });

        SortedList<Reclamation> sortedList = new SortedList<>(filteredList);
        sortedList.comparatorProperty().bind(ReclamationListId.comparatorProperty());
        ReclamationListId.setItems(sortedList);

        tfdescription.setPromptText("Entrez une description");
        showReclamations1();
    }
    private void triCroissant() throws SQLException {
        if (listrec != null && ReclamationListId != null) {
            FXCollections.sort(listrec, Comparator.comparing(Reclamation::getDate));
            ReclamationListId.setItems(listrec); // Mettre à jour le TableView avec la liste triée
        } else {
            System.out.println("listrec or ReclamationListId is null. Make sure they are properly initialized.");
        }
        }

    private void triDecroissant() throws SQLException {
        FXCollections.sort(listrec, Comparator.comparing(Reclamation::getDate).reversed());
        ReclamationListId.setItems(listrec); // Mettre à jour le TableView avec la liste triée
    }


}
