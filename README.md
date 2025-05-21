# Sprint_1_IOT

## 🏗️ Estrutura do projeto
### 🧰 Componentes necessários:
- 1x ESP32-CAM

- 1x Módulo FTDI (para programar o ESP32-CAM via USB)

- Broker MQTT

- Node-RED instalado no seu PC ou Raspberry Pi

![Capture](https://github.com/user-attachments/assets/a6810f0b-65e5-4ef5-8adc-980c0f274bcb)

![image](https://github.com/user-attachments/assets/eab7924d-49c6-4589-9236-2ca9680b602a)

### 🔁 Fluxo resumido do projeto:
ESP32-CAM capta imagem de uma área -->
 Ele identifica QR Codes com uma biblioteca -->
  Envia os dados dos QR Codes via MQTT -->
   Node-RED escuta esse tópico MQTT e processa os dados.

Objetivo do fluxo:
Receber os dados publicados pelo ESP32 no tópico leitura/qr via MQTT, exibir no debug e em um dashboard.

- Conecta ao Wi-Fi (FIAP-IOT)

- Se conecta ao broker MQTT público (broker.hivemq.com)

- Usa a biblioteca ESP32QRCodeReader para detectar QR Codes

- Publica os dados dos QR Codes no tópico MQTT leitura/qr

- Se inscreve no tópico SPRINT1DDJ/OUT e imprime no serial caso receba mensagens (via callback())

### 📚 Bibliotecas
- ESP32QRCodeReader: para detectar QR Codes

- PubSubClient: para MQTT

- WiFi.h: para Wi-Fi

### 🟥 NODE-RED
#### 🧰 Pré-requisitos
- Node-RED instalado e em execução (http://localhost:1880)

- Um broker MQTT acessível (broker.hivemq.com)

- Dashboard instalado via Manage Palette (node-red-dashboard)

![image](https://github.com/user-attachments/assets/1dd89315-5209-4fdd-9029-db99136875fc)

#### 🚧 Modelo Node-red
[mqtt in] ---> [debug]
           \
            \
             ---> [ui_text (dashboard)]

![image](https://github.com/user-attachments/assets/be2e9ca4-231e-4c51-9833-122d941e87db)

MQTT In: Conecta ao broker MQTT e escuta o tópico leitura/qr.

Debug: Mostra os QR Codes recebidos no painel de debug.

UI Text: Exibe os QR Codes recebidos em um painel web (Node-RED Dashboard).
