package services;

import models.Categorie;
import models.Ingredient;
import utils.DBConnection;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

public class ServiceIngredient implements CRUDUser<Ingredient> {
    private Connection cnx;

    public ServiceIngredient() {
        cnx = DBConnection.getInstance().getCnx();
    }

    @Override
    public void insertOne1(Ingredient ingredient) throws SQLException {
        String query = "INSERT INTO Ingredient (nom, image, prix, categorie) VALUES (?, ?, ?, ?)";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setString(1, ingredient.getNom());
        ps.setString(2, ingredient.getImage());
        ps.setDouble(3, ingredient.getPrix());
        ps.setString(4, ingredient.getCategorie().toString());
        ps.executeUpdate();
    }

    @Override
    public void update(Ingredient ingredient) throws SQLException {
        String query = "UPDATE Ingredient SET nom=?, image=?, prix=?, categorie=? WHERE id=?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setString(1, ingredient.getNom());
        ps.setString(2, ingredient.getImage());
        ps.setDouble(3, ingredient.getPrix());
        ps.setString(4, ingredient.getCategorie().toString());
        ps.setInt(5, ingredient.getId());
        ps.executeUpdate();
    }

    @Override
    public void delete(Ingredient ingredient) throws SQLException {
        String query = "DELETE FROM Ingredient WHERE id=?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, ingredient.getId());
        ps.executeUpdate();
    }

    @Override
    public List<Ingredient> selectAll() throws SQLException {
        List<Ingredient> ingredients = new ArrayList<>();
        String query = "SELECT * FROM Ingredient";
        PreparedStatement ps = cnx.prepareStatement(query);
        ResultSet rs = ps.executeQuery();

        while (rs.next()) {
            Ingredient ingredient = new Ingredient();
            ingredient.setId(rs.getInt("id"));
            ingredient.setNom(rs.getString("nom"));
            ingredient.setImage(rs.getString("image"));
            ingredient.setPrix(rs.getDouble("prix"));
            ingredient.setCategorie(Categorie.valueOf(rs.getString("categorie")));

            ingredients.add(ingredient);
        }

        return ingredients;
    }
    public List<Ingredient> getIngredientsByCategorie(Categorie categorieProduit) {
        try {
            return selectAll().stream()
                    .filter(ingredient -> ingredient.getCategorie().equals(categorieProduit))
                    .collect(Collectors.toList());
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }
}
