#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWERSIZE 5

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  Serial.println("I2C Master Demonstration");
}


byte x = 0;


void loop() {
  delay(50);
  Serial.println("Write data to slavle");
  
  Wire.beginTransmission(8);
  Wire.write(0);
  Wire.endTransmission();

  Serial.println("Receive data");

  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

  String response = "";
  while (Wire.available()){
    char b = Wire.read();
    response += b;
  }

  Serial.println(response);
}
