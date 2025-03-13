<?php
class ouvrier
{private ? int $id = null;
private ? string $nom = null;
private ? string $prenom = null;
private ? int $age = null;
private ? string $departement = null;
private ? string $email = null;

public function __construct(int $id, string $nom, string $prenom, int $age, string $departement, string $email)
    {
        $this->id = $id;
        $this->nom = $nom;
        $this->prenom = $prenom;
        $this->age = $age;
        $this->departement = $departement;
        $this->email = $email;
    }

public function getId()
    {
        return $this->id;
    }

public function getNom()
    {
        return $this->nom;
    }

public function getPrenom()
    {
        return $this->prenom;
    }

public function getAge()
    {
        return $this->age;
    }

public function getdepartement()
    {
        return $this->departement;
    }

public function getEmail()
    {
        return $this->email;
    }
public function setId()
    {
    $this->id = $id;
    }

public function setNom()
    {
    $this->nom = $nom;
    }

public function setPrenom()
    {
    $this->prenom = $prenom;
    }

public function setAge()
    {
    $this->age = $age;
    }

public function setDepartement()
    {
    $this->departement = $departement;
    }

public function setEmail()
    {
    $this->email = $email;
    }




}
?>   