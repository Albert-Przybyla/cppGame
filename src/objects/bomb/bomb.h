#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/*
    Class with fire ball
*/

class Bomb : public Drawable
{
private:
    CircleShape shape;
    float BombRadius{10};
    Vector2f velocity;
    int hp{10};
    void draw(RenderTarget &target, RenderStates state) const;

public:
    Bomb(float t_X, float t_Y, float speedX, float speedY);
    Bomb() = delete;
    ~Bomb() = default;
    void update();
    float top();
    float bottom();
    float left();
    float right();
};