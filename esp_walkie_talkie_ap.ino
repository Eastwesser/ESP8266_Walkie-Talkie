#include <ESP8266WiFi.h>
#include <SoftwareSerial.h>
#include <DFPlayerMini_Fast.h>

SoftwareSerial mySerial(D5, D6); // RX (D5) подключаем к TX DFPlayer, TX (D6) к RX DFPlayer
DFPlayerMini_Fast myMP3;

WiFiServer server(80);

void setup() {
  Serial.begin(115200);
  
  // Настройка ESP8266 как точки доступа
  WiFi.softAP("ESP8266_AP", "password");
  Serial.println("Access Point Started");
  Serial.print("IP address: ");
  Serial.println(WiFi.softAPIP());
  
  server.begin();
  
  // Настройка MP3 плеера
  mySerial.begin(9600);
  myMP3.begin(mySerial);
  myMP3.volume(10); // Установить громкость 0-30
}

void loop() {
  WiFiClient client = server.available();
  
  if (client) {
    Serial.println("New Client Connected.");
    myMP3.play(1); // Воспроизвести сигнал при подключении клиента
    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c); // Можно использовать для обработки данных
        // Здесь можно добавить логику для воспроизведения аудиофайла или работы с данными
      }
    }
    
    client.stop();
    Serial.println("Client Disconnected.");
  }
}
