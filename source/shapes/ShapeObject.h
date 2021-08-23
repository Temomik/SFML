#pragma once 

#include <stdint.h>

namespace sf
{
    class RenderWindow;
}

class ShapeObject
{
public:
    ShapeObject(sf::RenderWindow& renderWindow);

    virtual void Process() = 0;
protected:
    sf::RenderWindow& mRenderWindow;
};
