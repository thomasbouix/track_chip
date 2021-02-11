<?php

// Recuperer la/les dernières données (positions) insérer dans la base de donnée
// Met les données dans un Json. 
// Retourne ce Json lorsqu'un GET est effectué sur cette page par datas.js

	// Connection to database
  try
  {
    $db = new SQLite3('../database/track_chip.db');
  }
  catch(Exception $e)
  {
  	die('Erreur : '.$e->getMessage());
  }

  // Select last Location receive in database
  $response = $db->query('SELECT * FROM Location WHERE id = (SELECT MAX(id) FROM Location)');
  
  $data = array();

	while ($res = $response->fetchArray(1))
	{
		array_push($data, $res);
	}
	
	echo json_encode($data);
	
?>