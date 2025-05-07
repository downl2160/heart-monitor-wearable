#define BLYNK_TEMPLATE_ID "TMPL_ID"
#define BLYNK_DEVICE_NAME "heart2"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"
#define BLYNK_PRINT Serial
#include <Blynk.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
  
#define REPORTING_PERIOD_MS 1000
#define LHB 30
#define HHB 110

char auth[] = BLYNK_AUTH_TOKEN;             // You should get Auth Token in the Blynk App.
char ssid[] = "WIFI_NAME";                                     // Your WiFi credentials.
char pass[] = "WIFI_PASSWORD";
 
// Connections : SCL PIN - D1 , SDA PIN - D2 , INT PIN - D0
PulseOximeter pox;
 
float BPM, SpO2;
uint32_t tsLastReport = 0;
 
void onBeatDetected()
{
    Serial.println("Beat Detected!");
}
 
void update()
{
  if (LHB<pox.getHeartRate() and pox.getHeartRate()<HHB)        // dangerous situation
    {
      Serial.println("dangerous situation.");
      Blynk.notify("dangerous situation!");                          // blynk Udate
    }
    
  else
    {
      Serial.println("OK");                         // 
    }
}

void setup()
{
    Serial.begin(115200);
    pinMode(16, OUTPUT);
    Blynk.begin(auth, ssid, pass);
 
    Serial.print("Initializing Pulse Oximeter..");
 
    if (!pox.begin())
    {
         Serial.println("FAILED");
         for(;;);
    }
    else
    {
         Serial.println("SUCCESS");
         pox.setOnBeatDetectedCallback(onBeatDetected);
    }
 
    // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
     pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
 
}
 
void loop()
{
    pox.update();
    Blynk.run();
 
    BPM = pox.getHeartRate();
    SpO2 = pox.getSpO2();
     if (millis() - tsLastReport > REPORTING_PERIOD_MS)
    {
        Serial.print("Heart rate:");
        Serial.print(BPM);
        Serial.print(" bpm / SpO2:");
        Serial.print(SpO2);
        Serial.println(" %");
        update();
 
        Blynk.virtualWrite(V7, BPM);
        Blynk.virtualWrite(V8, SpO2);
        
 
        tsLastReport = millis();
    }
}
