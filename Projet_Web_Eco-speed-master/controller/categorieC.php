<?php
	include '../../config.php';
	include_once '../../Model/categorie.php';

	class categorieC {
		function afficher_categorie(){
			$sql="SELECT * FROM categories";
			$db = config::getConnexion();
			try{
				$liste = $db->query($sql);
				return $liste;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}


		function supprimer_categorie($id_categorie){
			$sql="DELETE FROM categories WHERE id_categorie=:id_categorie";
			$db = config::getConnexion();
			$query=$db->prepare($sql);
			$query->bindValue(':id_categorie', $id_categorie);
			try{
				$query->execute();
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}



		function ajouter_categorie($categorie){
			$sql="INSERT INTO categories ( nom, type, stock_max) 
			VALUES (:nom, :type, :stock_max)";
			$db = config::getConnexion();
			try{
				$query = $db->prepare($sql);
				$query->execute([
					
					'nom' => $categorie->getnom(),
					'type' => $categorie->gettype(),
                    'stock_max' => $categorie->getstock_max()
                    
				]);			
			}
			catch (Exception $e){
				echo 'Erreur: '.$e->getMessage();
			}			
		}



		function recuperer_categorie($id_categorie){
			$sql="SELECT * from categories where id_categorie=id_categorie";
			$db = config::getConnexion();
			try{
				$query=$db->prepare($sql);
				$query->execute();

				$categorie=$query->fetch();
				return $categorie;
			}
			catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
		}


		
		function recuperer_nom($id_categorie){
			$nom="";
			$sql="SELECT nom from categories where id_categorie=id_categorie";
			$db = config::getConnexion();
			try{
				$query=$db->prepare($sql);
				$query->execute();

				$nom=$query->fetch();
				return $nom;
			}
			catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
		}
		
	
	
		function modifier_categorie($categorie, $id_categorie){
			try {
				$db = config::getConnexion();
				$query = $db->prepare(
					'UPDATE categories SET 
					    nom=:nom,
						type= :type, 
						stock_max= :stock_max, 
                        
					WHERE id_categorie= :id_categorie'
				);
				$query->execute([
                     
					'nom'=>$categorie->getnom(),
					'type' => $categorie->gettype(),
					'stock_max' => $categorie->getstock_max(),
                     'id_categorie' => $id_categorie
				]);
				echo $query->rowCount() . " Modifié avec succés <br>";
			} catch (PDOException $e) {
				$e->getMessage();
			}
		}
	
	
	
	
	
	
	
	
	
	}
			
			
?>