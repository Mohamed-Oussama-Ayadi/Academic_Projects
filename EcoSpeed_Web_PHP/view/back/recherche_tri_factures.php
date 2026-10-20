<?php

include_once "../../controller/error.php";
include "../../controller/facturesController.php";

$fac=new facturesC();
$error=null;
/*$reference=$_POST['reference'];*/

if(isset($_POST['reference']))
{
 if(!empty($_POST['reference']))
{
$listerecherche=$fac->rechercherFacturesParRef($_POST['reference']);
}
}
else
{
 $error = "Missing Information";
}

if(isset($_POST['critere']))
{
 if(!empty($_POST['critere']))
 {
  $listetri=$fac->trierFacture($_POST['critere']);
 }
}


?>

<!DOCTYPE HTML>
<html lang="en">


<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

  <title>Eco-speed dashboard</title>

  <link href="images/favicon.ico" rel="shortcut icon" type="image/x-icon">

  <link href="css/bootstrapf9e3.css?v=1.1" rel="stylesheet" type="text/css"/>

  <!-- custom style -->
  <link href="css/uif9e3.css?v=1.1" rel="stylesheet" type="text/css"/>
  <link href="css/responsivef9e3.css?v=1.1" rel="stylesheet" />

  <!-- iconfont -->
  <link rel="stylesheet" href="fonts/material-icon/css/round.css"/>

</head>
<body>

<b class="screen-overlay"></b>

<aside class="navbar-aside" id="offcanvas_aside">
	<div class="aside-top">
	  <a href="index.php" class="brand-wrap">
		<img src="asset/images/Logo.png" height="46" class="logo" alt="Ecommerce dashboard template">
	  </a>
	  <div>
		<button class="btn btn-icon btn-aside-minimize"> <i class="text-muted material-icons md-menu_open"></i> </button>
	  </div>
	</div> <!-- aside-top.// -->
	
	<nav>
	  <ul class="menu-aside">
		<li class="menu-item active"> 
		  <a class="menu-link" href="index.php"> <i class="icon material-icons md-home"></i> 
			<span class="text">Acceuil</span> 
		  </a> 
		</li>
	    <li class="menu-item has-submenu">
                    <a class="menu-link" href="afficher_boutique.php"> <i class="icon material-icons md-shopping_bag"></i>
                        <span class="text">Boutiques</span>
                    </a>
                    <div class="submenu">
                        <a href="ajouter_boutique.php">Ajouter Boutique</a>
                        <a href="afficher_boutique.php">Afficher Boutique</a>
                        <a href="recherche_boutique.php">Recherche </a>
                        <a href="statistiques_boutique.html">Statistiques</a>
                        <a href="mailing.php">Mailing</a>
                    </div>
                </li>
                <li class="menu-item has-submenu">
                    <a class="menu-link" href="afficher_ouvrier.php"> <i class="icon material-icons md-person"></i>
                        <span class="text">Ouvriers</span>
                    </a>
                    <div class="submenu">
                        <a href="ajouter_ouvrier.php">Ajouter ouvrier</a>
                        <a href="afficher_ouvrier.php">Afficher ouvrier</a>
                        <a href="recherche_ouvrier.php">Recherche </a>
                        <a href="mailing.php">Mailing</a>
                    </div>
                </li>
                <li class="menu-item has-submenu"> 
      <a class="menu-link" href="afficherFactures.php"> <i class="icon material-icons md-shopping_bag"></i>  
        <span class="text">Factures</span> 
      </a> 
      <div class="submenu">
        <a href="ajouterFactures.php">Ajouter Facture</a>
        <a href="modifierFactures.php">Modifier Facture</a>
        <a href="supprimerFactures.php">Supprimer Factures</a>
        <a href="afficherFactures.php">Afficher Factures</a>
        <a href="recherche_tri_factures.php">Recherche et Tri</a>
        <a href="calculator.php">Calculatrice</a>
      </div>
    </li>
   
    <li class="menu-item has-submenu"> 
      <a class="menu-link" href="afficherStations.php"> <i class="icon material-icons md-add_box"></i>  
        <span class="text">Station Recharge</span> 
      </a> 
      <div class="submenu">
        <a href="ajouterStations.php">Ajouter station</a>
        <a href="modifierStations.php">Modifier station</a>
        <a href="supprimerStations.php">Supprimer station</a>
        <a href="afficherStations.php">Afficher station</a>
        <a href="rechercher_tri_stations.php">Recherche & Tri</a>
        <a href="statistique_station.php">Statistiques</a>
      </div>
    </li>
    
    <li class="menu-item has-submenu">
                    <a class="menu-link" href="afficher_categorie.php"> <i class="icon material-icons md-add_box"></i>
                        <span class="text">Categories</span>
                    </a>
                    <div class="submenu">
                        <a href="ajouter_categorie.php">Ajouter Catégorie</a>
						<a href="afficher_categorie.php">Afficher Catégorie</a>
                        <a href="statistique_categorie.html">Statistiques</a>
                    </div>
                </li>
	 <li class="menu-item has-submenu"> 
		  <a class="menu-link" href="afficher_produit.php"> <i class="icon material-icons md-add_box"></i>  
			<span class="text">Produits</span> 
		  </a> 
		  <div class="submenu">
			<a href="ajouter_produit.php">Ajouter Produits</a>
			<a href="afficher_produit.php">Afficher Produits</a>
			<a href="statistique_produit.html">Statistiques</a>
			
		  </div>
		</li>

		<li class="menu-item has-submenu"> 
		  <a class="menu-link" href="afficherUtilisateurs.php"> <i class="icon material-icons md-person"></i>  
			<span class="text">Utilisateurs</span> 
		  </a> 
		  <div class="submenu">
			<a href="ajouterUtilisateurs.php">Ajouter Utilisateurs</a>
			<a href="afficherUtilisateurs.php">Afficher Utilisateurs</a>
			</div>
			</li>
	  </ul>
	  <hr>
	</nav>
	</aside>

  
