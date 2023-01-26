#include "bomb.h"

Bomb::Bomb(float t_X, float t_Y, float radius, float speedX, float speedY)
{
    this->fireBallRadius = radius;
    this->velocity = Vector2f(speedX, speedY);
    shape.setPosition(t_X, t_Y);
    shape.setRadius(radius);
    shape.setFillColor(Color::White);
    shape.setOrigin(radius, radius);
}

void Bomb::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}

void Bomb::update()
{
    if (this->bottom() > 990 || this->top() < 0)
    {
        this->velocity.y = 0 - this->velocity.y;
        this->hp--;
    }

    if (this->right() > 1200 || this->left() < 0)
    {
        this->velocity.x = 0 - this->velocity.x;
        this->hp--;
    }

    shape.move(this->velocity);
}

float Bomb::top()
{
    return this->shape.getPosition().y - shape.getRadius();
}

float Bomb::bottom()
{
    return this->shape.getPosition().y + shape.getRadius();
}

float Bomb::right()
{
    return this->shape.getPosition().x + shape.getRadius();
}

float Bomb::left()
{
    return this->shape.getPosition().x - shape.getRadius();
}