// Pinos conectados aos segmentos do display de 7 segmentos
int LEDs[] = {15, 4, 16, 17, 5, 18, 19};

// Mapeamento de cada número para os segmentos correspondentes (anodo comum)
// Cada bit representa um segmento do display, onde 0 significa ligado e 1 significa desligado
const uint segmentMap[6] = {
  0b11000000, // Número 0
  0b11111001, // Número 1
  0b10100100, // Número 2
  0b10110000, // Número 3
  0b10011001, // Número 4
  0b10010010  // Número 5
};

// Variável para armazenar o número a ser exibido
int num = 0;

// Declaração da função que exibe um número no display
void displayNumber(int num);

void setup() {
  // Configura os pinos do display como saídas e os botões como entradas
  for (int i = 0; i < 7; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
  
  // Configuração dos pinos dos botões
  pinMode(34, INPUT); // Botão para o número 1
  pinMode(35, INPUT); // Botão para o número 2
  pinMode(32, INPUT); // Botão para o número 3
  pinMode(33, INPUT); // Botão para o número 4
  pinMode(25, INPUT); // Botão para o número 5
}

void loop() {
  // Verifica o estado de cada botão e atribui o número correspondente
  if (digitalRead(34) == HIGH) {
    num = 1;
    displayNumber(num);
  } else if (digitalRead(35) == HIGH) {
    num = 2;
    displayNumber(num);
  } else if (digitalRead(32) == HIGH) {
    num = 3;
    displayNumber(num);
  } else if (digitalRead(33) == HIGH) {
    num = 4;
    displayNumber(num);
  } else if (digitalRead(25) == HIGH) {
    num = 5;
    displayNumber(num);
  }
}

// Função para exibir o número selecionado no display de 7 segmentos
void displayNumber(int num) {
  // Certifica-se de que o número está dentro do intervalo (0-5)
  if (num < 0 || num > 5) return;

  // Pega o mapeamento de segmentos para o número fornecido
  int segments = segmentMap[num];

  // Atualiza cada segmento de acordo com o mapeamento
  for (int i = 0; i < 7; i++) {
    // Liga ou desliga cada segmento conforme o valor do bit correspondente
    digitalWrite(LEDs[i], (segments >> i) & 0x01);
  }
}