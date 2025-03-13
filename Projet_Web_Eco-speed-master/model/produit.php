<?php
class produit
{private ? int $id_produit = null;
private ? string $nom = null;
private ? string $marque = null;
private ? string $photo = null;
private ? string $description= null;
private ? float $prix = null;
private ? int $quantite = null;
private ? int $id_categorie=null;





public function __construct( string $nom,string $marque, string $photo,string $description, float $prix,int $quantite,int $id_categorie)
    {  
       
        $this->id_produit = $id_produit;
        $this->nom = $nom;
        $this->marque = $marque;
        $this->photo = $photo;
        $this->description = $description;
        $this->prix= $prix;
        $this->quantite= $quantite;
        $this->id_categorie= $id_categorie;
       
        
       
    }

public function getid_produit()
    {
        return $this->id_produit;
    }

public function getnom()
    {
        return $this->nom;
    }

public function getmarque()
    {
        return $this->marque;
    }

public function getphoto()
    {
        return $this->photo;
    }

public function getdescription()
    {
        return $this->description;
    }

public function getprix()
    {
        return $this->prix;
    }

public function getquantite()
    {
        return $this->quantite;
    }
public function getid_categorie()
    {
        return $this->id_categorie;
    }

public function getlike()
    {
        return $this->like;
    }


public function setid_produit()
    {
        $this->id_produit = $id_produit;
    }

public function setnom()
    {
        $this->nom = $nom;
    }

public function setmarque()
    {
        $this->marque = $marque;
    }

public function setphoto()
    {
        $this->photo = $photo;
    }

public function setdescription()
    {
        $this->description = $description;
    }

public function setprix()
    {
        $this->prix = $prix;
    }

public function setquantite()
    {
        $this->quantite = $quantite;
    }

public function setid_categorie()
    {
        $this->id_categorie = $id_categorie;
    }

public function setlike()
    {
        $this->like = $like;
    }




}
?>   