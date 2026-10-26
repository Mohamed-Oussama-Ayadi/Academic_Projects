package controllers;

import com.calendarfx.model.Calendar;
import com.calendarfx.model.CalendarSource;
import com.calendarfx.model.Entry;
import com.calendarfx.view.CalendarView;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.layout.HBox;
import models.Evenements;
import services.ServiceEvenements;

import java.net.URL;
import java.sql.SQLException;
import java.time.LocalDate;
import java.util.List;
import java.util.ResourceBundle;

public class Calendrier implements Initializable {

    @FXML
    private HBox hBox;

    @FXML
    private Button previousButton;

    @FXML
    private Label monthYearLabel;

    @FXML
    private Button nextButton;

    @FXML
    private CalendarView calendarView;

    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {
        monthYearLabel.setText("Month Year"); // Example initialization
        try {
            initializeCalendarView();
        } catch (SQLException e) {
            throw new RuntimeException(e);
        }
    }

    private void initializeCalendarView() throws SQLException {
        // Create a CalendarSource
        CalendarSource calendarSource = new CalendarSource("Events");

        // Get events from the service
        ServiceEvenements serviceEvenements = new ServiceEvenements();
        List<Evenements> events = serviceEvenements.selectAll();

        // Loop through events and add them to the CalendarSource
        for (Evenements event : events) {
            Calendar calendar = new Calendar(event.getNom_event());
            calendar.setShortName(event.getNom_event());
            calendar.setReadOnly(true);
            Entry<?> entry = new Entry<>(event.getNom_event());
            entry.changeStartDate(event.getDate_event().toLocalDate());
            calendar.addEntry(entry);

            calendarSource.getCalendars().add(calendar);
        }

        calendarView.getCalendarSources().add(calendarSource);
    }
}
