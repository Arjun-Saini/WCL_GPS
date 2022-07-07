#pragma once

/* WCL_GPS library by Arjun Saini */

#include "Particle.h"

class GPS
{
public:
  GPS();
  void readData();

  float lat, lon;
  int satelliteCount;

private:
  String content = "";
};
