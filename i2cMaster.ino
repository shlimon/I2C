//MASTER
#include <Wire.h>
//Slave I2C Address
#define SLAVE_ADDR 9
//Response size
#define ANSWERSIZE 7

void setup() {
  // Intialize communication 
  Wire.begin();

  //Serial Monitor
  Serial.begin(9600);
}

void loop() {
  delay(1000);
  Serial.println("write to slave");
  //send data to the slave
  Wire.beginTransmission(SLAVE_ADDR);
  Wire.write(0);
  Wire.endTransmission();

  
  //Response from the slave
  Wire.requestFrom(SLAVE_ADDR, ANSWERSIZE);

  //Add character to the string
  String response = "";
  while(Wire.available()){
    char b = Wire.read();
    response +=b;
  }

  //print to seraial monitor 
  Serial.println(response);
  

}
