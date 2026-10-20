<?php


class factures
{
 private $reference = null;
 private $id_station = null;
 private $id_user = null;
 private $matricule = null;
 private $montant = null;
 private $date_paiement = null;


function __construct($ref,$id_station,$id_user,$matricule,$montant,$date_paiement)
{
 $this->reference = $ref;
 $this->id_station = $id_station;
 $this->id_user = $id_user;
 $this->matricule=$matricule;
 $this->montant = $montant;
 $this->date_paiement =$date_paiement;
}

/* Defining Getters & Setters */
public function getReference()
{
 return $this->reference;
}
function setReference($reference):void
{
 $this->reference = $reference;
}
public function getIdStation()
{
 return $this->id_station;
}
function setIdStation($id_station):void
{
 $this->id_station = $id_station;
}
public function getid_user()
{
 return $this->id_user;
}
function setid_user($id):void
{
 $this->id_user = $id;
}
public function getmatricule()
{
 return $this->matricule;
}
function setMatricule($matricule):void
{
 $this->matricule = $matricule;
}
public function getdate_paiement()
{
 return $this->date_paiement;
}
function setdate_paiement($date_paiement):void
{
 $this->date_paiement = $date_paiement;
}
public function getmontant()
{
 return $this->montant;
}
function setmontant($montant):void
{
 $this->montant = $montant;
}


}
?>
