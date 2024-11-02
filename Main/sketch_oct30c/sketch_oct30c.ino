#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "Com5est_AP"; // Rede
const char* password = "mmr1234567"; // Senha

int endereco = 0;
boolean piscaled;
String pacotes = "";
IPAddress local_ip(192, 168, 3, 2); // IP do server AP (access point)
IPAddress gateway(192, 168, 3, 1); // Gateway
IPAddress subnet(255, 255, 255, 0); // Máscara de sub-rede

uint tempo = 0;
uint mudanca = 0;
int8_t num = 0;

// Pinos para os segmentos do display
const int segmentPins[7] = {15, 4, 16, 17, 5, 18, 19};
// Mapeamento dos segmentos para os números de 0 a 9
const uint8_t segmentMap[10] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000  // 9
};

WiFiUDP udp;
const int udpPort = 12345;

void displayNumber(uint8_t num);
void piscar_led();
void apagarDisplay();

void setup() {
  Serial.begin(9600);

  // Configuração dos botões
  
  pinMode(2, OUTPUT);
  pinMode(12, INPUT);  // Botão Stop
  pinMode(13, INPUT);  // Botão Cancel
  pinMode(34, INPUT);
  pinMode(35, INPUT);  

 WiFi.config(local_ip, gateway, subnet);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando ao AP...");
  }

  Serial.println("Conectado ao AP!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  udp.begin(udpPort);

  // Configura os pinos do display como saída
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
    
    
  }
   digitalWrite(15, LOW);
   digitalWrite(4, LOW);
   digitalWrite(16, HIGH);
   digitalWrite(17, LOW);
   digitalWrite(5, LOW);
   digitalWrite(18, HIGH);
   digitalWrite(19, LOW);
}

void loop() {
  int8_t guardabotao1 = digitalRead(34);
  int8_t guardabotao2 = digitalRead(35);
  int stopButton = digitalRead(12);
  int guardacancel = digitalRead(13);
  char incomingPacket[200];
  int packetSize = udp.parsePacket();

 if (packetSize) {
        int len = udp.read(incomingPacket, 200);
        if (len > 0) {
            incomingPacket[len] = 0;
            Serial.printf("Pacote recebido: %s\n", incomingPacket);
        }
        pacotes = incomingPacket;
    }

    if (pacotes == "Estacao01") {
        num = 1;
        piscaled = true;
        tempo = 30000;
        displayNumber(num);
    }
    if (pacotes == "Estacao02") {
        num = 2;
        piscaled = true;
        tempo = 30000;
        displayNumber(num);
    }
    if (pacotes == "Cancela") {
       digitalWrite(15, LOW);
       digitalWrite(4, LOW);
       digitalWrite(16, HIGH);
       digitalWrite(17, LOW);
       digitalWrite(5, LOW);
       digitalWrite(18, HIGH);
       digitalWrite(19, LOW);
       piscaled = false;
       tempo = 0;
    }

 
    // Se o botão stop for pressionado, apaga o display
    if (stopButton == HIGH) {
        apagarDisplay();
    }

    

 if (tempo > 0) {
        piscar_led();
    } else {
        
        digitalWrite(2, LOW); // apagar led
    }
 

  if (guardabotao1 > 0) { 
    udp.beginPacket("192.168.3.1", udpPort); // IP do ESP32 AP
    udp.print("Estacao02");
    udp.endPacket();

  
  }
 
  if (guardabotao2 > 0) {
    
  }

  if (guardacancel > 0){
    udp.beginPacket("192.168.3.1", udpPort); // IP do ESP32 AP
    udp.print("Cancela");
    udp.endPacket();

  }
  guardabotao1 = 0;
  guardabotao2 = 0;
  guardacancel = 0;
}

void displayNumber(uint8_t num) {
  if (num > 9) return;  // Número fora do intervalo

  uint8_t segments = segmentMap[num];
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], (segments >> i) & 0x01);
  }
}



void piscar_led() {
  mudanca = mudanca + 1;
 

  if (mudanca < 20) {
    digitalWrite(2, LOW);  // LED apagado
  } else {
    digitalWrite(2, HIGH);  // LED aceso
  }

  if (mudanca > 40) {
    mudanca = 0;
  }

  tempo = tempo - 1;
  delay(2);
}

void apagarDisplay() {
  digitalWrite(15, LOW);
  digitalWrite(4, LOW);
  digitalWrite(16, HIGH);
  digitalWrite(17, LOW);
  digitalWrite(5, LOW);
  digitalWrite(18, HIGH);
  digitalWrite(19, LOW);
    tempo = 0;
    piscaled = false;
    num = 0;
    pacotes = "";
}