/* WCL_GPS library by Arjun Saini */

#include "WCL_GPS.h"

GPS::GPS(){
    Serial1.begin(9600);
}

void GPS::readData(){
  for(int i = 0; i < Serial1.available(); i++){
    char value = Serial1.read();
    content.concat(value);
    if (value == '\n') {
      if(content.indexOf("GGA") > 0 && content.length() > 45){
        String latm = content.substring(17, 19);
        String lats = content.substring(19, 27);
        lat = (latm.toFloat() + lats.toFloat()/60);
        if(content.substring(28, 29) == "S"){
          lat = -lat;
        }
        String lonm = content.substring(30, 33);
        String lons = content.substring(33, 41);
        lon = (lonm.toFloat() + lons.toFloat()/60);
        if(content.substring(42, 43) == "W"){
          lon = -lon;
        }
        satelliteCount = content.substring(46, 48).toInt();
        //Serial.printlnf("Lat: %f, Lon: %f, Satellite Count: %d", lat, lon, satelliteCount);
      }
      content = "";
    }
  }
}