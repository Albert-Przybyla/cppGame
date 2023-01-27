#pragma once
#include "pauseScreen.h"

PauseScreen::PauseScreen(bool open)
{
    shape.setPosition(1180, 800);
    shape.setSize({20, 80});
    shape.setFillColor(Color::White);
    shape.setOrigin(10, 40);

    shape2.setPosition(1220, 800);
    shape2.setSize({20, 80});
    shape2.setFillColor(Color::White);
    shape2.setOrigin(10, 40);
}

void PauseScreen::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
    target.draw(this->shape2, state);
    target.draw(this->logout, state);
}