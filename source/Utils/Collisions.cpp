#include "Collisions.h"
#include "Dot.h"
#include "Circle.h"
#include "Line.h"
#include <math.h>

namespace
{
    double GetLength(const sf::Vector2<double>& first, const sf::Vector2<double>& second)
    {
        double dX = first.x - second.x;
        double dY = first.y - second.y;

        return std::sqrt(dX * dX + dY * dY);
    }
}

bool Collisions::IsIntersect(const Dot& dot, const Circle& circle)
{
    // double dX = dot.GetXCord() - circle.GetXCord();
    // double dY = dot.GetYCord() - circle.GetYCord();
    // double squareRadius = static_cast<double>(circle.getRadius() * circle.getRadius());

    // return  squareRadius >= dX * dX + dY * dY;
    // return false;
}

bool IsIntersect(const Circle& circle, const Dot& dot)
{
    // double dX = dot.getPosition().x - circle.getPosition().x;
    // double dY = dot.Process - circle.GetYCord();
    // double squareRadius = static_cast<double>(circle.getRadius() * circle.getRadius());

    // return  squareRadius >= dX * dX + dY * dY;
    return false;
}

bool IsIntersect(const Circle& circle, double x, double y)
{
    sf::Vector2<float> circleCords = circle.getPosition();
    circleCords.x += circle.getRadius();
    circleCords.y += circle.getRadius();

    double dX = x - circleCords.x;
    double dY = y - circleCords.y;
    double squareRadius = static_cast<double>(circle.getRadius() * circle.getRadius());

    return  squareRadius >= dX * dX + dY * dY;
    return false;
}

bool Collisions::IsIntersect(const Line& line, const Circle& circle)
{
    sf::Vector2<float> circleCords = circle.getPosition();
    circleCords.x += circle.getRadius();
    circleCords.y += circle.getRadius();

    sf::Vector2<double> thirdPoint(circleCords.x, circleCords.y);
    double a = GetLength(line.GetFirstDotCord(), line.GetSecondDotCord());
    double c = GetLength(line.GetFirstDotCord(), thirdPoint);
    double b = GetLength(line.GetSecondDotCord(), thirdPoint);

    double p = (a + b + c) / 2;

    float h = static_cast<float>(2 / a * std::sqrt(p * (p - a) * (p - b) * (p - c)));

    return h < circle.getRadius();
}

bool Collisions::IsIntersect(const Circle& circle, const Line& line)
{
    sf::Vector2<float> circleCords = circle.getPosition();
    circleCords.x += circle.getRadius();
    circleCords.y += circle.getRadius();

    sf::Vector2<double> thirdPoint(circleCords.x, circleCords.y);
    double a = GetLength(line.GetFirstDotCord(), line.GetSecondDotCord());
    double c = GetLength(line.GetFirstDotCord(), thirdPoint);
    double b = GetLength(line.GetSecondDotCord(), thirdPoint);

    double p = (a + b + c) / 2;

    float h = static_cast<float>(2 / a * std::sqrt(p * (p - a) * (p - b) * (p - c)));
    // check edge cases;
    return h < circle.getRadius();
}