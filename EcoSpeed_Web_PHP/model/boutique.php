<?php
class boutique
{private ? int $id = null;
private ? string $adresse = null;
private ? string $email = null;
private ? int $nbre_voitures = null;
private ? int $nbre_pieces_rechange = null;


public function __construct(int $id, string $adresse, string $email, int $nbre_voitures, int $nbre_pieces_rechange)
    {
        $this->id = $id;
        $this->adresse = $adresse;
        $this->email = $email;
        $this->nbre_voitures = $nbre_voitures;
        $this->nbre_pieces_rechange= $nbre_pieces_rechange;
    }

public function getId()
    {
        return $this->id;
    }

public function getAdresse()
    {
        return $this->adresse;
    }

public function getEmail()
    {
        return $this->email;
    }

public function getNbreVoitures()
    {
        return $this->nbre_voitures;
    }

public function getNbrePiecesRechange()
    {
        return $this->nbre_pieces_rechange;
    }


    public function setId()
    {
        $this->id = $id;
    }

public function setAdresse()
    {
        $this->adresse = $adresse;
    }

public function setEmail()
    {
        $this->email = $email;
    }

public function setNbreVoitures()
    {
        $this->nbre_voitures = $nbre_voitures;
    }

public function setNbrePiecesRechange()
    {
        $this->nbre_pieces_rechange = $nbre_pieces_rechange;
    }


}
?>   