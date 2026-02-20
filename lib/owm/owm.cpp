include "owm.h"
#include <ArduinoJson.h>

static char     owmWeatherIcon[4] = "";
static uint8_t  owmHumidity       = 0;
static int16_t  owmPressure       = 0;
static int16_t  owmWindSpeed      = 0;
static int16_t  owmTemperature    = 0;
static bool     owmValid          = false;

// ETag cache
static char     owmETag[64] = "";


static bool parseWeather(Stream& stream)
{
  StaticJsonDocument<128> filter;
  filter["main"]["humidity"] = true;
  filter["main"]["pressure"] = true;
  filter["main"]["temp"]     = true;
  filter["wind"]["speed"]    = true;
  filter["weather"][0]["icon"] = true;

  DynamicJsonDocument doc(512);

  DeserializationError err =
      deserializeJson(doc, stream, DeserializationOption::Filter(filter));

  if (err)
    return false;

  owmHumidity    = doc["main"]["humidity"] | 0;
  owmPressure    = doc["main"]["pressure"] | 0;
  owmWindSpeed   = doc["wind"]["speed"] | 0;
  owmTemperature = doc["main"]["temp"] | 0;

  const char* icon = doc["weather"][0]["icon"] | "";
  strncpy(owmWeatherIcon, icon, sizeof(owmWeatherIcon) - 1);
  owmWeatherIcon[sizeof(owmWeatherIcon) - 1] = '\0';

  owmValid = true;
  return true;
}


void owmWeatherUpdate(String city, String unitsFormat, String token) {
  SecureClient client;
  client.setInsecure();  // or setCACert()

  if (!client.connect("api.openweathermap.org", 443)) {
    Serial.println(F("OWM connect failed"));
    return;
  }

  char url[192];
  snprintf(url, sizeof(url),
           "/data/2.5/weather?q=%s&units=%s&appid=%s",
           city.c_str(),
           unitsFormat.c_str(),
           token.c_str());

  // --- Send Request with ETag ---
  client.print(F("GET "));
  client.print(url);
  client.print(F(" HTTP/1.1\r\nHost: api.openweathermap.org\r\n"));

  if (owmETag[0] != '\0') {
    client.print(F("If-None-Match: "));
    client.print(owmETag);
    client.print(F("\r\n"));
  }

  client.print(F("Connection: close\r\n\r\n"));

  // --- Read Status Line ---
  char statusLine[64];
  if (!client.readBytesUntil('\n', statusLine, sizeof(statusLine))) {
    client.stop();
    return;
  }

  bool notModified = strstr(statusLine, "304") != nullptr;
  bool ok          = strstr(statusLine, "200") != nullptr;

  // --- Read Headers ---
  char headerLine[128];

  while (client.connected()) {
    size_t len = client.readBytesUntil('\n', headerLine, sizeof(headerLine));
    if (len <= 2) break; // end of headers

    if (strncmp(headerLine, "ETag:", 5) == 0) {
      char* tag = headerLine + 5;
      while (*tag == ' ') tag++;
      tag[strcspn(tag, "\r\n")] = '\0';

      strncpy(owmETag, tag, sizeof(owmETag) - 1);
      owmETag[sizeof(owmETag) - 1] = '\0';
    }
  }

  if (notModified) {
    Serial.println(F("OWM 304 Not Modified"));
    client.stop();
    return;
  }

  if (!ok) {
    Serial.println(F("OWM HTTP error"));
    client.stop();
    return;
  }

  if (parseWeather(client))
    Serial.println(F("OWM updated (200 OK)"));
  else
    Serial.println(F("OWM JSON error"));
  client.stop();
}


String openWetherMapGetWeather(String whatToDisplay, String unitsFormat) {
  if (!owmValid)
    return F("err");

  char buffer[16];

  if (whatToDisplay == F("owmHumidity")) {
    snprintf(buffer, sizeof(buffer), "%u%%", owmHumidity);
    return String(buffer);
  }

  if (whatToDisplay == F("owmPressure")) {
    snprintf(buffer, sizeof(buffer), "%d", owmPressure);
    return String(buffer);
  }

  if (whatToDisplay == F("owmWindSpeed")) {
    if (unitsFormat == F("imperial"))
      snprintf(buffer, sizeof(buffer), "%dmph", owmWindSpeed);
    else
      snprintf(buffer, sizeof(buffer), "%dm/s", owmWindSpeed);
    return String(buffer);
  }

  if (whatToDisplay == F("owmTemperature")) {
    if (unitsFormat == F("imperial"))
      snprintf(buffer, sizeof(buffer), "%d°F", owmTemperature);
    else
      snprintf(buffer, sizeof(buffer), "%d°C", owmTemperature);
    return String(buffer);
  }

  if (whatToDisplay == F("owmWeatherIcon")) {

    if (!strcmp(owmWeatherIcon, "01d")) return F("S");
    if (!strcmp(owmWeatherIcon, "01n")) return F("M");
    if (!strcmp(owmWeatherIcon, "02d")) return F("s");
    if (!strcmp(owmWeatherIcon, "02n")) return F("m");
    if (!strcmp(owmWeatherIcon, "03d") || !strcmp(owmWeatherIcon, "03n")) return F("c");
    if (!strcmp(owmWeatherIcon, "04d") || !strcmp(owmWeatherIcon, "04n")) return F("C");
    if (!strcmp(owmWeatherIcon, "09d") || !strcmp(owmWeatherIcon, "09n")) return F("R");
    if (!strcmp(owmWeatherIcon, "10d") || !strcmp(owmWeatherIcon, "10n")) return F("r");
    if (!strcmp(owmWeatherIcon, "11d") || !strcmp(owmWeatherIcon, "11n")) return F("T");
    if (!strcmp(owmWeatherIcon, "13d") || !strcmp(owmWeatherIcon, "13n")) return F("F");
    if (!strcmp(owmWeatherIcon, "50d") || !strcmp(owmWeatherIcon, "50n")) return F("f");
  }

  return F("err");
}
