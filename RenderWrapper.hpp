#ifndef RENDERWRAPPER_HPP
#define RENDERWRAPPER_HPP

////////////
// Include
////////////

#include <MCUFRIEND_kbv.h>

#include "utility.hpp"

////////////////
// Definitions
////////////////

#define DISPLAY_SCREEN_WIDTH 320
#define DISPLAY_SCREEN_HEIGHT 240

#define DISPLAY_COLOR_CLEAR RGB(0, 0, 0)

//////////////
// Variables
//////////////

extern MCUFRIEND_kbv display;

//////////////
// Functions
//////////////

void displayInitialise();

////////////
// Classes
////////////

class Renderable{
public:
    Renderable();
    ~Renderable();

    virtual void render(bool clear);
};

#endif