#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 2



void setup() {
  //initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");
  pinMode(22, OUTPUT);
  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  while (!LoRa.begin(433E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  //LoRa.setSyncWord(0xF3);
  Serial.println("LoRa Initializing OK!");
}

void loop() {
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet '");

    // read packet
    while (LoRa.available()) {
      String LoRaData = LoRa.readString();
      //Serial.print(LoRaData); 
      //********Alert**********
  if(LoRaData == "30a")
  {
    Serial.print("BUZZER ON"); 
    digitalWrite(22, HIGH);//R1 on 
    
    
    }   
       if(LoRaData == "200b")
  {
    Serial.print("Rain Warning"); 
    digitalWrite(22, LOW);//R1 on 
    
    
    }   
      if(LoRaData == "100c")
  {
    Serial.print("N0 Warning"); 
    digitalWrite(22, LOW);//R1 on 
    
    
    }   
    
  delay (5000);
  
    }

  }
}
