package services;

import javafx.collections.ObservableList;
import models.Donation;
import models.Reclamation;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import models.Donation;
import models.Reclamation;
import utils.DBConnection;

import java.sql.*;


import java.sql.SQLException;

public class serviceDonation implements CRUD<Donation> {
    private Connection cnx;
    private PreparedStatement pre;

    public serviceDonation() {cnx= DBConnection.getInstance().getCnx();
    }

    @Override
    public void insertOne(Donation donation) throws SQLException {
        try {
            String req = "INSERT INTO `donation`(`montant`, `date_don`, `type_don` ,`idUtilisateur`) VALUES" +
                    "('" + donation.getMontant() + "','" + donation.getDate_don() + "','" + donation.getType_don() +"','" + donation.getIdUtilisateur() +"')";
            Statement st = cnx.createStatement();
            st.executeUpdate(req);
        }catch (SQLException ex)
        {
            System.out.println("probleme");
            System.out.println(ex.getMessage());
        }
    }
    @Override
    public void deleteOne(int id_don) {
        String req= "DELETE FROM `donation` WHERE id_donation = ?";
        try (PreparedStatement statement = cnx.prepareStatement(req)) {
            statement.setInt(1, id_don);
            int rowsAffected = statement.executeUpdate();
            if (rowsAffected == 0) {
                // Handle case where the museum with the specified name does not exist
                throw new SQLException("Reclamation with name " + id_don + " not found.");
            }
            System.out.println("Reclamation with name " + id_don + " deleted successfully.");
        } catch (SQLException e) {
            // Handle SQL exceptions appropriately (log, inform user, etc.)
            e.printStackTrace();
        }
    }
    @Override
    public ObservableList<Donation> selectAllDon() throws SQLException {
        ObservableList<Donation>donations = FXCollections.observableArrayList();
        String sql = "SELECT * FROM donation";

        try (PreparedStatement statement = cnx.prepareStatement(sql);
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Donation rec=new Donation();
                rec.setId_donation(resultSet.getInt("id_donation"));
                rec.setMontant(resultSet.getInt("montant"));
                rec.setDate_don(resultSet.getDate("date_don").toLocalDate());
                rec.setType_don(resultSet.getString("type_don"));

                donations.add(rec);
            }
        } catch (SQLException e) {
            // Handle SQL exceptions appropriately (log, inform user, etc.)
            e.printStackTrace();
        }


        return donations;
    }

    @Override
    public ObservableList<Reclamation> selectAll() throws SQLException {
        return null;
    }




}
