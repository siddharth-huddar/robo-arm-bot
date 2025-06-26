#include <SoftwareSerial.h>
#include <Servo.h>

// Servo declarations
Servo servo01, servo02, servo03, servo04, servo05, servo06;

SoftwareSerial Bluetooth(3, 4); // Arduino(RX, TX) - HC-05 Bluetooth (TX, RX)

// Current and previous positions
int servo01Pos, servo02Pos, servo03Pos, servo04Pos, servo05Pos, servo06Pos;
int servo01PPos, servo02PPos, servo03PPos, servo04PPos, servo05PPos, servo06PPos;

// Step arrays for each servo
int servo01SP[50], servo02SP[50], servo03SP[50], servo04SP[50], servo05SP[50], servo06SP[50];
int speedDelay = 20;
int index = 0;
String dataIn = "";

void setup() {
  servo01.attach(5);
  servo02.attach(6);
  servo03.attach(7);
  servo04.attach(8);
  servo05.attach(9);
  servo06.attach(10);
  
  Bluetooth.begin(38400); // Default baud rate of HC-05
  Bluetooth.setTimeout(1);
  delay(20);
}

void loop() {
  // Check for incoming data
  if (Bluetooth.available() > 0) {
    dataIn = Bluetooth.readString();

    // Move Servo 1
    if (dataIn.startsWith("s1")) {
      String dataIns = dataIn.substring(2);
      servo01Pos = dataIns.toInt();

      if (servo01PPos > servo01Pos) {
        for (int j = servo01PPos; j >= servo01Pos; j--) {
          servo01.write(j);
          delay(20);
        }
      } else if (servo01PPos < servo01Pos) {
        for (int j = servo01PPos; j <= servo01Pos; j++) {
          servo01.write(j);
          delay(20);
        }
      }
      servo01PPos = servo01Pos;
    }

    // Save position
    if (dataIn.startsWith("SAVE")) {
      servo01SP[index] = servo01PPos;
      servo02SP[index] = servo02PPos;
      servo03SP[index] = servo03PPos;
      servo04SP[index] = servo04PPos;
      servo05SP[index] = servo05PPos;
      servo06SP[index] = servo06PPos;
      index++;
    }

    // Run saved steps
    if (dataIn.startsWith("RUN")) {
      runservo();
    }

    // Reset memory
    if (dataIn == "RESET") {
      memset(servo01SP, 0, sizeof(servo01SP));
      memset(servo02SP, 0, sizeof(servo02SP));
      memset(servo03SP, 0, sizeof(servo03SP));
      memset(servo04SP, 0, sizeof(servo04SP));
      memset(servo05SP, 0, sizeof(servo05SP));
      memset(servo06SP, 0, sizeof(servo06SP));
      index = 0;
    }
  }
}

// Function to run all saved servo steps
void runservo() {
  for (int i = 0; i < index - 1; i++) {
    // Servo 1 Movement
    if (servo01SP[i] > servo01SP[i + 1]) {
      for (int j = servo01SP[i]; j >= servo01SP[i + 1]; j--) {
        servo01.write(j);
        delay(speedDelay);
      }
    } else if (servo01SP[i] < servo01SP[i + 1]) {
      for (int j = servo01SP[i]; j <= servo01SP[i + 1]; j++) {
        servo01.write(j);
        delay(speedDelay);
      }
    }

    // Repeat similar logic for servo02, servo03... as needed
  }
}
