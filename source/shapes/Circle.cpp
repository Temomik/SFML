#include "Circle.h"
#include <SFML\Graphics\RenderWindow.hpp>
#include "Collisions.h"
#include "Line.h"

using namespace sf;

namespace
{
    float random()
    {
        return 1 + rand() % 10;
    }

    constexpr int32_t height = 1080;
    constexpr int32_t width = 1920;

    Line up(sf::Vector2<double>(0, 0), sf::Vector2<double>(width, 0));
    Line left(sf::Vector2<double>(0, 0), sf::Vector2<double>(0, height));
    Line right(sf::Vector2<double>(width, 0), sf::Vector2<double>(width, height));
    Line down(sf::Vector2<double>(0, height), sf::Vector2<double>(width, height));
}

Circle::Circle(RenderWindow& renderWindow, float radius, size_t pointCount)
    : ShapeObject(renderWindow)
    , CircleShape(radius, pointCount)
{
    dx = random();
    dy = random();
}

void Circle::Process()
{
    setPosition(x, y);

    const Circle& circle = *this;

    if (Collisions::IsIntersect(circle, up))
    {
        dy *= -1;
    }

    if (Collisions::IsIntersect(circle, down))
    {
        dy *= -1;
    }

    if (Collisions::IsIntersect(circle, right))
    {
        dx *= -1;
    }

    if (Collisions::IsIntersect(circle, left))
    {
        dx *= -1;
    }

    x += dx;
    y += dy;

    // mRenderWindow.draw(circle);
}

void Circle::SetCords(const sf::Vector2f& cords)
{
    x = cords.x;
    y = cords.y;
}
