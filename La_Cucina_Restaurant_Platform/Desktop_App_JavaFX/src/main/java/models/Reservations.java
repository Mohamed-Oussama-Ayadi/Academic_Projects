package models;

import java.time.LocalDate;
import java.sql.Date;


public class Reservations {
    private int id_reservation;
    private int nbr_personnes;
    private Date date;
    private String horaire;
    Tables tables=new Tables();
    private  Integer num = tables.getNumeroTable();
    private int numero_table;
     private String emplacement; // Nouvel attribut pour l'emplacement
    Utilisateurs user = new Utilisateurs();
    private  int idUtilisateur=user.getIdUtilisateur();
    public int getIdUtilisateur() {
        return idUtilisateur;
    }

    public void setIdUtilisateur(int idUtilisateur) {
        this.idUtilisateur = idUtilisateur;
    }


    public Reservations() {}





   public Reservations(int nbr_personnes,String horaire , Date date, Integer num) {
        this.nbr_personnes = nbr_personnes;
        this.date = date;
        this.horaire = horaire;
        this.num = num;
    } /*
    public Reservations(int id_reservation,int nbr_personnes,   Date date,String horaire ,  Integer num) {
        this.id_reservation = id_reservation;
        this.nbr_personnes = nbr_personnes;
        this.date = date;
        this.horaire = horaire;
        this.num = num;

    }
*/


    public Integer getNum() {
        return num;
    }

    public void setNum(Integer num) {
        this.num = num;
    }


    public Reservations(int id_reservation, int nbr_personnes, Date date, String horaire, int num_tab, String emplacement,int idUtilisateur) {
        this.id_reservation = id_reservation;
        this.nbr_personnes = nbr_personnes;
        this.date = date;
        this.horaire = horaire;
        this.num = num_tab;
        this.emplacement = emplacement;
        this.idUtilisateur=idUtilisateur;
    }
    public Reservations( int nbr_personnes, String horaire,Date date,  int num_tab, int idUtilisateur) {

        this.nbr_personnes = nbr_personnes;
        this.date = date;
        this.horaire = horaire;
        this.num = num_tab;
        this.emplacement = emplacement;
        this.idUtilisateur=idUtilisateur;
    }
  public Reservations(int id_reservation,  int nbr_personnes, String horaire,Date date,  int num_tab, int idUtilisateur) {
      this.id_reservation = id_reservation;
        this.nbr_personnes = nbr_personnes;
        this.date = date;
        this.horaire = horaire;
        this.num = num_tab;
        this.emplacement = emplacement;
        this.idUtilisateur=idUtilisateur;
    }

    // Ajoutez les méthodes getter et setter pour l'attribut emplacement
    public String getEmplacement() {
        return emplacement;
    }

    public void setEmplacement(String emplacement) {
        this.emplacement = emplacement;
    }
    /*public Reservations(int nbr_personnes, Date date, String horaire, int numero_table, String emplacement) {
        this.nbr_personnes = nbr_personnes;
        this.date = date;
        this.horaire = horaire;
        this.numero_table=numero_table;
     /*   this.emplacement = emplacement;
    }
*/
    public Reservations(int nbrPersonnes, Date date, String horaire,int numero_table) {
    }

   /* public Reservations(int idReservation, int nbrPersonnes, Date date, String horaire, int numeroTable) {
        this.id_reservation=idReservation;
        this.nbr_personnes=nbrPersonnes;
        this.date=date;
        this.horaire=horaire;
        this.numero_table=numero_table;

    }
*/
    public int getId_reservation() {
        return id_reservation;
    }

    public void setId_reservation(int id_reservation) {
        this.id_reservation = id_reservation;
    }

    public int getNbr_personnes() {
        return nbr_personnes;
    }

    public void setNbr_personnes(int nbr_personnes) {
        this.nbr_personnes = nbr_personnes;
    }

    public Date getDate() {
        return date;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public String getHoraire() {
        return horaire;
    }

    public void setHoraire(String horaire) {
        this.horaire = horaire;
    }

    public int getNumero_table() {
        return numero_table;
    }

    public void setNumero_table(int numero_table) {
        this.numero_table = numero_table;
    }

  /*  public String getEmplacement() {
        return emplacement;
    }

    public void setEmplacement(String emplacement) {
        this.emplacement = emplacement;
    }*/

    @Override
    public String toString() {
        return "Reservations{" +
                "id_reservation=" + id_reservation +
                ", nbr_personnes=" + nbr_personnes +
                ", date=" + date +
                ", horaire='" + horaire + '\'' +
                ", numero_table='" + numero_table + '\'' +
                '}';
    }

    public void setNum_tab(int numTab) {
        this.numero_table=numTab;
    }

}
