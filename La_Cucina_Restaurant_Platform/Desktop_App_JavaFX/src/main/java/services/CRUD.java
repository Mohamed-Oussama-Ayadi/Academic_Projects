package services;
import javafx.collections.ObservableList;
import models.Donation;
import models.Reclamation;

import java.sql.SQLException;

public interface CRUD<T> {
        void insertOne(T t)throws SQLException;



        void deleteOne(int id_reclamation);

        ObservableList<Reclamation> selectAll()throws SQLException;
        ObservableList<Donation> selectAllDon()throws SQLException;

        }
