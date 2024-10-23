#include <iostream>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[])
{
	std::cout << "Hello world!";

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

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

	#ifdef _DEBUG
	_CrtDumpMemoryLeaks();
	#endif
	return 0;
}