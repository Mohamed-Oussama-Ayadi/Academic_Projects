package models;

public class UserEvent {
    private int id_utilisateur;
    private int id_evenement;

    public UserEvent() {
    }

    public UserEvent(int id_utilisateur, int id_evenement) {
        this.id_utilisateur = id_utilisateur;
        this.id_evenement = id_evenement;
    }

    public int getId_utilisateur() {
        return id_utilisateur;
    }

    public void setId_utilisateur(int id_utilisateur) {
        this.id_utilisateur = id_utilisateur;
    }

    public int getId_evenement() {
        return id_evenement;
    }

    public void setId_evenement(int id_evenement) {
        this.id_evenement = id_evenement;
    }


    @Override
    public String toString() {
        return "UserEvent{" +
                "id_utilisateur=" + id_utilisateur +
                ", id_evenement=" + id_evenement +
                '}';
    }
}



