# Sprint_1_IOT
Sprint 1 de IOT dos alunos Daniel Akiyama, Danilo Correa e João Pedro R

![image](https://github.com/user-attachments/assets/1dd89315-5209-4fdd-9029-db99136875fc)

![image](https://github.com/user-attachments/assets/be2e9ca4-231e-4c51-9833-122d941e87db)

![image](https://github.com/user-attachments/assets/eab7924d-49c6-4589-9236-2ca9680b602a)

![Capture](https://github.com/user-attachments/assets/a6810f0b-65e5-4ef5-8adc-980c0f274bcb)

Texto para utilizar no roteiro e para mostrar aqui no read.me:
🔁 Fluxo resumido do projeto:
📷 ESP32-CAM capta imagem de uma área

🔍 Ele identifica QR Codes com uma biblioteca

📡 Envia os dados dos QR Codes via MQTT

💻 Node-RED escuta esse tópico MQTT e processa os dados

--
✅ Captura imagens com a câmera integrada
✅ Suporta processamento de QR Codes com bibliotecas como ESP32QRCodeReader
✅ Tem Wi-Fi embutido para enviar dados via MQTT diretamente para o Node-RED
--
🧰 Componentes necessários:
1x ESP32-CAM

1x Módulo FTDI (para programar o ESP32-CAM via USB)

Fonte 5V (ou o próprio FTDI para alimentação)

Broker MQTT (ex: Mosquitto, pode rodar no mesmo PC do Node-RED)

Node-RED instalado no seu PC ou Raspberry Pi

--
💻 Código básico para ESP32-CAM com detecção de QR Code e envio via MQTT:
Você pode usar bibliotecas como:

ESP32QRCodeReader → para detectar QR Codes

PubSubClient → para MQTT

WiFi.h → para Wi-Fi
--
✅ O que esse código faz corretamente:
Conecta ao Wi-Fi (FIAP-IOT)

Se conecta ao broker MQTT público (broker.hivemq.com)

Usa a biblioteca ESP32QRCodeReader para detectar QR Codes

Publica os dados dos QR Codes no tópico MQTT leitura/qr

Se inscreve no tópico SPRINT1DDJ/OUT e imprime no serial caso receba mensagens (via callback())
--
Você está com um código totalmente funcional para um projeto com ESP32-CAM, leitura de QR Code e envio via MQTT para o Node-RED.
--
✅ Objetivo do fluxo:
Receber os dados publicados pelo ESP32 no tópico leitura/qr via MQTT, exibir no debug e (opcionalmente) em um dashboard.

🧰 Pré-requisitos:
Node-RED instalado e em execução (geralmente em http://localhost:1880)

Um broker MQTT acessível (você está usando broker.hivemq.com)

(Opcional) Dashboard instalado via Manage Palette (node-red-dashboard)
--
[mqtt in] ---> [debug]
           \
            \
             ---> [ui_text (dashboard)]

--
Colocar QR code no pátio, tirar quando sair
