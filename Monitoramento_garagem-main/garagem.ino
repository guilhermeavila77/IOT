#include <Ultrasonic.h>

Ultrasonic ultrasonic1(30, 31);
Ultrasonic ultrasonic2(32,33);
Ultrasonic ultrasonic3(34,35);
Ultrasonic ultrasonic4(36, 37);
Ultrasonic ultrasonic5(38,39);
Ultrasonic ultrasonic6(40,41);


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(ultrasonic1.read());
  Serial.print(",");
  Serial.print(ultrasonic2.read());
  Serial.print(",");
  Serial.print(ultrasonic3.read());
  Serial.print(",");
  Serial.print(ultrasonic4.read());
  Serial.print(",");
  Serial.print(ultrasonic5.read());
  Serial.print(",");
  Serial.println(ultrasonic6.read());
  delay(100);
}
