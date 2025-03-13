<?php

use PHPMailer\PHPMailer\PHPMailer;
use PHPMailer\PHPMailer\SMTP;
use PHPMailer\PHPMailer\Exception;

include_once "../../controller/config.php";
include_once "../../model/factures.php";
include "../../fpdf/fpdf.php";
/* require 'vendor/autoload.php'; */

class facturesC
{
 function ajouterFactures($factures)
 {
  $sql = "INSERT INTO facture (reference,id_station,id_user,matricule,montant,date_paiement) VALUES(NULL,:id_station,:id_user,:matricule,:montant,:date_paiement)";
  $db = config::getConnexion();

  try
  {
   $query = $db->prepare($sql);
   $query->execute([
	'id_station' =>$factures->getidstation(),
	'id_user' =>$factures->getid_user(),
	'matricule' => $factures->getmatricule(),
	'montant' => $factures->getmontant(),
	'date_paiement' => $factures->getdate_paiement()
   ]);
  }
  catch(exception $e)
  {
   echo 'erreur: ',$e->getmessage();
  }
 }

 function afficherfactures()
 {
  $sql="select * from facture";
  $db=config::getconnexion();

  try{
   $liste=$db->query($sql);
   return $liste;
  }
  catch(exception $e)
  {
   echo 'erreur: ',$e->getmessage();
  }
 }
 function afficherRefernce()
 {
  $sql = "SELECT DISTINCT reference from facture";
  $db = config::getConnexion();

  try
  {
   $liste=$db->query($sql);
   return $liste;
  }
  catch(exception $e)
  {
   echo 'erreur: ',$e->getMessage();
  }
 }
 function afficherIdStation()
 {
  $sql = "SELECT DISTINCT id_station from facture";
  $db = config::getConnexion();

  try
  {
   $liste=$db->query($sql);
   return $liste;
  }
  catch(exception $e)
  {
   echo 'Erreur : ', $e->getMessage();
  }
 }

 function affichertotalite($id_user,$matricule,$montant)
 {
   $sql="select * from facture where id_user=$id_user and matricule=$matricule and montant=$montant";
	$db = config::getconnexion();
   try{
   $query=$db->prepare($sql);
	$query->execute();

   $factures=$query->fetch();
	return $factures;
			}
			catch (Exception $e){
				die('Erreur: '.$e->getMessage());
			}
		}

 function supprimerFacture($reference)
 {
  $sql="DELETE from facture where reference=:reference";
  $db=config::getConnexion();
  $query=$db->prepare($sql);
  $query->bindValue(':reference',$reference);
  try
  { 
   $query->execute();
  }
  catch(Exception $e)
   {
   echo 'Erreur: ',$e->getMessage();
  }
 }

 function modifierFacture($reference,$id_user,$matricule,$montant,$date_paiement)
 {
  try
  {
   $db=config::getConnexion();
   $query=$db->prepare('UPDATE facture SET id_user=:id_user,matricule=:matricule,montant=:montant,date_paiement=:date_paiement WHERE reference=:reference');
   $query->execute([
	'id_user'=>$id_user,
	'matricule'=>$matricule,
	'montant'=>$montant,
	'date_paiement'=>$date_paiement,
	'reference'=>$reference,
   ]);
   echo $query->rowCount(), "Factures modifiees avec succe";
  }
  catch(PDOException $e)
   {
   echo 'Erreur: ',$e->getMessage();
  }
 }
 function rechercherFacturesParRef($reference)
 {
  $db=config::getConnexion();
  $sql="SELECT * from facture where reference=:reference";
  $query=$db->prepare($sql);
  $query->bindParam(':reference',$reference);

  try
  {
   $query->execute();
   $liste=$query->fetchAll();
   return $liste;
  }
  catch(Exception $e)
  {
   echo 'Erreur : ', $e->getMessage();
  }
 }
 function trierFacture($critere)
 {
  $db=config::getconnexion();
  /* $query="SELECT * from facture ORDER BY '%".$critere."%'"; */
  $query="SELECT * from facture ORDER BY $critere ";
  try
  {
   $liste= $db->query($query);
   $rows=$liste->fetchAll(PDO::FETCH_ASSOC);
   return $rows;
  }
  catch(Exception $e)
  {
   echo 'ERREUR : ', $e->getMessage();
  }
 }

