#include <Arduino.h>


#define BLINKPIN PB12
#define DCF77PIN PB3

int prevSensorValue=0;
  
void setup() {
  Serial.begin(9600);
  pinMode(DCF77PIN, INPUT);
  pinMode(13, OUTPUT);
  Serial.println("0ms       100ms     200ms     300ms     400ms     500ms     600ms     700ms     800ms     900ms     1000ms    1100ms    1200ms");
}

void loop() {
  int sensorValue = digitalRead(DCF77PIN);
  if (sensorValue==1 && prevSensorValue==0) { Serial.println("");   }
  digitalWrite(BLINKPIN, sensorValue);
  Serial.print(sensorValue);   
  prevSensorValue = sensorValue;
  delay(10);
}

