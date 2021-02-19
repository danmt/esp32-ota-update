#include <Arduino.h>
#include <HTTPClient.h>
#include <Update.h>

void updateFromUrl(String url)
{
  HTTPClient http;

  // Your Domain name with URL path or IP address with path
  http.begin(url);

  // Send HTTP GET request
  int httpResponseCode = http.GET();

  // http.getSize
  if (httpResponseCode > 0)
  {
    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);

    if (Update.begin(http.getSize()))
    {
      size_t written = Update.writeStream(http.getStream());
      if (written == http.getSize())
      {
        Serial.println("Written : " + String(written) + " successfully");
      }
      else
      {
        Serial.println("Written only : " + String(written) + "/" + String(http.getSize()) + ". Retry?");
      }
      if (Update.end())
      {
        Serial.println("OTA done!");
        if (Update.isFinished())
        {
          Serial.println("Update successfully completed. Rebooting.");
          ESP.restart();
        }
        else
        {
          Serial.println("Update not finished? Something went wrong!");
        }
      }
      else
      {
        Serial.println("Error Occurred. Error #: " + String(Update.getError()));
      }
    }
  }
  else
  {
    Serial.print("Error code: ");
    Serial.println(httpResponseCode);
  }
  // Free resources
  http.end();
}