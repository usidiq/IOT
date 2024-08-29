#include "BluetoothSerial.h"

BluetoothSerial SerialBT;

const int ledPin = 2;

void setup(){
  SerialBT.begin("ESP32-Bluetooth");
  pinMode(ledPin, OUTPUT);

}

void loop(){
  if(SerialBT.available()){
    char signal = SerialBT.read();
    if(signal=='1'){
      digitalWrite(ledPin, HIGH);
    }else if(signal=='0'){
      digitalWrite(ledPin, LOW);
    }
  }
}