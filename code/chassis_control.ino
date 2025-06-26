#include <Servo.h>

Servo myservo1;
Servo myservo2;

int pos = 0;

char t;
int leftMotorForwardPin = 13;  // Left motor forward
int leftMotorReversePin = 12;  // Left motor reverse
int rightMotorForwardPin = 11; // Right motor forward
int rightMotorReversePin = 10; // Right motor reverse

void setup() {
  pinMode(leftMotorForwardPin, OUTPUT);
  pinMode(leftMotorReversePin, OUTPUT);
  pinMode(rightMotorForwardPin, OUTPUT);
  pinMode(rightMotorReversePin, OUTPUT);

  pinMode(9,  OUTPUT); 
  pinMode(8, OUTPUT);

  myservo1.attach(6);
  myservo2.attach(5);

  Serial.begin(9600);
}

void moveForward() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorReversePin, LOW);
}

void moveBackward() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, HIGH);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorReversePin, HIGH);
}

void turnLeft() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, HIGH);
  digitalWrite(rightMotorForwardPin, HIGH);
  digitalWrite(rightMotorReversePin, LOW);
}

void turnRight() {
  digitalWrite(leftMotorForwardPin, HIGH);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorReversePin, HIGH);
}

void stopMotors() {
  digitalWrite(leftMotorForwardPin, LOW);
  digitalWrite(leftMotorReversePin, LOW);
  digitalWrite(rightMotorForwardPin, LOW);
  digitalWrite(rightMotorReversePin, LOW);
}

void baseopen(){
  for (pos = 90; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }

}

void baseclose(){
  for (pos = 180; pos >= 90; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}

void end(){
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo2.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15 ms for the servo to reach the position
  }
}
void loop() {

  analogWrite(9, 255); //ENA  pin
  analogWrite(8 , 255); //ENB pin

  if (Serial.available()) {
    t = Serial.read();
    Serial.println(t);

    if (t == '1') {
      moveForward();
      delay(500);
      stopMotors();
    } else if (t == '2') {
      moveBackward();
      delay(500);
      stopMotors();
    } else if (t == '3') {
      turnLeft();
      delay(500);
      stopMotors();
    } else if (t == '4') {
      turnRight();
      delay(500);
      stopMotors();
    } else if (t =='5') {
      // Default action or error handling
      stopMotors();
    } else if (t == '6'){
      baseopen();

    } else if (t == '7'){
      baseclose();

    } else if (t == '8'){
      end();

    }
  }
}

