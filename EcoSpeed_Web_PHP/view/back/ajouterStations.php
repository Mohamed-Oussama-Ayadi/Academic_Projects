<?php
include_once "../../controller/stationsController.php";
include_once "../../model/stations.php";
include_once "../../controller/error.php";

$error = "";
$st =null;
$id=null;

/*$ville= $_POST['ville'];
$energie = $_POST['energie'];
$nombre_voiture = $_POST['nombre_voiture'];
$rentabilite = $_POST['rentabilite'];*/


$stationC = new stationController();
if (isset($_POST['ville']) &&
 isset($_POST['energie']) && 
 isset($_POST['nombre_voiture']) && 
 isset($_POST['rentabilite'])) 
{
 if (!empty($_POST['ville'])&&
  !empty($_POST['energie']) && 
  !empty($_POST['nombre_voiture']) && 
  !empty($_POST['rentabilite'])) {
  if($stationC->verifierVilleStation($_POST['ville']) && $stationC->verifierEnergie($_POST['energie']) && $stationC->verifierNombreVoiture($_POST['nombre_voiture']) && $stationC->verifierRentabilite($_POST['rentabilite']))
  {
            $st = new station($id,$_POST['ville'],$_POST['energie'],$_POST['nombre_voiture'],$_POST['rentabilite']);
			$stationC->ajouterStation($st);
			header('Location:afficherStations.php');
  }
		}
	}
	   	else {
            $error = "Missing information";
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
		<h2 class="content-title">Ajouter Station</h2>
	</div>
<div id="error">
<?php echo $error ?>
</div>

  <form action ="" method="POST">
	<div class="card mb-4">
          <div class="card-body">
				<div class="mb-4">
					<label class="form-label">Ville</label>
					<input placeholder="Type" type="text" class="form-control" name="ville" id="ville">
				</div>

				<div class="mb-4">
					<label for="energie" class="form-label">Energie en KW</label>
					<input type="text" placeholder="Type here" class="form-control" name="energie" id="energie">
				</div>
				<div class="mb-4">
					<label for="nombre_voitures" class="form-label">Nombre Voitures</label>
					<input type="text" placeholder="Type here" class="form-control" name="nombre_voiture" id="nombre_voiture">
				</div>
				<div class="mb-4">
					<label for="rentabilite" class="form-label">Rentabilite en %</label>
					<input type="text" placeholder="Type here" class="form-control" name="rentabilite" id="rentabilite">
				</div>
				

<input type="submit" class="btn btn-primary" id='boutton_ajouter' name='boutton_ajouter' value="Ajouter"/>
          </div>
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
