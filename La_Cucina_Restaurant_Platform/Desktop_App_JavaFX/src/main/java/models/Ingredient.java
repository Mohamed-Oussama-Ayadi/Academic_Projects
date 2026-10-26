package models;

public class Ingredient {
    private int id;
    private String nom;
    private String image;
    private double prix;
    private Categorie categorie;

    public Ingredient() {
    }

    public Ingredient(String nom, String image, double prix, Categorie categorie) {
        this.nom = nom;
        this.image = image;
        this.prix = prix;
        this.categorie = categorie;
    }

    public Ingredient(int id, String nom, String image, double prix, Categorie categorie) {
        this.id = id;
        this.nom = nom;
        this.image = image;
        this.prix = prix;
        this.categorie = categorie;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public double getPrix() {
        return prix;
    }

    public void setPrix(double prix) {
        this.prix = prix;
    }

    public Categorie getCategorie() {
        return categorie;
    }

    public void setCategorie(Categorie categorie) {
        this.categorie = categorie;
    }

    @Override
    public String toString() {
        return "Ingredient{" +
                "id=" + id +
                ", nom='" + nom + '\'' +
                ", image='" + image + '\'' +
                ", prix=" + prix +
                ", categorie=" + categorie +
                '}';
    }
}
