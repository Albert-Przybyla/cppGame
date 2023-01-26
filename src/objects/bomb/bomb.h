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
    float fireBallRadius;
    Vector2f velocity;
    int hp = 10;
    void draw(RenderTarget &target, RenderStates state) const;

public:
    Bomb(float t_X, float t_Y, float radius, float speedX, float speedY);

    void update();
    float top();
    float bottom();
    float left();
    float right();
};