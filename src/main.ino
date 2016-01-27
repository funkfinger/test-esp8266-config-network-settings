#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

MDNSResponder mdns;
WiFiServer server(80);

const char* ssid = "BUBBLES";
String st;

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect();
  // wifiManager.startConfigPortal("wifiManager");
  Serial.println("connected...yeey :)");
}



void loop() {
  // put your main code here, to run repeatedly:

}