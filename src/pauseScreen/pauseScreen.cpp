#pragma once
#include "pauseScreen.h"

PauseScreen::PauseScreen(bool open)
{
    shape.setPosition(620, 450);
    shape.setSize({20, 80});
    shape.setFillColor(Color::White);
    shape.setOrigin(10, 60);

    shape2.setPosition(580, 450);
    shape2.setSize({20, 80});
    shape2.setFillColor(Color::White);
    shape2.setOrigin(10, 60);

    logout.setString("Hello world");
    logout.setPosition(620, 550);
    logout.setCharacterSize(24);
    logout.setFillColor(Color::White);
    logout.setStyle(Text::Bold | Text::Underlined);
}

void PauseScreen::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
    target.draw(this->shape2, state);
    target.draw(this->logout, state);
}