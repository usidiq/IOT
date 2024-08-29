const int PIR_SENSOR_OUTPUT_PIN = 27;  /* PIR sensor O/P pin */
int warm_up;
#define led 14

void setup() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  pinMode(led, OUTPUT);
  Serial.begin(115200); /* Define baud rate for serial communication */
  Serial.println("Waiting For Power On Warm Up");
  delay(5000); /* Power On Warm Up Delay */
  Serial.println("Ready!");
}

void loop() {
  pinMode(PIR_SENSOR_OUTPUT_PIN, INPUT);
  int sensor_output;
  sensor_output = digitalRead(PIR_SENSOR_OUTPUT_PIN);
  if( sensor_output == LOW )
  {
    if( warm_up == 1 )
     {
      Serial.print("Warming Up\n\n");
      warm_up = 0;
      delay(2000);
    }
    Serial.print("No object in sight\n\n");
    delay(1000);
    digitalWrite(led, LOW);  // turn the LED on (HIGH is the voltage level)
    delay(1000); 
  }
  else
  {
    Serial.print("Object detected\n\n");   
    warm_up = 1;
    delay(1000);
    digitalWrite(led, HIGH);  // turn the LED on (HIGH is the voltage level)
    delay(1000); 
  } 
}
