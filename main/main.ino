int LEDs[] = {22, 23, 2, 4, 19, 18, 5};  // Pinos conectados ao display de 7 segmentos

// Array bidimensional contendo os estados dos segmentos para os números de 1 a 5
int numeros[5][7] = {
  {1, 0, 0, 1, 1, 1, 1},  // Número 1
  {0, 0, 1, 0, 0, 1, 0},  // Número 2
  {0, 0, 0, 0, 1, 1, 0},  // Número 3
  {1, 0, 0, 1, 1, 0, 0},  // Número 4
  {0, 1, 0, 0, 1, 0, 0}   // Número 5
};

void setup() {
  // Configura os pinos do display como saídas
  for (int i = 0; i < 7; i++) {
    pinMode(LEDs[i], OUTPUT);
  }
}

// Função para exibir um número no display de 7 segmentos
void mostrarNumero(int numero[]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(LEDs[i], numero[i]);
  }
}

void loop() {
  // Loop para exibir os números de 1 a 5 com atraso de 1 segundo
  for (int i = 0; i < 5; i++) {
    mostrarNumero(numeros[i]);
    delay(1000);  // Espera 1 segundo antes de mudar para o próximo número
  }
}