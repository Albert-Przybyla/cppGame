#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <iostream>

#include "objects/fire/fireBall.cpp"
#include "objects/bomb/bomb.cpp"
#include "objects/player/player.cpp"
#include "objects/enemy/enemy.cpp"

using namespace sf;
using namespace std;

template <class T1, class T2>
bool isIntersecting(T1 &A, T2 &B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}
bool collisionTest(Player &Player, FireBall &fireBall)
{
    if (!isIntersecting(Player, fireBall))
    {
        return false;
    }
    else
    {
        Player.playerLossLife();
        return true;
    }
}

int main()
{

    FireBall FireBall(600, 20, 0.1);
    Bomb bomb1(12, 12, 0.05, 0.05);
    Enemy Enemy(100, 100, 2);
    Player Player(600, 940);
    RenderWindow window(VideoMode(1200, 990), "Space Shooter");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                // TODO: pauza
            }
        }
        FireBall.update();
        Enemy.update();
        Player.update();
        bomb1.update();
        collisionTest(Player, FireBall);
        window.clear();
        window.draw(Enemy);
        window.draw(bomb1);
        window.draw(Player);
        window.draw(FireBall);
        window.display();
    }

    return 0;
}