package models;

public class Administrateurs extends Utilisateurs {
    // Ajoutez des champs spécifiques à l'administrateur si nécessaire

    public Administrateurs() {
        // Appel du constructeur par défaut de la classe parente Utilisateurs
        super();
    }

    public Administrateurs(int idUtilisateur, String nom, String prenom, String surnom, String sexe, String email, int numeroTelephone, Role role, String motDePasse, String image_user) {
        // Appel du constructeur de la classe parente Utilisateurs avec les paramètres correspondants
        super(idUtilisateur, nom, prenom, surnom, sexe, email, numeroTelephone, role, motDePasse, image_user);
    }

    // Vous pouvez ajouter des méthodes spécifiques à l'administrateur ici
}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////