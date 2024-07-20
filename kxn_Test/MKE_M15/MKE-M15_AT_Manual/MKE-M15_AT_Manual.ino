
#include "SoftwareSerial.h"

SoftwareSerial tt(13,12);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  tt.begin(9600);
  Serial.println("Start");
}

void loop() {
  // put your main code here, to run repeatedly:
  checkStream(&Serial, &tt);
  checkStream(&tt, &Serial);
}

void checkStream(Stream * mySerialIn, Stream * mySerialOut){
  if(mySerialIn){
    if(mySerialIn->available()){
      String tempStr = "";
      while(mySerialIn->available()){
        tempStr += (char)mySerialIn->read();
        delay(1);
      }
      mySerialOut->print(tempStr);
    }
  }
}
