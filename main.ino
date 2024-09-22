const int ledPin = 13; 
const int botaoClaroPin = 7;
const int botaoEscuroPin = 8;

int estadoBotaoClaro = 0;
int estadoBotaoEscuro = 0;

bool ledLigado = true;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(botaoClaroPin, INPUT);
  pinMode(botaoEscuroPin, INPUT);
  
  digitalWrite(ledPin, HIGH);
}

void loop() {
  estadoBotaoClaro = digitalRead(botaoClaroPin);
  estadoBotaoEscuro = digitalRead(botaoEscuroPin);

  if (estadoBotaoClaro == HIGH) {
    ledLigado = false;
    digitalWrite(ledPin, LOW);
  }

  if (estadoBotaoEscuro == HIGH) {
    ledLigado = true;
    digitalWrite(ledPin, HIGH);
  }

  delay(50);
}
