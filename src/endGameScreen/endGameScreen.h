#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class EndGameScreen : public Drawable
{
public:
    EndGameScreen(bool open);
    EndGameScreen() = delete;
    ~EndGameScreen() = default;

private:
    RectangleShape shape;
    CircleShape shape2;
    CircleShape shape3;
    sf::Text logout;

    void draw(RenderTarget &target, RenderStates state) const;
};