#pragma once
#include "enemy.h"

Enemy::Enemy(float t_X, float t_Y, int EnemyLevel)
{
    shape.setPosition(t_X, t_Y);
    this->enemyStartPosition = t_X;
    shape.setFillColor(Color::Red);
    switch (EnemyLevel)
    {
    case 1:
        this->enemyWidth = 20;
        this->enemyHeight = 20;
        this->enemySpeed = 0.05;
        this->enemyMovment = 300;
        this->enemyHP = 5;
        break;
    case 2:
        this->enemyWidth = 25;
        this->enemyHeight = 25;
        this->enemySpeed = 0.06;
        this->enemyMovment = 400;
        this->enemyHP = 8;
        break;
    default:
        this->enemyWidth = 16;
        this->enemyHeight = 16;
        this->enemySpeed = 0.04;
        this->enemyMovment = 250;
        this->enemyHP = 3;
    };
    this->velocity = Vector2f(this->enemySpeed, 0);
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

void Enemy::update()
{
    // if (this->right() > this->enemyStartPosition + this->enemyMovment || this->left() < this->enemyStartPosition)
    // {
    //     this->velocity.x = 0 - this->velocity.x;
    // }

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