<?php
class categorie
{private ? int $id_categorie = null;
private ? string $nom = null;
private ? string $type = null;
private ? int $stock_max = null;


public function __construct( string $nom, string $type, int $stock_max)
    {
       
        $this->id_categorie = $id_categorie;
        $this->nom = $nom;
        $this->type = $type;
        $this->stock_max = $stock_max;
        
    }

public function getid_categorie()
    {
        return $this->id_categorie;
    }

public function getnom()
    {
        return $this->nom;
    }

public function gettype()
    {
        return $this->type;
    }

public function getstock_max()
    {
        return $this->stock_max;
    }


public function setid_categorie()
    {
    $this->id_categorie = $id_categorie;
    }

public function setnom()
    {
    $this->nom = $nom;
    }

public function settype()
    {
    $this->type = $type;
    }

public function setstock_max()
    {
    $this->stock_max = $stock_max;
    }






}
?>   