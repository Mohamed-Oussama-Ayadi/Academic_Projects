<?php
	include '../../controller/produitC.php';
	$produitC=new produitC();
	$produitC->supprimer_produit($_POST["id_produit"]);
	header('Location:afficher_produit.php');
?>