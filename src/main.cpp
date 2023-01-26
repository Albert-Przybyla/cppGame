#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <string>

#include "objects/fire/fireBall.cpp"
#include "objects/bomb/bomb.cpp"

using namespace sf;
using namespace std;

int main()
{

    FireBall FireBall(600, 20, 20, 0.1, 0.1);
    Bomb bomb1(12, 12, 10, 0.1, 0.1);
    RenderWindow window(VideoMode(1200, 990), "Space Shooter");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        FireBall.update();
        bomb1.update();
        window.clear();
        window.draw(bomb1);
        window.draw(FireBall);
        window.display();
    }

    return 0;
}