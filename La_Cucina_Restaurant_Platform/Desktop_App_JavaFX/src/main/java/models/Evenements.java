package models;
import java.sql.Date;
import java.sql.Time;

public class Evenements {
    private int id_event;
    private String nom_event;
    private Date date_event;
    private Time heure_event;
    private String description_event;
    private int idUtilisateur; // Clé étrangère vers la table Utilisateurs


    public Evenements() {
    }


    public Evenements(int id_event, String nom_event, Date date_event, Time heure_event, String description_event, int idUtilisateur) {
        this.id_event = id_event;
        this.nom_event = nom_event;
        this.date_event = date_event;
        this.heure_event = heure_event;
        this.description_event = description_event;
        this.idUtilisateur = idUtilisateur;
    }

    public Evenements(String nom_event, Date date_event, Time heure_event, String description_event) {
        this.nom_event = nom_event;
        this.date_event = date_event;
        this.heure_event = heure_event;
        this.description_event = description_event;
    }

    public Evenements(int idEvent, Date dateEvent, Time heureEvent, String descriptionEvent) {
        this.id_event = id_event;
        this.date_event = date_event;
        this.heure_event = heure_event;
        this.description_event = description_event;

    }

    public Evenements(int id_event, String nomEvent, Date dateEvent, Time heureEvent, String descriptionEvent) {
        this.id_event = id_event;
        this.nom_event = nom_event;
        this.date_event = date_event;
        this.heure_event = heure_event;
        this.description_event = description_event;
    }


    // Getters et Setters
    public int getId_event() {
        return id_event;
    }

    public void setId_event(int id_event) {
        this.id_event = id_event;
    }

    public String getNom_event() {
        return nom_event;
    }

    public void setNom_event(String nom_event) {
        this.nom_event = nom_event;
    }

    public Date getDate_event() {
        return date_event;
    }

    public void setDate_event(Date date_event) {
        this.date_event = date_event;
    }

    public Time getHeure_event() {
        return heure_event;
    }

    public void setHeure_event(Time heure_event) {
        this.heure_event = heure_event;
    }

    public String getDescription_event() {
        return description_event;
    }

    public void setDescription_event(String description_event) {
        this.description_event = description_event;
    }

    public int getIdUtilisateur() {
        return idUtilisateur;
    }

    public void setIdUtilisateur(int idUtilisateur) {
        this.idUtilisateur = idUtilisateur;
    }

    @Override
    public String toString() {
        return "Evenements{" +
                "id_event=" + id_event +
                ", nom_event='" + nom_event + '\'' +
                ", date_event=" + date_event +
                ", heure_event=" + heure_event +
                ", description_event='" + description_event + '\'' +
                ", idUtilisateur=" + idUtilisateur +
                '}';
    }
}