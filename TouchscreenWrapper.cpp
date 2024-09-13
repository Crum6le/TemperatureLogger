#include "TouchscreenWrapper.hpp"

TouchScreen touchscreen = TouchScreen(TOUCHSCREEN_PIN_X_DIGITAL, TOUCHSCREEN_PIN_Y_ANALOG, TOUCHSCREEN_PIN_X_ANALOG, TOUCHSCREEN_PIN_Y_DIGITAL, TOUCHSCREEN_OHMS);

Touchable::Touchable(){}

Touchable::~Touchable(){}

TouchPoint Touchable::getTouchPointInScreenSpace(){
    TSPoint point = touchscreen.getPoint();
    TouchPoint touchPointInScreenSpace;

    touchPointInScreenSpace.x = map(point.x, TOUCHSCREEN_ANALOG_X_MIN, TOUCHSCREEN_ANALOG_X_MAX, 0, TOUCHSCREEN_SCREEN_WIDTH);
    touchPointInScreenSpace.y = map(point.y, TOUCHSCREEN_ANALOG_Y_MIN, TOUCHSCREEN_ANALOG_Y_MAX, 0, TOUCHSCREEN_SCREEN_HEIGHT);

    touchPointInScreenSpace.touched = point.z > touchscreen.pressureThreshhold ? true : false;

    // Touchscreen and Display share Pins
    pinMode(TOUCHSCREEN_PIN_X_ANALOG, OUTPUT);
    pinMode(TOUCHSCREEN_PIN_Y_ANALOG, OUTPUT);


    return touchPointInScreenSpace;
}