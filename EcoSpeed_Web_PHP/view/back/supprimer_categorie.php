<?php
	include '../../controller/categorieC.php';
	$categorieC=new categorieC();
	$categorieC->supprimer_categorie($_POST["id_categorie"]);
	header('Location:afficher_categorie.php');
?>