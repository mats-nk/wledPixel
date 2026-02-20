#ifndef WLEDPIXEL_OWM_H
#define WLEDPIXEL_OWM_H

#include <Arduino.h>

void owmWeatherUpdate(String city, String unitsFormat, String token);
String openWetherMapGetWeather(String whatToDisplay, String unitsFormat);

#endif
