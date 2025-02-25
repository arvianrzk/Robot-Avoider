#include <Servo.h> 
Servo Myservo;
#define trigPin A3           // Trig Pin Of HC-SR04
#define echoPin 2        // Echo Pin Of HC-SR04
const int ENA = 5; // Left motor PWM speed control
const int IN1 = 9; // Left motor Direction 1
const int IN2 = 8; // Left motor Direction 2
const int IN3 = 7; // Right motor Direction 1
const int IN4 = 4; // Right motor Direction 2
const int ENB = 6; // Right motor PWM speed control
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(trigPin, OUTPUT);       // Set Trig Pin As O/P To Transmit Waves
  pinMode(echoPin, INPUT);        //Set Echo Pin As I/P To Receive Reflected Waves
  Myservo.attach(12);
}
void loop() 
{
  Serial.begin(9600);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);   
  digitalWrite(trigPin, HIGH);       
  delayMicroseconds(10);
  duration = pulseIn(echoPin, HIGH);        
  distance = duration / 58.2;                      
  Serial.println(distance);
  delay(10);
  if (distance > 17)               // Condition For Absence Of Obstacle            
  {
    
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH); 
  }
  else if (distance < 16)            // Condition For Presence Of Obstacle
  {

    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(500);

    Myservo.write(52);
    delay(500);
    Myservo.write(100);
    delay(500);
    Myservo.write(0);
    delay(500);
    Myservo.write(52);
    delay(500);

    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500);
    
    digitalWrite(IN1, LOW); //Stop
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
    delay(100);
 
    analogWrite(ENA, 255);
    analogWrite(ENB, 255);
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    delay(500); 
  }

}