<?php

  // Recupere les donnees postee par Sigfox et les insere dans la base de donnee

  echo "On rentre dans sigfox.php\n";

  // Receive Data from SigFox
  if (isset($_POST['altitude'], $_POST['latitude'], $_POST['longitude'])) 
  {  
    $altitude   = (int)$_POST['altitude'];
    $latitude   = (int)$_POST['latitude'];
    $longitude  = (int)$_POST['longitude'];

    // scalling SigFox data
    $latitude   = ($latitude / 100000) - 180;
    $longitude  = ($longitude / 100000) - 90;
  }
  else
  {
    echo "Error POST";
  }

	// Connection to database
  try
  {
    // system('bash ../database/database.sh');
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