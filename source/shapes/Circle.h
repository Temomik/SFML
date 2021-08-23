#pragma once

#include "ShapeObject.h"
#include <SFML/Graphics/CircleShape.hpp>

class Circle : public ShapeObject, public sf::CircleShape
{
public:
    Circle(sf::RenderWindow& renderWindow, float radius = 0, size_t pointCount = 30);

    void Process() override;
    void SetCords(const sf::Vector2f& cords);

    float x = 0.f, y = 0.f;
    float dx = 0.f, dy = 0.f;
};
