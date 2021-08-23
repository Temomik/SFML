#pragma once

#include <SFML/System/Vector2.hpp>
#include "ShapeObject.h"

class Line
{
public:
    const sf::Vector2<double>& GetFirstDotCord() const;
    const sf::Vector2<double>& GetSecondDotCord() const;

    Line(const sf::Vector2<double>& first, const sf::Vector2<double>& second);
private:

    sf::Vector2<double> mFirst;
    sf::Vector2<double> mSecond;
};