 function rechercherFacture($val)
 {
  $query = "SELECT * from facture where CONCAT(reference,id_user,matricule) LIKE '%".$val."%'";
  $db=config::getConnexion();

  try
  {
   $liste = $db->query($query);
   $rows=$liste->fetchAll(PDO::FETCH_ASSOC);
   return $rows;
  }
  catch(Exception $e)
  {
   echo 'Erreur: ', $e->getMessage();

  }
 }
function verifiermatricule($matricule):bool
{
 $cond="tun";
 if(strpos($matricule,$cond) == false)
 {
  echo "<script type='text/javascript'>alert('Matricule doit contenir la chaine TUN ');</script>";
  return false;
 }
  return true;
}
function verifierMontant($montant):bool
{
 if(preg_match('/^[0-9]+$/',$montant) == false)
 {
   echo "<script type='text/javascript'>alert('Montant doit etre un entier POSITIF');</script>";
   return false;
 }
 else
  return true;
}

function generatePDF()
{
 $db = config::getConnexion();
 $pdf = new FPDF();

 $pdf->AddPage();
 $pdf->SetFont('Arial','B',12);
 $pdf->SetTitle('Liste Factures');
 $pdf->Image('images/Logo.png',10,10,-300);
 $sql="SELECT column_name from information_schema.columns where table_name like 'facture'";
 $query1 = $db->prepare($sql);
 $query1->execute();
 $header = $query1->fetchAll(PDO::FETCH_OBJ);
 $cnt = 1;

 if($query1->rowCount() > 0)
 {
  foreach($header as $heading)
  {
   foreach($heading as $column_heading)
   {
	$pdf->Cell(39,7,$column_heading,1);
   }
  }
 }

 $sql2 = "SELECT * from facture";
 $query=$db->prepare($sql2);
 $query->execute();
 $results=$query->fetchAll(PDO::FETCH_OBJ);
 $cnt=1;
  if($query->rowCount() > 0)
  {
   foreach($results as $row)
   {
	$pdf->SetFont('Arial','',10);
	$pdf->Ln();
	foreach($row as $col)
	{
	 $pdf->Cell(39,7,$col,1);
	}
   }
  }

 $pdf->Output();


}

/* function sendMail() */
/* { */
/*  $to="soussinourtn@gmail.com"; */
/*  $subject="test php"; */
/*  $message="test hhhhhhh"; */
/* /1* $header = "From:abc@somedomain.com \r\n"; *1/ */
/* /1*          $header .= "Cc:afgh@somedomain.com \r\n"; *1/ */
/* /1*          $header .= "MIME-Version: 1.0\r\n"; *1/ */
/* /1*          $header .= "Content-type: text/html\r\n"; *1/ */
/* 		 $val=mail($to,$subject,$message); */

/* 		 if($val == true) */
/* 		 { */
/* 		  echo "Message sent"; */
/* 		 } */
/* 		 else */
/* 		 { */
/* 		  echo "Message not sent"; */
/* 		 } */
/* } */
/* function sendMailPhp() */
/* { */
/*  $mail= new PHPMailer(true);try { */
/*     //Server settings */
/*     $mail->SMTPDebug = SMTP::DEBUG_SERVER;                      //Enable verbose debug output */
/*     $mail->isSMTP();                                            //Send using SMTP */
/*     $mail->Host       = 'smtp.gmail.com';                     //Set the SMTP server to send through */
/*     $mail->SMTPAuth   = true;                                   //Enable SMTP authentication */
/*     $mail->Username   = 'username';                     //SMTP username */
/*     $mail->Password   = 'secret';                               //SMTP password */
/*     $mail->SMTPSecure = PHPMailer::ENCRYPTION_SMTPS;            //Enable implicit TLS encryption */
/*     $mail->Port       = 25;                                    //TCP port to connect to; use 587 if you have set `SMTPSecure = PHPMailer::ENCRYPTION_STARTTLS` */

/*     //Recipients */
/*     $mail->setFrom('soussinourtn@gmail.com', 'Mailer'); */
/*     /1* $mail->addAddress('joe@example.net', 'Joe User');     //Add a recipient *1/ */
/*     /1* $mail->addAddress('ellen@example.com');               //Name is optional *1/ */
/*     /1* $mail->addReplyTo('info@example.com', 'Information'); *1/ */
/*     /1* $mail->addCC('cc@example.com'); *1/ */
/*     /1* $mail->addBCC('bcc@example.com'); *1/ */

/*     //Attachments */
/*     /1* $mail->addAttachment('/var/tmp/file.tar.gz');         //Add attachments *1/ */
/*     /1* $mail->addAttachment('/tmp/image.jpg', 'new.jpg');    //Optional name *1/ */

/*     //Content */
/*     $mail->isHTML(true);                                  //Set email format to HTML */
/*     $mail->Subject = 'Here is the subject'; */
/*     $mail->Body    = 'This is the HTML message body <b>in bold!</b>'; */
/*     $mail->AltBody = 'This is the body in plain text for non-HTML mail clients'; */

/*     $mail->send(); */
/*     echo 'Message has been sent'; */
/* } catch (Exception $e) { */
/*     echo "Message could not be sent. Mailer Error: {$mail->ErrorInfo}"; */
/* } */
/* } */
}

?>
