<?php

  // Recupere les donnees postee par Sigfox et les insere dans la base de donnee

  // echo "On rentre dans login.php\n";

  // Receive Data from SigFox
  if (isset($_POST['username'], $_POST['password'])) 
  {  
    $username   = (string)$_POST['username'];
    $password   = (string)$_POST['password'];
  }
  else
  {
    echo "Error POST";
  }

  // Connection to database
  try
  {
    $db = new SQLite3('../database/track_chip.db');
  }
  catch(Exception $e)
  { 
    die('Erreur : '.$e->getMessage());
  }

  // echo "username : ";
  // echo $username;
  // echo "\n";

  // echo "password : ";
  // echo $password;
  // echo "\n";

  // Insert in to database
  $response = $db->query('SELECT * FROM Owner WHERE username="' .$username. '" AND password="' .$password. '";');
  $resutl = $response->fetchArray(1);

  // echo "result : ";
  // print_r($resutl);
  // echo "\n";

  if (empty($resutl) == false) 
  {
    // header('Location: https://track-chip.alwaysdata.net/map.php');
    header('Location: http://127.0.0.1:8888/php/map.php');
    exit();
  }
  else
  {
    // header('Location: https://track-chip.alwaysdata.net/index.php');
    header('Location: http://127.0.0.1:8888/index.php');
    exit();
  }

?>