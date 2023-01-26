#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/*
    Class with fire ball
*/

class FireBall : public Drawable
{
private:
    CircleShape shape;
    float fireBallRadius;
    Vector2f velocity;
    void draw(RenderTarget &target, RenderStates state) const;

public:
    FireBall(float t_X, float t_Y, float radius, float speedX, float speedY);

    void update();
    float top();
    float bottom();
    float left();
    float right();
};