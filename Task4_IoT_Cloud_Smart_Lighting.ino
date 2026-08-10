#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

String apiKey = "SEIOS25MUJBYFG78";

const int ldrPin = 34;
const int ledPin = 13;

int ldrValue;
int threshold = 500;

void setup() {
  Serial.begin(115200);

  pinMode(ledPin, OUTPUT);

  Serial.println("Connecting to WiFi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.println("WiFi Connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {

  ldrValue = analogRead(ldrPin);

  // Automatic lighting control
  if (ldrValue < threshold) {
    digitalWrite(ledPin, HIGH);
    Serial.println("DARK - LED ON");
  } 
  else {
    digitalWrite(ledPin, LOW);
    Serial.println("BRIGHT - LED OFF");
  }

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  // Send data to ThingSpeak
  if (WiFi.status() == WL_CONNECTED) {

    HTTPClient http;

    String url = "http://api.thingspeak.com/update?api_key=" 
                 + apiKey + "&field1=" + String(ldrValue);

    http.begin(url);

    int httpResponseCode = http.GET();

    Serial.print("ThingSpeak Response: ");
    Serial.println(httpResponseCode);

    http.end();
  }

  Serial.println("-------------------------");

  delay(15000);
}
