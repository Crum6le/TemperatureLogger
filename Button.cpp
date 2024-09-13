#include "Button.hpp"

Button::Button(int positionXMin, int positionXMax, int positionYMin, int positionYMax, uint16_t colorPressed, uint16_t colorReleased){
    m_positionXMin = positionXMin;
    m_positionXMax = positionXMax;
    m_positionYMin = positionYMin;
    m_positionYMax = positionYMax;

    m_colorReleased = colorReleased;
    m_colorPressed = colorPressed;

    m_width = m_positionXMax - m_positionXMin;
    m_height = m_positionYMax - m_positionYMin;
}

Button::~Button(){}

void Button::render(bool clear){
    if(!clear){
        TouchPoint p = getTouchPointInScreenSpace();

        if(p.touched){
            display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, RGB(0, 255, 0));
        }else{
            display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, RGB(255, 0, 0));
        }
    }else{
        display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, DISPLAY_COLOR_CLEAR);
    }
}