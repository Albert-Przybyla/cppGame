#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class HelloScreen : public Drawable
{
public:
    HelloScreen(bool open);
    HelloScreen() = delete;
    ~HelloScreen() = default;

private:
    RectangleShape shapeH1;
    RectangleShape shapeH2;
    RectangleShape shapeH3;
    RectangleShape shapeE1;
    RectangleShape shapeE2;
    RectangleShape shapeE3;
    RectangleShape shapeE4;
    RectangleShape shapeL1;
    RectangleShape shapeL2;
    RectangleShape shapeL3;
    RectangleShape shapeL4;
    CircleShape shapeO1;
    CircleShape shapeO2;
    CircleShape shape2;
    CircleShape shape3;
    sf::Text logout;

    void draw(RenderTarget &target, RenderStates state) const;
};