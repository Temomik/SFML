#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <iostream>

#include "Circle.h"
#include "Collisions.h"
#include <vector>

constexpr int32_t height = 1080;
constexpr int32_t width = 1920;

using namespace sf;

std::vector<Circle> circles;
RenderWindow window(VideoMode(width, height), "SFML works!");

void ProcessCircles()
{
    while (window.isOpen())
    {

        for (Circle& circle : circles)
        {
            circle.Process();
        }
    }
}

int main()
{
    srand(time(0));
    window.setFramerateLimit(60);
    sf::Thread thread(&ProcessCircles);

    float radius = 5.f;
    int32_t count = 1000000;
    for (size_t i = 0; i < count; i++)
    {
        circles.push_back(Circle(window, radius));
        float x = (int)(i * radius * 2) % 1920;
        float y = (int)((int)(i * radius * 2) / 1920 * radius * 2) % 1080;
        circles[i].SetCords(sf::Vector2f(x, y));
        circles[i].setFillColor(sf::Color(rand() % 250, rand() % 250, rand() % 250));
    }

    thread.launch();
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();

        for (Circle& circle : circles)
        {
            window.draw(circle);
        }
        window.display();
    }

    return 0;
}
