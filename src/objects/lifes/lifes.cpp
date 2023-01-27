#pragma once
#include "lifes.h"

Lifes::Lifes(float t_X, float t_Y)
{
    shape.setPosition(t_X, t_Y);
    shape.setSize({20, 20});
    shape.setFillColor(Color::Red);
    shape.setOrigin(10, 10);
    shape.rotate(45);

    shape2.setRadius(10);
    shape2.setFillColor(Color::Red);
    shape2.setOrigin(5, 5);
    shape2.setPosition(t_X - 13, t_Y - 13);

    shape3.setRadius(10);
    shape3.setFillColor(Color::Red);
    shape3.setOrigin(5, 5);
    shape3.setPosition(t_X + 3, t_Y - 13);
}

void Lifes::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
    target.draw(this->shape2, state);
    target.draw(this->shape3, state);
}

void Lifes::hide()
{
    show = false;
    shape.setFillColor(Color::Black);
    shape2.setFillColor(Color::Black);
    shape3.setFillColor(Color::Black);
}