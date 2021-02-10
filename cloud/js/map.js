
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
        if (results[0]) 
        {
          current_alt = results[0].elevation
          document.getElementById("current_alt").innerHTML = current_alt;
        } 
        else 
        {
          console.log("No results found");
        }

      } 
      else 
      {
        console.log("Elevation service failed due to: " + status)
      }
    }
  );
}