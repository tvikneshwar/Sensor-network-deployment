#include <SoftwareSerial.h>
 
SoftwareSerial gprsSerial(10,11);

// Constants definitions
const float pi = 3.14159265;  // pi number
int period = 10000;           // Measurement period (miliseconds)
int delaytime = 10000;        // Time between samples (miliseconds)
int radio = 225 ;             // Distance from center windmill to sensor (mm)
char* winds[] = {"Calm", "Light air", "Light breeze", "Gentle breeze", "Moderate breeze", "Fresh breeze", "Strong breeze", "Moderate gale", "Fresh gale", "Strong gale", "Storm", "Violent storm", "Hurricane"};

// Variable definitions
unsigned int Sample = 0;       // Sample number
unsigned int counter = 0;      // B/W counter for sensor 
unsigned int RPM = 0;          // Revolutions per minute
float speedwind = 0;           // Wind speed (m/s)
unsigned short windforce = 0;  // Beaufort Wind Force Scale




 
void setup()
{
  // Set the pins
  pinMode(2, INPUT);
  digitalWrite(2, HIGH);
  
  gprsSerial.begin(115200); // GPRS shield baud rate 
  Serial.begin(115200);   
  delay(500);
}

void loop()
{
Sample++;
  Serial.print(Sample);
  Serial.print(": Start measurement...");
  windvelocity();
  Serial.println("   finished.");
  Serial.print("Counter: ");
  Serial.print(counter);
  Serial.print(";  RPM: ");
  RPMcalc();
  Serial.print(RPM);
  Serial.print(";  Wind speed: ");
  WindSpeed();
  Serial.print(speedwind);
  Serial.print(" [m/s]  (+/- 0.07 m/s);  Wind force (Beaufort Scale): ");
  Serial.print(windforce);
  Serial.print(" - ");
  gprsSerial.print(winds[windforce]);
  Serial.println();
  delay(5000);
  speedwind = ((2 * pi * radio * RPM)/60) / 1000;
  
}

// Measure wind speed
void windvelocity(){
  speedwind = 0;
  counter = 0;  
  attachInterrupt(0, addcount, CHANGE);
  unsigned long millis();                     
  long startTime = millis();
  while(millis() < startTime + period) {
  }
  detachInterrupt(1);
}

void RPMcalc(){
  RPM=((counter/2)*60)/(period/1000);  // Calculate revolutions per minute (RPM)
}

//***************************************************************************
void WindSpeed(){
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  
  gprsSerial.print((char)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
  speedwind = ((2 * pi * radio * RPM)/60) / 1000;  // Calculate wind speed on m/s

if (speedwind <= 0.3)
{                           // Calculate Wind force depending of wind velocity
    Calm();
  delay(100);
  }
  
  else if (speedwind <= 1.5)
  {
   Light();
  delay(100);
  }

else if (speedwind <= 3.4)
{
   Lightbreeze();
  delay(100);
  }
  
  else if (speedwind <= 5.4)
  {
   Gentlebreeze();
  delay(100);
  }
  else if (speedwind <= 10.7)
  {
   Freshbreeze();
  delay(100);
  }
  else if (speedwind <= 13.8)
  {
   Strongbreeze();
  delay(100);
  }
  else if (speedwind <= 20.7)
  {
   Gale();
  delay(100);
  }
  else if (speedwind <= 28.4)
  {
   Storm();
  delay(100);
  }
  else if (speedwind <= 32.6)
  {
   Violentstorm();
  delay(100);
  }
  
//*********************************************************************************  
  
}

void Calm()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  int sensorValue = speedwind;
  String message = "calm" + sensorValue;
  
   gprsSerial.println(message);
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void Light()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
  //gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void Lightair()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void Lightbreeze()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void Gentlebreeze()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}



void Freshbreeze()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void Strongbreeze()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}


void Gale()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
  gprsSerial.println(speedwind); //the content of the message
  delay(100);
//  gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}



void Storm()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
 gprsSerial.println(speedwind); //the content of the message
  delay(100);
//  gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void Violentstorm()
{
  Serial.println("Sending Text...");
  gprsSerial.print("AT+CMGF=1\r"); // Set the shield to SMS mode
  delay(100);
  // send sms message, the phone number needs to include the country code e.g. if a U.S. phone number such as (540) 898-5543 then the string must be:
  // +15408985543
  gprsSerial.println("AT+CMGS = \"+6592424149\"");
  delay(100);
 // gprsSerial.println(speedwind +"violent storm"); //the content of the message
  delay(100);
 // gprsSerial.print((speedwind)26);//the ASCII code of the ctrl+z is 26 (required according to the datasheet)
  delay(100);
  gprsSerial.println();
  Serial.println("Text Sent.");
}

void addcount()
{
  counter++;
}
