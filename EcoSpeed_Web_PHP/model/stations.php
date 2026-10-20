<?php

class station
{
 private $id=null;
 private $ville=null;
 private $energie=null;
 private $nombre_voiture=null;
 private $rentabilite=null;


function __construct($id,$ville,$energie,$nombre_voiture,$rentabilite)
{
 $this->id = $id;
 $this->ville = $ville;
 $this->energie = $energie;
 $this->nombre_voiture =$nombre_voiture;
 $this->rentabilite = $rentabilite;
}

/* Defining Setters */
function setId($id)
{
 $this->id = $id;
}
function setville($ville)
{
 $this->ville = $ville;
}
function setEnergie($energie)
{
 $this->energie = $energie;
}
function setNombreVoitures($nb_voitures)
{
 $this->nombre_voiture = $nb_voitures;
}
function setRentabilite($rentabilite)
{
 $this->rentabilite = $rentabilite;
}
/* Defining Getters */
function getId()
{
 return $this->id;
}
function getMatricule()
{
 return $this->matricule;
}
function getville()
{
 return $this->ville;
}
function getEnergie()
{
 return $this->energie;
}
function getNombreVoiture()
{
 return $this->nombre_voiture;
}
function getRentabilite()
{
 return $this->rentabilite;
}
}
?>
