#ifndef BUTTON_HPP
#define BUTTON_CPP

////////////
// Include
////////////

#include "TouchscreenWrapper.hpp"
#include "RenderWrapper.hpp"

////////////
// Classes
////////////

class Button : Renderable, Touchable{
public:
    Button(int positionXMin, int positionXMax, int positionYMin, int positionYMax, bool toggle, int delayTime, uint16_t colorPressed, uint16_t colorReleased);
    ~Button();

    void render() override;

    void checkPress();

private:
    int m_positionXMin, m_positionXMax, m_positionYMin, m_positionYMax;
    int m_width, m_height;

    int m_delayTime;

    uint16_t m_colorPressed, m_colorReleased;

    bool m_toggle, m_pressed;
    bool m_redraw;
};

#endif