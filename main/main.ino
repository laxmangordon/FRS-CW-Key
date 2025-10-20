#include "main.h"

/* H-bridge setup
signal ---- 1k v            signal ---- 1k v
        GND < T3 ----                ---- T4 > GND
                    |                | 
                    |---MIC OUTPUT---|
                    |                |
        VCC > T1 ----                ---- T2 < VCC
signal ---- 1k ^            signal ---- 1k ^
*/

void setup(){
  Serial.begin(9600);

  Serial.print("\nProgram created by Harley Smith 2025\n");
  Serial.print("Last Update: N/A\n\n");

  Serial.print("The h-bridge setup looks like this...\n");
  Serial.print("signal ---- 1k v            signal ---- 1k v\n");
  Serial.print("        GND < T3 ----                ---- T4 > GND\n");
  Serial.print("                    |                |\n");
  Serial.print("                    |---MIC OUTPUT---|\n");
  Serial.print("                    |                |\n");
  Serial.print("        VCC > T1 ----                ---- T2 < VCC\n");
  Serial.print("signal ---- 1k ^            signal ---- 1k ^\n\n");

  Serial.print("Starting up...\n");

  t1Pin = 5;
  t2Pin = 6;
  t3Pin = 7;
  t4Pin = 8;
  keyPin = 9;

  pinMode(t1Pin, OUTPUT);
  pinMode(t2Pin, OUTPUT);
  pinMode(t3Pin, OUTPUT);
  pinMode(t4Pin, OUTPUT);
  pinMode(keyPin, INPUT);

  digitalWrite(t1Pin, LOW);
  digitalWrite(t2Pin, LOW);
  digitalWrite(t3Pin, LOW);
  digitalWrite(t4Pin, LOW);

  Serial.print("Starting Program");

  delay(10);

  timer, lastTime = millis();
}

void loop(){
  timer = millis();
  switch (digitalRead(keyPin)){
    case 1:
      sendTone(t1Pin, t2Pin, t3Pin, t4Pin);
      lastTime = timer;
      break;
    case 0:
      if ((timer - lastTime) > 2000){
        endTone(t1Pin, t2Pin, t3Pin, t4Pin);
        break;
      }
      sendSubTone(t1Pin, t2Pin, t3Pin, t4Pin);
      break;
    }
}