#include <WiFi.h>
#include <PubSubClient.h>
#include <SdsDustSensor.h> // Biblioteca para o SDS011
#include <Adafruit_BME680.h> // Biblioteca para o BME680

// Configurações Wi-Fi e MQTT
const char* ssid = "TEU_WIFI";
const char* password = "TUA_PASSWORD";
const char* mqtt_server = "IP_DO_TEU_BROKER";

WiFiClient espClient;
PubSubClient client(espClient);

// Definição dos sensores
SdsDustSensor sds(Serial2, 16, 17); // RX=16, TX=17
Adafruit_BME680 bme; 

void setup() {
  Serial.begin(115200);
  sds.begin();
  if (!bme.begin()) {
    Serial.println("Erro a iniciar BME680!");
  }
  
  WiFi.begin(ssid, password);
  client.setServer(mqtt_server, 1883);
}

void loop() {
  if (!client.connected()) {
    // Tenta reconectar ao broker MQTT se cair
    if (WiFi.status() == WL_CONNECTED) client.connect("EstacaoAmora");
  }
  client.loop();

  // Leitura do SDS011
  PmResult pm = sds.read();
  
  // Leitura do BME680
  bme.performReading();

  // Publicação via MQTT (Exemplo para um tópico)
  char payload[50];
  sprintf(payload, "{\"pm25\": %.2f, \"temp\": %.2f}", pm.pm25, bme.temperature);
  client.publish("amora/setubal/dados", payload);

  delay(60000); // Aguarda 60 segundos
}