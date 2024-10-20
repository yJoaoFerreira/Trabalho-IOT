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
  
  // Inicializa a comunicação serial
  Serial.begin(115200);
  Serial.println("Digite um número de 1 a 5:");
}

void mostrarNumero(int numero[]) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(LEDs[i], numero[i]);
  }
}

void loop() {
  // Verifica se há dados disponíveis na entrada serial
  if (Serial.available() > 0) {
    int numeroDigitado = Serial.parseInt();  // Lê o número digitado

    // Verifica se o número está dentro do intervalo permitido (1 a 5)
    if (numeroDigitado >= 1 && numeroDigitado <= 5) {
      mostrarNumero(numeros[numeroDigitado - 1]);  // Exibe o número correspondente
    } else {
      Serial.println("Por favor, digite um número válido de 1 a 5.");
    }
    
    // Aguarda um tempo para evitar múltiplas leituras do mesmo número
    delay(1000);  // Atraso para não sobrecarregar a leitura
  }
}