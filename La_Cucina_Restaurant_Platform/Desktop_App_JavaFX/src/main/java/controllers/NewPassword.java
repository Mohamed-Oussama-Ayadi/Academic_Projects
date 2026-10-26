package controllers;

import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.PasswordField;
import models.Utilisateurs;
import services.ServiceUser;

import java.nio.charset.StandardCharsets;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.sql.SQLException;

public class NewPassword {

    @FXML
    private PasswordField password;

    @FXML
    private PasswordField confirm;

    @FXML
    private Button change;
    @FXML
    private Label pass_labe;
    private Utilisateurs user;
    public void initData(Utilisateurs user) {
        this.user = user;

        // Utiliser les données de l'utilisateur pour la réinitialisation du mot de passe
    }
    @FXML
    void changePasswordButtonOnClick(ActionEvent event) {
        String newPassword = password.getText();
        String newconfirmPassword = confirm.getText();

        // Vérifier si les champs ne sont pas vides
        if (!newPassword.isBlank() && !newconfirmPassword.isBlank()) {
            // Vérifier si le mot de passe contient au moins 8 caractères et au moins un chiffre
            if (newPassword.length() >= 8 && newPassword.matches(".*\\d.*")) {
                if (newPassword.equals(newconfirmPassword)) {
                    // Mettre à jour le mot de passe dans la base de données
                    try {
                        ServiceUser serviceUser = new ServiceUser();
                        Utilisateurs existingUser = serviceUser.selectById(user.getIdUtilisateur());
                        Utilisateurs updatedUser = new Utilisateurs(user.getIdUtilisateur(), existingUser.getNom(), existingUser.getPrenom(), existingUser.getSurnom(), existingUser.getSexe(), existingUser.getEmail(), existingUser.getNumeroTelephone(), existingUser.getRole(), newPassword, existingUser.getImage_user());

                        // Vérifier si le nouveau mot de passe est sécurisé
                        if (isSecurePassword(newPassword)) {
                            serviceUser.update(updatedUser);
                            // Afficher un message de succès
                            pass_labe.setText("Password updated successfully!");
                        } else {
                            pass_labe.setText("The password is not secure! Please use at least 8 characters, including letters, numbers and special characters.");
                        }
                    } catch (SQLException e) {
                        e.printStackTrace();
                        pass_labe.setText("Error updating password!");
                    }
                } else {
                    pass_labe.setText("Passwords don't match!");
                }
            } else {
                pass_labe.setText("The password must be at least 8 characters long and include at least one number!");
            }
        } else {
            pass_labe.setText("Please complete all fields !");
        }
    }

    // Vérifie si le mot de passe est sécurisé
    // Vérifie si le mot de passe est sécurisé
    private boolean isSecurePassword(String password) {
        // Au moins 8 caractères, y compris des lettres, des chiffres et au moins un symbole
        return password.length() >= 8 && password.matches("^(?=.*[a-zA-Z])(?=.*\\d)(?=.*[@#$%^&+=!*]).{8,}$");
    }



    private String hashPassword(String password) throws NoSuchAlgorithmException {
        MessageDigest digest = MessageDigest.getInstance("SHA-256");
        byte[] hash = digest.digest(password.getBytes(StandardCharsets.UTF_8));
        StringBuilder hexString = new StringBuilder(2 * hash.length);
        for (byte b : hash) {
            String hex = Integer.toHexString(0xff & b);
            if (hex.length() == 1) {
                hexString.append('0');
            }
            hexString.append(hex);
        }
        return hexString.toString();
    }



    /* @FXML
    private void handleChangePassword(ActionEvent event) {
        String newPassword = password.getText();
        String confirmPassword = confirm.getText();

        if (!newPassword.equals(confirmPassword)) {
            // Les mots de passe ne correspondent pas
            System.out.println("Les mots de passe ne correspondent pas. Veuillez réessayer.");
            return;
        }

        try {
            // Hasher le nouveau mot de passe
            String hashedPassword = hashPassword(newPassword);

            // Mettre à jour le mot de passe dans la base de données pour l'utilisateur actuel
            // Vous devez implémenter votre propre logique pour mettre à jour le mot de passe dans votre base de données

            // Afficher un message de succès
            System.out.println("Mot de passe changé avec succès.");
        } catch (NoSuchAlgorithmException e) {
            e.printStackTrace();
            System.out.println("Erreur lors du hachage du mot de passe.");
        }
    }*/
}
