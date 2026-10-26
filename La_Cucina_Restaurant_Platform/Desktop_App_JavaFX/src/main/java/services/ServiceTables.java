package services;
import com.sun.javafx.charts.Legend;
import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.scene.control.ListView;
import models.Reservations;
import models.Tables;
import utils.DBConnection;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;


public class ServiceTables implements CRUD_Tables<Tables> {

    private Connection cnx ;
    public ServiceTables() {
        cnx = DBConnection.getInstance().getCnx();
    }

    ////////////////////////////////////////////////////////////////////////////////////////

   @Override
    public void update(Tables tables) throws SQLException {
        String req = "UPDATE tables SET  capacite=?, emplacement=?, disponibilite=? WHERE numeroTable=? ";
       PreparedStatement ps = cnx.prepareStatement(req);


       ps.setInt(1, tables.getCapacite());
       ps.setString(2, tables.getEmplacement());
       ps.setBoolean(3, tables.isDisponibilite());
       ps.setInt(4, tables.getNumeroTable());
       ps.executeUpdate();

    }
    public void updateAvailability(int tableNumber, boolean availability) throws SQLException {
        String query = "UPDATE tables SET disponibilite = ? WHERE numeroTable = ?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setBoolean(1, availability);
        ps.setInt(2, tableNumber);
        ps.executeUpdate();
    }
    public List<Tables> getTablesByCapacityAndAvailability(int capacity, boolean isAvailable) throws SQLException {
        List<Tables> filteredTables = new ArrayList<>();
        String query = "SELECT * FROM tables WHERE capacite >= ? AND disponibilite = ?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, capacity);
        ps.setBoolean(2, isAvailable);
        ResultSet rs = ps.executeQuery();

        while (rs.next()) {
            Tables table = new Tables();
            table.setNumeroTable(rs.getInt("numeroTable"));
            table.setCapacite(rs.getInt("capacite"));
            table.setEmplacement(rs.getString("emplacement"));
            table.setDisponibilite(rs.getBoolean("disponibilite"));
            filteredTables.add(table);
        }

        return filteredTables;
    }
    ////////////////////////////////////////////////////////////////////////////////////////
   @Override
    public void delete(Tables tables) throws SQLException {

           String selectQuery = "SELECT * FROM tables WHERE numeroTable=?";
           PreparedStatement selectStatement = cnx.prepareStatement(selectQuery);
           selectStatement.setInt(1, tables.getNumeroTable());
           ResultSet resultSet = selectStatement.executeQuery();

           if (resultSet.next()) { // Si trouve
               // Supprimer la table de la base de données
               String deleteQuery = "DELETE FROM tables WHERE numeroTable=?";
               PreparedStatement deleteStatement = cnx.prepareStatement(deleteQuery);
               deleteStatement.setInt(1, tables.getNumeroTable());
               deleteStatement.executeUpdate();
               System.out.println("Table avec numero table" + tables.getNumeroTable() + " a ete supprimee avec succes.");
           }
           else
           {
               // Afficher un message indiquant que la personne n'a pas été trouvée
               System.out.println("Aucune Table avec numero table " + tables.getNumeroTable() + " n'a ete trouvee dans la base de donnees.");
           }


    }

    ////////////////////////////////////////////////////////////////////////////////////////
    @Override
    public List<Tables> selectAll() throws SQLException {
        List<Tables> TablesList= new ArrayList<>();

        String req = "SELECT * FROM `Tables`";
        Statement st = cnx.createStatement();

        ResultSet rs = st.executeQuery(req);

        while (rs.next()){
            Tables t = new Tables();

            t.setNumeroTable(rs.getInt(("numeroTable")));
            t.setCapacite(rs.getInt(("capacite")));
            t.setEmplacement(rs.getString(("emplacement")));
            t.setDisponibilite(rs.getBoolean(("disponibilite")));

            TablesList.add(t);
        }

        return TablesList;
    }
    ////////////////////////////////////////////////////////////////////////////////////////
    public void insert(Tables tables) throws SQLException {
        String req = "INSERT INTO `tables` (`numeroTable`, `capacite`, `emplacement`, `disponibilite`) VALUES "+
                "(?,?,?,?)";
        PreparedStatement ps = cnx.prepareStatement(req);

        ps.setInt(1, tables.getNumeroTable());
        ps.setInt(2, tables.getCapacite());
        ps.setString(3, tables.getEmplacement());
        ps.setBoolean(4, tables.isDisponibilite());

        ps.executeUpdate();
    }

    ////////////////////////////////////////////////////////////////////////////////////////
   @Override
    public void displayAllTable()
    {
        try{
            List<Tables> tables=selectAll();
            if(tables.isEmpty()){
                System.out.println("Aucune table trouve");
            }
            else {
                System.out.println("Liste de table");
                for(Tables table : tables)
                {System.out.println(table.getNumeroTable()+","+table.getCapacite()+","+table.getEmplacement());
                }
            }

        }
        catch(SQLException e){
            System.err.println("erreur de la recuperation"+e.getMessage());

    }
    }


    public boolean isTableAvailable(String emplacement, Date date, String horaire) throws SQLException {
        String query = "SELECT disponibilite FROM tables WHERE emplacement = ? AND date = ? AND horaire = ?";
        PreparedStatement ps = DBConnection.getCnx().prepareStatement(query);
        ps.setString(1, emplacement);
        ps.setDate(2, new java.sql.Date(date.getTime()));
        ps.setString(3, horaire);
        ResultSet rs = ps.executeQuery();

        if (rs.next()) {
            return rs.getBoolean("disponibilite");
        } else {
            return false;
        }
    }
}

