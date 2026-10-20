<?php
	include '../../controller/ouvrierO.php';
	$ouvrierO=new ouvrierO();
	$listeOuvrier=$ouvrierO->afficher_ouvrier(); 
?>

<!DOCTYPE HTML>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Eco-speed dashboard</title>
    
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js"></script>
    <script type="text/javascript" src="fichier_excel_ouvriers.js"></script>
    
    <link href="asset/images/favicon.ico" rel="shortcut icon" type="image/x-icon">

    <link href="asset/css/bootstrapf9e3.css?v=1.1" rel="stylesheet" type="text/css" />

    <!-- custom style -->
    <link href="asset/css/uif9e3.css?v=1.1" rel="stylesheet" type="text/css" />
    <link href="asset/css/responsivef9e3.css?v=1.1" rel="stylesheet" />

    <!-- iconfont -->
    <link rel="stylesheet" href="fonts/material-icon/css/round.css" />

</head>
<body>
    <b class="screen-overlay"></b>
    <aside class="navbar-aside" id="offcanvas_aside">
        <div class="aside-top">
            <a href="index.php" class="brand-wrap">
                <img src="asset/images/Logo.png" height="46" class="logo" alt="Ecommerce dashboard template">
            </a>
            <div>
                <button class="btn btn-icon btn-aside-minimize"> <i class="text-muted material-icons md-menu_open"></i>
                </button>
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
                    <a class="menu-link" href="afficher_ouvrier.php"> <i class="icon material-icons md-shopping_bag"></i>
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
                        <button class="btn btn-light bg" type="button"> <i class="material-icons md-search"></i>
                        </button>
                    </div>
                </form>
            </div>
            <div class="col-nav">
                <button class="btn btn-icon btn-mobile me-auto" data-trigger="#offcanvas_aside"> <i
                        class="md-28 material-icons md-menu"></i> </button>
                <ul class="nav">
                    <li class="nav-item">
                        <a class="nav-link btn-icon" onclick="darkmode(this)" title="Dark mode" href="#"> <i
                                class="material-icons md-nights_stay"></i> </a>
                    </li>
                    <li class="dropdown nav-item">
                        <a class="dropdown-toggle" data-bs-toggle="dropdown" href="#"> <img
                                class="img-xs rounded-circle" src="asset/images/people/avatar1.jpg" alt="User"></a>
                        <div class="dropdown-menu dropdown-menu-end">
                            <a class="dropdown-item" href="#">Mon profile</a>
                            <a class="dropdown-item" href="#">Paramètres</a>
                            <a class="dropdown-item text-danger" href="#">Sortie</a>
                        </div>
                    </li>
                </ul>
            </div>
        </header>

        <section class="content-main">

            <div class="row" style="justify-content: center;">
                <div class="col-lg-12">
                    <div class="card">
                        <div class="card-header">
                            <strong class="card-title"></strong>
                        </div>
                        <div class="card-body">
                            <!-- Credit Card -->
                            <div id="pay-invoice">
                                <div class="card-body">
                                    <div class="card-title">

                                        <center>
                                            <h1>Liste des ouvriers</h1>
                                        </center>
                                        <br>
                                        <table nom="table_des_ouvriers" id="table_des_ouvriers" class="table align-items-center table-flush">
                                            <tr>
                                                <th>Id</th>
                                                <th>Nom</th>
                                                <th>Prenom</th>
                                                <th>Age</th>
                                                <th>Departement</th>
                                                <th>Email</th>
                                                <th>Modifier</th>
                                                <th>Supprimer</th>
                                            </tr>
                                            <?php
				foreach($listeOuvrier as $ouvrier){
			?>
                                            <tr>
                                                <td><?php echo $ouvrier['id']; ?></td>
                                                <td><?php echo $ouvrier['nom']; ?></td>
                                                <td><?php echo $ouvrier['prenom']; ?></td>
                                                <td><?php echo $ouvrier['age']; ?></td>
                                                <td><?php echo $ouvrier['departement']; ?></td>
                                                <td><?php echo $ouvrier['email']; ?></td>
                                                <td>
                                                    <form method="POST" action="modifier_ouvrier.php">
                                                        <input type="submit" name="Modifier"
                                                            class="btn btn-primary btn-sm"
                                                            style="margin-top:3%;margin-left:5%;border-radius: 10%;"
                                                            value="Modifier">
                                                        <input type="hidden" value=<?PHP echo $ouvrier['id']; ?>
                                                        name="id">
                                                    </form>
                                                </td>
                                                <td>
                                                    <form method="POST" action="supprimer_ouvrier.php">
                                                        <input type="submit" name="Supprimer"
                                                            class="btn btn-primary btn-sm"
                                                            style="margin-top:3%;margin-left:5%;border-radius: 10%;"
                                                            value="Supprimer">
                                                        <input type="hidden" value=<?PHP echo $ouvrier['id']; ?>
                                                        name="id">
                                                    </form>
                                                </td>
                                            </tr>
                                            <?php
				}
			?>
                                        </table>

                                        <div>
                                        <button onclick="ExportToExcel(table_des_ouvriers)" class="btn btn-primary" style="margin-top:3%;margin-left:5%;border-radius: 10%;" id="excel">
                                         Excel </button>
                                        
                                        </div>

                                    </div> <!-- table-responsive end// -->
                                </div> <!-- card-body end// -->
                            </div> <!-- card end// -->
                        </div>

        </section> <!-- content-main end// -->
    </main>

    <script type="text/javascript">
    if (localStorage.getItem("darkmode")) {
        var body_el = document.body;
        body_el.className += 'dark';
    }
    </script>

    <script src="asset/js/jquery-3.5.0.min.js"></script>
    <script src="asset/js/bootstrap.bundle.min.js"></script>

    <!-- ChartJS files-->
    <script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0"></script>

    <!-- Custom JS -->
    <script src="asset/js/scriptc619.js?v=1.0" type="text/javascript"></script>

    <!-- ChartJS customize-->
    <script>
    var ctx = document.getElementById('myChart').getContext('2d');
    var chart = new Chart(ctx, {
        // The type of chart we want to create
        type: 'line',

        // The data for our dataset
        data: {
            labels: ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'],
            datasets: [{
                    label: 'Sales',
                    backgroundColor: 'rgb(44, 120, 220)',
                    borderColor: 'rgb(44, 120, 220)',
                    data: [18, 17, 4, 3, 2, 20, 25, 31, 25, 22, 20, 9]
                },
                {
                    label: 'Visitors',
                    backgroundColor: 'rgb(180, 200, 230)',
                    borderColor: 'rgb(180, 200, 230)',
                    data: [40, 20, 17, 9, 23, 35, 39, 30, 34, 25, 27, 17]
                }

            ]
        },

        // Configuration options go here
        options: {}
    });
    </script>

</body>

<!-- Mirrored from www.ecommerce-admin.com/demo/page-index-1.html by HTTrack Website Copier/3.x [XR&CO'2014], Tue, 12 Apr 2022 00:14:39 GMT -->

</html>