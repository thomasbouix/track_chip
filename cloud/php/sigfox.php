<?php

  // Recupere les donnees postee par Sigfox et les insere dans la base de donnee

  echo "On rentre dans sigfox.php\n";

  // Receive Data from SigFox
  if (isset($_POST['altitude'], $_POST['latitude'], $_POST['longitude'])) 
  {  
    $altitude   = (double)$_POST['altitude'];
    $latitude   = (double)$_POST['latitude'];
    $longitude  = (double)$_POST['longitude'];
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

  // Insert in to database
  $res = $db->query('INSERT INTO Location(altitude, latitude, longitude, device_id) 
                            VALUES ('.$altitude.', '.$latitude.', ' .$longitude.', 1)');
?>