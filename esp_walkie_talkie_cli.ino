#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

SoftwareSerial mySerial(D5, D6); // RX (D5) подключаем к TX DFPlayer, TX (D6) к RX DFPlayer
DFPlayerMini_Fast myMP3;

const char* ssid = "ESP8266_AP";
const char* password = "password";

void setup() {
  Serial.begin(115200);
  
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to Access Point...");
  }
  
  Serial.println("Connected to Access Point");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  
  // Настройка MP3 плеера
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.volume(10); // Установить громкость 0-30
}

void loop() {
  WiFiClient client;
  
  if (client.connect(WiFi.gatewayIP(), 80)) {
    Serial.println("Connected to Server.");
    myMP3.play(2); // Воспроизвести сигнал при подключении к серверу
    
    // Здесь можно добавить логику для отправки данных на сервер или получения данных
    client.print("Hello Server!");
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        // Можно обрабатывать данные от сервера и воспроизводить аудио
      }
    }
    
    client.stop();
    Serial.println("Disconnected from Server.");
  }
}
