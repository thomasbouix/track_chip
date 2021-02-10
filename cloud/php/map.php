<!DOCTYPE html>
<html>
  <head>
    
    <meta charset="utf-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1">

    <title>Geolocation</title>

    <link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/css/bootstrap.min.css">

    <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.16.0/umd/popper.min.js"></script>
    <script src="https://maxcdn.bootstrapcdn.com/bootstrap/4.5.2/js/bootstrap.min.js"></script>
    <script src="https://polyfill.io/v3/polyfill.min.js?features=default"></script>

    <style type="text/css">
      /* Always set the map height explicitly to define the size of the div
       * element that contains the map. */
      #map {
        height: 100%;
      }

      /* Optional: Makes the sample page fill the window. */
      html,
      body {
        height: 100%;
        margin: 0;
        padding: 0;
      }

      .custom-map-control-button {
        appearance: button;
        background-color: #fff;
        border: 0;
        border-radius: 2px;
        box-shadow: 0 1px 4px -1px rgba(0, 0, 0, 0.3);
        cursor: pointer;
        margin: 10px;
        padding: 0 0.5em;
        height: 40px;
        font: 400 18px Roboto, Arial, sans-serif;
        overflow: hidden;
      }
      .custom-map-control-button:hover {
        background: #ebebeb;
      }
    </style>
    <script>

      var current_alt = 0;

      let map, window_current_pos;

      function initMap() {
        
        console.log("initMap()");

        // Default position : center of Paris
        map = new google.maps.Map(document.getElementById("map"), {
          center: { lat: 48.858725, lng: 2.341706 },
          zoom: 6,
        });

        // Create elevation service for current position
        const current_elevator = new google.maps.ElevationService();

        // Create info window for current position
        window_current_pos = new google.maps.InfoWindow();

        // Create info window for tracker position
        window_tracker_pos = new google.maps.InfoWindow();

        // button to get current position
        const button_current_pos = document.createElement("button");

        // button to get tracket position
        const button_tracker_pos = document.createElement("button");

        // Customize buttons
        button_current_pos.textContent = "View Current Location";
        button_current_pos.classList.add("custom-map-control-button");
        button_tracker_pos.textContent = "View Tracker Location";
        button_tracker_pos.classList.add("custom-map-control-button");
        
        // Add buttons to map
        map.controls[google.maps.ControlPosition.TOP_CENTER].push(
          button_current_pos
        );
        map.controls[google.maps.ControlPosition.TOP_CENTER].push(
          button_tracker_pos
        );

        button_current_pos.addEventListener("click", () => {
          console.log("Click on current pos button");
          // Try HTML5 geolocation.
          if (navigator.geolocation) {
            navigator.geolocation.getCurrentPosition(
              (position) => {
                
                const curr_pos = { lat: position.coords.latitude, lng: position.coords.longitude };

                getElevation(curr_pos, current_elevator);

                window_current_pos.setPosition(curr_pos);
                window_current_pos.setContent("Current Location found.");
                window_current_pos.open(map);
                map.setCenter(curr_pos);

              }, () => { handleLocationError(true, window_current_pos, map.getCenter()); }
            );
          } 
          else {
            // Browser doesn't support Geolocation
            handleLocationError(false, window_current_pos, map.getCenter());
          }
        });

        button_tracker_pos.addEventListener("click", () => {
          console.log("Click on tracker pos button");

          // Default tracker position : center of Lyon
          const tracker_pos = { lat: 45.738888, lng: 4.840406 };

          window_tracker_pos.setPosition(tracker_pos);
          window_tracker_pos.setContent("Tracker Location found.");
          window_tracker_pos.open(map);
          
          map.setCenter(tracker_pos);

          handleLocationError(true, window_tracker_pos, map.getCenter());

        });
      }

      function handleLocationError(browserHasGeolocation, window_info, pos) {
        window_info.setPosition(pos);
        
        if (!browserHasGeolocation){
          window_info.setContent("Error: The Geolocation service failed.");
        }

        window_info.open(map);
      }

      function getElevation(location, elevator) {

        console.log("getElevation()");

        // Initiate the location request
        elevator.getElevationForLocations(
          {
            locations: [location],
          },
          (results, status) => {

            if (status === "OK") {
              // Retrieve the first result
              if (results[0]) {
                current_alt = results[0].elevation
                document.getElementById("current_alt").innerHTML = current_alt;
                // print(current_alt)
              } 
              else {
                console.log("No results found");
              }
            } 
            else {
              console.log("Elevation service failed due to: " + status)
            }
          }
        );
      }

    </script>
  </head>

  <body onload="getElevation()">

    <?php

      $db = new SQLite3('/Users/enzocalvino/Documents/Polytech/5A/IOT/Projet/track_chip/cloud/database/track_chip.db');

      $res = $db->query('SELECT * FROM Device');

      while ($row = $res->fetchArray()) {
        echo "{$row['id']} {$row['name']} {$row['ref_com']} {$row['owner_id']} \n";
      }

    ?>

    <div class="jumbotron text-center">
      <h1>Bienvenue sur votre Application de Tracking !</h1>
      <p>Ici, vous pourrez suivre votre position par rapport à celle de votre tracker !</p>
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