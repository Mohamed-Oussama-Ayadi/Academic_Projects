package services;

import models.Produit_Ingredient;
import utils.DBConnection;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;

public class ServiceProduitIngredient implements CRUDUser<Produit_Ingredient> {
    private Connection cnx;

    public ServiceProduitIngredient() {
        cnx = DBConnection.getInstance().getCnx();
    }

    @Override
    public void insertOne1(Produit_Ingredient produitIngredient) throws SQLException {
        String query = "INSERT INTO Produit_Ingredient (id_produit, id_ingredient) VALUES (?, ?)";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, produitIngredient.getId_produit());
        ps.setInt(2, produitIngredient.getId_ingredient());
        ps.executeUpdate();
    }

    @Override
    public void update(Produit_Ingredient produitIngredient) throws SQLException {
        String query = "UPDATE Produit_Ingredient SET id_produit=?, id_ingredient=? WHERE id=?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, produitIngredient.getId_produit());
        ps.setInt(2, produitIngredient.getId_ingredient());
        ps.setInt(3, produitIngredient.getId());
        ps.executeUpdate();
    }

    @Override
    public void delete(Produit_Ingredient produitIngredient) throws SQLException {
        String query = "DELETE FROM Produit_Ingredient WHERE id=?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, produitIngredient.getId());
        ps.executeUpdate();
    }
    public void deleteParProduitEtIngredient(int idProduit, int idIngredient) throws SQLException {
        String query = "DELETE FROM Produit_Ingredient WHERE id_produit = ? AND id_ingredient = ?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, idProduit);
        ps.setInt(2, idIngredient);
        ps.executeUpdate();
    }
    public void deleteParIdProduit(int idProduit) throws SQLException {
        String query = "DELETE FROM Produit_Ingredient WHERE id_produit = ?";
        try (PreparedStatement ps = cnx.prepareStatement(query)) {
            ps.setInt(1, idProduit);
            ps.executeUpdate();
        }
    }

    @Override
    public List<Produit_Ingredient> selectAll() throws SQLException {
        List<Produit_Ingredient> produitIngredients = new ArrayList<>();
        String query = "SELECT * FROM Produit_Ingredient";
        PreparedStatement ps = cnx.prepareStatement(query);
        ResultSet rs = ps.executeQuery();

        while (rs.next()) {
            Produit_Ingredient produitIngredient = new Produit_Ingredient();
            produitIngredient.setId(rs.getInt("id"));
            produitIngredient.setId_produit(rs.getInt("id_produit"));
            produitIngredient.setId_ingredient(rs.getInt("id_ingredient"));

            produitIngredients.add(produitIngredient);
        }

        return produitIngredients;
    }
    public double getPrixTotalProduit(int idProduit) throws SQLException {
        double prixTotal = 0.0;

        String queryProduit = "SELECT prix FROM Produit WHERE id = ?";
        try (PreparedStatement psProduit = cnx.prepareStatement(queryProduit)) {
            psProduit.setInt(1, idProduit);
            try (ResultSet rsProduit = psProduit.executeQuery()) {
                if (rsProduit.next()) {
                    prixTotal += rsProduit.getDouble("prix");
                }
            }
        }

        String queryIngredients = "SELECT SUM(i.prix) AS prixIngredients " +
                "FROM Ingredient i " +
                "INNER JOIN Produit_Ingredient pi ON i.id = pi.id_ingredient " +
                "WHERE pi.id_produit = ?";
        try (PreparedStatement psIngredients = cnx.prepareStatement(queryIngredients)) {
            psIngredients.setInt(1, idProduit);
            try (ResultSet rsIngredients = psIngredients.executeQuery()) {
                if (rsIngredients.next()) {
                    double prixIngredients = rsIngredients.getDouble("prixIngredients");
                    if (!rsIngredients.wasNull()) {
                        prixTotal += prixIngredients;
                    }
                }
            }
        }

        return prixTotal;
    }

}
