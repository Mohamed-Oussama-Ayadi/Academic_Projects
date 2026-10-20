<?php
	include '../../controller/boutiqueB.php';
	$boutiqueB=new boutiqueB();
	$boutiqueB->supprimer_boutique($_POST["id"]);
	header('Location:afficher_boutique.php');
?>