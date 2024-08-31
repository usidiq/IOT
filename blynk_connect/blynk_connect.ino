#define BLYNK_TEMPLATE_ID "TMPL3_Xtd9RBv"
#define BLYNK_TEMPLATE_NAME "First demo"
#define BLYNK_AUTH_TOKEN "5qrB8jjoInPcW1johEsxtlR6Vw7JpRf2"


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <HTTPClient.h>

char auth[] = BLYNK_AUTH_TOKEN;


//#define DHT11_PIN 21


const char* ssid = "Ha1fd3vi1";

const char* password = "9677065892";







unsigned long lastTime = 0;

unsigned long timerDelay = 30000;



void setup() {

  //pinMode(34,INPUT);

  Serial.begin(9600); // Opens up the serial port with a baudrate of 9600 bits per second

  //WiFi.begin(ssid, password); // Attempt to connect to wifi with our password
  Blynk.begin(auth,ssid,password);
  Serial.println("Connecting"); // Print our status to the serial monitor

  // Wait for wifi to connect

  while(WiFi.status() != WL_CONNECTED) {

    delay(500);

    Serial.print(".");

  }

  Serial.println("");

  Serial.print("Connected to WiFi network with IP Address: ");

  Serial.println(WiFi.localIP());

}

void loop() {

  if ((millis() - lastTime) > timerDelay) { // Check if its been a minute

    if(WiFi.status()== WL_CONNECTED){ // Check to make sure wifi is still connected
      Blynk.run();
      
    }

    else {

      Serial.println("WiFi Disconnected");

    }

    lastTime = millis();
    delay(1000);
  }

}
/**
void sendData(int dta){

  HTTPClient http; // Initialize our HTTP client

Serial.println(dta);



 // String url = serverName + "&field1=" + dta; // Define our entire url

      

  http.begin(url.c_str()); // Initialize our HTTP request

      

  int httpResponseCode = http.GET(); // Send HTTP request

      

  if (httpResponseCode > 0){ // Check for good HTTP status code

    Serial.print("HTTP Response code: ");

    Serial.println(httpResponseCode);

  }else{

    Serial.print("Error code: ");

    Serial.println(httpResponseCode);

  }

  http.end();

}
**/