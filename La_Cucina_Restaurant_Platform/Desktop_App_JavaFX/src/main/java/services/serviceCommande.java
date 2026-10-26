package services;
import javafx.collections.ObservableList;
import models.Donation;
import models.Reclamation;
import models.commande;
import utils.DBConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
import java.sql.Statement;

public class serviceCommande implements CRUD<commande>{
    private Connection cnx;
    private PreparedStatement pre;
    public serviceCommande(){cnx= DBConnection.getInstance().getCnx();
    }
    @Override
    public void insertOne(commande commande) throws SQLException {
        try {
            String req = "INSERT INTO `commandes`(`date_commande`, `montant_total`,`mode_paiement`) VALUES" +
                    "('" + commande.getDate_commande() + "','" + commande.getMontant_commande() + "','" + commande.getMode_paiement() +"')";
            Statement st = cnx.createStatement();
            st.executeUpdate(req);
        }catch (SQLException ex)
        {
            System.out.println("probleme");
            System.out.println(ex.getMessage());
        }
    }

    @Override
    public void deleteOne(int id_reclamation) {

    }

    @Override
    public ObservableList<Reclamation> selectAll() throws SQLException {
        return null;
    }

    @Override
    public ObservableList<Donation> selectAllDon() throws SQLException {
        return null;
    }
}
