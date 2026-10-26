
package services;
import javafx.scene.control.Alert;
import javafx.scene.control.ButtonType;
import models.Role;
import models.Utilisateurs;
import utils.DBConnection;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class ServiceUser implements CRUDUser<Utilisateurs> {

    private Connection cnx ;// Déclaration d'une variable Connection pour établir la connexion à la base de données.
    Utilisateurs user;

    public ServiceUser() {
        cnx = DBConnection.getInstance().getCnx(); // Initialisation de la connexion à la base de données en utilisant DBConnection.
    }

    /*
        @Override
        public void insertOne(Utilisateurs utilisateurs) throws SQLException {
            String req = "INSERT INTO `Utlisateurs`(`idUtilisateur`,`nom`, `prenom`, `surnom`, `sexe`, `email`, `numeroTelephone`, `role`, `motDePasse`, `image_user`) VALUES " +
                    "("+ Utilisateurs.getIdUtilisateur()+",'"+ Utilisateurs.getNom()+"','"+ Utilisateurs.getPrenom()+"','"+ Utilisateurs.getSexe()+"','"+ Utilisateurs.getEmail()+"',"+ Utilisateurs.getNumeroTelephone()+",'"+ Utilisateurs.getRole()+"','"+ Utilisateurs.getMotDePasse()+"','"+ Utilisateurs.getMotDePasse()+"','"+ Utilisateurs.getImage_user()+"')";
            Statement st = cnx.createStatement();
            st.executeUpdate(req);
            System.out.println("Utlisateurs Ajouté !");
        }*/
/////////////////////////////////////////*   Create or Insert   */////////////////////////////////////////////////////////////////////////////////////
    public void insertOne1(Utilisateurs utilisateurs) throws SQLException {
        String req = "INSERT INTO `utilisateurs`(`nom`, `prenom`, `surnom`, `sexe`, `email`, `numeroTelephone`, `role`, `motDePasse`, `image_user`) VALUES " +
                "(?,?,?,?,?,?,?,?,?)";
        PreparedStatement ps = cnx.prepareStatement(req); // Préparation de la requête

        // Attribution des valeurs aux paramètres de la requête préparée.

        ps.setString(1, utilisateurs.getNom());
        ps.setString(2, utilisateurs.getPrenom());
        ps.setString(3, utilisateurs.getSurnom());
        ps.setString(4, utilisateurs.getSexe());
        ps.setString(5, utilisateurs.getEmail());
        ps.setInt(6, utilisateurs.getNumeroTelephone());
        ps.setString(7, utilisateurs.getRole().toString());

        String hashedPassword = null;
        try {
            hashedPassword = hashPassword(utilisateurs.getMotDePasse());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
        ps.setString(8,hashedPassword );
        ps.setString(9, utilisateurs.getImage_user());

        // Exécution de la requête d'insertion.
        int rowsAffected = ps.executeUpdate();
        if (rowsAffected > 0) {
            System.out.println("L'insertion a été effectuée avec succès.");
        } else {
            System.out.println("L'insertion a échoué. Veuillez vérifier les données et réessayer.");
        }
    }

    /////////////////////////////////////////////*   Update   */////////////////////////////////////////////////////////////////////////////////////
    @Override
    public void update(Utilisateurs utilisateur) throws SQLException {
        String req = "UPDATE Utilisateurs SET nom=?, prenom=?, surnom=?, sexe=?, email=?, numeroTelephone=?,  motDePasse=?, image_user=? WHERE idUtilisateur=?";
        PreparedStatement ps = cnx.prepareStatement(req);

        // Attribution des valeurs aux paramètres de la requête préparée.

        ps.setString(1, utilisateur.getNom());
        ps.setString(2, utilisateur.getPrenom());
        ps.setString(3, utilisateur.getSurnom());
        ps.setString(4, utilisateur.getSexe());
        ps.setString(5, utilisateur.getEmail());
        ps.setInt(6, utilisateur.getNumeroTelephone());
        //ps.setString(7, utilisateur.getRole().toString());

        String hashedPassword = null;
        try {
            hashedPassword = hashPassword(utilisateur.getMotDePasse());
        } catch (NoSuchAlgorithmException e) {
            throw new RuntimeException(e);
        }
        ps.setString(7,hashedPassword );
        ps.setString(8, utilisateur.getImage_user());
        ps.setInt(9, utilisateur.getIdUtilisateur());

        // Exécution de la requête de mise à jour.
        int rowsAffected = ps.executeUpdate();

        if (rowsAffected > 0) {
            System.out.println("L'utilisateur " + utilisateur.getPrenom() + " a été mis à jour avec succès.");
        } else {
            System.out.println("La mise à jour de  " +  utilisateur.getPrenom() + " a échoué.");
        }
    }






    /////////////////////////////////////////*   Delete   */////////////////////////////////////////////////////////////////////////////////////
    @Override
    public void delete(Utilisateurs utilisateur) throws SQLException {
        String req = "DELETE FROM Utilisateurs WHERE idUtilisateur=?";
        PreparedStatement ps = cnx.prepareStatement(req);

        ps.setInt(1, utilisateur.getIdUtilisateur());

        // Exécution de la requête de suppression.
        int rowsAffected = ps.executeUpdate();

        if (rowsAffected > 0) {
            System.out.println("L'utilisateur " + utilisateur.getPrenom()  + " a été supprimé avec succès.");
        } else {
            System.out.println("La suppression de " + utilisateur.getPrenom() + " a échoué.");
        }
    }

    /////////////////////////////////////////*   Read   */////////////////////////////////////////////////////////////////////////////////////
    // Méthode pour récupérer la liste de tous les utilisateurs depuis la base de données.

    @Override
    public List<Utilisateurs> selectAll(){
        // Initialisation d'une liste pour stocker les utilisateurs récupérés de la base de données.
        List<Utilisateurs> utilisateursList = new ArrayList<>();

        // Définition de la requête SQL pour sélectionner tous les utilisateurs.
        String req = "SELECT * FROM `Utilisateurs`";
        Statement st = null;
        try {
            st = cnx.createStatement();

            // Exécution de la requête et traitement du résultat.
            ResultSet rs = st.executeQuery(req);

            while (rs.next()) {
                // Création d'un objet Utilisateurs pour chaque enregistrement récupéré.
                Utilisateurs utilisateurs = new Utilisateurs();

                // Attribution des valeurs des colonnes de la base de données aux attributs de l'objet Utilisateurs.
                utilisateurs.setIdUtilisateur(rs.getInt("idUtilisateur"));
                utilisateurs.setNom(rs.getString("nom"));
                utilisateurs.setPrenom(rs.getString("prenom"));
                utilisateurs.setSurnom(rs.getString("surnom"));
                utilisateurs.setSexe(rs.getString("sexe"));
                utilisateurs.setEmail(rs.getString("email"));
                utilisateurs.setNumeroTelephone(rs.getInt("numeroTelephone"));
                //utilisateurs.setRole(rs.getString("role"));
                String roleS=rs.getString("role");
                Role role = Role.valueOf(roleS);
                utilisateurs.setRole(role);
                utilisateurs.setMotDePasse(rs.getString("motDePasse"));
                utilisateurs.setImage_user(rs.getString("image_user"));

                // Ajout de l'objet Utilisateurs à la liste des utilisateurs.
                utilisateursList.add(utilisateurs);
            }
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        // Retour de la liste des utilisateurs récupérés.
        return utilisateursList;
    }

    /////////////////////////////////////////*  hachage  */////////////////////////////////////////////////////////////////////////////////////
    // Méthode pour hacher un mot de passe en utilisant l'algorithme SHA-256.

    private String hashPassword(String motDePasse) throws NoSuchAlgorithmException {
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] hash = digest.digest(motDePasse.getBytes());
        StringBuilder hexString = new StringBuilder();
        for (byte b : hash) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) hexString.append('0');
            hexString.append(hex);
        }
        return hexString.toString();
    }
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    public void deleteCompte(Utilisateurs u) {
        try {
            Alert alert = new Alert(Alert.AlertType.CONFIRMATION);
            alert.setTitle("Delete Account");
            alert.setHeaderText(null);
            alert.setContentText("Are you sure you want to delete your account?");
            Optional<ButtonType> result = alert.showAndWait();
            if (result.isPresent() && result.get() == ButtonType.OK) {
                ServiceUser serviceUser = new ServiceUser();
                serviceUser.delete(u);
            }
        } catch (SQLException e) {
            e.printStackTrace();
            // Gérer l'exception
        }
    }


    public  Utilisateurs selectById(int idUtilisateur) throws SQLException {
        String req = "SELECT * FROM `utilisateurs` WHERE idUtilisateur=?";
        PreparedStatement ps = cnx.prepareStatement(req);
        ps.setInt(1, idUtilisateur);
        ResultSet rs = ps.executeQuery();
        if (rs.next()) {
            Utilisateurs u = new Utilisateurs();
            u.setIdUtilisateur(rs.getInt("idUtilisateur"));
            u.setNom(rs.getString("nom"));
            u.setPrenom(rs.getString("prenom"));
            u.setSurnom(rs.getString("surnom"));
            u.setSexe(rs.getString("sexe"));
            u.setEmail(rs.getString("email"));
            u.setNumeroTelephone(rs.getInt("NumeroTelephone"));
            String roleString = rs.getString("role");
            Role role = Role.valueOf(roleString); // Convertir la chaîne en valeur d'énumération
            u.setRole(role);
            u.setMotDePasse(rs.getString("MotDePasse"));
            u.setImage_user(rs.getString("Image_user"));

            return u;
        } else {
            return null; // Retourner null si aucun utilisateur n'est trouvé avec cet ID
        }
    }
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Méthode pour vérifier si le nom d'utilisateur est unique dans la base de données
    public boolean isUsernameUnique(String username) throws SQLException {
        String query = "SELECT COUNT(*) FROM utilisateurs WHERE surnom = ?";
        try (PreparedStatement statement = cnx.prepareStatement(query)) {
            statement.setString(1, username);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                int count = resultSet.getInt(1);
                return count == 0; // Si count == 0, le nom d'utilisateur est unique
            }
        }
        return false;
    }
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    // Méthode pour vérifier si le surnom de l'utilisateur est unique dans la base de données
    public boolean isUsernameUniqueUpdate(String surnom, int idUtilisateur) throws SQLException {
        String query = "SELECT COUNT(*) FROM utilisateurs WHERE surnom = ?";
        // Si l'ID de l'utilisateur est supérieur à zéro, cela signifie qu'il s'agit d'une mise à jour
        // Nous vérifions donc l'unicité uniquement si le nouveau surnom est différent de l'ancien



        if (idUtilisateur > 0) {
            String existingSurnom = null;
            String existingSurnomQuery = "SELECT surnom FROM utilisateurs WHERE idUtilisateur = ?";
            try (PreparedStatement existingSurnomStatement = cnx.prepareStatement(existingSurnomQuery)) {
                existingSurnomStatement.setInt(1, idUtilisateur);
                ResultSet existingSurnomResultSet = existingSurnomStatement.executeQuery();
                if (existingSurnomResultSet.next()) {
                    existingSurnom = existingSurnomResultSet.getString("surnom");
                }
            }
            if (existingSurnom != null && existingSurnom.equals(surnom)) {
                // Si le surnom est le même, nous retournons true sans effectuer de vérification supplémentaire
                return true;
            }
        }
        // Sinon, nous effectuons la vérification normale du surnom
        try (PreparedStatement statement = cnx.prepareStatement(query)) {
            statement.setString(1, surnom);
            ResultSet resultSet = statement.executeQuery();
            if (resultSet.next()) {
                int count = resultSet.getInt(1);
                return count == 0; // Si count == 0, le surnom d'utilisateur est unique
            }
        }
        return false;
    }

    // recherche
    public List<Utilisateurs> selectByRole(Role role) throws SQLException {
        List<Utilisateurs> userList = new ArrayList<>();
        String req = "SELECT * FROM utilisateurs WHERE role=?";
        PreparedStatement ps = cnx.prepareStatement(req);
        ps.setString(1, role.toString());
        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            Utilisateurs  u = new Utilisateurs();
            u.setIdUtilisateur(rs.getInt("idUtilisateur"));
            u.setNom(rs.getString("nom"));
            u.setPrenom(rs.getString("prenom"));
            u.setSurnom(rs.getString("surnom"));
            u.setSexe(rs.getString("sexe"));
            u.setEmail(rs.getString("email"));
            u.setNumeroTelephone(rs.getInt("NumeroTelephone"));
            String roleString = rs.getString("role");
            u.setRole(role);
            u.setMotDePasse(rs.getString("MotDePasse"));
            u.setImage_user(rs.getString("Image_user"));
            userList.add(u);
        }
        return userList;
    }



    public List<Utilisateurs> selectBySurnom(String surnom) throws SQLException {
        List<Utilisateurs> userList = new ArrayList<>();
        String req = "SELECT * FROM utilisateurs WHERE surnom=?";
        PreparedStatement ps = cnx.prepareStatement(req);
        ps.setString(1, surnom);
        ResultSet rs = ps.executeQuery();
        while (rs.next()) {
            Utilisateurs  u = new Utilisateurs();
            u.setIdUtilisateur(rs.getInt("idUtilisateur"));
            u.setNom(rs.getString("nom"));
            u.setPrenom(rs.getString("prenom"));
            u.setSurnom(rs.getString("surnom"));
            u.setSexe(rs.getString("sexe"));
            u.setEmail(rs.getString("email"));
            u.setNumeroTelephone(rs.getInt("NumeroTelephone"));
            String roleS=rs.getString("role");
            Role role = Role.valueOf(roleS);
            u.setMotDePasse(rs.getString("MotDePasse"));
            u.setImage_user(rs.getString("Image_user"));
            userList.add(u);
        }
        return userList;
    }

    public boolean userExists(String surnom) throws SQLException {
        String query = "SELECT COUNT(*) AS count FROM utilisateurs  WHERE surnom=?";
        try (PreparedStatement statement = cnx.prepareStatement(query)) {
            statement.setString(1, surnom);
            try (ResultSet resultSet = statement.executeQuery()) {
                if (resultSet.next()) {
                    int count = resultSet.getInt("count");
                    return count > 0;
                }
            }
        }
        return false;
    }

    public Utilisateurs selectByEmail(String email) throws SQLException {
        Connection connection = null;
        PreparedStatement statement = null;
        ResultSet resultSet = null;
        Utilisateurs user = null;

        try {
            connection = DBConnection.getInstance().getCnx();
            statement = connection.prepareStatement("SELECT * FROM utilisateurs WHERE email = ?");
            statement.setString(1, email);
            resultSet = statement.executeQuery();

            if (resultSet.next()) {

                int id = resultSet.getInt("idUtilisateur");
                String firstName = resultSet.getString("nom");
                String lastName = resultSet.getString("prenom");
                String username = resultSet.getString("surnom");
                String sexe = resultSet.getString("sexe");
                String userEmail = resultSet.getString("email") ;
                int tel = resultSet.getInt("numeroTelephone");
                String role = resultSet.getString("role");
                String password = resultSet.getString("motDePasse");
                String image_user = resultSet.getString("image_user");



                user = new Utilisateurs(id, firstName, lastName,username,sexe ,userEmail,tel,Role.valueOf(role), password,image_user);
            }
        } finally {
            if (resultSet != null) {
                resultSet.close();
            }
            if (statement != null) {
                statement.close();
            }
        }

        return user;
    }
}



