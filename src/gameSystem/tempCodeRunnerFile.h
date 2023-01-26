#pragma once

/*
    Class with game engine
*/

class Game
{
private:
public:
    // construstors, distractors:
    Game();
    virtual ~Game();

    // functions:

    void update();

    void render();
};