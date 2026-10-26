package models;

import java.time.LocalDate;
import java.util.Date;

public class Reclamation {
    int id_reclamation;
    String email;
    String description;
    LocalDate date;
    String etat = "Non traite";
    String etat2 = "Traite";

    public Reclamation(int idReclamation, int idUser, String description) {
        this.id_reclamation=idReclamation;
        this.idUtilisateur=idUser;
        this.description=description;
    }


    public String getEtat2() {
        return etat2;
    }

    public void setEtat2(String etat2) {
        this.etat2 = etat2;
    }

    commande commande=new commande();
    private Integer id_cm=commande.getId_commande();
    Utilisateurs user = new Utilisateurs();
    private  int idUtilisateur=user.getIdUtilisateur();
    public String getEtat() {
        return etat;
    }

    public void setEtat(String etat) {
        this.etat = etat;
    }

    public int getIdUtilisateur() {
        return idUtilisateur;
    }

    public void setIdUtilisateur(int idUtilisateur) {
        this.idUtilisateur = idUtilisateur;
    }

    public Reclamation(int id, String email, String description, LocalDate date, String etat, int cm, int idUtilisateur) {
        this.id_reclamation = id;
        this.email = email;
        this.description = description;
        this.etat = etat;
        this.date = date;
        this.id_cm=cm;
        this.idUtilisateur= idUtilisateur;
    }
    public Reclamation( String email, String description, LocalDate date, String etat,int cm,int idUtilisateur) {

        this.email = email;
        this.description = description;
        this.etat = etat;
        this.date = date;
        this.id_cm=cm;
        this.idUtilisateur= idUtilisateur;
    }
    public Integer getId_cm() {
        return id_cm;
    }

    public void setId_cm(Integer id_cm) {
        this.id_cm = id_cm;
    }

    public Reclamation(int id_reclamation, String email, String description, LocalDate date, String etat, Integer id_cm, int idUtilisateur) {
        this.id_reclamation = id_reclamation;
        this.email = email;
        this.description = description;
        this.date = date;
        this.etat = etat;
        this.id_cm = id_cm;
        this.idUtilisateur = idUtilisateur;
    }
    public Reclamation( String email, String description, LocalDate date, String etat, Integer id_cm, int idUtilisateur) {

        this.email = email;
        this.description = description;
        this.date = date;
        this.etat = etat;
        this.id_cm = id_cm;
        this.idUtilisateur = idUtilisateur;
    }
    public Reclamation( String email, String description, LocalDate date, Integer id_cm, int idUtilisateur) {

        this.email = email;
        this.description = description;
        this.date = date;
        this.id_cm = id_cm;
        this.idUtilisateur = idUtilisateur;
    }


    public Reclamation() {
    }

    public Reclamation(String email, String description, LocalDate date, Integer cm) {

        this.email = email;
        this.description = description;
        this.etat = etat;
        this.date = date;
        this.id_cm=cm;
    }

    @Override
    public String toString() {
        return "Reclamation{" + "id=" + id_reclamation + ", sujet=" + email + ", description=" + description + ", date=" + date + '}';
    }

    public int getId() {
        return id_reclamation;
    }

    public void setId(int id) {
        this.id_reclamation = id;
    }

    public String getEmail() {
        return email;
    }

    public void setEmail(String email) {
        this.email = email;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public LocalDate getDate() {
        return date;
    }

    public void setDate(LocalDate date) {
        this.date = date;
    }
}
