<?php
	include '../../config.php';
	include_once '../../Model/produit.php';

	class produitC {
		function afficher_produit(){
			$sql="SELECT * FROM produits";
			$db = config::getConnexion();
			try{
				$listeProduit = $db->query($sql);
				return $listeProduit;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}


		function supprimer_produit($id_produit){
			$sql="DELETE FROM produits WHERE id_produit=:id_produit";
			$db = config::getConnexion();
			$query=$db->prepare($sql);
			$query->bindValue(':id_produit', $id_produit);
			try{
				$query->execute();
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}

		
		
		function rechercher($val)
 {
  $query = "SELECT * from produits where nom LIKE '%".$val."%'";
  $db=config::getConnexion();

  try
  {
   $liste = $db->query($query);
   return $liste;
  }
  catch(Exception $e)
  {
   echo 'Erreur: ', $e->getMessage();

  }
 }



		
		function ajouter_produit($produit){
			$sql="INSERT INTO produits (nom,marque, photo, description, prix,quantite,id_categorie) 
			VALUES (:nom,:marque, :photo, :description, :prix,:quantite,:id_categorie)";
			$db = config::getConnexion();
			try{
				$query = $db->prepare($sql);
				$query->execute([
					
					'nom' => $produit->getnom(),
					'marque' => $produit->getmarque(),
					'photo' => $produit->getphoto(),
                    'description' => $produit->getdescription(),
                    'prix' => $produit->getprix(),
					'quantite' => $produit->getquantite(),
					'id_categorie' => $produit->getid_categorie()
					
				
					
					
				]);			
			}
			catch (Exception $e){
				echo 'Erreur: '.$e->getMessage();
			}			
		}



		function recuperer_produit($id_produit){
			$sql="SELECT * from produits where id_produit=id_produit";
			$db = config::getConnexion();
			try{
				$query=$db->prepare($sql);
				$query->execute();

				$produit=$query->fetch();
				return $produit;
			}
			catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
		}

		function afficher_voiture(){
		
			$sql="SELECT * from produits where mod (id_categorie,2)=0 ";
			$db = config::getConnexion();
			try{
				$liste = $db->query($sql);
				return $liste;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
			  
		}

		function afficher_piece(){
		
			$sql="SELECT * from produits where mod (id_categorie,2)!=0 ";
			$db = config::getConnexion();
			try{
				$list = $db->query($sql);
				return $list;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
			  
		}

		

		

		
		function modifier_produit($produit,$id_produit){
			
			try {
				$db = config::getConnexion();
				$query = $db->prepare(
					'UPDATE produits SET 
					    nom=:nom,
						marque= :marque, 
						photo= :photo, 
                        description= :description, 
                        prix= :prix,
						quantite= :quantite,
						id_categorie= :id_categorie
					WHERE id_produit= :id_produit'
					
				);
				
				$query->execute([
                     
					'nom'=>$produit->getnom(),
					'marque' => $produit->getmarque(),
					'photo' => $produit->getphoto(),
                    'description' => $produit->getdescription(),
                    'prix' => $produit->getprix(),
					'quantite' => $produit->getquantite(),
					'id_categorie' => $produit->getid_categorie(),
				
                    'id_produit' => $id_produit
				]) or die(print_r($db->errorInfo()));
				echo $query->rowCount() . " Modifié avec succés <br>";
			} catch (PDOException $e) {
				$e->getMessage();
			}
		}

		
 public function triPrix()
	{
		$db = config::getConnexion();
    	$sql = " SELECT * FROM produits ORDER BY prix ASC";
		
		
		$db = config::getConnexion();
			try{
				$listeProd = $db->query($sql);
				return $listeProd;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
	
	}
		
	
	
	 function triPrixDESC()
	{
		$db = config::getConnexion();
    	$sql = " SELECT * FROM produits ORDER BY prix DESC";
		
		
		$db = config::getConnexion();
			try{
				$listePro = $db->query($sql);
				return $listePro;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
	}
		
	}


	function increment ($produit,$nom){

		try {
			$db = config::getConnexion();
			$query = $db->prepare(
				'UPDATE produits SET 
					like=like+1 where nom=:nom'
					
					
				
			);
			
			$query->execute([
				 
				'like'=>$produit->getlike(),
				'nom' => $nom
			]);
			echo $query->rowCount() . " Modifié avec succés <br>";
		} catch (PDOException $e) {
			$e->getMessage();
		}
	}
			
		


		




	
?>