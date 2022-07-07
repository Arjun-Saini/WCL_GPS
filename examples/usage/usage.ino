#include "WCL_GPS.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

GPS gps;

void setup(){
  Serial.begin(9600);
}

void loop(){
  gps.readData();
  Serial.printlnf("%f, %f, %i", gps.lat, gps.lon, gps.satelliteCount);
}