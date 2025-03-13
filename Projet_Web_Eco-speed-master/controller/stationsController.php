<?php
include '../../controller/config.php';
include '../../controller/error.php';
include_once "../../model/stations.php";


class stationController
{
 function verifierVilleStation($ville):bool
 {
  if(!in_array(strtoupper($ville),array('TUNIS','ARIANA','BIZERTE','SOUSSE','SFAX')))
  {
   echo '<script type="text/javascript">alert("Veuillez choisir une ville inscrite dans cette liste:\n- Tunis\n- Ariana\n- Bizerte\n- Sousse\n- Sfax");</script>';
   return false;
  }
  else
   return true;
 }
 function verifierEnergie($energie):bool
 {
  if($energie < 10)
  {
   echo '<script type="text/javascript">alert("Le total d energie disponible doit etre superieur a 10 KiloWatt");</script>';
   return false;
  }
  else
   return true;
  
 }
 function verifierNombreVoiture($nombre_voiture):bool
 {
  if($nombre_voiture > 1000)
  {
   echo '<script type="text/javascript">alert("Une station ne peut pas servir plus de 1000 voitures.");</script>';
   return false;
  }
  else
   return true;
 }
 function verifierRentabilite($rentabilite):bool
 {
  if($rentabilite > 100 && $rentabilite < 0)
  {
   echo '<script type="text/javascript">alert("Rentablite doit etre un entier compris entre 0 et 100;");</script>';
   return false;
  }
  else
   return true;
 }

 function afficherStation()
 {
  $sql="SELECT * from station";
  $db=config::getConnexion();

  try
  {
   $liste=$db->query($sql);
   return $liste;
  }
  catch(Exception $e)
  {
   echo 'Erreur: ', $e->getMessage();
  }
 }
 function afficherId()
 {
  $sql="SELECT DISTINCT id from station";
  $db=config::getConnexion();

  try
  {
   $liste=$db->query($sql);
   return $liste;
  }
  catch(Exception $e)
  {
   echo 'Erreur : ', $e->getMessage();
  }
 }

 function ajouterStation($station)
 {
  $sql="INSERT into station (id,ville,energie,nombre_voiture,rentabilite) VALUES(NULL,:ville,:energie,:nombre_voiture,:rentabilite)";
  $db=config::getConnexion();

  try
  {
   $query=$db->prepare($sql);
   $query->execute([
	'ville' =>$station->getville(),
	'energie' =>$station->getEnergie(),
	'nombre_voiture' =>$station->getNombreVoiture(),
	'rentabilite' =>$station->getRentabilite()
   ]);
 }
  catch(Exception $e)
  {
   echo 'Erreur', $e->getMessage();
  }
 }

 function supprimerStation($reference)
 {
  $sql="DELETE from station where id=:id";
  $db=config::getConnexion();

  $req=$db->prepare($sql);
  $req->bindValue(':id',$reference);
  try
  {
   $req->execute();
  }
  catch(Exception $e)
  {
   echo 'Error', $e->getMessage();
  }
 }

 function modifierStation($id,$ville,$energie,$nombre_voiture,$rentabilite)
 {
  try
  {
   $db=config::getConnexion();
   $query=$db->prepare("UPDATE station SET ville=:ville,energie=:energie,nombre_voiture=:nombre_voiture,rentabilite=:rentabilite WHERE id=:id");
   $query->execute([
	'id'=>$id,
	'ville'=>$ville,
	'energie'=>$energie,
	'nombre_voiture'=>$nombre_voiture,
	'rentabilite'=>$rentabilite,
   ]);
   echo $query->rowCount(), "station updated avec succes";
  }
  catch(PDOException $e)
  {
   echo 'ERREUR : ',$e->getMessage();
  }
 }
 function rechercherStationId($id)
 {
  $db=config::getConnexion();
  $sql="SELECT * from station where id=:id";
  $query=$db->prepare($sql);
  $query->bindParam(':id',$id);

  try
  {
   $query->execute();
   $liste=$query->fetchAll();
   return $liste;
  }
  catch(Exception $e)
  {
   echo 'ERREUR : ', $e->getMessage();
  }
 }
 function trierStation($critere)
 {
  $db=config::getConnexion();
  $query="SELECT * from station ORDER BY '%".$critere."%'";
  try
  {
   $liste=$db->query($query);
   $rows=$liste->fetchAll(PDO::FETCH_ASSOC);
   return $rows;
  }
  catch(Exception $e)
  {
   echo 'Erreur :',$e->getMessage();
  }
 }
}
?>
