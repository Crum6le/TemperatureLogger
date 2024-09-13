#include "TouchscreenWrapper.hpp"

Touchable t;

void setup(){
  Serial.begin(9600);
}

void loop(){
    TouchPoint p = t.getTouchPointInScreenSpace();
    if(p.touched){
      Serial.print("X: ");
      Serial.print(p.x);
      Serial.print(" , Y: ");
      Serial.println(p.y);
    }
}