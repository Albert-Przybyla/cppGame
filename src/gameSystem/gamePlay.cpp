#pragma once

#include "../objects/fire/fireBall.cpp"
#include "../objects/bomb/bomb.cpp"
#include "../objects/player/player.cpp"
#include "../objects/enemy/enemy.cpp"

/*
    Class with game engine
*/

class Game
{
private:
    int Score{0};
    int level{0};

public:
    // construstors, distractors:
    Game();

    // functions:

    void level1()
    {
    }

    void render();
};