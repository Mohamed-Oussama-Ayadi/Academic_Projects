package services;


import models.Evenements;
import models.Role;
import models.Utilisateurs;
import utils.DBConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
public class ServiceUserEvent {

    private Connection cnx;

    public ServiceUserEvent() {
        cnx = DBConnection.getInstance().getCnx();
    }
    public List<Utilisateurs> getUsersWithAbonnements() throws SQLException {
        List<Utilisateurs> usersinTheEvent = new ArrayList<>();
        String req = "SELECT DISTINCT u.* FROM `utilisateurs` u JOIN `userevent` au ON u.idUtilisateur = au.id_utilisateur";
        PreparedStatement ps = cnx.prepareStatement(req);

        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            Utilisateurs user = new Utilisateurs();

            user.setIdUtilisateur(rs.getInt("idUtilisateur"));
            user.setNom(rs.getString("nom"));
            user.setPrenom(rs.getString("prenom"));
            user.setSurnom(rs.getString("surnom"));
            user.setSexe(rs.getString("sexe"));
            user.setEmail(rs.getString("email"));
            user.setNumeroTelephone(rs.getInt("numeroTelephone"));
            //utilisateurs.setRole(rs.getString("role"));
            String roleS=rs.getString("role");
            Role role = Role.valueOf(roleS);
            user.setRole(role);
            user.setMotDePasse(rs.getString("motDePasse"));
            user.setImage_user(rs.getString("image_user"));

            usersinTheEvent.add(user);
        }
        return usersinTheEvent;
    }


    public List<Evenements> selectEventsForUser(int userId) throws SQLException {
        List<Evenements> evenements = new ArrayList<>();
        String req = "SELECT a.* FROM evenements a JOIN userevent au ON a.id_event = au.id_event WHERE au.id_utilisateur = ?";
        try (PreparedStatement ps = cnx.prepareStatement(req)) {
            ps.setInt(1, userId);
            try (ResultSet rs = ps.executeQuery()) {
                while (rs.next()) {
                    Evenements evenement = new Evenements();
                    evenement.setId_event(rs.getInt("id_event"));
                    evenement.setNom_event(rs.getString("nom_event"));
                    evenement.setDate_event(rs.getDate("date_event"));
                    evenement.setHeure_event(rs.getTime("heure_event"));
                    evenement.setDescription_event(rs.getString("description_event"));
                    evenements.add(evenement);



                }
            }
        }
        return evenements;
    }
    public List<Evenements> getEvenementsEventForUser(int userId) throws SQLException {
        List<Evenements> evenements = new ArrayList<>();
        String req = "SELECT a.* FROM evenements e JOIN userevent eu ON e.id_event = eu.id_evenement WHERE eu.id_utilisateur = ?";
        PreparedStatement ps = cnx.prepareStatement(req);
        ps.setInt(1, userId);

        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            Evenements evenement = new Evenements();

            evenement.setId_event(rs.getInt("id_event"));
            evenement.setNom_event(rs.getString("nom_event"));
            evenement.setNom_event(rs.getString("nom_event"));





            // Autres attributs d'abonnement à initialiser si nécessaire
            evenements.add(evenement);
        }
        return evenements;
    }

// tfaskh l user mel table de jointure
    public void deleteEventUser(int userId) throws SQLException {
        String req = "DELETE FROM userevent WHERE id_utilisateur = ?";
        try (PreparedStatement ps = cnx.prepareStatement(req)) {
            ps.setInt(1, userId);
            ps.executeUpdate();
        }
    }


    public void deleteUserEvent(int userId) throws SQLException {
        String req = "DELETE FROM userevent WHERE id_event = ?";
        try (PreparedStatement ps = cnx.prepareStatement(req)) {
            ps.setInt(1, userId);
            ps.executeUpdate();
        }
    }






}





