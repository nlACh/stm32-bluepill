// Debug Mode prints everything on Serial
#define DEBUG

#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include <PID_v1.h>
#include "l298n.h"
#include "pins.h"

#define MAX_BUF 16
#define INTERVAL 25 //  milliseconds
Servo head;
Adafruit_NeoPixel neo = Adafruit_NeoPixel(4, NEO_PIN, NEO_GRBW + NEO_KHZ400);

//                      RX    TX
HardwareSerial Serial3(PB11, PB10);

L298N m(E1, MA1, MA2, E2, MB1, MB2);
char BUF[MAX_BUF]; // 16 character buffer
int pos = 0;
unsigned long last = 0L;

void setup() {
  Serial.begin(9600); //  Serial attached to FTDI --> Serial1: PA9, PA10
  //  HC-05 set at 38400 baudrate
  Serial3.begin(38400);
  head.attach(SERVO);
  neo.begin();
}

void loop() {
  if(millis() - last >= INTERVAL){
  // For now use HC-05
  while(Serial3.available()){
    if(pos<MAX_BUF){
      char c = Serial3.read();
      BUF[pos] = (c==';') ? c : '\0';
      pos++;
    }
    else{
      pos = 0;
      #ifdef DEBUG
        Serial.println(F("> "));
      #endif
      break;
    }
  }
  #ifdef DEBUG
    Serial.println(BUF);
  #endif
  process(BUF);
  }
}

void process(char* x){
  // By default, the max buffer length is 16 characters
  // Since the max length is predetermined, the process becomes simpler
  // The format of received data is provided on a separate file.
}
