package services;

import models.Evenements;
import models.Utilisateurs;
import utils.DBConnection;
import java.sql.Date;
import java.sql.Time;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;

public class ServiceEvenements implements CRUDEvenement<Evenements> {

private final DBConnection cnx ;
    public ServiceEvenements() {
        cnx = DBConnection.getInstance();
    }

    @Override
    public void insertOne1(Evenements evenement) throws SQLException {
        String req = "INSERT INTO evenements ( nom_event, date_event, heure_event,description_event) VALUES (?, ?, ?, ?)";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);

        ps.setString(1, evenement.getNom_event());
        ps.setDate(2, evenement.getDate_event());
        ps.setTime(3, evenement.getHeure_event());
        ps.setString(4, evenement.getDescription_event());


       // ps.setInt(5, evenement.getIdUtilisateur().getIdUtilisateur());

        int rowsAffected = ps.executeUpdate();
        if (rowsAffected > 0) {
            System.out.println("L'événement a été ajouté avec succès.");
        } else {
            System.out.println("L'ajout de l'événement a échoué. Veuillez vérifier les données et réessayer.");
        }
    }

    @Override
    public void update(Evenements evenement) throws SQLException {
        String req = "UPDATE evenements SET nom_event=?, date_event=?, heure_event=?, description_event=? WHERE id_event=?";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);

        ps.setString(1, evenement.getNom_event());
        ps.setDate(2, evenement.getDate_event());
        ps.setTime(3, evenement.getHeure_event());
        ps.setString(4, evenement.getDescription_event());
        ps.setInt(5, evenement.getId_event());

        int rowsAffected = ps.executeUpdate();

        if (rowsAffected > 0) {
            System.out.println("L'événement avec l'ID " + evenement.getId_event() + " a été mis à jour avec succès.");
        } else {
            System.out.println("La mise à jour de l'événement a échoué.");
        }
    }

    @Override
    public void delete(Evenements evenement) throws SQLException {
        String req = "DELETE FROM evenements WHERE id_event=?";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);

        ps.setInt(1, evenement.getId_event());

        int rowsAffected = ps.executeUpdate();

        if (rowsAffected > 0) {
            System.out.println("L'événement avec l'ID " + evenement.getId_event() + " a été supprimé avec succès.");
        } else {
            System.out.println("La suppression de l'événement a échoué.");
        }
    }

    @Override
    public List<Evenements> selectAll() throws SQLException {
        List<Evenements> evenementsList = new ArrayList<>();

        String req = "SELECT * FROM evenements";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ResultSet rs = ps.executeQuery();

        while (rs.next()) {
            Evenements evenement = new Evenements();
            evenement.setId_event(rs.getInt("id_event"));
            evenement.setNom_event(rs.getString("nom_event"));
            evenement.setDate_event(rs.getDate("date_event"));
            evenement.setHeure_event(rs.getTime("heure_event"));
            evenement.setDescription_event(rs.getString("description_event"));

            evenementsList.add(evenement);
        }

        return evenementsList;
    }

    // Méthode pour récupérer un utilisateur par son ID
    private Utilisateurs fetchUtilisateurById(int id) throws SQLException {
        String req = "SELECT * FROM utilisateurs WHERE idUtilisateur=?";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ps.setInt(1, id);
        ResultSet rs = ps.executeQuery();

        if (rs.next()) {
            Utilisateurs utilisateur = new Utilisateurs();
            utilisateur.setIdUtilisateur(rs.getInt("idUtilisateur"));
            // Ajouter les autres attributs de l'utilisateur selon votre modèle Utilisateurs
            return utilisateur;
        } else {
            return null;
        }
    }




    public void inscrireUser(Evenements evenements, Utilisateurs user) throws SQLException {
        String req = "INSERT INTO userevent (id_event, id_utilisateur) VALUES (?, ?)";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ps.setInt(1, evenements.getId_event());
        ps.setInt(2, user.getIdUtilisateur());
        ps.executeUpdate();
    }



    public List<String> selectAllTypesAbonnements() throws SQLException {
        List<String> typesAbonnements = new ArrayList<>();
        String req = "SELECT DISTINCT type FROM abonnement";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            typesAbonnements.add(rs.getString("type"));
        }
        return typesAbonnements;
    }
    public Evenements selectEvenementByNom(String nom_event) throws SQLException {
        String req = "SELECT * FROM evenements WHERE nom_event=?";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ps.setString(1, nom_event);
        ResultSet rs = ps.executeQuery();

        if (rs.next()) {
            int id_event = rs.getInt("id_event");
            Date date_event = rs.getDate("date_event");
            Time heure_event = rs.getTime("heure_event");
            String description_event = rs.getString("description_event");

            // Utilisez un autre nom pour la variable locale pour éviter la confusion
            String nomEventFromDB = rs.getString("nom_event");

            return new Evenements(id_event, nomEventFromDB, date_event, heure_event, description_event);
        }

        return null;
    }



    public Evenements selectEvenementById(int evenementId) throws SQLException {
        String req = "SELECT * FROM evenements WHERE id_event=?";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ps.setInt(1, evenementId);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {

             String nom_event = rs.getString("nom_event");
            Date date_event = rs.getDate("date_event");
            Time heure_event = rs.getTime("heure_event");
            String description_event = rs.getString("description_event");

            return new Evenements(evenementId, nom_event, date_event,heure_event, description_event);
        }
        return null;
    }


    public boolean userInEvent(Utilisateurs user, Evenements evenement) throws SQLException {
        String req = "SELECT * FROM  userevent WHERE id_utilisateur=? AND id_event=?";
        PreparedStatement ps = DBConnection.getInstance().getCnx().prepareStatement(req);
        ps.setInt(1, user.getIdUtilisateur());
        ps.setInt(2, evenement.getId_event());
        ResultSet rs = ps.executeQuery();
        return rs.next();
    }


    public Evenements selectEventByDateTime(Date date, Time time) throws SQLException {
        String req = "SELECT * FROM evenements WHERE date_event=? AND heure_event=?";
        PreparedStatement ps = cnx.getCnx().prepareStatement(req);
        ps.setDate(1, date);
        ps.setTime(2, time);
        ResultSet rs = ps.executeQuery();

        if (rs.next()) {
            int id_event = rs.getInt("id_event");
            String nom_event = rs.getString("nom_event");
            String description_event = rs.getString("description_event");

            // Créer un nouvel objet Evenements avec les données récupérées
            return new Evenements(id_event, nom_event, date, time, description_event);
        }

        // Si aucun événement correspondant n'est trouvé, retourner null
        return null;
    }


}
