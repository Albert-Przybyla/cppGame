#pragma once
#include "player.h"

Player::Player(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    this->playerSpeed = 0.08;
    this->velocity = Vector2f(0, 0);
    shape.setSize({this->playerWidth, this->playerheight});
    shape.setFillColor(Color::Green);
    shape.setOrigin(this->playerWidth / 2, this->playerheight / 2);
}

void Player::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
}

Vector2f Player::getPosition()
{
    return shape.getPosition();
}

void Player::update()
{
    // if (this->bottom() > 990 || this->top() < 0)
    // {
    //     this->velocity.y = 0 - this->velocity.y;
    // }

    // if (this->right() > 1200 || this->left() < 0)
    // {
    //     this->velocity.x = 0 - this->velocity.x;
    // }
    this->shape.move(this->velocity);
    if (Keyboard::isKeyPressed(Keyboard::Key::Left) && this->left() > 0)
    {
        this->velocity.x = 0 - this->playerSpeed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Right) && this->right() < 1200)
    {
        this->velocity.x = this->playerSpeed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Up) && this->top() > 0)
    {
        this->velocity.y = 0 - this->playerSpeed;
    }
    else if (Keyboard::isKeyPressed(Keyboard::Key::Down) && this->bottom() < 990)
    {
        this->velocity.y = this->playerSpeed;
    }
    else
    {
        this->velocity = Vector2f(0, 0);
    }
}

void Player::playerLossLife()
{
    shape.setFillColor(Color::Red);
}

float Player::top()
{
    return this->shape.getPosition().y - shape.getSize().y / 2;
}

float Player::bottom()
{
    return this->shape.getPosition().y + shape.getSize().y / 2;
}

float Player::right()
{
    return this->shape.getPosition().x + shape.getSize().x / 2;
}

float Player::left()
{
    return this->shape.getPosition().x - shape.getSize().x / 2;
}