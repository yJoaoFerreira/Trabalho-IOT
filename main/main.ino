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
  // Configura os pinos do display como saídas

  for (int i = 0; i < 7; i++) {
    pinMode(LEDs[i], OUTPUT);
    pinMode(34, INPUT); // Botão1
    pinMode(35, INPUT); // Botão2
    pinMode(32, INPUT); // Botão3
    pinMode(33, INPUT); // Botão4
    pinMode(25, INPUT); // Botão5

    digitalWrite(LEDs[i], HIGH);
  }

}




void loop() {
  // Verifica se há dados disponíveis na entrada serial
    int guardabotao1 = digitalRead(34);
    int guardabotao2 = digitalRead(35);
    int guardabotao3 = digitalRead(32);
    int guardabotao4 = digitalRead(33);
    int guardabotao5 = digitalRead(25);
    
    if (guardabotao1 > 0){
      num = 1;
      displayNumber(num);
    }

    if (guardabotao2 > 0){
      num = 2;
      displayNumber(num);
    }

    if (guardabotao3 > 0){
      num = 3;
      displayNumber(num);
    }

    if (guardabotao4 > 0){
      num = 4;
      displayNumber(num);
    }

    if (guardabotao5 > 0){
      num = 5;
      displayNumber(num);
    }

    guardabotao1 = 0;
    guardabotao2 = 0;
    guardabotao3 = 0;
    guardabotao4 = 0;
    guardabotao5 = 0;
}


void displayNumber(int num) {
  if (num > 5) return;

  int segments = segmentMap[num];

  for (int i = 0; i < 7; i++){
    digitalWrite(LEDs[i], (segments >> i) & 0x01);
  }
}
