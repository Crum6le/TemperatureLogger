#include "RenderWrapper.hpp"

Renderable::Renderable(){}

Renderable::~Renderable(){}

void Renderable::render(MCUFRIEND_kbv* target){}

void RenderTarget::init(){
  m_target.begin(0x9341);
  m_target.fillScreen(RGB(0, 0, 0));
}

RenderTarget::~RenderTarget(){}