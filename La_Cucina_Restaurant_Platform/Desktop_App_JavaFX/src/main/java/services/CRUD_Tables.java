package services;

import java.sql.SQLException;
import java.util.List;

public interface CRUD_Tables<T> {

    void insert(T t) throws SQLException;
    void update(T t) throws SQLException;
    void delete(T t) throws SQLException;
    public void displayAllTable();
    List<T> selectAll() throws SQLException;

}
