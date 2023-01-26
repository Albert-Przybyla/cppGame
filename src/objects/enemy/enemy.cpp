#pragma once
#include "enemy.h"

Enemy::Enemy(float t_X, float t_Y, int EnemyLevel)
{
    shape.setPosition(t_X, 0);
    this->enemyStartPosition = Vector2f(t_X, t_Y);
    shape.setFillColor(Color::Red);
    switch (EnemyLevel)
    {
    case 1:
        this->enemyWidth = 30;
        this->enemyHeight = 30;
        this->enemySpeed = 0.1;
        this->enemyMovment = 300;
        this->enemyHP = 3;
        break;
    case 2:
        this->enemyWidth = 30;
        this->enemyHeight = 30;
        this->enemySpeed = 0.14;
        this->enemyMovment = 400;
        this->enemyHP = 4;
        break;
    default:
        this->enemyWidth = 40;
        this->enemyHeight = 40;
        this->enemySpeed = 0.06;
        this->enemyMovment = 250;
        this->enemyHP = 2;
    };
    this->velocity = Vector2f(this->enemySpeed, this->enemySpeed);
    shape.setSize({this->enemyWidth, this->enemyHeight});
    shape.setOrigin(this->enemyWidth / 2, this->enemyHeight / 2);
}

void Enemy::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}

Vector2f Enemy::getPosition()
{
    return shape.getPosition();
}

void Enemy::EnemyLossLife()
{
    if (enemyHP > 0)
        this->enemyHP--;

    if (enemyHP == 0)
        this->destroy();
    // shape.setFillColor(Color::Black);
}

void Enemy::destroy()
{
    destoyed = true;
}

bool Enemy::isDestroyed()
{
    return destoyed;
}

void Enemy::update()
{
    if (this->enemyStartPosition.y <= shape.getPosition().y)
    {
        this->velocity.y = 0;
    }

    if (this->right() > this->enemyMovment + this->enemyStartPosition.x - this->shape.getSize().x || this->left() < this->enemyStartPosition.x - this->shape.getSize().x)
    {
        this->velocity.x = -this->velocity.x;
    }

    shape.move(this->velocity);
}

float Enemy::top()
{
    return this->shape.getPosition().y - shape.getSize().y / 2;
}

float Enemy::bottom()
{
    return this->shape.getPosition().y + shape.getSize().y / 2;
}

float Enemy::right()
{
    return this->shape.getPosition().x + shape.getSize().x / 2;
}

float Enemy::left()
{
    return this->shape.getPosition().x - shape.getSize().x / 2;
}