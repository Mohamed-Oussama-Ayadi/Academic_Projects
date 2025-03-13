<?php 
session_start() ; 

if (session_destroy())
{
	header ("location:../front/login.php")  ; 
}

?>