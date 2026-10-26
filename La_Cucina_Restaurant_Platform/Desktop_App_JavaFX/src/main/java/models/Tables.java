package models;

public class Tables {
    private int numeroTable;
    private int capacite;
    private String emplacement;
    private boolean disponibilite;

    public Tables() {}

    public Tables(int numeroTable) {
        this.numeroTable = numeroTable;
    }

    public Tables(int numeroTable, int capacite, String emplacement, boolean disponibilite) {
        this.numeroTable = numeroTable;
        this.capacite = capacite;
        this.emplacement = emplacement;
        this.disponibilite = disponibilite;
    }


    ////////////////////////////////////////////////////////////////////////////////////////
    @Override
    public String toString() {
        return "Tables{" +
                "numeroTable=" + numeroTable +
                ", capacite=" + capacite +
                ", emplacement='" + emplacement + '\'' +
                ", disponibilite=" + disponibilite +
                '}';
    }
    ////////////////////////////////////////////////////////////////////////////////////////

    public int getNumeroTable() {
        return numeroTable;
    }

    public void setNumeroTable(int numeroTable) {
        this.numeroTable = numeroTable;
    }

    public int getCapacite() {
        return capacite;
    }

    public void setCapacite(int capacite) {
        this.capacite = capacite;
    }

    public String getEmplacement() {
        return emplacement;
    }

    public void setEmplacement(String emplacement) {
        this.emplacement = emplacement;
    }

    public boolean isDisponibilite() {
        return disponibilite;
    }

    public void setDisponibilite(boolean disponibilite) {
        this.disponibilite = disponibilite;
    }
}
