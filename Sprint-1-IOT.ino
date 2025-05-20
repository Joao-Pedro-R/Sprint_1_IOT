#include <WiFi.h>
#include <PubSubClient.h>
#include <ESP32QRCodeReader.h>

const char* ssid = "FIAP-IOT"; //Utilizar o wifi da sua área
const char* password = "****"; 
const char* mqtt_server = "broker.hivemq.com";  // ex: 192.168.0.100

WiFiClient espClient;
PubSubClient client(espClient);
ESP32QRCodeReader qrCodeReader;

void setup_wifi() {
  delay(10);

  Serial.println();
  Serial.print("Conectando ao ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao Wi-Fi...");
  }

  
  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Tentando conexão MQTT...");
    String clientId = "ESP32Client-";
    // Create a random client ID
    clientId += String(random(0xffff), HEX);
    // Attempt to connect
    if (client.connect(clientId.c_str())) {
      Serial.println("conectado");
      // Once connected, publish an announcement...
      client.publish("SPRINT1DDJ/IN", "Iniciando transferencias...");
      // ... and resubscribe
      client.subscribe("SPRINT1DDJ/OUT");
    } else {
      Serial.print("falhou, rc=");
      Serial.print(client.state());
      Serial.println(" tente novamente em 5 segundos");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensagem recebida [");
  Serial.print(topic);
  Serial.print("]: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup() {
  Serial.begin(115200);
  setup_wifi();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  qrCodeReader.setup();
  qrCodeReader.begin();
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }

  client.loop();

  if (qrCodeReader.detected()) {
    String qrData = qrCodeReader.payload();
    Serial.println("QR Code Detectado: " + qrData);
    client.publish("leitura/qr", qrData.c_str());
  }
}
