const int gasPin = A0; //GAS sensor output pin to Arduino analog A0 pin
float sensorValue;

int LED = 13; // Use the onboard Uno LED
int obstaclePin = 7;  // This is our input pin
int hasObstacle = HIGH;  // HIGH MEANS NO OBSTACLE
void setup()
{
  Serial.begin(9600); //Initialize serial port - 9600 bps
  pinMode(LED, OUTPUT);
  pinMode(obstaclePin, INPUT);
  Serial.println("Gas Sensor is warming up!");
  delay(10000); // allow the sensor to heat up for 10 secs
}

void loop()
{ digitalWrite(LED, LOW);
  sensorValue = analogRead(gasPin);
  hasObstacle = digitalRead(obstaclePin); //Reads the output of the obstacle sensor from the 7th PIN of the Digital section of the arduino
  
  
  if(sensorValue>220)
  {
    Serial.println(" - Smoke Detected! ");
  }
  else{
  Serial.println("");
  }
  if (hasObstacle == LOW) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Obstacle Detected!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
  }
  else
  {
    Serial.print(" ");
  }
  //hasObstacle = digitalRead(obstaclePin);
  /*if (hasObstacle == HIGH) //LOW means something is ahead, so illuminates the 13th Port connected LED
  {
    Serial.println("Obstacle Detected!!");
    digitalWrite(LED, HIGH);//Illuminates the 13th Port LED
  }*/
  
}