<main class="main-wrap">
	<header class="main-header navbar">
		<div class="col-search">
			<form class="searchform">
				<div class="input-group">
				  <input list="search_terms" type="text" class="form-control" placeholder="Search term">
				  <button class="btn btn-light bg" type="button"> <i class="material-icons md-search"></i> </button>
				</div>
			</form>
		</div>
		<div class="col-nav">
     <button class="btn btn-icon btn-mobile me-auto" data-trigger="#offcanvas_aside"> <i class="md-28 material-icons md-menu"></i> </button>
     <ul class="nav">
      <li class="nav-item">
          <a class="nav-link btn-icon" onclick="darkmode(this)" title="Dark mode" href="#"> <i class="material-icons md-nights_stay"></i> </a>
      </li>
      <li class="dropdown nav-item">
        <a class="dropdown-toggle" data-bs-toggle="dropdown" href="#"> <img class="img-xs rounded-circle" src="images/people/avatar1.jpg" alt="User"></a>
        <div class="dropdown-menu dropdown-menu-end">
          <a class="dropdown-item" href="#">Mon profile</a>
          <a class="dropdown-item" href="#">Paramètres</a>
          <a class="dropdown-item text-danger" href="#">Sortie</a>
        </div>
      </li>
    </ul> 
  </div>
	</header>


<section class="content-main" style="max-width: 720px">
	
	<div class="content-header">
		<h2 class="content-title">Recherche & Tri</h2>
	</div>
<div id="error">
<?php echo $error ?>
</div>

  <form action ="" method="POST">
	<div class="card mb-4">
          <div class="card-body">
				<div class="mb-4">
<label for="reference" id="reference" class="form-label">Reference</label>
<input type="text" placeholder="chercher par reference" class="form-control" name="reference" id="reference"/>
<br>
<input type="submit" class="btn btn-primary" id="boutton_rechercher" name="boutton_rechercher" value="Rechercher"/>
<br>
<br>
			  </div>
                <div class="table-responsive">
                <table class="table table-hover">
                    <thead>
                        <tr>
                            <th>Reference</th>
                            <th>ID Station</th>
                            <th>ID Utilsateur</th>
                            <th>Matricule</th>
                            <th>Montant</th>
                            <th>Date Paiement</th>
						 </tr>
					  </thead>
<?php
foreach($listerecherche as $liste)
{
?>
<tr>
<td><?php echo $liste['reference']; ?></td>
<td><?php echo $liste['id_station']; ?></td>
<td><?php echo $liste['id_user']; ?></td>
<td><?php echo $liste['matricule']; ?></td>
<td><?php echo $liste['montant']; ?></td>
<td><?php echo $liste['date_paiement']; ?></td>
<?php
}
?>
</table>
		  </div>
<br>
<br>
<br>
<br>
<label for="critere" id="critere" class="form-label"> Critere de Tri</label>
<br>
<select class="form-select" name="critere" id="critere">
<option>Reference</option>
<option>id_station</option>
<option>id_user</option>
<option>Matricule</option>
<option>Montant</option>
<option>date_paiement</option>
</select>
<br>
<input type="submit" class="btn btn-primary" id="boutton_tri" name="boutton_tri" value="Trier"/>
<br>
<br>
			  </div>
                <div class="table-responsive">
                <table class="table table-hover">
                    <thead>
                        <tr>
                            <th>Reference</th>
                            <th>ID Station</th>
                            <th>ID Utilsateur</th>
                            <th>Matricule</th>
                            <th>Montant</th>
                            <th>Date Paiement</th>
						 </tr>
					  </thead>
<?php
foreach($listetri as $listecritere)
{
?>
<tr>
<td><?php echo $listecritere['reference']; ?></td>
<td><?php echo $listecritere['id_station']; ?></td>
<td><?php echo $listecritere['id_user']; ?></td>
<td><?php echo $listecritere['matricule']; ?></td>
<td><?php echo $listecritere['montant']; ?></td>
<td><?php echo $listecritere['date_paiement']; ?></td>
<?php
}
?>

    </div> <!-- card end// -->
</form>
</section> <!-- content-main end// -->
</main>
<script>
    if(localStorage.getItem("darkmode")){
        var body_el = document.body;
        body_el.className += 'dark';
    }
</script>
<script src="js/jquery-3.5.0.min.js"></script>
<script src="js/bootstrap.bundle.min.js"></script>

<!-- ChartJS files-->
<script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0"></script>

<!-- Custom JS -->
<script src="js/scriptc619.js?v=1.0" type="text/javascript"></script>


</body>

<!-- Mirrored from www.ecommerce-admin.com/demo/page-index-1.html by HTTrack Website Copier/3.x [XR&CO'2014], Tue, 12 Apr 2022 00:14:39 GMT -->
</html>
