#ifndef TOUCHSCREENWRAPPER_HPP
#define TOUCHSCREENWRAPPER_HPP

////////////
// Include
////////////

#include <TouchScreen.h>
#include <Arduino.h>

////////////////
// Definitions
////////////////

// touchscreen analog values to match coordinate space
#define TOUCHSCREEN_ANALOG_X_MIN 115
#define TOUCHSCREEN_ANALOG_X_MAX 945
#define TOUCHSCREEN_ANALOG_Y_MIN 150
#define TOUCHSCREEN_ANALOG_Y_MAX 910

// touchscreen pins
#define TOUCHSCREEN_PIN_Y_ANALOG A2
#define TOUCHSCREEN_PIN_X_ANALOG A3
#define TOUCHSCREEN_PIN_Y_DIGITAL 8
#define TOUCHSCREEN_PIN_X_DIGITAL 9

#define TOUCHSCREEN_OHMS 300

// touchscreen coordinate space
#define TOUCHSCREEN_SCREEN_WIDTH 320
#define TOUCHSCREEN_SCREEN_HEIGHT 240

//////////////
// Variables
//////////////

extern TouchScreen touchscreen;

////////////
// Structs
////////////

struct TouchPoint{
    int x;
    int y;
    bool touched;
};

////////////
// Classes
////////////

class Touchable{
public:
    Touchable();
    ~Touchable();

    TouchPoint getTouchPointInScreenSpace();
};

#endif