package models;

public class Utilisateurs {
    private int idUtilisateur;
    private String nom;
    private String prenom;
    private String surnom;
    private String sexe;
    private String email;
    private int numeroTelephone;
    private Role role;
    private String motDePasse;
    private String image_user;

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructeur par défaut.
    public Utilisateurs() {}

    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Constructeur avec tous les paramètres.
    public Utilisateurs(int idUtilisateur, String nom, String prenom, String surnom, String sexe, String email, int numeroTelephone, Role role, String motDePasse,String image_user) {
        this.idUtilisateur = idUtilisateur;
        this.nom = nom;
        this.prenom = prenom;
        this.surnom = surnom;
        this.sexe = sexe;
        this.email = email;
        this.numeroTelephone = numeroTelephone;
        this.role = role;
        this.motDePasse = motDePasse;
        this.image_user = image_user;
    }
////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Constructeur sans l'identifiant utilisateur.
    /*l'identifiant utilisateur est auto-incrémenté dans la base de données et que tu veux créer un objet
     Utilisateurs sans avoir besoin de spécifier cet identifiant.*/
    public Utilisateurs(String nom, String prenom, String surnom, String sexe, String email, int numeroTelephone, Role role, String motDePasse, String image_user) {
        this.nom = nom;
        this.prenom = prenom;
        this.surnom = surnom;
        this.sexe = sexe;
        this.email = email;
        this.numeroTelephone = numeroTelephone;
        this.role = role;
        this.motDePasse = motDePasse;
        this.image_user = image_user;


    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////

    public Utilisateurs(String nom, String prenom, String surnom, String sexe, String email, int numeroTelephone) {
        this.nom = nom;
        this.prenom = prenom;
        this.surnom = surnom;
        this.sexe = sexe;
        this.email = email;
        this.numeroTelephone = numeroTelephone;



    }

    public Utilisateurs(int idUtilisateur, String motDePasse) {
        this.idUtilisateur=idUtilisateur;
        this.motDePasse=motDePasse;
    }

    public Utilisateurs(int idUtilisateur, String newFirstname, String newLastname, String newUsername, String newSexe, String newEmail, int newPhoneNumber, Role role, String imagePath) {
        this.idUtilisateur = idUtilisateur;
        this.nom = nom;
        this.prenom = prenom;
        this.surnom = surnom;
        this.sexe = sexe;
        this.email = email;
        this.numeroTelephone = numeroTelephone;
        this.role = role;
        this.image_user = image_user;
    }


    // Méthodes getters et setters pour accéder et modifier les attributs de la classe.
    public int getIdUtilisateur() {
        return idUtilisateur;
    }

    public  void setIdUtilisateur(int idUtilisateur) {
        this.idUtilisateur = idUtilisateur;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public String getSurnom() {
        return surnom;
    }

    public  void setSurnom(String surnom) {
        this.surnom = surnom;
    }

    public String getSexe() {
        return sexe;
    }

    public void setSexe(String sexe) {
        this.sexe = sexe;
    }

    public String getEmail() {
        return email;
    }

    public  void setEmail(String email) {
        this.email = email;
    }

    public int getNumeroTelephone() {
        return numeroTelephone;
    }

    public void setNumeroTelephone(int numeroTelephone) {
        this.numeroTelephone = numeroTelephone;
    }

    public Role getRole() {
        return role;
    }

    public void setRole(Role role) {
        this.role = role;
    }

    public String getMotDePasse() {
        return motDePasse;
    }

    public void setMotDePasse(String motDePasse) {
        this.motDePasse = motDePasse;
    }

    public String getImage_user() {
        return image_user;
    }

    public void setImage_user(String image_user) {
        this.image_user = image_user;
    }


    // afficher les détails d'un objet Utilisateurs sous forme de chaîne de caractères.
    @Override
    public String toString() {
        return "Utilisateurs{" +
                "idUtilisateur=" + idUtilisateur +
                ", nom='" + nom + '\'' +
                ", prenom='" + prenom + '\'' +
                ", surnom='" + surnom + '\'' +
                ", sexe='" + sexe + '\'' +
                ", email='" + email + '\'' +
                ", numeroTelephone=" + numeroTelephone +
                ", role='" + role + '\'' +
                ", motDePasse='" + motDePasse + '\'' +
                ", image_user='" + image_user + '\'' +
                '}';
    }
}