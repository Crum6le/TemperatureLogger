#include "Button.hpp"

#include "utility.hpp"

Button b = Button(100, 220, 20, 220, RGB(255, 0, 0), RGB(0, 255, 0));

void setup(){
  Serial.begin(9600);

  displayInitialise();
}

void loop(){
    b.render(false);
    b.render(true);
}