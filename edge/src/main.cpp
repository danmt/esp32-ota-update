#include <Arduino.h>
#include <HTTPClient.h>
#include <ArduinoJson.h>
#include <credentials.h>
#include <wifi.h>

//Your Domain name with URL path or IP address with path
String serverName = "http://192.168.1.64:3000/api/firmware";

int version = 0;

void getFirmware()
{
  HTTPClient http;

  // Your Domain name with URL path or IP address with path
  http.begin("http://192.168.1.64:3000/api/firmware");

  // Send HTTP GET request
  int httpResponseCode = http.GET();

  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);

    StaticJsonDocument<256> doc;
    deserializeJson(doc, payload);
    version = doc["version"];
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
}

void setup()
{
  Serial.begin(115200);
  connectWiFi(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("version ");
  Serial.println(version);

  getFirmware();
}

void loop()
{
}