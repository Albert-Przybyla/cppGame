#pragma once
#include "endGameScreen.h"

EndGameScreen::EndGameScreen(bool open)
{
    shape.setPosition(1200, 820);
    shape.setSize({80, 20});
    shape.setFillColor(Color::White);
    shape.setOrigin(40, 10);
    shape.rotate(10);

    shape2.setRadius(10);
    shape2.setFillColor(Color::White);
    shape2.setOrigin(5, 5);
    shape2.setPosition(1170, 765);

    shape3.setRadius(10);
    shape3.setFillColor(Color::White);
    shape3.setOrigin(5, 5);
    shape3.setPosition(1230, 765);

    logout.setString("Press enter to reload");
    logout.setPosition(620, 550);
    logout.setCharacterSize(24);
    logout.setFillColor(Color::White);
    logout.setStyle(Text::Bold | Text::Underlined);
}

void EndGameScreen::draw(RenderTarget &target, RenderStates state) const
{
    target.draw(this->shape, state);
    target.draw(this->shape2, state);
    target.draw(this->shape3, state);
    target.draw(this->logout, state);
}