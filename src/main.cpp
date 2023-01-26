#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>

#include "objects/fire/fireBall.cpp"
#include "objects/bomb/bomb.cpp"
#include "objects/player/player.cpp"
#include "objects/enemy/enemy.cpp"

#include "pauseScreen/pauseScreen.cpp"

using namespace sf;
using namespace std;

bool pauseGame = false;

int score = 0;

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
    FireBall FireBallEnemy(0.3, true);
    FireBall FireBallEnemy2(0.3, true);
    Enemy enemy1(100, 100, 0);
    Enemy enemy2(800, 100, 1);
    Player PlayerOne(600, 940);
    PauseScreen PauseScreen(false);
    FireBall fireBall(-0.3, false);
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
        if (pauseGame)
        {
            if (score < 2)
            {
            }
            fireBall.update(PlayerOne.getPosition());
            FireBallEnemy.update(enemy1.getPosition());
            FireBallEnemy2.update(enemy2.getPosition());
            enemy1.update();
            enemy2.update();
            PlayerOne.update();

            collisionTest(PlayerOne, FireBallEnemy);
            collisionTest(PlayerOne, FireBallEnemy2);
            collisionEnemy(enemy1, fireBall);
            collisionEnemy(enemy2, fireBall);

            window.draw(enemy1);
            window.draw(enemy2);
            window.draw(FireBallEnemy);
            window.draw(FireBallEnemy2);
            window.draw(PlayerOne);
            window.draw(fireBall);
        }
        else
        {
            window.draw(PauseScreen);
        }

        if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
        {
            pauseGame = !pauseGame;
        }

        window.display();
    }

    return 0;
}