#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>

#include "objects/fire/fireBall.cpp"
#include "objects/bomb/bomb.cpp"
#include "objects/player/player.cpp"
#include "objects/enemy/enemy.cpp"

using namespace sf;
using namespace std;

bool inGame = false;

template <class T1, class T2>
bool isIntersecting(T1 &A, T2 &B)
{
    return A.right() >= B.left() && A.left() <= B.right() && A.bottom() >= B.top() && A.top() <= B.bottom();
}
void collisionTest(Player &Player, FireBall &fireBall)
{
    if (!isIntersecting(Player, fireBall))
    {
        return;
    }
    else if (fireBall.getAuthor())
    {
        Player.playerLossLife();
    }
}

void collisionEnemy(Enemy &Enemy, FireBall &fireBall)
{
    if (!isIntersecting(Enemy, fireBall))
    {
        return;
    }
    else if (!fireBall.getAuthor())
    {
        Enemy.EnemyLossLife();
    }
}

int main()
{
    // FireBall FireBall(600, 20, 0.1);
    // Bomb bomb1(12, 12, 0.05, 0.05);
    Enemy Enemy(100, 100, 0);
    FireBall FireBallEnemy(0.3, true);
    Player PlayerOne(600, 940);
    FireBall FireBall(-0.3, false);
    RenderWindow window(VideoMode(1200, 990), "Space Shooter");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        if (inGame)
        {
            FireBall.update(PlayerOne.getPosition());
            FireBallEnemy.update(Enemy.getPosition());
            Enemy.update();
            PlayerOne.update();

            collisionTest(PlayerOne, FireBallEnemy);
            collisionEnemy(Enemy, FireBall);

            window.draw(Enemy);
            window.draw(FireBallEnemy);
            window.draw(PlayerOne);
            window.draw(FireBall);
        }
        else
        {
            sf::Text text;

            // set the string to display
            text.setString("Hello world");

            // set the character size
            text.setCharacterSize(24); // in pixels, not points!

            // set the color
            text.setFillColor(Color::Red);

            // set the text style
            text.setStyle(Text::Bold | Text::Underlined);
            // inside the main loop, between window.clear() and window.display()
            text.setPosition(23, 23);
            window.draw(text);
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
        {
            inGame = !inGame;
        }

        window.display();
    }

    return 0;
}