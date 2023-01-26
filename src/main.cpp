#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <string>

using namespace sf;
using namespace std;

int main()
{
    RenderWindow window(VideoMode(1200, 1200), "space shutter");
    window.setFramerateLimit(60);
    CircleShape shape(100.f);
    shape.setFillColor(Color::Red);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear(Color::Green);
        window.draw(shape);
        window.display();
    }

    return 0;
}