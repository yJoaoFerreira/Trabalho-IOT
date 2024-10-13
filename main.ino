#include "WiFi.h"

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  Serial.println("Initializing WiFi...");
  WiFi.mode(WIFI_STA);
  Serial.println("Setup done!");
  pinMode(34, INPUT);
  pinMode(35, INPUT);
  pinMode(32, INPUT);
  pinMode(33, INPUT);
  pinMode(25, INPUT);
}

void loop() {
  
  
  switch() {
  case 34:
    Serial.println('1');
   break;
  
  case 35:
    Serial.println('2');
   break;
  
  case 32:
    Serial.println('3');
   break;
  
  case 33:
    Serial.println('4');
   break;

  case 25:
    Serial.println('5');
   break; 
  }
}
