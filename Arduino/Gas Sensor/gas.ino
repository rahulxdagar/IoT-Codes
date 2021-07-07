/* Testing MQ-2 GAS sensor with serial monitor
   Suitable for detecting of LPG, i-butane, propane, methane ,alcohol, Hydrogen or smoke
   More info: http://www.ardumotive.com/how-to-use-mq2-gas-sensor-en.html
   Dev: Michalis Vasilakis // Date: 11/6/2015 // www.ardumotive.com                     */

const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin

float sensorValue;
void setup()
{
  Serial.begin(9600); //Initialize serial port - 9600 bps
  Serial.println("Gas Sensor is warming up!");
  delay(10000); // allow the sensor to heat up for 10 secs
}

void loop()
{ sensorValue = analogRead(gasPin);
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);
  if(sensorValue>220)
  {
    Serial.print(" - Smoke Detected! ");
  }
  Serial.println("");
  delay(2000); // Print value every 1 sec.
}
