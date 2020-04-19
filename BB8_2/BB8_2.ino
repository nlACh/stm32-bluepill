#include <Servo.h>
#include <Adafruit_NeoPixel.h>
#include <PID_v1.h>
#include "l298n.h"
#include "pins.h"

Servo head;
Adafruit_NeoPixel neo = Adafruit_NeoPixel(4, NEO, NEO_GRBW + NEO_KHZ400);

L298N m1(E1, MA1, MA2);
L298N m2(E2, MB1, MB2);

void setup() {
  head.attach(SERVO);
  neo.begin();
  
}

void loop() {
  // put your main code here, to run repeatedly:

}
