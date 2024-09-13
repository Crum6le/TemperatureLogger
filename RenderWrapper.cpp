#include "RenderWrapper.hpp"

MCUFRIEND_kbv display;

void displayInitialise(){
  display.begin(0x9341);
  display.setRotation(3);
  display.fillScreen(DISPLAY_COLOR_CLEAR);
}

Renderable::Renderable(){}

Renderable::~Renderable(){}