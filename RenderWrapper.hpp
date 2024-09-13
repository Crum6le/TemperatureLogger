#ifndef RENDERWRAPPER_HPP
#define RENDERWRAPPER_HPP

#include <MCUFRIEND_kbv.h>

#include "util.hpp"

////////////////////////
// A renderable object
////////////////////////

class Renderable
{
public:
    Renderable();
    ~Renderable();

    virtual void render(MCUFRIEND_kbv* target);
};

////////////////////////////
// the window to render to
////////////////////////////

class RenderTarget{
public:
    ~RenderTarget();

    void init();

    MCUFRIEND_kbv* getRenderTarget();

private:
    MCUFRIEND_kbv m_target;


};

#endif