void setup() {
  Serial.begin(115200); // Inicializa a comunicação serial
  delay(1000); // Aguarda um pouco para a conexão ser estabelecida
  
  // A frequência do clock do Arduino Uno é 16 MHz
  Serial.print("Frequência da CPU: ");
  Serial.println(16); // Imprime a frequência em MHz
}

void loop() {
  // O loop pode ficar vazio se você não precisar de mais ações
}
