#ifndef INDEX_PAGE_h
#define INDEX_PAGE_h

#include <Arduino.h>

const char indexPage[] PROGMEM = R"=====(<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <!-- Bootstrap CSS -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/css/bootstrap.min.css" rel="stylesheet" integrity="sha384-1BmE4kWBq78iYhFldvKuhfTAU6auU8tT94WrHftjDbrCEXSU1oBoqyl2QvZ6jIW3" crossorigin="anonymous">
    <link rel="icon" href="data:image/svg+xml,%3C%3Fxml version='1.0' encoding='UTF-8'%3F%3E%3C!DOCTYPE svg PUBLIC '-//W3C//DTD SVG 1.1//EN' 'http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd'%3E%3Csvg height='24' viewBox='0 0 24 24' width='24' xmlns='http://www.w3.org/2000/svg'%3E%3Cpath d='M3,9H7V5H3V9M3,14H7V10H3V14M8,14H12V10H8V14M13,14H17V10H13V14M8,9H12V5H8V9M13,5V9H17V5H13M18,14H22V10H18V14M3,19H7V15H3V19M8,19H12V15H8V19M13,19H17V15H13V19M18,19H22V15H18V19M18,5V9H22V5H18Z'/%3E%3C/svg%3E" type="image/svg+xml">
    <title>WledPixel</title>
  </head>
  <body>
      <header>
    <div class="px-3 py-2 bg-dark text-white">
      <div class="container">
        <div class="d-flex flex-wrap align-items-center justify-content-center justify-content-lg-start">
          <a href="https://github.com/widapro/wledPixel" class="d-flex align-items-center my-2 my-lg-0 me-lg-auto text-white text-decoration-none">
            <h1 class="mb-3 fw-bold font-monospace">wledPixel</h1>
          </a>

          <ul class="nav col-12 col-lg-auto my-2 justify-content-center my-md-0 text-small">
            <li>
                <span class="nav-link text-secondary">
                  Home
                </span>
              </li>
              <li>
                <a href="/settings" class="nav-link text-white">
                  Settings
                </a>
              </li>
              <li>
                <a href="/update" class="nav-link text-white">
                  Update firmware
                </a>
              </li>
          </ul>
        </div>
      </div>
    </div>
  </header>
  <div class="container">
    <main>
        <div class="py-5 text-center">
            <h2>wledPixel dot led Display</h2>
        </div>
        <div class="row g-5">
            <div class="col-md-5 col-lg-4 order-md-last">
              <h4 class="d-flex justify-content-between align-items-center mb-3">
                <span class="text-primary">Status</span>
              </h4>
              <ul class="list-group mb-3">
                <li class="list-group-item d-flex justify-content-between lh-sm">
                  <div>
                    <h6 class="my-0">wledPixel</h6>
                    <small class="text-muted">wledPixel dot led Display</small>
                  </div>
                  <span class="text-muted">%firmwareVer%</span>
                </li>
                <li class="list-group-item d-flex justify-content-between lh-sm">
                    <div>
                      <h6 class="my-0">Wifi SSID:</h6>
                    </div>
                    <span class="text-muted">%wifiSsid%</span>
                </li>
                <li class="list-group-item d-flex justify-content-between lh-sm">
                    <div>
                      <h6 class="my-0">Wifi IP:</h6>
                    </div>
                    <span class="text-muted">%wifiIp%</span>
                </li>
                <li class="list-group-item d-flex justify-content-between lh-sm">
                    <div>
                      <h6 class="my-0">Wifi Gateway:</h6>
                    </div>
                    <span class="text-muted">%wifiGateway%</span>
                </li>
              </ul>
              <ul class="list-group mb-3">
                <li class="list-group-item d-flex justify-content-between lh-sm">
                  <div>
                    <h7 class="my-0">Zone0</h7>
                    <small class="text-muted">Work mode</small>
                  </div>
                  <span class="text-muted">%workModeZone0%</span>
                </li>
                <li class="list-group-item d-flex justify-content-between lh-sm">
                    <div>
                      <h7 class="my-0">Zone1</h7>
                      <small class="text-muted">Work mode</small>
                    </div>
                    <span class="text-muted">%workModeZone1%</span>
                </li>
              </ul>
            </div>
            <div class="col-md-7 col-lg-8">
              <h4 class="mb-3">Manual text sender</h4>
              <span class="text-secondary">If work mode is configured to <mark>"Manual input"</mark> you can send a message here. If you select 
                <strong>"Scroll effect OUT"</strong> to <strong>"NO_EFFECT"</strong> the message will stay on display until a new message will be sent or the device will be rebooted.</span>

              <hr class="my-5">

              
                <div class="row g-3">
                  <div class="col-10">
                    <label for="messageZone0" class="form-label">Zone0 text</label>
                    <input id="messageZone0" class="form-control form-control-lg" type="text" placeholder="Zone0 message">
                  </div>
                  <div class="col-2 align-self-end">
                    <button id="postZone0Text" class="w-100 btn btn-primary btn-lg" onClick="preparePostRequest(event, this.id, null);">Send</button>
                  </div>
                  <div class="col-sm-12"></div>
                  <div class="col-10">
                    <label for="messageZone1" class="form-label">Zone1 text</label>
                    <input id="messageZone1" class="form-control form-control-lg" type="text" placeholder="Zone1 message">
                  </div>
                  <div class="col-2 align-self-end">
                    <button id="postZone1Text" class="w-100 btn btn-primary btn-lg" onClick="preparePostRequest(event, this.id, null);">Send</button>
                  </div>
                  <div class="col-sm-12"></div>
                  <div class="col-10">
                    <label for="messageZone2" class="form-label">Zone2 text</label>
                    <input id="messageZone2" class="form-control form-control-lg" type="text" placeholder="Zone2 message">
                  </div>
                  <div class="col-2 align-self-end">
                    <button id="postZone2Text" class="w-100 btn btn-primary btn-lg" onClick="preparePostRequest(event, this.id, null);">Send</button>
                  </div>
