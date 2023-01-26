#include "fireBall.h"

FireBall::FireBall(float speedY, bool isFromEnemy)
{
    this->velocity = Vector2f(0, speedY);
    this->isFromEnemy = isFromEnemy;
    shape.setRadius(this->fireBallRadius);
    shape.setFillColor(Color::White);
    shape.setOrigin(this->fireBallRadius, this->fireBallRadius);
}

void FireBall::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}

Vector2f FireBall::getPosition()
{
    return shape.getPosition();
}

void FireBall::update(Vector2f startPosition)
{
    if (this->bottom() > 990 || this->top() < 0)
    {
        shape.setPosition(startPosition);
    }

    if (this->right() > 1200 || this->left() < 0)
    {
        this->velocity.x = 0 - this->velocity.x;
    }

    shape.move(this->velocity);
}

bool FireBall::getAuthor()
{
    return this->isFromEnemy;
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