// EmonLibrary examples openenergymonitor.org, Licence GNU GPL V3

#include "EmonLib.h"                   // Include Emon Library
EnergyMonitor emon1;                   // Create an instance
int in2 =2;
unsigned long previousMillis = 0;
const long interval = 5000;
int ledState = LOW;


void setup()
{  
  pinMode(in2,OUTPUT);
  digitalWrite(in2, LOW);
  Serial.begin(9600);
  
  emon1.current(1, 15);             // Current: input pin, calibration.
}

void loop()
{
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }

    digitalWrite(in2, ledState);
  }
  double Irms = emon1.calcIrms(1480);  // Calculate Irms only
  
  Serial.print(Irms*230.0);	       // Apparent power
  Serial.print(" ");
  Serial.println(Irms);		       // Irms
  Serial.println("\n");

  

  
  
}
