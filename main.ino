void setup() { // coloque seu código setup aqui, para executar uma vez:
  Serial.begin(9600);
  Serial.println("oi");
}

void loop() { // coloque seu código main aqui, para executar repetidamente:
    delay(1000);
    Serial.println("tchau");
}
