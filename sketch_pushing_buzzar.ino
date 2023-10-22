#include <Wire.h>
int buzzerPin = 4;  // Buzzer pin
int greenPin = 10;  // Green LED pin
int redPin = 9;     // Red LED pin

void setup() {
  Serial.begin(115200);
  Wire.begin();
  pinMode(buzzerPin, OUTPUT);    // set buzzer pin as OUTPUT
  pinMode(greenPin, OUTPUT);     // set green LED pin as OUTPUT
  pinMode(redPin, OUTPUT);       // set red LED pin as OUTPUT
  digitalWrite(buzzerPin, LOW);  // turn off buzzer initially
  digitalWrite(greenPin, HIGH);   // turn off green LED initially
  digitalWrite(redPin, LOW);     // turn off red LED initially
}

void loop() {

  uint16_t data[2];
  char *ptr;

  ptr = (char *)data;

  Wire.requestFrom(2, 4);
  while (Wire.available() > 0) {
    *ptr = Wire.read();
    ptr++;
  }

  Serial.print(data[0]);
  Serial.print(",");
  Serial.println(data[1]);

  // Check if there's any incoming command from Python
  if (Serial.available()) {
    char command = Serial.read();
    switch (command) {
      case 'B':                         // Dead
        digitalWrite(buzzerPin, HIGH);  // turn on buzzer
        delay(2000);                    // keep it on for 2 seconds
        digitalWrite(buzzerPin, LOW);   // turn off buzzer
        digitalWrite(redPin, HIGH);     // turn on red LED
        digitalWrite(greenPin, LOW);    // ensure green LED is off
        break;
      case 'F':                               // Food
        // int snakeLength = Serial.parseInt();  // Read the integer value for snake length
        digitalWrite(buzzerPin, HIGH);        // short beep
        delay(200);
        digitalWrite(buzzerPin, LOW);
        // int intensity = map(snakeLength, 5, 20, 0, 255);  // Map snake length to intensity
        // analogWrite(greenPin, intensity);                 // Set intensity of green LED
        // digitalWrite(redPin, LOW);                        // Ensure red LED is off
        break;
        
    }
  }


delay(100);
}
