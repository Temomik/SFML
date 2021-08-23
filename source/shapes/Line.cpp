#include "Line.h"

const sf::Vector2<double>& Line::GetFirstDotCord() const
{
    return mFirst;
}

const sf::Vector2<double>& Line::GetSecondDotCord() const
{
    return mSecond;
}

Line::Line(const sf::Vector2<double>& first, const sf::Vector2<double>& second)
    : mFirst(first)
    , mSecond(second)
{
}
