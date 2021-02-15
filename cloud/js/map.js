
var curr_pos, tracker_pos;

var current_alt = 0;
document.getElementById("current_alt").innerHTML = current_alt;

let map, window_current_pos, window_tracker_pos;

let markers     = [];
let pos_marker  = [];

var nb_position_display = 5;

function initMap() {
  
  console.log("initMap()");

  const DirectionsService   = new google.maps.DirectionsService();
  const directionsRenderer  = new google.maps.DirectionsRenderer();
  const geocoder            = new google.maps.Geocoder();

  // Default position : center of Paris
  map = new google.maps.Map(document.getElementById("map"), {
    center: { lat: 48.858725, lng: 2.341706 },
    zoom: 6,
  });

  directionsRenderer.setMap(map);

  // Create elevation service for current position
  const current_elevator = new google.maps.ElevationService();

  // Create info window for current position
  window_current_pos = new google.maps.InfoWindow();

  // Create info window for tracker position
  window_tracker_pos = new google.maps.InfoWindow();

  // button to get current position
  const button_current_pos  = document.createElement("button");

  // button to get tracket position
  const button_tracker_pos  = document.createElement("button");

  // button to get itinerary between current and tracker pos
  const button_itineraty    = document.createElement("button");

  // Customize buttons
  button_current_pos.textContent = "View Current Location";
  button_current_pos.classList.add("custom-map-control-button");

  button_tracker_pos.textContent = "View Tracker Location";
  button_tracker_pos.classList.add("custom-map-control-button");

  button_itineraty.textContent = "Get Route";
  button_itineraty.classList.add("custom-map-control-button");
  
  // Add buttons to map
  map.controls[google.maps.ControlPosition.TOP_CENTER].push(
    button_current_pos
  );
  map.controls[google.maps.ControlPosition.TOP_CENTER].push(
    button_tracker_pos
  );
  map.controls[google.maps.ControlPosition.TOP_CENTER].push(
    button_itineraty
  );

  button_current_pos.addEventListener("click", () => {
    console.log("Click on current pos button");
    // Try HTML5 geolocation.
    if (navigator.geolocation) {
      navigator.geolocation.getCurrentPosition(
        (position) => {
          
          curr_pos = { lat: position.coords.latitude, lng: position.coords.longitude };

          getElevation(curr_pos, current_elevator);

          window_current_pos.setPosition(curr_pos);
          // window_current_pos.setContent("Current Location found.");
          geocodeLatLng(geocoder, map, window_current_pos, curr_pos, 0);

          window_current_pos.open(map);
          
          map.setCenter(curr_pos);
          map.setZoom(11);

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

    // remove all markers
    clearMarkers();
    markers = [];

    for (var i = 0; i < nb_position_display; i++) {

      // call fonction which GET datas.php
      let data_array;
      data_array = get_data_device(i);

      console.log("data_array[");
      console.log(i);
      console.log("] :\n");
      console.log(data_array);

      pos_marker.push({ lat: data_array[1], lng: data_array[2] });

      if (i != nb_position_display - 1){
        // add circle marker on each old tracker's position
        markers.push(new google.maps.Marker({
          position: pos_marker[i],
          icon: {
            path: google.maps.SymbolPath.CIRCLE,
            scale: 5,
          },
          map: map,
        }));
      }
      else{
        // add clasic marker on current tracker position
        markers.push(new google.maps.Marker({
          position: pos_marker[i],
          map: map,
        }));
      }
    }

    tracker_marker = markers[nb_position_display - 1];
    
    // Rely all old tracker's positions
    const flightPlanCoordinates = [
      pos_marker[0],
      pos_marker[1],
      pos_marker[2],
      pos_marker[3],
      pos_marker[4],
    ];
    const flightPath = new google.maps.Polyline({
      path: flightPlanCoordinates,
      geodesic: true,
      strokeColor: "#000000",
      strokeOpacity: 1.0,
      strokeWeight: 2,
    });
    flightPath.setMap(map);

    tracker_pos = pos_marker[nb_position_display - 1];

    window_tracker_pos.setPosition(pos_marker[nb_position_display - 1]);
    // window_tracker_pos.setContent("Tracker Location found.");
    geocodeLatLng(geocoder, map, window_tracker_pos, pos_marker[nb_position_display - 1], 1);

    // window_tracker_pos.open(map);
    tracker_marker.addListener("click", () => {
      window_tracker_pos.open(map, tracker_marker);
    });
    
    map.setCenter(pos_marker[nb_position_display - 1]);
    map.setZoom(11);

    handleLocationError(true, window_tracker_pos, map.getCenter());
  });

  button_itineraty.addEventListener("click", () => {
    console.log("Click on route button");
    // do some tests on position available !
    calculateAndDisplayRoute(directionsService, directionsRenderer);
  });
}

function clearMarkers() {
  for (let i = 0; i < markers.length; i++) {
    markers[i].setMap(null);
  }
}

function handleLocationError(browserHasGeolocation, window_info, pos) {
  window_info.setPosition(pos);
  
  if (!browserHasGeolocation){
    window_info.setContent("Error: The Geolocation service failed.");
  }
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

function geocodeLatLng(geocoder, map, infowindow, latlng, pos) {

  console.log("geocodeLatLng()");

  geocoder.geocode({ location: latlng }, (results, status) => {
    if (status === "OK") 
    {
      if (results[0]) 
      {
        // current pos
        if (pos == 0) 
        {
          infowindow.setContent("Current Location : \n" + results[0].formatted_address);
        }
        // tracker pos`
        else{
          infowindow.setContent("Tracker Location : \n" + results[0].formatted_address);
        }
        
      } 
      else {
        window.alert("No results found");
      }
    } 
    else {
      window.alert("Geocoder failed due to: " + status);
    }
  });
}

function calculateAndDisplayRoute(directionsService, directionsRenderer) {
  directionsService.route(
    {
      origin: curr_pos,
      destination: tracker_pos,
      travelMode: google.maps.TravelMode.DRIVING,
    },
    (response, status) => {
      if (status === "OK") {
        directionsRenderer.setDirections(response);
      } else {
        window.alert("Directions request failed due to " + status);
      }
    }
  );
}