<!--                  <div class="col-10">
                    <label for="messageZone3" class="form-label">Zone3 text</label>
                    <input id="messageZone3" class="form-control form-control-lg" type="text" placeholder="Zone3 message">
                  </div>                  
                  <div class="col-2 align-self-end">
                    <button id="postZone3Text" class="w-100 btn btn-primary btn-lg" onClick="preparePostRequest(event, this.id, null);">Send</button>
                  </div>
-->                
                <div class="col-sm-12"></div>
            </div>
          </div>
    </main>
  </div>


    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.1.3/dist/js/bootstrap.bundle.min.js" integrity="sha384-ka7Sk0Gln4gmtz2MlQnikT1wXgYsOg+OMhuP+IlRH9sENBO0LRn5q+8nbTov4+1p" crossorigin="anonymous"></script>



    <div class="position-fixed top-0 end-0 p-3" style="z-index: 11">
    
        <div id="liveToastDanger" class="toast align-items-center text-white bg-danger border-0" role="alert" aria-live="assertive" aria-atomic="true" data-bs-autohide="true">
            <div class="d-flex">
                <div class="toast-body">
                Error!
                </div>
                <button type="button" class="btn-close btn-close-white me-2 m-auto" data-bs-dismiss="toast" aria-label="Close"></button>
            </div>
        </div>
        <div id="liveToastSuccess" class="toast align-items-center text-white bg-success border-0" role="alert" aria-live="assertive" aria-atomic="true">
            <div class="d-flex">
                <div class="toast-body">
                Success.
                </div>
                <button type="button" class="btn-close btn-close-white me-2 m-auto" data-bs-dismiss="toast" aria-label="Close"></button>
            </div>
        </div>
    </div>

<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.0/jquery.min.js"></script>
<script>
  function preparePostRequest(event, key, val) {
    event.preventDefault(); //This will prevent the default click action

    if (key == "postZone0Text") {
        data = {
            messageZone0: document.getElementById("messageZone0").value,
        }
        sendPost(data);
    };

    if (key == "postZone1Text") {
        data = {
            messageZone1: document.getElementById("messageZone1").value,
        }
        sendPost(data);
    };

    if (key == "postZone2Text") {
        data = {
            messageZone2: document.getElementById("messageZone2").value,
        }
        sendPost(data);
    };

    if (key == "postZone3Text") {
        data = {
            messageZone3: document.getElementById("messageZone3").value,
        }
        sendPost(data);
    };
  };

    function sendPost(dataPost) {
        var toastDanger = new bootstrap.Toast(document.getElementById('liveToastDanger'));
        var toastSuccess = new bootstrap.Toast(document.getElementById('liveToastSuccess'));

        var request = $.ajax({
            url: "/api/message",
            method: "POST",
            cache: false,
            data: dataPost,
            dataType: "json"
        });
        
        request.done(function( msg ) {
            toastSuccess.show();            
        });
            
        request.fail(function( jqXHR, textStatus, responseText ) {
            toastDanger.show();
        });
    }

    const zoneNumbers = %zoneNumbers%;
    const workModeZone0 = "%workModeZone0%"
    const workModeZone1 = "%workModeZone1%"
    const workModeZone2 = "%workModeZone2%"
    const workModeZone3 = "%workModeZone3%"
    if (workModeZone1 != "manualInput") {
        document.getElementById('messageZone1').disabled = true;
        document.getElementById('postZone1Text').disabled = true;
        document.getElementById('messageZone1').placeholder = "Zone1 is not in a Manual input work mode";
    }
    if (workModeZone0 != "manualInput") {
        document.getElementById('messageZone0').disabled = true;
        document.getElementById('postZone0Text').disabled = true;
        document.getElementById('messageZone0').placeholder = "Zone0 is not in a Manual input work mode";
    }
    if (workModeZone2 != "manualInput") {
        document.getElementById('messageZone2').disabled = true;
        document.getElementById('postZone2Text').disabled = true;
        document.getElementById('messageZone2').placeholder = "Zone2 is not in a Manual input work mode";
    }
    if (workModeZone3 != "manualInput") {
        document.getElementById('messageZone3').disabled = true;
        document.getElementById('postZone3Text').disabled = true;
        document.getElementById('messageZone3').placeholder = "Zone3 is not in a Manual input work mode";
    }
    if (zoneNumbers == 1) {
        document.getElementById('messageZone1').disabled = true;
        document.getElementById('postZone1Text').disabled = true;
        document.getElementById('messageZone1').placeholder = "Zone1 is not initialized";

        document.getElementById('messageZone2').disabled = true;
        document.getElementById('postZone2Text').disabled = true;
        document.getElementById('messageZone2').placeholder = "Zone2 is not initialized";
    }
   
</script>

</body>
</html>)=====";

#endif
