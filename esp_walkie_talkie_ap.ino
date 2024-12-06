#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

WiFiUDP udp;
const int port = 12345;  // UDP port for communication

const int micPin = D1;       // Microphone pin
const int buttonPin = D6;    // Button pin
const int speakerPin = D5;   // Speaker pin
const int ledPin = D7;       // LED pin for indication

const char* ssid = "WalkieTalkieAP";       // Network SSID
const char* password = "password123";     // Network password

IPAddress clientIP; // To store the connected client's IP address

void setup() {
  Serial.begin(115200);

  // Start Access Point mode
  WiFi.softAP(ssid, password);
  Serial.println("Access Point Started");

  // Start UDP
  udp.begin(port);

  // GPIO setup
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(speakerPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  Serial.println("Ready to transmit/receive audio.");
}

void loop() {
  if (digitalRead(buttonPin) == LOW) {
    // Transmitting mode
    digitalWrite(ledPin, HIGH);

    // Read microphone value
    int micValue = analogRead(micPin);
    char buffer[10];
    sprintf(buffer, "%d", micValue);

    // Broadcast audio data
    if (clientIP) {  // Ensure the client IP is known
      udp.beginPacket(clientIP, port);
      udp.write(buffer);
      if (!udp.endPacket()) {
        Serial.println("Error sending packet to client");
      }
    }
    delay(10);
  } else {
    // Receiving mode
    digitalWrite(ledPin, LOW);

    int packetSize = udp.parsePacket();
    if (packetSize) {
      char packet[255];
      int len = udp.read(packet, sizeof(packet) - 1);
      if (len > 0) {
        packet[len] = '\0';
        int soundValue = atoi(packet);

        // Play sound on speaker
        analogWrite(speakerPin, soundValue);

        // Capture the sender's IP dynamically
        clientIP = udp.remoteIP();
        Serial.printf("Received audio from %s\n", clientIP.toString().c_str());
      }
    }
  }
}
