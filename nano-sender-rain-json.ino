/*
https://techtutorialsx.com/2017/04/29/esp32-sending-json-messages-over-mqtt/


*/

#include <ArduinoJson.h>
#include <SPI.h>
#include <LoRa.h>


const int sensorMin = 0;     // sensor minimum
const int sensorMax = 1024;  // sensor maximum


void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

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
    sensorReading += '\n';
  LoRa.beginPacket();
  LoRa.print(sensorReading);
  StaticJsonBuffer<300> JSONbuffer;
  JsonObject& JSONencoder = JSONbuffer.createObject();

  JSONencoder["device"] = "E01";
  JSONencoder["sensorType"] = "LKE";
  JsonArray& VAL = JSONencoder.createNestedArray("VAL");
 
  VAL.add(sensorReading);

  char JSONmessageBuffer[100];
  JSONencoder.printTo(JSONmessageBuffer, sizeof(JSONmessageBuffer));
  
  
  LoRa.print(JSONmessageBuffer);
 // Serial.println("Sending message to MQTT topic..");
  Serial.println(JSONmessageBuffer);
  
  
  /*
  // range value:
  switch (range) {
 case 0:    // Sensor getting wet
    //Serial.println("Flood");
    LoRa.print("30\n");
    break;
 case 1:    // Sensor getting wet
    //Serial.println("Rain Warning");
    LoRa.print("200\n");
    break;
 case 2:    // Sensor dry - To shut this up delete the " Serial.println("Not Raining"); " below.
    //Serial.println("Not Raining");
    LoRa.print("100\n");
    break;
  }
  */
  LoRa.endPacket();
  delay(9000);
  
}
