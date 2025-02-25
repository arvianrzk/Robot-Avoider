#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 10); // rx, tx

const int ENA = 5; // Left motor PWM speed control
const int IN1 = 9; 
const int IN2 = 8; 
const int IN3 = 7; 
const int IN4 = 4; 
const int ENB = 6; // Right motor PWM speed control

void maju() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);  // MOVE FRONT
  digitalWrite(IN2, HIGH); // MOVE FRONT
  digitalWrite(IN3, LOW);  // MOVE FRONT
  digitalWrite(IN4, HIGH); // MOVE FRONT
}
void mundur() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH); // MOVE BACK
  digitalWrite(IN2, LOW);  // MOVE BACK
  digitalWrite(IN3, HIGH); // MOVE BACK
  digitalWrite(IN4, LOW);  // MOVE BACK
}
void kanan() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, LOW);  // MOVE FRONT
  digitalWrite(IN2, HIGH); // MOVE FRONT
  digitalWrite(IN3, HIGH); // MOVE BACK
  digitalWrite(IN4, LOW);  // MOVE BACK
}
void kiri() {
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);
  digitalWrite(IN1, HIGH); // MOVE BACK
  digitalWrite(IN2, LOW);  // MOVE BACK
  digitalWrite(IN3, LOW);  // MOVE FRONT
  digitalWrite(IN4, HIGH); // MOVE FRONT
}
void stopped() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void setup() {
  mySerial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  stopped(); // Make sure the motors are stopped initially
}

void loop() {
  if (mySerial.available()) {
    delay(25);
    while (mySerial.available()) {
      char c = mySerial.read();
      switch (c) {
        case '1':
          maju();
          break;
        case '2':
          mundur();
          break;
        case '3':
          kiri();
          break;
        case '4':
          kanan();
          break;
        case '5':
          stopped();
          break;
      }
    }
  }
}
