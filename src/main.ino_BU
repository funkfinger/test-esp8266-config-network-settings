#include <ArduinoOTA.h>
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <LiquidCrystal_I2C.h>
#include <ThingSpeak.h>
#include <WiFiUdp.h>
#include <WiFiClient.h>
#include <Wire.h> 

#include "settings.h"

const char* ssid = SETTINGS_SSID;
const char* password = SETTINGS_PASS;

WiFiClient client;
LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);  // YwRobot Arduino I2C LCD backpack - Set the LCD I2C address

void setup() {
  lcd.begin(16,2);               // initialize the lcd 
  lcd.backlight();  
  lcd.home ();                   // go home
  lcd.print("Booting...");
  
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    lcd.print("Connection Failed! Rebooting...");
    delay(5000);
    ESP.restart();
  }
  
  ArduinoOTA.onStart([]() {
    // lcd.print("Start");
  });
  ArduinoOTA.onEnd([]() {
    lcd.print("\nEnd");
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    lcd.clear(); 
    lcd.home();
    lcd.print("Progress:");
    lcd.print((progress / (total / 100)));
  });
  ArduinoOTA.onError([](ota_error_t error) {
    Serial.printf("Error[%u]: ", error);
    if (error == OTA_AUTH_ERROR) lcd.print("Auth Failed");
    else if (error == OTA_BEGIN_ERROR) lcd.print("Begin Failed");
    else if (error == OTA_CONNECT_ERROR) lcd.print("Connect Failed");
    else if (error == OTA_RECEIVE_ERROR) lcd.print("Receive Failed");
    else if (error == OTA_END_ERROR) lcd.print("End Failed");
  });
  ArduinoOTA.begin();
  lcd.home ();
  lcd.print("OTA READY");
  lcd.setCursor ( 0, 1 );
  lcd.print("IP:");
  lcd.print(WiFi.localIP());
  
  delay(2000);
  ThingSpeak.begin(client);
  delay(100);
  
  // lcd.setCursor ( 0, 1 );        // go to the next line
  // lcd.print ("in full effect");
}

void loop() {
  ArduinoOTA.handle();
  delay(100);
}