#include "Button.hpp"

Button::Button(int positionXMin, int positionXMax, int positionYMin, int positionYMax, bool toggle, int delayTime, uint16_t colorPressed, uint16_t colorReleased):
    m_positionXMin(positionXMin),
    m_positionXMax(positionXMax),
    m_positionYMin(positionYMin),
    m_positionYMax(positionYMax),
    m_toggle(toggle),
    m_pressed(false),
    m_delayTime(delayTime),
    m_colorReleased(colorReleased),
    m_colorPressed(colorPressed),
    m_redraw(true)
{
    m_width = m_positionXMax - m_positionXMin;
    m_height = m_positionYMax - m_positionYMin;
}

Button::~Button(){}

void Button::checkPress(){
    TouchPoint touchPoint = getTouchPointInScreenSpace();
    bool touchPointIsInButton = touchPoint.touched && touchPoint.x > m_positionXMin && touchPoint.x < m_positionXMax && touchPoint.y > m_positionYMin && touchPoint.y < m_positionYMax;

    if(m_toggle){
        if(touchPointIsInButton){
            m_pressed = !m_pressed;
            m_redraw = true;

            delay(m_delayTime);
        }
    }else{
        if(touchPointIsInButton != m_pressed){
            m_pressed = touchPointIsInButton;
            
            m_redraw = true;
            delay(m_delayTime);
        }
    }
}

void Button::render(){
    if(m_redraw){
        if(m_pressed){
            display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, RGB(0, 255, 0));
        }else{
            display.fillRect(m_positionXMin, m_positionYMin, m_width, m_height, RGB(255, 0, 0));
        }

        m_redraw = false;
    }
}