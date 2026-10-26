package services;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import models.Donation;
import models.Reclamation;
import utils.DBConnection;
import java.sql.*;
import java.util.ArrayList;

public class serviceReclamation implements CRUD<Reclamation> {

    private Connection cnx;
    private PreparedStatement pre;
    public serviceReclamation(){cnx= DBConnection.getInstance().getCnx();
    }
    @Override
    public void insertOne(Reclamation reclamation) {
        try {
            String req = "INSERT INTO `reclamation`(`email`, `description`, `date`, `etat`, `id_commande`, `idUtilisateur`) VALUES (?, ?, ?, ?, ?, ?)";
            PreparedStatement ps = cnx.prepareStatement(req);
            ps.setString(1, reclamation.getEmail());
            ps.setString(2, reclamation.getDescription());
            ps.setDate(3, Date.valueOf(reclamation.getDate()));
            ps.setString(4, reclamation.getEtat());
            ps.setInt(5, reclamation.getId_cm());
            ps.setInt(6, reclamation.getIdUtilisateur());
            ps.executeUpdate();
        } catch (SQLException ex) {
            System.out.println("probleme");
            System.out.println(ex.getMessage());
        }
    }
    @Override
         public void deleteOne(int id_reclamation)  {
         String req = "DELETE FROM `reclamation` WHERE id_reclamation = ?";
             try (PreparedStatement statement = cnx.prepareStatement(req)) {
            statement.setInt(1, id_reclamation);
            int rowsAffected = statement.executeUpdate();
            if (rowsAffected == 0) {
                // Handle case where the museum with the specified name does not exist
                throw new SQLException("Reclamation with name " + id_reclamation + " not found.");
            }
            System.out.println("Reclamation with name " + id_reclamation + " deleted successfully.");
        } catch (SQLException e) {
            // Handle SQL exceptions appropriately (log, inform user, etc.)
            e.printStackTrace();
        }
    }

    @Override
    public ObservableList<Reclamation> selectAll()throws SQLException  {
        ObservableList<Reclamation>Reclamations = FXCollections.observableArrayList();

        String sql = "SELECT * FROM reclamation ";
        try (PreparedStatement statement = cnx.prepareStatement(sql);
             ResultSet resultSet = statement.executeQuery()) {

            while (resultSet.next()) {
                Reclamation rec=new Reclamation();
                rec.setId(resultSet.getInt("id_reclamation"));
                rec.setDate(resultSet.getDate("date").toLocalDate());
                rec.setEmail(resultSet.getString("email"));
                rec.setDescription(resultSet.getString("description"));
                rec.setEtat(resultSet.getString("etat"));
                rec.setId_cm(resultSet.getInt("id_commande"));
                rec.setIdUtilisateur(resultSet.getInt("idUtilisateur"));
                Reclamations.add(rec);
            }
        } catch (SQLException e) {
            // Handle SQL exceptions appropriately (log, inform user, etc.)
            e.printStackTrace();
        }


        return Reclamations;
    }

    @Override
    public ObservableList<Donation> selectAllDon() throws SQLException {
        return null;
    }
    public Reclamation getReclamation(int id) throws SQLException {
        Reclamation reclamation = null;
        String query = "SELECT * FROM reclamation WHERE id_reclamation = ?";
        if (cnx == null || cnx.isClosed()) {
            // reconnect to the database
            cnx = DBConnection.getInstance().getCnx();
        }
        try (PreparedStatement st = cnx.prepareStatement(query)) {
            st.setInt(1, id);

            try (ResultSet rs = st.executeQuery()) {
                if (rs.next()) {
                    reclamation = new Reclamation();
                    reclamation.setId(rs.getInt("id_reclamation"));
                    reclamation.setEmail(rs.getString("email"));
                    reclamation.setDescription(rs.getString("description"));
                    reclamation.setEtat(rs.getString("etat"));
                    reclamation.setId_cm(rs.getInt("id_commande"));
                    reclamation.setIdUtilisateur(rs.getInt("idUtilisateur"));
                }
            }
        }
        return reclamation;
    }
    public ArrayList<Reclamation> getReclamationsByUserId(int idUser) throws SQLException {
        ArrayList<Reclamation> reclamations = new ArrayList<>();
        Connection conn = null;
        PreparedStatement stmt = null;
        ResultSet rs = null;

        try {
            conn = DBConnection.getInstance().getCnx(); // Remplacez YourDatabaseConnection par votre classe de connexion à la base de données
            String query = "SELECT * FROM reclamation WHERE idUtilisateur= ?";
            stmt = conn.prepareStatement(query);
            stmt.setInt(1, idUser);
            rs = stmt.executeQuery();

            while (rs.next()) {
                int idReclamation = rs.getInt("id_reclamation");
                String description = rs.getString("description");
                // Autres colonnes de votre table de réclamations à récupérer

                // Créer un objet Reclamation avec les données récupérées
                Reclamation reclamation = new Reclamation(idReclamation, idUser, description);
                // Ajouter la réclamation à la liste
                reclamations.add(reclamation);
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } finally {
            // Fermeture des ressources
            if (rs != null) rs.close();
            if (stmt != null) stmt.close();
            if (conn != null) conn.close();
        }

        return reclamations;
    }

}
