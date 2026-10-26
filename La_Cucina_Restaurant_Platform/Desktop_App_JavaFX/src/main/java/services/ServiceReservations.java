package services;

import models.Reservations;
import utils.DBConnection;

import java.sql.*;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;

public class ServiceReservations implements CRUD_Reservations<Reservations> {
    private final DBConnection dbConnection;
    private Connection cnx;
    private PreparedStatement pre;
    public ServiceReservations() {
        dbConnection = DBConnection.getInstance();
        cnx= DBConnection.getInstance().getCnx();
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @Override
    public void insert(Reservations reservations) throws SQLException {

        try {
            String req = "INSERT INTO reservations (nbr_personnes, date, horaire,num_tab,idUtilisateur) VALUES " +"('"+reservations.getNbr_personnes()+"','"+reservations.getDate()+"','"+reservations.getHoraire()+"','"+reservations.getNum()+"','"+reservations.getIdUtilisateur()+"')";
            Statement st = cnx.createStatement();
            st.executeUpdate(req);
        }catch (SQLException ex)
        {
            System.out.println("probleme");
            System.out.println(ex.getMessage());
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////
   @Override
   public void updateReservation(Reservations reservation) throws SQLException {
       if (reservation.getDate() == null) {
           throw new IllegalArgumentException("La date de la réservation ne peut pas être null");
       }

       String req = "UPDATE reservations SET nbr_personnes=?, date=?, horaire=?, num_tab=? WHERE id_reservation=?";
       PreparedStatement ps = dbConnection.getCnx().prepareStatement(req);

       ps.setInt(1, reservation.getNbr_personnes());
       ps.setDate(2, new java.sql.Date(reservation.getDate().getTime()));
       ps.setString(3, reservation.getHoraire());
       ps.setInt(4, reservation.getNumero_table());
       ps.setInt(5, reservation.getId_reservation()); // Assurez-vous de définir le cinquième paramètre (id_reservation)

       ps.executeUpdate();
   }
    ////////////////////////////////////////////////////////////////////////////////////////
    @Override
    public void deleteReservation(Reservations reservation) throws SQLException {
        String req = "DELETE FROM reservations WHERE id_reservation=?";
        PreparedStatement ps = dbConnection.getCnx().prepareStatement(req);
        ps.setInt(1, reservation.getId_reservation());
        ps.executeUpdate();
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    @Override
    public List<Reservations> selectAllReservations() throws SQLException {
        List<Reservations> reservationList = new ArrayList<>();
        String req = "SELECT * FROM reservations";
        PreparedStatement ps = dbConnection.getCnx().prepareStatement(req);
        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            int id_reservation = rs.getInt("id_reservation");
            int nbr_personnes = rs.getInt("nbr_personnes");
            Date date = rs.getDate("date");
            String horaire = rs.getString("horaire");
            int num = rs.getInt("num_tab");
            int iduser = rs.getInt("idUtilisateur");
           // String emplacement = rs.getString("emplacement");

            Reservations reservation = new Reservations( id_reservation,nbr_personnes, horaire, (java.sql.Date) date,num,iduser);

            reservationList.add(reservation);
        }
        return reservationList;
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    public boolean isReservationPossible(String emplacement, Date date, String horaire) throws SQLException {
        // Effectuer la requête pour vérifier la disponibilité de la table
        String query = "SELECT COUNT(*) AS count FROM reservations WHERE emplacement = ? AND date = ? AND horaire = ?";
        PreparedStatement ps = dbConnection.getCnx().prepareStatement(query);
        ps.setString(1, emplacement);
        ps.setDate(2, new java.sql.Date(date.getTime()));
        ps.setString(3, horaire);
        ResultSet rs = ps.executeQuery();

        // Vérifier si une réservation correspondante a été trouvée
        if (rs.next()) {
            int count = rs.getInt("count");
            return count == 0; // Si aucun enregistrement trouvé, la table est disponible à cette date et cet horaire
        } else {
            return true; // Si aucun enregistrement trouvé, la table est disponible
        }
    }


///////////////////////////////////////////////////////////////////////////////////////////
    public void displayAllReservations() throws SQLException {
        List<Reservations> reservationList = selectAllReservations();
        for (Reservations reservation : reservationList) {
            System.out.println(reservation);
        }


    }
    ////////////////////////////////////////////////////////////////////////////////////////
    public boolean reservationExists(int nbrPersonnes, String horaire, Date date, int numeroTable) throws SQLException {
        String req = "SELECT COUNT(*) FROM reservations WHERE nbr_personnes=? AND horaire=? AND date=? AND num_tab=?";
        PreparedStatement ps = dbConnection.getCnx().prepareStatement(req);
        ps.setInt(1, nbrPersonnes);
        ps.setString(2, horaire);
        ps.setDate(3, new java.sql.Date(date.getTime()));
        ps.setInt(4, numeroTable);

        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            int count = rs.getInt(1);
            return count > 0;
        }
        return false;
    }

}
