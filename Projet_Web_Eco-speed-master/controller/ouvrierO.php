<?php
	include '../../config.php';
	include_once '../../model/ouvrier.php';

	class ouvrierO {
		function afficher_ouvrier(){
			$sql="SELECT * FROM ouvriers";
			$db = config::getConnexion();
			try{
				$liste = $db->query($sql);
				return $liste;
			}
			catch(Exception $e){
				die('Erreur:'. $e->getMessage());
			}
		}


		function supprimer_ouvrier($id){
			$sql="DELETE FROM ouvriers WHERE id=:id";
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



		function ajouter_ouvrier($ouvrier){
			$sql="INSERT INTO ouvriers ( nom, prenom, age, departement, email) 
			VALUES (:nom, :prenom, :age, :departement, :email)";
			$db = config::getConnexion();
			try{
				$query = $db->prepare($sql);
				$query->execute([
					 //'id' => $ouvrier->getId(),
					'nom' => $ouvrier->getNom(),
					'prenom' => $ouvrier->getPrenom(),
                    'age' => $ouvrier->getAge(),
                    'departement' => $ouvrier->getDepartement(),
					'email' => $ouvrier->getEmail()
				]);			
			}
			catch (Exception $e){
				echo 'Erreur: '.$e->getMessage();
			}			
		}



		function recuperer_ouvrier($id){
			$sql="SELECT * from ouvriers where id=id";
			$db = config::getConnexion();
			try{
				$query=$db->prepare($sql);
				$query->execute();

				$ouvrier=$query->fetch();
				return $ouvrier;
			}
			catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
		}
		
		function modifier_ouvrier($ouvrier, $id){
			try {
				$db = config::getConnexion();
				$query = $db->prepare(
					'UPDATE ouvriers SET 
						nom= :nom, 
						prenom= :prenom, 
                        age= :age, 
                        departement= :departement,  
						email= :email
					WHERE id= :id'
				);
				$query->execute([
					'nom' => $ouvrier->getNom(),
					'prenom' => $ouvrier->getPrenom(),
                    'age' => $ouvrier->getAge(),
					'departement' => $ouvrier->getDepartement(),
					'email' => $ouvrier->getEmail(),
					'id' => $id
				]);
				echo $query->rowCount() . " Modifié avec succés <br>";
			} catch (PDOException $e) {
				$e->getMessage();
			}
		}


		
		function rechercher($val_nom, $val_prenom, $val_age, $val_departement, $val_email)
		{$db=config::getConnexion();
		 $sql = "SELECT * from ouvriers where nom=:val_nom or prenom=:val_prenom or age=:val_age or departement=:val_departement or email=:val_email";
		 $query=$db->prepare($sql);
  		 $query->bindParam(':val_nom',$val_nom);
  		 $query->bindParam(':val_prenom',$val_prenom);
  		 $query->bindParam(':val_age',$val_age);
 		 $query->bindParam(':val_departement',$val_departement);
		 $query->bindParam(':val_email',$val_email);

		 try
		 {$query->execute();
		  $liste=$query->fetchAll();
		  return $liste;}
		 catch(Exception $e)
		 {echo 'Erreur: ', $e->getMessage();}
		}


	}
?>