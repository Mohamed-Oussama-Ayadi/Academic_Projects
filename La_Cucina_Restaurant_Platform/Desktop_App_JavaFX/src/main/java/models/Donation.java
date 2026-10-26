package models;

import javafx.scene.control.DatePicker;

import java.time.LocalDate;

public class Donation {
    int id_donation ;
    float montant ;
    LocalDate date_don ;
    String type_don;
    Utilisateurs user = new Utilisateurs();
    private  int idUtilisateur=user.getIdUtilisateur();
    public int getIdUtilisateur() {
        return idUtilisateur;
    }

    public void setIdUtilisateur(int idUtilisateur) {
        this.idUtilisateur = idUtilisateur;
    }


    public Donation(int id_donation, float montant, LocalDate date_don, String type_don) {
        this.id_donation = id_donation;
        this.montant = montant;
        this.date_don = date_don;
        this.type_don = type_don;
    }
    public Donation( float montant, LocalDate date_don, String type_don, int idUtilisateur) {
        this.montant = montant;
        this.date_don = date_don;
        this.type_don = type_don;
        this.idUtilisateur= idUtilisateur;
    }
    public Donation() {
    }


    public int getId_donation() {
        return id_donation;
    }

    public void setId_donation(int id_donation) {
        this.id_donation = id_donation;
    }

    public float getMontant() {
        return montant;
    }

    public void setMontant(float montant) {
        this.montant = montant;
    }

    public LocalDate getDate_don() {
        return date_don;
    }

    public void setDate_don(LocalDate date_don) {
        this.date_don = date_don;
    }

    public String getType_don() {
        return type_don;
    }

    public void setType_don(String type_don) {
        this.type_don = type_don;
    }

    @Override
    public String toString() {
        return "Donation{" +
                "id_donation=" + id_donation +
                ", montant=" + montant +
                ", date_don='" + date_don + '\'' +
                ", type_don='" + type_don + '\'' +
                '}';
    }
}
