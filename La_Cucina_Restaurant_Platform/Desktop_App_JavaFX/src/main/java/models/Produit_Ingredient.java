package models;

public class Produit_Ingredient {
    private int id;
    private int id_produit;
    private int id_ingredient;

    public Produit_Ingredient() {
    }

    public Produit_Ingredient(int id_produit, int id_ingredient) {
        this.id_produit = id_produit;
        this.id_ingredient = id_ingredient;
    }

    public Produit_Ingredient(int id, int id_produit, int id_ingredient) {
        this.id = id;
        this.id_produit = id_produit;
        this.id_ingredient = id_ingredient;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public int getId_produit() {
        return id_produit;
    }

    public void setId_produit(int id_produit) {
        this.id_produit = id_produit;
    }

    public int getId_ingredient() {
        return id_ingredient;
    }

    public void setId_ingredient(int id_ingredient) {
        this.id_ingredient = id_ingredient;
    }

    @Override
    public String toString() {
        return "Produit_Ingredient{" +
                "id=" + id +
                ", id_produit=" + id_produit +
                ", id_ingredient=" + id_ingredient +
                '}';
    }
}
