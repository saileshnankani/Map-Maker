// this sketch will allow you to bypass the Atmega chip
// and connect the GPS sensor directly to the USB/Serial
// chip converter.

// Connect VIN to +5V
// Connect GND to Ground
// Connect GPS RX (data into GPS) to Digital 0
// Connect GPS TX (data out from GPS) to Digital 1
// mcwhorpj. “LESSON 22: Build an Arduino GPS Tracker.” YouTube, YouTube, 30 July 2014, www.youtube.com/watch?v=OsMoowoB2Rg.

#include <Adafruit_GPS.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(3,2);
Adafruit_GPS GPS(&mySerial);

String NMEA1;
String NMEA2;
char c;


void setup() {
  Serial.begin(115200);
  GPS.begin(9600);
  GPS.sendCommand("$PGCMD,33,0*6PD");
  GPS.sendCommand("PMTK_SET_NEMA_UPDATE_1HZ");
  GPS.sendCommand("PMTK_SET_NEMA_OUTPUT_RMCGGA");
  delay(1000);
  
  }

  
void loop() {
  readGPS();

  
  }

void readGPS(){
  while(!GPS.newNMEAreceived()){
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
  NMEA1 = GPS.lastNMEA();

  while(!GPS.newNMEAreceived()){
    c=GPS.read();
  }
  GPS.parse(GPS.lastNMEA());
  NMEA2 = GPS.lastNMEA();

  Serial.println(NMEA1);
  Serial.println("");
  Serial.println(NMEA2);
  
  
} 




