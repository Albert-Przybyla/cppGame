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
    float fireBallRadius{3};
    Vector2f velocity;
    void draw(RenderTarget &target, RenderStates state) const;

public:
    FireBall(float t_X, float t_Y, float speedY);
    FireBall() = delete;
    ~FireBall() = default;

    Vector2f getPosition();

    void update();
    float top();
    float bottom();
    float left();
    float right();
};