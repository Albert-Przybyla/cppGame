#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <unistd.h>

#include "objects/fire/fireBall.cpp"
#include "objects/bomb/bomb.cpp"
#include "objects/player/player.cpp"
#include "objects/enemy/enemy.cpp"
#include "objects/lifes/lifes.cpp"

#include "pauseScreen/pauseScreen.cpp"
#include "endGameScreen/endGameScreen.cpp"
#include "helloScreen/helloScreen.cpp"
#include "gameSystem/gamePlay.cpp"

using namespace sf;
using namespace std;

bool pauseGame = false;
bool gameStarted = false;
int score;

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
        fireBall.isShooted(true);
        Player.playerLossLife();
    }
}

void collisionTestBomb(Player &Player, Bomb &bomb)
{
    if (!isIntersecting(Player, bomb))
    {
        return;
    }
    bomb.isShooted(true);
    Player.playerLossLife();
}

void collisionEnemy(Enemy &Enemy, FireBall &fireBall)
{
    if (!isIntersecting(Enemy, fireBall))
    {
        return;
    }
    else if (!fireBall.getAuthor())
    {
        fireBall.isShooted(true);
        Enemy.destroy();
        Enemy.EnemyLossLife();
        score++;
    }
}

int main()
{
    unsigned inX{7}, inY{2}, level1{100}, level2{100};
    vector<Enemy> enemys;
    vector<FireBall> fireBalls;
    for (int i = 0; i < inY; i++)
    {
        for (int j = 0; j < inX; j++)
        {
            enemys.emplace_back(100 + j * 250 + (100 * i), 100 + (100 * i), i);
            fireBalls.emplace_back(0.4, true);
        }
    }
    Game game;
    Bomb bomb(1400, 160, 0.2, 0.2);
    Bomb bomb2(1000, 160, -0.2, 0.2);
    Lifes lifeTab[3] = {Lifes(2360, 40), Lifes(2310, 40), Lifes(2260, 40)};
    Player PlayerOne(600, 940);
    PauseScreen PauseScreen(false);
    EndGameScreen endGameScreen(false);
    HelloScreen helloScreen(false);
    FireBall fireBall(-0.3, false);
    RenderWindow window(VideoMode(2400, 1600), "Space Shooter");

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }
        window.clear();
        if (!gameStarted)
        {
            window.draw(helloScreen);
            if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
            {
                gameStarted = true;
            }
        }
        if (!pauseGame && PlayerOne.getPlayerHp() > 0 && gameStarted)
        {
            fireBall.update(PlayerOne.getPosition());
            bomb.update();
            bomb2.update();
            collisionTestBomb(PlayerOne, bomb);
            PlayerOne.update();

            for (int i = 0; i < inX * inY; i++)
            {
                enemys[i].update();
                window.draw(enemys[i]);
                fireBalls[i].update(enemys[i].getPosition());
                collisionTest(PlayerOne, fireBalls[i]);
                collisionEnemy(enemys[i], fireBall);
                window.draw(fireBalls[i]);
            }

            auto iterator = remove_if(begin(enemys), end(enemys), [](Enemy &enemy)
                                      { return enemy.isDestroyed(); });
            enemys.erase(iterator, end(enemys));
            window.draw(bomb);
            window.draw(bomb2);
            for (int i = 0; i < PlayerOne.getPlayerHp(); i++)
            {
                window.draw(lifeTab[i]);
            }
            window.draw(PlayerOne);
            window.draw(fireBall);
            if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                pauseGame = true;
            }
        }
        else if (pauseGame && PlayerOne.getPlayerHp() > 0 && gameStarted)
        {
            window.draw(PauseScreen);
        }
        else if (gameStarted)
        {
            window.draw(endGameScreen);
            int lastScore = game.getScore();
            if (lastScore < score)
            {
                game.setScore(score);
            }
            cout << score;
            if (Keyboard::isKeyPressed(Keyboard::Key::Escape))
            {
                return 0;
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::Enter))
        {
            pauseGame = false;
        }

        window.display();
    }

    return 0;
}