#define tracaofrente 5
#define tracaotras 6
#define directD 11
#define directE 9

void setup() {
  pinMode(tracaofrente, OUTPUT);
  pinMode(tracaotras, OUTPUT);
  pinMode(directD, OUTPUT);
  pinMode(directE, OUTPUT);
}

void loop() {

  //bloco de codigo responsavel por realizar a trasferencia do da vaga esquerda para a vaga direita
  analogWrite(tracaofrente, 255);
  analogWrite(directD, 255);
  delay(1000);
  digitalWrite(directD, LOW);
  analogWrite(directE, 255);
  delay(500);
  digitalWrite(directE, LOW);
  digitalWrite(tracaofrente, LOW);
  delay(500);
  analogWrite(tracaotras, 255);
  delay(1000);
  digitalWrite(tracaotras, LOW);
  delay(10000);

  //bloco de codigo responsavel por ir da vaga a direita para a vaga a esquerda

  analogWrite(tracaofrente, 255);
  analogWrite(directE, 255);
  delay(1000);
  digitalWrite(directE, LOW);
  analogWrite(directD, 255);
  delay(500);
  digitalWrite(directD, LOW);
  digitalWrite(tracaofrente, LOW);
  delay(500);
  analogWrite(tracaotras, 255);
  delay(1000);
  digitalWrite(tracaotras, LOW);
  delay(10000);
}
