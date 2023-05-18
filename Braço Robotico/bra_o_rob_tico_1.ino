#include <Servo.h>

#define POSRESET 0
#define POS01 90
#define POS02 45
#define ABERTA 15 
#define SEGURA 30

#define pinSensor 8
#define pinServo01 9
#define pinServo02 10
#define pinServo03 6
#define pinServo04 5
#define pinServo05 3

Servo servo01;
Servo servo02;
Servo servo03;
Servo servo04;
Servo servo05;

void setup (){
  
  pinMode(pinSensor,INPUT);
  servo01.attach(9);
  servo02.attach(10);
  servo03.attach(6);
  servo04.attach(5);
  servo05.attach(3);
}

void loop (){
  
    servo02.write(POS01);
    servo03.write(POSRESET);
    servo04.write(POSRESET);
    servo05.write(ABERTA);
    servo01.write(POSRESET);
  
  if (digitalRead(8)==HIGH){
    delay (2000);
    servo02.write(POSRESET);
    delay (2000);
    servo03.write(POS02);
    delay (2000);
    servo04.write(POS02);
    delay (2000);
    servo05.write(SEGURA);
    delay (2000);
    servo03.write(POSRESET);
    delay (2000);
    servo02.write(POS01);
    delay (2000);
    servo03.write(POS02);
    delay (2000);
    servo05.write(ABERTA);
    delay (2000);
    servo04.write(POSRESET);
    delay (2000);
    servo05.write(SEGURA);
    delay (2000);
    servo04.write(POS02);
    delay (2000);
    servo02.write(POSRESET);
    delay (2000);
    servo05.write(ABERTA);
    delay (2000);
    servo04.write(POSRESET);
    delay (2000);
    servo02.write(POS01);
    delay (2000);
    servo04.write(POS02);
    delay (2000);
    servo05.write(SEGURA);
    delay (2000);
    servo04.write(POSRESET);
    delay (2000);
    servo05.write(ABERTA);
    delay (2000);
    servo01.write(POSRESET);
  }
  
  else{
    servo02.write(POS01);
    servo03.write(POSRESET);
    servo04.write(POSRESET);
    servo05.write(ABERTA);
    servo01.write(POSRESET);
  }
}
