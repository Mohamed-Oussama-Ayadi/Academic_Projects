<?php
session_start() ; 
if (isset($_SESSION["email"]))
{
	if ($_SESSION["role_user"] == "Administrateur") {
		header("location:../back/afficherUtilisateurs.php"); 
     } else if ($_SESSION["role_user"] == "User")
	header("location:index.php") ; 
}
$con = mysqli_connect('localhost','root') ; 
mysqli_select_db($con,'projet') ;
$email = "" ; 
if (isset($_POST['email'])) 
{
	$email = $_POST["email"] ; 
	$password = md5($_POST["password_user"]) ; 

	$req = "select * from users where Email='$email' and password='$password'" ; 
	$result = $con->query($req) ; 

	if ($result->num_rows>0) 
	{
		$_SESSION['email'] = $email ;
		while ($row = $result->fetch_assoc()) 
		{
			$_SESSION['nom_prenom_user'] = $row['Nom'] ." " .$row['Prenom'];
			$_SESSION['email'] = $row['Email'];
			$_SESSION['tel_user'] = $row['tel_user'];
			$_SESSION['id_user'] = $row['Id_user'] ;
			$_SESSION['role_user'] = $row['Role'];
            $_SESSION['img'] = $row['img'];
		}
		if ($_SESSION["role_user"] == "Administrateur")
        header("location:../back/afficherUtilisateurs.php"); 
		else if ($_SESSION["role_user"] == "User")
			header("location:index.php") ; 
		die ; 

	} else {
		echo "Try again." ; 
	}
}
?>	
<!DOCTYPE html>
<html lang="fr">
    <style>
        body {text-align: center;}
    </style>
    
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Connexion</title>
     <!-- Google Fonts -->
     <link href='http://fonts.googleapis.com/css?family=Titillium+Web:400,200,300,700,600' rel='stylesheet' type='text/css'>
     <link href='http://fonts.googleapis.com/css?family=Roboto+Condensed:400,700,300' rel='stylesheet' type='text/css'>
     <link href='http://fonts.googleapis.com/css?family=Raleway:400,100' rel='stylesheet' type='text/css'>
     
     <!-- Bootstrap -->
     <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/bootstrap/3.2.0/css/bootstrap.min.css">
     
     <!-- Font Awesome -->
     <link rel="stylesheet" href="http://maxcdn.bootstrapcdn.com/font-awesome/4.3.0/css/font-awesome.min.css">
     
     <!-- Custom CSS -->
     <link rel="stylesheet" href="css/owl.carousel.css">
     <link rel="stylesheet" href="style.css">
     <link rel="stylesheet" href="css/responsive.css">
</head>

<body>
    <div class="header-area">
        <div class="container">
            <div class="row">
                <div class="col-md-8">
                    <div class="user-menu">
                        <ul>
                            <li><a href="cart.html"><i class="fa fa-user"></i> Mon panier </a></li>
                            <li><a href="signup.php"><i class="fa fa-user"></i> signup</a></li>
                        </ul>
                    </div>
                </div>
                
                <div class="col-md-4">
                    <div class="header-right">
                        <ul class="list-unstyled list-inline">
                            <li class="dropdown dropdown-small">
                                <a data-toggle="dropdown" data-hover="dropdown" class="dropdown-toggle" href="#"><span class="key">Language :</span><span class="value">Français </span><b class="caret"></b></a>
                                <ul class="dropdown-menu">
                                    <li><a href="#">Français</a></li>
                                    <li><a href="#">Anglais</a></li>
                                </ul>
                            </li>
                        </ul>
                    </div>
                </div>
            </div>
        </div>
    </div> <!-- End header area -->
    
    <div class="site-branding-area">
        <div class="container">
            <div class="row">
                <div class="col-sm-6">
                    <div class="logo">
                        <h1><a href="index.php"><span>Eco-speed</span></a></h1>
                    </div>
                </div>
                
                <div class="col-sm-6">
                    <div class="shopping-item">
                        <a href="cart.html">Panier - <span class="cart-amunt">000 dt</span> <i class="fa fa-shopping-cart"></i> <span class="product-count"> 0 </span></a>
                    </div>
                </div>
            </div>
        </div>
    </div> <!-- End site branding area -->
    
    <div class="mainmenu-area">
        <div class="container">
            <div class="row">
                <div class="navbar-header">
                    <button type="button" class="navbar-toggle" data-toggle="collapse" data-target=".navbar-collapse">
                        <span class="sr-only">Toggle navigation</span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                        <span class="icon-bar"></span>
                    </button>
                </div> 
                <div class="navbar-collapse collapse">
                    <ul class="nav navbar-nav">
                        <li class="active"><a href="index.php">Acceuil</a></li>
                        <li><a href="shop.html">Boutique</a></li>
                        <li><a href="cart.html">Panier</a></li>
                        <li><a href="#">Contacts</a></li>
                    </ul>
                </div>  
            </div>
        </div>
    </div> <!-- End mainmenu area -->

    <div class="product-big-title-area">
        <div class="container">
            <div class="row">
                <div class="col-md-12">
                    <div class="product-bit-title text-center">
                        <h2>Connexion</h2>
                    </div>
                </div>
            </div>
        </div>
    </div> <!-- End Page title area -->
    <br><br>
    <form method="POST" action="">
    <div class="textbox">
        <i class="fa fa-user" aria-hidden="true"></i>
        <input type="text" id="id" placeholder="Identifiant" name="email" value="">
    </div>
      <br>

      <div class="textbox"> 
        <i class="fa fa-lock" aria-hidden="true"></i>
        <input type="password" id="pwd" placeholder="Mot de passe" name="password_user" value="">
    </div>
    <br>
    <a href="forgotPassword.php"><p>forgot your Password ?</p></a>
    <div>
         <input class="btn" type="submit" value="Se connecter"/> </a>
    </div>
    </form>
    <br><br>
</body>