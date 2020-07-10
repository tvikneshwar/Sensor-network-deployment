#include <SPI.h>
#include <LoRa.h>

String id;
void setup() {
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver-Sender");
  if (!LoRa.begin(915E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
}

void loop() {

   int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    //Serial.print("Received packet '");
    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      Serial.print(id +LoRaData); 
      if(LoRaData == "R#11")
  {
    //digitalWrite(R1,HIGH);
    Serial.print(LoRaData);
    LoRa.print("Active");
  
  } 
 }
 }
 }
