#include <Arduino.h>
#include <credentials.h>
#include <wifi.h>
#include <ota.h>

String FIRMWARE_UPDATE_URL = "http://192.168.1.64:3000/api/firmware";

void setup()
{
  Serial.begin(115200);
  connectWiFi(WIFI_SSID, WIFI_PASSWORD);
  updateFromUrl(FIRMWARE_UPDATE_URL);
}

void loop()
{
}