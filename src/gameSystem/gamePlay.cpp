#pragma once

#include <fstream>
#include <string>

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
    int score;
    int level;

public:
    // construstors, distractors:
    Game()
    {
        this->level = 0;
        this->score = 0;
    }

    // functions:

    void checkStorageScore()
    {
        std::ifstream file("bestScore.txt");
        while (file >> this->score)
            file.close();
    }

    void checkStorageLevel()
    {
        std::ifstream file("bestLevel.txt");
        while (file >> this->level)
            file.close();
    }

    int getScore()
    {
        return this->level;
    }

    int getLevel()
    {
        return this->score;
    }

    void setScore(int newScore)
    {
        this->score = newScore;
        std::ofstream file("bestScore.txt");
        file << newScore;
        file.close();
    }

    void setLevel(int newLevel)
    {
        this->level = newLevel;
        std::ofstream file("bestLevel.txt");
        file << newLevel;
        file.close();
    }
};