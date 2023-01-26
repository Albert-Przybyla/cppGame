#include "fireBall.h"

FireBall::FireBall(float t_X, float t_Y, float radius, float speedX, float speedY)
{
    this->fireBallRadius = radius;
    this->velocity = Vector2f(speedX, speedY);
    shape.setPosition(t_X, t_Y);
    shape.setRadius(radius);
    shape.setFillColor(Color::White);
    shape.setOrigin(radius, radius);
}

void FireBall::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}

void FireBall::update()
{
    if (this->bottom() > 990 || this->top() < 0)
    {
        this->velocity.y = 0 - this->velocity.y;
    }

    if (this->right() > 1200 || this->left() < 0)
    {
        this->velocity.x = 0 - this->velocity.x;
    }

    shape.move(this->velocity);
}

float FireBall::top()
{
    return this->shape.getPosition().y - shape.getRadius();
}

float FireBall::bottom()
{
    return this->shape.getPosition().y + shape.getRadius();
}

float FireBall::right()
{
    return this->shape.getPosition().x + shape.getRadius();
}

float FireBall::left()
{
    return this->shape.getPosition().x - shape.getRadius();
}