#include <Wire.h>
int newData = 0;
uint16_t buffer[2];

//Our request handler
void requestHandler() {
  //Read from the ADC at I02 and I04
  buffer[0] = analogRead(0);
  buffer[1] = analogRead(1);
  Wire.write((uint8_t*)buffer, sizeof(buffer));
  //Set the newData flag
  newData = 1;
}

void setup() {
  //put your setup code here,to run once:
  Wire.begin(2);  //We are slave #2
  Serial.begin(115200);
  Wire.onRequest(requestHandler);
}

void loop() {
  //put your main code here,to run repeatedly:
  //Loop until there is new data.newData is set by
  //request handler.
  while (!newData)
    delay(50);

  newData = 0;

  //Write the values read
  Serial.print("x(slave)=");
  Serial.print(buffer[0]);
  Serial.print("y(slave)=");
  Serial.println(buffer[1]);
}
