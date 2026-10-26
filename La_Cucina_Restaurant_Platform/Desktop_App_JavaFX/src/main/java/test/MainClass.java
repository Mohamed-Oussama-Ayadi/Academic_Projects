package test;

import models.Role;
import models.Utilisateurs;
import services.ServiceUser;
import utils.DBConnection;

import java.sql.SQLException;

public class MainClass {

    public static void main(String[] args) {
        DBConnection cn1 = DBConnection.getInstance();
Role role= Role.CLIENT;
        Utilisateurs p = new Utilisateurs("Dina","Dina","Dina","femme","Yosra",222,role,"Yosra","Yosra");
//person to update
        Utilisateurs UserToUpdate = new Utilisateurs();
        UserToUpdate.setIdUtilisateur(671);
        UserToUpdate.setPrenom("tkkjk");
        UserToUpdate.setSurnom("Dina");
        UserToUpdate.setNom("nfjfnj");
        UserToUpdate.setEmail("fj@kj.tn00");
        UserToUpdate.setMotDePasse("5555");
  //  UserToUpdate.setRole(Role.CLIENT);



        ServiceUser sp = new ServiceUser();

        try {
            sp.insertOne1(p);

           // Mettre à jour l'utilisateur
            //p.setNom("NouveauNom");
            //p.setPrenom("NouveauPrenom");
            // Autres attributs à mettre à jour
            sp.update(UserToUpdate);

            System.out.println("L'utilisateur a été mis à jour avec succès.");

            // Supprimer l'utilisateur
            sp.delete(p);
            System.out.println("L'utilisateur a été supprimé avec succès.");
          //  System.out.println(sp.selectAll());
        } catch (SQLException e) {
            System.err.println("Erreur: "+e.getMessage());
        }


    }
}
