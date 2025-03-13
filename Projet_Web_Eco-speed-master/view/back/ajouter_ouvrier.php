<?php
    include_once '../../model/ouvrier.php';
    include_once '../../controller/ouvrierO.php';
    
    $error = "";
    // creation ouvrier
    $ouvrier = null;

    // create an instance of the controller
    $ouvrierO = new ouvrierO();
    if ( isset($_POST["id"])&&
        isset($_POST["nom"]) &&		
        isset($_POST["prenom"]) &&
		isset($_POST["age"]) && 
        isset($_POST["departement"]) &&  
        isset($_POST["email"])) 
        {if (!empty($_POST["id"])&&
            !empty($_POST['nom']) &&
            !empty($_POST["prenom"]) && 
			!empty($_POST["age"]) && 
            !empty($_POST["departement"]) && 
            !empty($_POST["email"])) 
        { $ouvrier = new ouvrier(
            $_POST['id'],
			$_POST['nom'],
            $_POST['prenom'], 
            $_POST['age'],
            $_POST['departement'],
            $_POST['email']);
            $ouvrierO->ajouter_ouvrier($ouvrier);
            header('Location:afficher_ouvrier.php');
        }
        else $error = "Informations manquantes";
        }

    
?>

<!DOCTYPE HTML>
<html lang="en">


<head>
    <meta charset="utf-8">
    <meta nom="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Gestion Ouvriers</title>

    <link href="images/favicon.ico" rel="shortcut icon" type="image/x-icon">

    <link href="css/bootstrapf9e3.css?v=1.1" rel="stylesheet" type="text/css" />

    <link rel="stylesheet" href="fonts/material-icon/css/round.css" />

    <!-- custom style -->
    <link href="css/uif9e3.css?v=1.1" rel="stylesheet" type="text/css" />
    <link href="css/responsivef9e3.css?v=1.1" rel="stylesheet" />

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
                                class="img-xs rounded-circle" src="images/people/avatar1.jpg" alt="User"></a>
                        <div class="dropdown-menu dropdown-menu-end">
                            <a class="dropdown-item" href="#">My profile</a>
                            <a class="dropdown-item" href="#">Settings</a>
                            <a class="dropdown-item text-danger" href="#">Exit</a>
                        </div>
                    </li>
                </ul>
            </div>
        </header>

        <section class="content-main" style="max-width: 720px">

            <div class="content-header">
                <h2 class="content-title">Ajouter Ouvrier</h2>
            </div>
            <div id="error">
                <?php echo $error; ?>
            </div>
            <form action="ajouter_ouvrier.php" method="POST" onsubmit="return verif()">

                <div class="mb-4">

                    <label for="nom">nom: </label>
                    <input type="text" nom="nom" id="nom" maxlength="20" class="form-control">
                    <p><div id="errornom" style="color:red"></div></p>
                </div>

                <div class="mb-4">
                    <label for="prenom">prenom: </label>
                    <input type="text" nom="prenom" id="prenom" maxlength="20" class="form-control">
                    <p><div id="errorprenom" style="color:red"></div></p>
                </div>

                <div class="mb-4">
                    <label for="age">age: </label>
                    <input type="text" nom="age" id="age" class="form-control">
                    <p><div id="errorage" style="color:red"></div></p>
                </div>

                <div class="mb-4">

                    <label for="departement">Departement: </label>
                    <input type="text" nom="departement" id="departement" class="form-control">
                    <p><div id="errordepartement" style="color:red"></div></p>
                </div>

                <div class="mb-4">

                    <label for="email">email: </label>
                    <input type="email" nom="email" id="email" class="form-control">
                    <p><div id="erroremail" style="color:red"></div></p>
                </div>

                <td>
                    <input type="submit" type="button" class="btn btn-primary btn-sm"
                        style="margin-top:3%;margin-left:5%;border-radius: 10%;" nom="Envoyer" value="Envoyer">
                </td>
                <td>
                    <input type="reset" class="btn btn-outline-danger"
                        style="margin-top:3%;margin-left:5%;border-radius: 10%;" nom="Annuler" value="Annuler">
                </td>
            </form>
               
      <script>
        function verif()
        {

		var nom = document.getElementById('nom').value;
		var prenom = document.getElementById('prenom').value;
        var age = document.getElementById('age').value;
        var departement = document.getElementById('departement').value;
        var email = document.getElementById('email').value;
		

        var errornom = document.getElementById('errornom');
		var errorprenom = document.getElementById('errorprenom');
		var errorage = document.getElementById('errorage');
		var errordepartement = document.getElementById('errordepartement');
        var erroremail = document.getElementById('erroremail');

        if(nom =="")
        {//alert("veuillez saisir votre nom!");
        errornom.innerHTML="erreur!nom vide!";
        return false;}
         
        if(prenom =="")
        {//alert("Veuillez saisir votre prenom!");
        errorprenom.innerHTML="erreur!prenom vide!";
        return false;}
        
        if(age=="")
        {//alert("Veuillez saisir votre age!");  
        errorage.innerHTML="erreur!age vide!";
        return false;}
        else 
        if(age<= 18)
        {//alert("l'age doit etre superieur à 18 !"); 
        errorage.innerHTML="erreur!age invalide!";
         return false;}  

        if(departement=="")
        {//alert("Veuillez saisir votre departement!");  
        errordepartement.innerHTML="erreur!departement vide!";
        return false;}
        
        if (email=="")
        {//alert("Veuillez saisir votre email!");
        erroremail.innerHTML="erreur!email vide!";
        return false;}
        
        }  
        </script>  

          
            


            </div> <!-- table-responsive end// -->
            </div> <!-- card-body end// -->
            </div> <!-- card end// -->
            <!--</div> -->

        </section> <!-- content-main end// -->
    </main>

    <script type="text/javascript">
    if (localStorage.getItem("darkmode")) {
        var body_el = document.body;
        body_el.classnom += 'dark';
    }
    </script>

    <script src="asset/js/jquery-3.5.0.min.js"></script>
    <script src="asset/js/bootstrap.bundle.min.js"></script>

    <!-- ChartJS files-->
    <script src="https://cdn.jsdelivr.net/npm/chart.js@2.8.0"></script>

    <!-- Custom JS -->
    <script src="asset/js/scriptc619.js?v=1.0" type="text/javascript"></script>

</body>

<!-- Mirrored from www.ecommerce-admin.com/demo/page-index-1.html by HTTrack Website Copier/3.x [XR&CO'2014], Tue, 12 Apr 2022 00:14:39 GMT -->

</html>