//*****************************************************

esp32 Single board Lora recever 





//******************************************************

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define SS 18
#define RST 14
#define DI0 26



void setup() {
  SPI.begin(5, 19, 27, 18);
  LoRa.setPins(SS, RST, DI0);
  

  
  //initialize Serial Monitor
  Serial.begin(9600);
  while (!Serial);
  Serial.println("LoRa Receiver");
  pinMode(25, OUTPUT);
  //setup LoRa transceiver module
  LoRa.setPins(SS, RST, DI0);
  
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
      Serial.print(LoRaData); 
//###################################################      
      //***Alert***
  if(LoRaData == "nod01#30")
  {
    Serial.print("Node1 Leakage detected"); 
    digitalWrite(34, HIGH);//Buzzer on GPIO34 
    
    }   
    if(LoRaData == "nod01#20")
  {
    Serial.print("Node1 Leakage detected"); 
    digitalWrite(34, HIGH);//Buzzer on GPIO34 
    
    } 
    if(LoRaData == "nod01#10")
  {
    Serial.print("Node1 No Leakage detected"); 
    digitalWrite(34, LOW);//Buzzer on GPIO34 
    
    } 


//##################################################


    
  delay (5000);
 //******
 
    }

    // print RSSI of packet
   // Serial.print("' with RSSI ");
   // Serial.println(LoRa.packetRssi());
  }
}
