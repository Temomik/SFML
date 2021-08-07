#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    std::cout << "run" << std::endl;

    LoadLibrary("SFML\\bin\\openal32.dll");
    LoadLibrary("SFML\\bin\\sfml-audio-2.dll");
    LoadLibrary("SFML\\bin\\sfml-audio-d-2.dll");   
    LoadLibrary("SFML\\bin\\sfml-graphics-2.dll");
    LoadLibrary("SFML\\bin\\sfml-graphics-d-2.dll");
    LoadLibrary("SFML\\bin\\sfml-network-2.dll");
    LoadLibrary("SFML\\bin\\sfml-network-d-2.dll");
    LoadLibrary("SFML\\bin\\sfml-system-2.dll");
    LoadLibrary("SFML\\bin\\sfml-system-d-2.dll");
    LoadLibrary("SFML\\bin\\sfml-window-2.dll");
    LoadLibrary("SFML\\bin\\sfml-window-d-2.dll");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}
