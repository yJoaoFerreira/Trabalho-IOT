void setup() { // coloque seu código setup aqui, para executar uma vez:
  Serial.begin(9600);
  Serial.println("oi");
}

void loop() { // coloque seu código main aqui, para executar repetidamente:
    delay(1000); // Espera 1000 MS (1 Segundo)
    Serial.println("tchau");
}
