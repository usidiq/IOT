/* Fill-in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL39VUvbJWo"
#define BLYNK_TEMPLATE_NAME "LED Brightness"
#define BLYNK_AUTH_TOKEN "yawqEKof-Z4bl-0znSrWxc1o-qCQ5toH"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "yawqEKof-Z4bl-0znSrWxc1o-qCQ5toH"; // Replace with your Blynk auth token
char ssid[] = "OnePlus 10 Pro 5G"; // Replace with your WiFi SSID
char pass[] = "1122334455"; // Replace with your WiFi password

#define LED_PIN 5 // Connect LED to pin D5 (or any PWM-capable pin)

BLYNK_WRITE(V0) { // Virtual pin V1 is linked to the Blynk slider
    int brightness = param.asInt(); // Get slider value (0-255)
    analogWrite(LED_PIN, brightness); // Adjust LED brightness
}

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass);
    pinMode(5, OUTPUT);
}

void loop() {
    Blynk.run();
}