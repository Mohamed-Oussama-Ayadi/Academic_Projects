package services;

import models.Categorie;
import models.Produit;
import utils.DBConnection;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class ServiceProduit implements CRUDUser<Produit> {
    private Connection cnx;

    public ServiceProduit() {
        cnx = DBConnection.getInstance().getCnx();
    }

    @Override
    public void insertOne1(Produit produit) throws SQLException {
        String query = "INSERT INTO Produit (nom, prix, description, note, image, categorie) VALUES (?, ?, ?, ?, ?, ?)";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setString(1, produit.getNom());
        ps.setDouble(2, produit.getPrix());
        ps.setString(3, produit.getDescription());
        ps.setInt(4, produit.getNote());
        ps.setString(5, produit.getImage());
        ps.setString(6, produit.getCategorie().toString());
        ps.executeUpdate();
    }

    @Override
    public void update(Produit produit) throws SQLException {
        String query = "UPDATE Produit SET nom=?, prix=?, description=?, note=?, image=?, categorie=? WHERE id=?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setString(1, produit.getNom());
        ps.setDouble(2, produit.getPrix());
        ps.setString(3, produit.getDescription());
        ps.setInt(4, produit.getNote());
        ps.setString(5, produit.getImage());
        ps.setString(6, produit.getCategorie().toString());
        ps.setInt(7, produit.getId());
        ps.executeUpdate();
    }

    @Override
    public void delete(Produit produit) throws SQLException {
        String query = "DELETE FROM Produit WHERE id=?";
        PreparedStatement ps = cnx.prepareStatement(query);
        ps.setInt(1, produit.getId());
        ps.executeUpdate();
    }

    @Override
    public List<Produit> selectAll() throws SQLException {
        List<Produit> produits = new ArrayList<>();
        String query = "SELECT * FROM Produit";
        PreparedStatement ps = cnx.prepareStatement(query);
        ResultSet rs = ps.executeQuery();

        while (rs.next()) {
            Produit produit = new Produit();
            produit.setId(rs.getInt("id"));
            produit.setNom(rs.getString("nom"));
            produit.setPrix(rs.getDouble("prix"));
            produit.setDescription(rs.getString("description"));
            produit.setNote(rs.getInt("note"));
            produit.setImage(rs.getString("image"));
            produit.setCategorie(Categorie.valueOf(rs.getString("categorie")));

            produits.add(produit);
        }

        return produits;
    }
    public List<Produit> trierProduits(List<Produit> produits, String critere) {
        switch (critere) {
            case "Nom":
                return produits.stream()
                        .sorted(Comparator.comparing(Produit::getNom))
                        .collect(Collectors.toList());
            case "Prix":
                return produits.stream()
                        .sorted(Comparator.comparing(Produit::getPrix))
                        .collect(Collectors.toList());
            case "Note":
                return produits.stream()
                        .sorted(Comparator.comparing(Produit::getNote))
                        .collect(Collectors.toList());
            default:
                try {
                    return selectAll();
                } catch (SQLException e) {
                    throw new RuntimeException(e);
                }
        }
    }
    public Produit getProduitById(List<Produit> produits, int id) {
        return produits.stream()
                .filter(produit -> produit.getId() == id)
                .findFirst().orElse(null);
    }
    public List<Produit> getListProduitParCategorie(Categorie categorie) throws SQLException {
        return selectAll().stream()
                .filter(produit -> produit.getCategorie().equals(categorie))
                .collect(Collectors.toList());
    }



}
