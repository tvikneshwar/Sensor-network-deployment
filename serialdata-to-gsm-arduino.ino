
/* G.chellavel 09/10/2020 */

#include <SoftwareSerial.h>

SoftwareSerial mySerial(9, 10); /* 10(Tx)------gsm (Rx) , 9(Tx)--------gsm(Tx)  interface line for gsm module */
int sensorValue = 0;
String messagetext = "Sensor value: ";
String WindmillID = "mill-1 ";

void setup()
{
  mySerial.begin(9600);   // Setting the baud rate of GSM Module  
  Serial.begin(9600);    // Setting the baud rate of Serial Monitor (Arduino)
  delay(100);
}


void loop()
{
  if (Serial.available()>0)// if there is incoming serial data
  
   sensorValue = Serial.read(); // store serial data to variable
   SendMessage();               // call send message function  
   /* if (mySerial.available()>0)
   Serial.write(mySerial.read());
  */
   
}


 void SendMessage()
{
  mySerial.println("AT+CMGF=1");  //Sets the GSM Module in Text Mode
  delay(1000);              // Delay of 1000 milli seconds or 1 second
  
  mySerial.println("AT+CMGS=\"+6592424149\"\r");  // Replace with phone number. 
  
  String message= WindmillID + messagetext + sensorlValue;   // message and sensor value concardination.
  //mySerial.println("I am SMS from GSM Module");          // The SMS text you want to send
  mySerial.println(message);
  delay(100);
  
  mySerial.println((char)26);// ASCII code of CTRL+Z
  delay(1000);
  
}


 void RecieveMessage()
{
  mySerial.println("AT+CNMI=2,2,0,0,0"); // AT Command to receive a live SMS
  delay(1000);
 }
 
