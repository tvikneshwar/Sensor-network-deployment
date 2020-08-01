
//Vikneshwar Thandeswaran
/*
        Interface/Wiring

Rain Sensor ................. Arduino
VCC............................... 5v
GND.............................. GND
A0.................................. Analog in 0


*/

#include <SPI.h>
#include <LoRa.h>

const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum
int led = 3;                 // Digital pin D3

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");
  pinMode(led, OUTPUT);

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {
  Serial.print("Sending packet: ");
  //Serial.println(counter);
  // read the sensor on analog A0:
  int sensorReading = analogRead(A0);
  // map the sensor range (four options):
  // ex: 'long int map(long int, long int, long int, long int, long int)'
  int range = map(sensorReading, sensorMin, sensorMax, 0, 3);
    // send packet
  LoRa.beginPacket();
  //LoRa.print(sensorReading);
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    Serial.println("Flood30");
    LoRa.print("nod02#30\n");
    digitalWrite(led, LOW);      //Turn on Buzzer       gpio logic is ulta
    break;
 case 1:    // Sensor getting wet
    Serial.println("Rain Warning20");
    LoRa.print("nod02#20\n");
    digitalWrite(led, LOW);      //Turn on Buzzer       gpio logic is ulta
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    Serial.println("Not Raining10");
    LoRa.print("nod02#10\n");
    digitalWrite(led, HIGH);  //Turn off Buzzer
    break;
  }
  
  LoRa.endPacket();
  delay(9000);
  
}
