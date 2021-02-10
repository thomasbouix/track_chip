<!DOCTYPE html>
<html>
  <head>
    
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Geolocation</title>

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">
    <link rel="stylesheet" href="../css/map.css">

    <!-- Google API JS -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>   
    
    <script src="../js/map.js" type="text/javascript" charset="utf-8" async defer></script>

  </head>

  <body>

    <?php

    	// Connection to database
      try
      {
        $db = new SQLite3('/Users/enzocalvino/Documents/Polytech/5A/IOT/Projet/track_chip/cloud/database/track_chip.db');
      }
      catch(Exception $e)
      {
      	die('Erreur : '.$e->getMessage());
      } 

      // Request to database
      $res = $db->query('SELECT * FROM Device');

    ?>

    <div class="jumbotron text-center">
      <h1>Bienvenue sur votre Application de Tracking !</h1>
      <p>Ici, vous pourrez suivre votre position par rapport à celle de votre tracker !</p>
    </div>

    <div class="container">
    	
    	<?php

    	// Test print some data from database

    	while ($row = $res->fetchArray()) {
        echo "{$row['id']} {$row['name']} {$row['ref_com']} {$row['owner_id']} \n";
      }

    	?>

    </div>

    <div class="container">
      
      <h2>Informations iténaire :</h1>

      <p>Distance : </p>
      <p>Direction : </p>
      <p>Altitude : <span id="current_alt"></span> m</p>

    </div>

    <div class="container" id="map"></div>

    <!-- Async script executes immediately and must be after any DOM elements used in callback. -->
    <script
      src="https://maps.googleapis.com/maps/api/js?key=AIzaSyDMnY8W47H_ztdC4sJjo2Z9_bu2y9-zEPM&callback=initMap&libraries=&v=weekly"
      async
    ></script>

  </body>

</html>