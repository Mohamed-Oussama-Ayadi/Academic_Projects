<?php
	include '../../config.php';
	include_once '../../model/boutique.php';

	class boutiqueB 
	{
		function afficher_boutique()
		{
			$sql="SELECT * FROM boutiques";
			$db = config::getConnexion();
			try{
				$liste = $db->query($sql);
				return $liste;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}


		function supprimer_boutique($id)
		{
			$sql="DELETE FROM boutiques WHERE id=:id";
			$db = config::getConnexion();
			$query=$db->prepare($sql);
			$query->bindValue(':id', $id);
			try{
				$query->execute();
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}


		
		function ajouter_boutique($boutique)
		{
			$sql="INSERT INTO boutiques (adresse, email, nbre_voitures, nbre_pieces_rechange) 
			VALUES (:adresse, :email, :nbre_voitures, :nbre_pieces_rechange)";
			$db = config::getConnexion();
			try{
				$query = $db->prepare($sql);
				$query->execute([
					//'id' => $boutique->getId(),
					'adresse' => $boutique->getAdresse(),
					'email' => $boutique->getEmail(),
                    'nbre_voitures' => $boutique->getNbreVoitures(),
                    'nbre_pieces_rechange' => $boutique->getNbrePiecesRechange()
				]);			
			}
			catch (Exception $e){
				echo 'Erreur: '.$e->getMessage();
			}			
		}



		function recuperer_boutique($id)
		{
			$sql="SELECT * from boutiques where id=id";
			$db = config::getConnexion();
			try{
				$query=$db->prepare($sql);
				$query->execute();

				$boutique=$query->fetch();
				return $boutique;
			}
			catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
		}
		

		function modifier_boutique($boutique, $id)
		{
			try {
				$db = config::getConnexion();
				$query = $db->prepare(
					'UPDATE boutiques SET 
						adresse= :adresse, 
						email= :email, 
                        nbre_voitures= :nbre_voitures, 
                        nbre_pieces_rechange= :nbre_pieces_rechange
					WHERE id= :id'
				);
				$query->execute([
					'adresse' => $boutique->getAdresse(),
					'email' => $boutique->getEmail(),
                    'nbre_voitures' => $boutique->getNbreVoitures(),
					'nbre_pieces_rechange' => $boutique->getNbrePiecesRechange(),
					'id' => $id
				]);
				echo $query->rowCount() . " Modifié avec succés <br>";
			} catch (PDOException $e) {
				$e->getMessage();
			}
		}


		function rechercher($val_adresse, $val_email, $val_nbre_voitures, $val_nbre_pieces_rechange)
		{$db=config::getConnexion();
		 $sql = "SELECT * from boutiques where adresse=:val_adresse or email=:val_email or nbre_voitures=:val_nbre_voitures or nbre_pieces_rechange=:val_nbre_pieces_rechange";
		 $query=$db->prepare($sql);
  		 $query->bindParam(':val_adresse',$val_adresse);
  		 $query->bindParam(':val_email',$val_email);
  		 $query->bindParam(':val_nbre_voitures',$val_nbre_voitures);
 		 $query->bindParam(':val_nbre_pieces_rechange',$val_nbre_pieces_rechange);
	   
		 try
		 {$query->execute();
		  $liste=$query->fetchAll();
		  return $liste;}
		 catch(Exception $e)
		 {echo 'Erreur: ', $e->getMessage();}
		}


		
	}
?>