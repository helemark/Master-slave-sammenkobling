#include <Wire.h>

#define SLAVE_ADDR 9
#define ANSWERSIZE 11

String answer = "Hallo pa do";


void setup() {
  Wire.begin(SLAVE_ADDR);       // join i2c bus with address #8

  Wire.onRequest(requestEvent);
  Wire.onReceive(receiveEvent); 
  
  Serial.begin(9600);           // start serial for output
  Serial.println("I2C Slave Demonstration");
} 

void loop() {
  delay(50);
}


void receiveEvent() {
  while (0 < Wire.available()) { // loop through all but the last
    byte x = Wire.read();        // print the character
  }
  Serial.println("Receive evet");         // print the integer
}

void requestEvent(){
  
  byte response[ANSWERSIZE];

  for(byte i = 0; i<ANSWERSIZE; i++){
    response[i] = (byte)answer.charAt(i);
  }

  Wire.write(response, sizeof(response));

  Serial.println("Request event");
}
