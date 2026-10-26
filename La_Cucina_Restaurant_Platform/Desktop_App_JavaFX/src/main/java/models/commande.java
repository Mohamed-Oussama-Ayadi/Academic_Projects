package models;

import utils.DBConnection;

import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;

public class commande {
    private int id_commande;
    private String date_commande;
    private Float montant_commande;
    private String mode_paiement;

    public commande(int id_commande, String date_commande, Float montant_commande, String mode_paiement) {
        this.id_commande = id_commande;
        this.date_commande = date_commande;
        this.montant_commande = montant_commande;
        this.mode_paiement = mode_paiement;
    }

    public commande(String date_commande, Float montant_commande, String mode_paiement) {
        this.date_commande = date_commande;
        this.montant_commande = montant_commande;
        this.mode_paiement = mode_paiement;
    }

    public commande() {
    }

    public int getId_commande() {
        return id_commande;
    }

    public void setId_commande(int id_commande) {
        this.id_commande = id_commande;
    }

    public String getDate_commande() {
        return date_commande;
    }

    public void setDate_commande(String date_commande) {
        this.date_commande = date_commande;
    }

    public Float getMontant_commande() {
        return montant_commande;
    }

    public void setMontant_commande(Float montant_commande) {
        this.montant_commande = montant_commande;
    }

    public String getMode_paiement() {
        return mode_paiement;
    }

    public void setMode_paiement(String mode_paiement) {
        this.mode_paiement = mode_paiement;
    }

    @Override
    public String toString() {
        return "commande{" +
                "id_commande=" + id_commande +
                ", date_commande='" + date_commande + '\'' +
                ", montant_commande=" + montant_commande +
                ", mode_paiement='" + mode_paiement + '\'' +
                '}';
    }
    public static commande getUserById(int id) throws SQLException {
         Connection cnx;
        commande cms = null;
        cnx = null;
        PreparedStatement statement = null;
        ResultSet resultSet = null;

        try {
            cnx = DBConnection.getInstance().getCnx();
            String sql = "SELECT * FROM commande WHERE id_commande = ?";
            statement = cnx.prepareStatement(sql);
            statement.setInt(1, id); // Utiliser la nouvelle variable id
            resultSet = statement.executeQuery();
            if (resultSet.next()) {
                // Récupérer les informations de l'utilisateur à partir du ResultSet
                int cm_id = resultSet.getInt("id_commande");
                String date_cm = resultSet.getString("date_commande");
                Float montant_cm = resultSet.getFloat("montant_total");
                String mode_paiement = resultSet.getString("mode_paiement");

                // Créer un objet User avec les données récupérées
                cms = new commande(cm_id, date_cm, montant_cm, mode_paiement
                       );
            }
        } finally {
            // Fermeture des ressources dans un bloc finally pour s'assurer qu'elles sont toujours fermées,
            // même en cas d'exception
            if (resultSet != null) {
                resultSet.close();
            }
            if (statement != null) {
                statement.close();
            }
            // Ne fermez pas la connexion ici, car elle doit être utilisée par d'autres méthodes
            // La connexion sera fermée au niveau supérieur, dans le code qui appelle cette méthode
        }

        return cms;
    }
}
