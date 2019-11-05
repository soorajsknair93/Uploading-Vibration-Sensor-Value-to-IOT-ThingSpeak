#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;

const char* ssid = "ABCDEF"; //Your Network SSID

const char* password = "**********"; //Your Network Password

//int val;

int VIBRATION_SENSOR = 5;
int led_RED = 4;
int led_GREEN = 16;
int val; 


WiFiClient client;

unsigned long myChannelNumber = ******; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "****************"; //Your Write API Key

void setup()

{

Serial.begin(9600);
pinMode(VIBRATION_SENSOR, INPUT);
pinMode(led_RED, OUTPUT);
pinMode(led_GREEN, OUTPUT);

digitalWrite(led_RED,LOW);
digitalWrite(led_GREEN,LOW);


delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}
long TP_init()
  {
  delay(10);
  long measurement=pulseIn (VIBRATION_SENSOR, HIGH);  //wait for the pin to get HIGH and returns measurement
  return measurement;
  }


void loop()

{
long measurement =TP_init();
  delay(10);
  
  if(measurement >= 1000)
  {
    digitalWrite(led_RED,HIGH);
    digitalWrite(led_GREEN,LOW);
    delay(100);
    Serial.print("measurment = ");
    Serial.println(measurement);
    ThingSpeak.writeField(myChannelNumber, 1,measurement, myWriteAPIKey);
    delay(10);
    
  }
  else
  digitalWrite(led_GREEN,HIGH);
  digitalWrite(led_RED,LOW);
  delay(100);
  Serial.print("measurment = ");
  Serial.println(measurement);
  ThingSpeak.writeField(myChannelNumber, 1,measurement, myWriteAPIKey);
  delay(10);

}
