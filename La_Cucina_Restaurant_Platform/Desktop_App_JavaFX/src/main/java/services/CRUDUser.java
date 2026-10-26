package services;

import java.sql.SQLException;
import java.util.List;

public interface CRUDUser<T> {

    void insertOne1(T t) throws SQLException;
    void update(T t) throws SQLException;
    void delete(T t) throws SQLException;
    List<T> selectAll() throws SQLException;

}


   /* définir un ensemble de méthodes standard pour effectuer des opérations de
        base de données (CRUD : Create, Read, Update, Delete) sur une entité donnée.*/

//l'interface CRUDUser fournit une abstraction des opérations de base
// de données et une structure standard pour les implémentations, ce qui
// rend le code plus maintenable, plus flexible et plus facile à comprendre.