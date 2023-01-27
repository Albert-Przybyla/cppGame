#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Lifes : public Drawable
{
public:
    Lifes(float t_X, float t_Y);
    Lifes() = delete;
    ~Lifes() = default;

    void hide();

private:
    RectangleShape shape;
    CircleShape shape2;
    CircleShape shape3;
    bool show{true};

    void draw(RenderTarget &target, RenderStates state) const;
};