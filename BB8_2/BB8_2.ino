#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include <PID_v1.h>
#include "l298n.h"
#include "pins.h"

#define MAX_BUF 16
Servo head;
Adafruit_NeoPixel neo = Adafruit_NeoPixel(4, NEO, NEO_GRBW + NEO_KHZ400);

L298N m(E1, MA1, MA2, E2, MB1, MB2);
char BUF[MAX_BUF]; // 16 character buffer
int pos = 0;

void setup() {
  Serial.begin(9600);
  head.attach(SERVO);
  neo.begin();
}

void loop() {
  // For now use HC-05
  while(Serial.available()){
    char c = Serial.read();
    if(pos<MAX_BUF)
      BUF[pos] = c;
    else{
      pos = 0;
      Serial.println(F("> "));
      break;
    }
    else if(c == ';'){
      BUF[pos] = '\0';
      String cmd = String(BUF);
      process(cmd);
    }
  } 
}

void process(String str){
  
}
