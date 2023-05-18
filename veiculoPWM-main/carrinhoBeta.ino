/*
 * A variavel i será armazenada em "uint8_t" para vizando melhor
 * processamento de memoria
 * 
 * Essa variavel será responsavel pelo incremento/decremento 
 * de velocidade
 */


/*******************************************************************
 * Bloco de codigo destinado ao "Set" de informações
 */
#include <AFMotor.h> // Biblioteca de controle do motor pela "Shild" 

AF_DCMotor motorLft(2); // Motores da esquerda serão no pino 2 da placa
AF_DCMotor mototRgt(4); // Motores da direita serão no pino 4 da placa

//Pinos usados pelo sensor ultrasonico
const int trigPin = 30;
const int echoPin = 31;

void setup() 
{
  //Seta a velocidade inicial do motor
  motorLft.setSpeed(200);
  motorLft.run(RELEASE);
  mototRgt.setSpeed(200);
  mototRgt.run(RELEASE);

  //Set de informações dos pinos utilizados pelo ultrasonico
  //O triger envia informação 
  //Enquanto o Echo recebe essa inmformação
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Inicia o monitor serial para controle da distancia
  Serial.begin(9600);
}

/*
 * *****************************************************************
 */

 /*******************************************************************
 * Bloco de codigo destinado a declaração de funções
 */
// Função para ligar os motores para frente
void ligaFrente(){
  motorLft.run(FORWARD);
  mototRgt.run(FORWARD);
}

 // Função para ligar os motores para tras
void ligaTras(){
  motorLft.run(BACKWARD);
  mototRgt.run(BACKWARD);
}

//Função que desliga motor
void deslig(){
  motorLft.run(RELEASE);
  mototRgt.run(RELEASE);
}

//Função para acelerar o carrinho até a velocidadade determinada
void aceleraAte(int velAtual, int velMax){
  uint8_t i;
  for (i=velAtual; i<velMax; i++) {
    motorLft.setSpeed(i); 
    mototRgt.setSpeed(i);  
    delay(10);
  }
}

/*
 * Função para desacelerar o carrinho da velocidade atual
 * até a velocidadade determinada
 */
 
void desaceleraAte(int velAtual, int velMin){
  uint8_t i;
  for (i=velAtual; i!=velMin; i--) {
    motorLft.setSpeed(i); 
    mototRgt.setSpeed(i); 
    delay(10);
  }
}


//Função de leitura do sensor ultrasonico
int lerDistancia(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int distancia = pulseIn(echoPin, HIGH) / 58; // divide por 58 para converter a duração do pulso em centímetros
  return distancia;

  // Maneira de resgatar a informação no void Loop
  //int distancia = lerDistancia();
  //Serial.println(distance);
}

/*
 * *****************************************************************
 */

void loop(){

  /*  
   *Primeira etapa é o veiculo se mover para frente assim que iniciado   
   *Deve ser feita uma leitura constante de distancia
   *De acordo com essa distancia o veiculo deve se manter em uma distancia permanete de 10CM
   */
   
  ligaFrente();
  aceleraAte(255,255);
  int distancia = lerDistancia();
  Serial.println(distancia);
  
  /*
   * ou seja
   * caso a distancia seja maior que 10, o veiculo deve ir para frente
   */

   while(distancia > 30){
    ligaFrente();
    aceleraAte(255,255);
    int distancia = lerDistancia();
    Serial.println(distancia);
   }
  
   /*
    * Caso a distancia seja menor que 10, ele deve ir para tras
    */

   while(distancia < 20){
    ligaTras();
    aceleraAte(255,255);
    int distancia = lerDistancia();
    Serial.println(distancia);
   }
  
   /*
    * caso a distancia seja 10 ele deve ficar parado
    */
  while (distancia < 30 and distancia > 20){
    deslig();
    int distancia = lerDistancia();
    Serial.println(distancia);
  }
}
