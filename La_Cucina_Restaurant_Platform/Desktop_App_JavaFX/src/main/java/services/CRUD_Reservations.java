package services;

import models.Reservations;

import java.sql.SQLException;
import java.util.List;
public interface CRUD_Reservations<T> {
    void insert(T t) throws SQLException;
    public void updateReservation(T t) throws SQLException;
    public void deleteReservation(T t) throws SQLException;
    public List <T> selectAllReservations() throws SQLException;
    public void displayAllReservations() throws SQLException;
}
