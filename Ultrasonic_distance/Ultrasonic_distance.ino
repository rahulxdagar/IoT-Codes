#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define TRIGGERPIN D1
#define ECHOPIN    D2
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "XH8FggY90xQFzRQkYm005LW-tR_D-ggx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "PSCHAHAR";//your wifi name
char pass[] = "dkcpp9109n"; //your wifi password
int eggs=0;
WidgetLCD lcd(V1);

void setup()
{
  // Debug console
  Serial.begin(9600);
 pinMode(TRIGGERPIN, OUTPUT);
  pinMode(ECHOPIN, INPUT);
  Blynk.begin(auth, ssid, pass);
  // You can also specify server:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8442);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8442);
  
  lcd.clear(); //Use it to clear the LCD Widget
  lcd.print(0, 0, "No of Eggs:"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  // Please use timed events when LCD printintg in void loop to avoid sending too many commands
  // It will cause a FLOOD Error, and connection will be dropped
}

void loop()
{
  lcd.clear();
  lcd.print(2, 0, "Eggs in tray"); // use: (position X: 0-15, position Y: 0-1, "Message you want to print")
  long duration, distance;
  digitalWrite(TRIGGERPIN, LOW);  
  delayMicroseconds(3); 
  
  digitalWrite(TRIGGERPIN, HIGH);
  delayMicroseconds(12); 
  
  digitalWrite(TRIGGERPIN, LOW);
  duration = pulseIn(ECHOPIN, HIGH);
  distance = (duration/2) / 29.1;
  if (distance <= 5 && distance>=2) {
  eggs=3;
  Serial.println("No. of Eggs: 3");
   lcd.print(7, 1, eggs);
  }
  else if (distance >=7 && distance<=10) {
    eggs=2;
  Serial.println("No. of Eggs: 2");
  lcd.print(7, 1, eggs);
  }
  else {
    Serial.println("No. of Eggs: 1"); 
    eggs=1;
    lcd.print(7, 1, eggs);
  }
  
  
  Blynk.run();

  delay(200);

}