/*    -   executeQuery :
        Cette méthode est utilisée pour exécuter des instructions SQL qui retournent un ensemble de résultats, généralement une sélection de lignes provenant d'une table de base de données.
        Lorsque vous exécutez une requête SQL SELECT, vous utilisez executeQuery. Cette méthode renvoie un objet ResultSet qui contient les données récupérées à partir de la base de données.
     -   executeUpdate :
        Cette méthode est utilisée pour exécuter des instructions SQL qui effectuent des mises à jour dans la base de données, telles que INSERT, UPDATE ou DELETE.
        Lorsque vous exécutez des requêtes SQL qui modifient les données, comme l'insertion de nouvelles lignes, la mise à jour ou la suppression de lignes existantes, vous utilisez executeUpdate. Cette méthode renvoie un entier qui représente le nombre de lignes affectées par l'instruction SQL.

L'interface Statement et l'interface PreparedStatement sont toutes deux utilisées pour exécuter des requêtes SQL dans une base de données relationnelle en Java,

2 types de Statement :
Statement     ⇒  requêtes statiques simples
PreparedStatement   ⇒  requêtes dynamiques   précompilées

PreparedStatemt : envoie une requête sans paramètres à la base de données:

plus rapide qu’un Statement classique
le SGBD n’analyse qu’une seule fois la requête

⇒ requêtes dynamiques précompilées (avec paramètres d’entrée/sortie)



Gestion des paramètres :

Statement n'accepte pas de paramètres dynamiques dans les requêtes SQL, tandis que
 PreparedStatement prend en charge l'utilisation de paramètres dynamiques grâce à l'utilisation de marqueurs de paramètres.




Maven :  Maven est un outil de gestion dautomatisation pour les  projet pour les projets Java


Le fichier pom.xml est un fichier de configuration principal utilisé dans les projets Maven. Maven est un outil de gestion de projet de logiciel
qui permet de simplifier et d'automatiser le processus de construction, de gestion et de déploiement d'applications Java.
Le fichier pom.xml contient des informations sur le projet, telles que le nom du projet, sa version, ses dépendances sur d'autres bibliothèques,
les plugins utilisés pour la construction et le déploiement, et d'autres configurations spécifiques au projet.

*/