<?php
	include '../../controller/ouvrierO.php';
	$ouvrierO=new ouvrierO();
	$ouvrierO->supprimer_ouvrier($_POST["id"]);
	header('Location:afficher_ouvrier.php');
?>