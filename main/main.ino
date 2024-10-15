#include "WiFi.h" // Biblioteca para conexão Wi-Fi
#include "SevSeg.h" // Biblioteca para controle do display de 7 segmentos

// Credenciais da rede Wi-Fi
const char* ssid = "NOME_DA_REDE";
const char* password = "SENHA_DA_REDE";

// Definição dos pinos dos botões e do LED
const int botao1 = 34;
const int botao2 = 35;
const int botao3 = 32;
const int botao4 = 33;
const int botao5 = 25;
const int ledPin = 2;

SevSeg sevseg; // Instância para o display de 7 segmentos

// Definição dos IPs das estações
const char* Estacao1 = "192.168.1.101";
const char* Estacao2 = "192.168.1.102";
const char* Estacao3 = "192.168.1.103";
const char* Estacao4 = "192.168.1.104";
const char* Estacao5 = "192.168.1.105";

unsigned long tempoPiscaLed = 0; // Variável para controlar o tempo de piscada do LED
bool ledLigado = false; // Flag para indicar se o LED está ligado
int contadorPisca = 0; // Contador para limitar o número de piscadas do LED

WiFiServer server(80); // Criação de um servidor HTTP na porta 80

void setup() {
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");
  Serial.println("Initializing WiFi...");
  WiFi.mode(WIFI_STA);
  Serial.println("Setup done!");
}

void loop() {
  switch() {
  case 34:
    Serial.println('1');
   break;
  
  case 35:
    Serial.println('2');
   break;
  
  case 32:
    Serial.println('3');
   break;
  
  case 33:
    Serial.println('4');
   break;

  case 25:
    Serial.println('5');
   break; 
  }
}
