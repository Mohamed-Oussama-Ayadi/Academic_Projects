<?php

include_once '../../model/User.php';
include_once '../../controller/UtilisateursU.php';
session_start();
if (isset($_SESSION["email"])) {
    if ($_SESSION["role_user"] == "Administrateur")
        header("location:../back/backUser.php");
    else if ($_SESSION["role_user"] == "User")
        header("location:index.php");
}
$error = "";
// create Utilisateur
$Utilisateurs = null;

// create an instance of the controller
$UtilisateursU = new UtilisateursU();
if (
    isset($_POST["Nom"]) &&
    isset($_POST["Prenom"]) &&
    isset($_POST["Age"]) &&
    isset($_POST["Ville"]) &&
    isset($_POST["Num_tel"]) &&
    isset($_POST["Email"]) &&
    isset($_POST["Role"]) &&
    isset($_POST["password"])
) {
    if (
        !empty($_POST['Nom']) &&
        !empty($_POST["Prenom"]) &&
        !empty($_POST["Age"]) &&
        !empty($_POST["Ville"]) &&
        !empty($_POST["Num_tel"]) &&
        !empty($_POST["Email"]) &&
        !empty($_POST["Role"])
    ) {


        //upload image
        $target_dir = "../uploads/";
        $target_file = $target_dir . basename($_FILES["fileToUpload"]["name"]);
        $uploadOk = 1;
        $imageFileType = strtolower(pathinfo($target_file, PATHINFO_EXTENSION));
        $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
        if ($check !== false) {
            // echo "File is an image - " . $check["mime"] . ".";
            $uploadOk = 1;
        } else {
            // echo "File is not an image.";
            $uploadOk = 0;
        }

        // Check if file already exists
        if (file_exists($target_file)) {
            echo "Sorry, file already exists.";
            $uploadOk = 0;
        }

        // Check file size
        if ($_FILES["fileToUpload"]["size"] > 500000) {
            echo "Sorry, your file is too large.";
            $uploadOk = 0;
        }

        // Allow certain file formats
        if (
            $imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
            && $imageFileType != "gif"
        ) {
            echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.";
            $uploadOk = 0;
        }
        if ($uploadOk == 0) {
            header('Location:image not uploaded');
        } else {
            if (move_uploaded_file($_FILES["fileToUpload"]["tmp_name"], $target_file)) {

                $Utilisateurs = new Utilisateurs(
                    null,
                    $_POST['Nom'],
                    $_POST['Prenom'],
                    $_POST['Age'],
                    $_POST['Ville'],
                    $_POST['Num_tel'],
                    $_POST['Email'],
                    $_POST['Role'],
                    md5($_POST['password'])
                );
                $Utilisateurs->setImg($target_file);
                $UtilisateursU->ajouterUtilisateurs($Utilisateurs);
                header('Location:login.php');
            }
        }
    } else {
        $error = "Missing information";
    }
}

?>
<!DOCTYPE html>
<html lang="fr">
<style>
    body {
        text-align: center;
    }
</style>

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>sign up</title>
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
                            <li><a href="login.php"><i class="fa fa-user"></i> Login</a></li>
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
                        <h2>sign up</h2>
                    </div>
                </div>
            </div>
        </div>
    </div> <!-- End Page title area -->
    <br><br>
    <form method="POST" action="" enctype="multipart/form-data">
        <div class="textbox">

            <input type="text" name="Nom" id="Nom" maxlength="20" placeholder="nom">
        </div>
        <br>

        <div class="textbox">
            <input type="text" name="Prenom" id="Prenom" maxlength="20" placeholder="prenom">
        </div>
        <br>
        <div class="textbox">
            <input type="text" name="Age" id="Age" placeholder="age">
        </div>
        <br>
        <div class="textbox">
            <input type="text" name="Ville" id="Ville" placeholder="ville">
        </div>
        <br>
        <div class="textbox">
            <input type="tel" name="Num_tel" id="Num_tel" placeholder="tel">
        </div>
        <br>
        <div class="textbox">
            <input type="Email" name="Email" id="Email" placeholder="email@esprit.tn">
        </div>
        <br>
        <div class="textbox">
            <input type="password" name="password" id="password" placeholder="password">
            <br>
            <br>
            <center><input type="file" name="fileToUpload" id="fileToUpload"></center>
        </div>
        <div class="textbox">

        </div>
        <br>
        <input type="hidden" name="Role" id="" value="User">
        <div>
            <input class="btn" type="submit" value="s'inscrire" />
        </div>
    </form>
    <br><br>
</body>