// Definições de pinos
const int ledPin = 13;    // Pino do LED
const int botaoClaroPin = 7;  // Pino do botão claro
const int botaoEscuroPin = 8; // Pino do botão escuro

// Variáveis para armazenar o estado dos botões
int estadoBotaoClaro = 0;
int estadoBotaoEscuro = 0;

// Variável para armazenar o estado atual do LED (inicia aceso)
bool ledLigado = true;

void setup() {
  // Configurar pinos como saída ou entrada
  pinMode(ledPin, OUTPUT);
  pinMode(botaoClaroPin, INPUT);
  pinMode(botaoEscuroPin, INPUT);
  
  // Começa com o LED aceso
  digitalWrite(ledPin, HIGH);
}

void loop() {
  // Ler o estado dos botões
  estadoBotaoClaro = digitalRead(botaoClaroPin);
  estadoBotaoEscuro = digitalRead(botaoEscuroPin);

  // Se o botão claro for pressionado, apagar o LED
  if (estadoBotaoClaro == HIGH) {
    ledLigado = false;
    digitalWrite(ledPin, LOW);
  }

  // Se o botão escuro for pressionado, acender o LED
  if (estadoBotaoEscuro == HIGH) {
    ledLigado = true;
    digitalWrite(ledPin, HIGH);
  }

  // Pequena pausa para evitar debounce (rebote)
  delay(50);
}
