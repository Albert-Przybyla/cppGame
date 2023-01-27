#include "bomb.h"

Bomb::Bomb(float t_X, float t_Y, float speedX, float speedY)
{
    this->velocity = Vector2f(speedX, speedY);
    shape.setPosition(t_X, t_Y);
    shape.setRadius(this->BombRadius);
    shape.setFillColor(Color::White);
    shape.setOrigin(this->BombRadius, this->BombRadius);
}

void Bomb::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}

void Bomb::update()
{
    if (this->shooted)
    {
        shape.setPosition(1200, 140);
        this->isShooted(false);
    }
    if (this->bottom() > 1600 || this->top() < 0)
    {
        this->velocity.y = 0 - this->velocity.y;
    }

    if (this->right() > 2400 || this->left() < 0)
    {
        this->velocity.x = 0 - this->velocity.x;
    }

    this->shape.move(this->velocity);
}

void Bomb::isShooted(bool state)
{
    this->shooted = state;
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