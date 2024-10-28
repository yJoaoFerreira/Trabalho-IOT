int LEDs[] = {15, 4, 16, 17, 5, 18, 19};  // Pinos conectados ao display de 7 segmentos

const uint segmentMap[6] = {
  // Anodo comum
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
};

int num = 0;

void displayNumber(int num);

void setup() {
  // Inicializa a comunicação serial para envio de logs
  Serial.begin(115200);

  // Configura os pinos do display como saídas
  for (int i = 0; i < 7; i++) {
    pinMode(LEDs[i], OUTPUT);
    digitalWrite(LEDs[i], HIGH);
  }
  
  // Configura os pinos dos botões como entradas
  pinMode(34, INPUT); // Botão1
  pinMode(35, INPUT); // Botão2
  pinMode(32, INPUT); // Botão3
  pinMode(33, INPUT); // Botão4
  pinMode(25, INPUT); // Botão5
}

void loop() {
  // Verifica o estado dos botões
  int guardabotao1 = digitalRead(34);
  int guardabotao2 = digitalRead(35);
  int guardabotao3 = digitalRead(32);
  int guardabotao4 = digitalRead(33);
  int guardabotao5 = digitalRead(25);
  
  // Verifica qual botão foi pressionado e exibe o número correspondente
  if (guardabotao1 > 0) {
    num = 1;
    displayNumber(num);
    Serial.println("Botão 1 pressionado, número exibido: 1");
  }

  if (guardabotao2 > 0) {
    num = 2;
    displayNumber(num);
    Serial.println("Botão 2 pressionado, número exibido: 2");
  }

  if (guardabotao3 > 0) {
    num = 3;
    displayNumber(num);
    Serial.println("Botão 3 pressionado, número exibido: 3");
  }

  if (guardabotao4 > 0) {
    num = 4;
    displayNumber(num);
    Serial.println("Botão 4 pressionado, número exibido: 4");
  }

  if (guardabotao5 > 0) {
    num = 5;
    displayNumber(num);
    Serial.println("Botão 5 pressionado, número exibido: 5");
  }

  // Limpa o estado dos botões para evitar múltiplas detecções
  guardabotao1 = 0;
  guardabotao2 = 0;
  guardabotao3 = 0;
  guardabotao4 = 0;
  guardabotao5 = 0;

  delay(100); // Pequeno atraso para evitar ruído de leitura
}

void displayNumber(int num) {
  if (num > 5) return;

  int segments = segmentMap[num];

  for (int i = 0; i < 7; i++) {
    digitalWrite(LEDs[i], (segments >> i) & 0x01);
  }
}