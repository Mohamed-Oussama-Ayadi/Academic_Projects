package services;

import java.sql.SQLException;
import java.util.List;

public interface CRUDEvenement<T> {

    void insertOne1(T t) throws SQLException;
    void update(T t) throws SQLException;
    void delete(T t) throws SQLException;
    List<T> selectAll() throws SQLException;

}
