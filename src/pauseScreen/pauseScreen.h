#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class PauseScreen : public Drawable
{
public:
    PauseScreen(bool open);
    PauseScreen() = delete;
    ~PauseScreen() = default;

private:
    RectangleShape shape;
    RectangleShape shape2;
    sf::Text logout;
    sf::Text comeBack;

    void draw(RenderTarget &target, RenderStates state) const;
};