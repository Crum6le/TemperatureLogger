#ifndef GRAPH_HPP
#define GRAPH_HPP

////////////
// Include
////////////

#include "RenderWrapper.hpp"

////////////
// Classes
////////////

class CoordinateSystem : Renderable{
public:
    CoordinateSystem();
    ~CoordinateSystem();

    void render override;
};

class Graph : Renderable{
public:
    Graph();
    ~Graph();

    void render override;
}

#endif