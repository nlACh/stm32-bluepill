#include "Arduino.h"
#include "l298n.h"

L298N::L298N(int en1, int p1, int p2, int en2, int p3, int p4){
  pinMode(en1, OUTPUT);
  pinMode(p1, OUTPUT);
  pinMode(p2, OUTPUT);
  pinMode(en2, OUTPUT);
  pinMode(p3, OUTPUT);
  pinMode(p4, OUTPUT);
  
  E1 = en1; P1 = p1; P2 = p2;
  E2 = en2; P3 = p3; P4 = p4;

  digitalWrite(E1, HIGH); // Motor always enabled
  digitalWrite(E2, HIGH); // Motor always enabled
}

void L298N::fwd(int s){
  analogWrite(P1, s);
  analogWrite(P2, 0);
  analogWrite(P3, s);
  analogWrite(P4, 0);
}

void L298N::rev(int s){
  analogWrite(P1, 0);
  analogWrite(P2, s);
  analogWrite(P3, 0);
  analogWrite(P4, s);
}

void L298N::stop(){
  digitalWrite(E1, LOW); // Disable stuff
  digitalWrite(E2, LOW);
}

void L298N::left(int s){
  
}

void L298N::right(int s){
  
}
