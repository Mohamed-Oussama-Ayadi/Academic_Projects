package services;

import models.Ingredient;
import models.Produit;

public interface OnChangeListener {
    void refreshPrice();
    void fillForum(Produit p);
    void fillForum2(Ingredient i);
}
