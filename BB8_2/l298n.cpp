#include "Arduino.h"
#include "l298n.h"

L298N::L298N(int en, int p1, int p2){
  pinMode(en, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);

  E = en; P1 = p1; P2 = p2;

  digitalWrite(E, HIGH); // Motor always enabled
}

void L298N::fwd(int s){
  analogWrite(P1, s);
  analogWrite(P2, 0);
}

void L298N::rev(int s){
  analogWrite(P1, 0);
  analogWrite(P2, s);
}

void L298N::stop(){
  digitalWrite(E, LOW); // Disable stuff
}
