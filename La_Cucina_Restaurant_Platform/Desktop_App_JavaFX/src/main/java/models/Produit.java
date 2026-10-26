package models;

public class Produit {
    private int id;
    private String nom;
    private double prix;
    private String description;
    private int note;
    private String image;
    private Categorie categorie;

    public Produit() {
    }

    public Produit(String nom, double prix, String description, int note, String image, Categorie categorie) {
        this.nom = nom;
        this.prix = prix;
        this.description = description;
        this.note = note;
        this.image = image;
        this.categorie = categorie;
    }

    public Produit(int id, String nom, double prix, String description, int note, String image, Categorie categorie) {
        this.id = id;
        this.nom = nom;
        this.prix = prix;
        this.description = description;
        this.note = note;
        this.image = image;
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

    public double getPrix() {
        return prix;
    }

    public void setPrix(double prix) {
        this.prix = prix;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public int getNote() {
        return note;
    }

    public void setNote(int note) {
        this.note = note;
    }

    public String getImage() {
        return image;
    }

    public void setImage(String image) {
        this.image = image;
    }

    public Categorie getCategorie() {
        return categorie;
    }

    public void setCategorie(Categorie categorie) {
        this.categorie = categorie;
    }

    @Override
    public String toString() {
        return "Produit{" +
                "id=" + id +
                ", nom='" + nom + '\'' +
                ", prix=" + prix +
                ", description='" + description + '\'' +
                ", note=" + note +
                ", image='" + image + '\'' +
                ", categorie=" + categorie +
                '}';
    }
}
