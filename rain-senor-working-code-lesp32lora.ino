#include <SPI.h>
#include <LoRa.h>


// Potentiometer is connected to GPIO 34 (Analog ADC1_CH6) 

const int potPin = 34;
// variable for storing the potentiometer value

int potValue = 0;
//define the pins used by the transceiver module
#define ss 18
#define rst 14
#define dio0 26


void setup() {
  
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  SPI.begin(5, 19, 27, 18);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //433E6 for Asia
  //866E6 for Europe
  //915E6 for North America
  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  //LoRa.setSyncWord(0xF3);
  //Serial.println("LoRa Initializing OK!");
}

  


void loop() {
  Serial.print("Sending packet: ");
  // Reading potentiometer value
  potValue = analogRead(potPin);
  LoRa.beginPacket();
  Serial.println(potValue);
   //LoRa.print("potValue");
  
  if (potValue> 2600){
  Serial.println("Water is not Detected");
  LoRa.print("nod02#30\n");
  
  }
 else{
  Serial.println("Water is Detected");
   LoRa.print("nod02#10\n");
 }
 
 LoRa.endPacket();
  delay(500);
}
