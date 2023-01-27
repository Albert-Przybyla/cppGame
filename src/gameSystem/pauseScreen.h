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
    CircleShape shape2;
    CircleShape shape3;

    void draw(RenderTarget &target, RenderStates state) const;
};