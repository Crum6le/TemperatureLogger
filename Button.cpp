#include "Button.hpp"

Button::Button(int positionXMin, int positionXMax, int positionYMin, int positionYMax, uint16_t colorPressed, uint16_t colorReleased, bool toggle){
    m_positionXMin = positionXMin;
    m_positionXMax = positionXMax;
    m_positionYMin = positionYMin;
    m_positionYMax = positionYMax;

    m_colorReleased = colorReleased;
    m_colorPressed = colorPressed;

    m_width = m_positionXMax - m_positionXMin;
    m_height = m_positionYMax - m_positionYMin;

    m_toggle = toggle;

    m_pressed = false;
}

Button::~Button(){}

void Button::checkPress(){
    TouchPoint touchPoint = getTouchPointInScreenSpace();
    if(touchPoint.touched){
        if(touchPoint.x > m_positionXMin && touchPoint.x < m_positionXMax){
            if(touchPoint.y > m_positionYMin && touchPoint.y < m_positionYMax){
                if(m_toggle){
                    m_pressed = !m_pressed;
                    m_needsRedraw = true;
                }else{
                    if(m_pressed == false){
                        m_needsRedraw = true;
                    }
                    m_pressed = true;
                }
            }
        }
    }else{
        if(m_pressed == true){
            m_needsRedraw = true;
        }
        m_pressed = false;
    }
}

void Button::render(){
    if(m_needsRedraw){
        m_needsRedraw = false;
        if(m_pressed){
            display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, RGB(0, 255, 0));
        }else{
            display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, RGB(255, 0, 0));
        }
    }
}