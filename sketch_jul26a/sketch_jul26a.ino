#include <WebServer.h>
#include <WiFi.h>

const char* ssid = "MagentaWLAN-RT6R";
const char* password = "stenistderking";

WebServer server(80);

void setup() {
  pinMode(32, INPUT);
  Serial.begin(9600);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.on("/", handle_root);
  server.begin();
}

void loop() {
  server.handleClient();
  
  Serial.print((4096.0-analogRead(32))/4096.0*100);
  Serial.println(" %");
  delay(500);

}

void handle_root() {
  String pre = "Eberhardt Jr.:<br>Bodenfeuchtigkeit: ";
  float moisture = (4096.0-analogRead(32))/4096.0*100;
  String rest = " %";
  String out = pre + moisture + rest;
  server.send(200, "text/html", out);
}
