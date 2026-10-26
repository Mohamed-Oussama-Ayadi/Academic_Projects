package models;
import javafx.stage.FileChooser;
import javafx.stage.Stage;
import org.apache.pdfbox.pdmodel.PDDocument;
import org.apache.pdfbox.pdmodel.PDPage;
import org.apache.pdfbox.pdmodel.PDPageContentStream;
import org.apache.pdfbox.pdmodel.font.PDType1Font;

import javafx.collections.ObservableList;
import javafx.scene.control.ChoiceBox;
import models.Reclamation;
import services.ServiceUser;
import services.serviceReclamation;

import java.io.File;
import java.io.IOException;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.ArrayList;
public class GeneratePdf {

    public static void generatePDF(int idUser, File file) throws SQLException {
        // Récupérer toutes les réclamations de l'utilisateur
        serviceReclamation sr = new serviceReclamation();
        ArrayList<Reclamation> reclamations = sr.getReclamationsByUserId(idUser);

        // Vérifier si des réclamations existent pour cet utilisateur
        if (reclamations != null && !reclamations.isEmpty()) {
            // Obtenez les informations sur l'utilisateur
            ServiceUser su = new ServiceUser();
            String username = su.selectById(idUser).getNom();

            // Définir les marges et les espacements
            float margin = 50;
            float startX = 50;
            float startY = 750;
            float endY = 50;
            float lineSpacing = 20;

            // Créer un nouveau document PDF
            try (PDDocument document = new PDDocument()) {
                PDPage page = new PDPage();
                document.addPage(page);

                // Créer un flux de contenu pour écrire dans le document PDF
                try (PDPageContentStream contentStream = new PDPageContentStream(document, page)) {
                    // Ajouter le titre avec la date actuelle
                    Date currentDate = new Date();
                    SimpleDateFormat dateFormat = new SimpleDateFormat("dd/MM/yyyy");
                    String formattedDate = dateFormat.format(currentDate);
                    contentStream.beginText();
                    contentStream.setFont(PDType1Font.HELVETICA_BOLD, 16);
                    contentStream.newLineAtOffset(startX, startY);
                    contentStream.showText("Réclamations de " + username + " - " + formattedDate);
                    contentStream.endText();

                    // Déplacer vers une nouvelle ligne
                    startY -= lineSpacing * 2;

                    // Parcourir toutes les réclamations de l'utilisateur et les ajouter au document PDF
                    for (Reclamation reclamation : reclamations) {
                        String description = reclamation.getDescription();

                        startY -= lineSpacing;
                        contentStream.beginText();
                        contentStream.setFont(PDType1Font.HELVETICA_BOLD, 12);
                        contentStream.newLineAtOffset(startX, startY);
                        contentStream.showText("Description: ");
                        contentStream.setFont(PDType1Font.HELVETICA, 12);
                        contentStream.showText(description);
                        contentStream.endText();
                    }
                } catch (IOException ex) {
                    throw new RuntimeException(ex);
                }

                // Sauvegarder le document PDF
                try {
                    document.save(file);
                } catch (IOException e) {
                    e.printStackTrace();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        } else {
            // Gérer le cas où aucune réclamation n'a été trouvée pour cet utilisateur
            System.out.println("Aucune réclamation trouvée pour l'utilisateur avec l'ID: " + idUser);
        }
    }
}

