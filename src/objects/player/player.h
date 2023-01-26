#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Player : public Drawable
{
public:
    Player(float t_X, float t_Y);
    Player() = delete;
    ~Player() = default;

    Vector2f getPosition();

    void update();
    void playerLossLife();

    float top();
    float bottom();
    float left();
    float right();
    int getPlayerHp();

private:
    RectangleShape shape;
    float playerWidth{40};
    float playerheight{40};
    float playerSpeed;
    int playerHP{3};
    Vector2f velocity;
    void draw(RenderTarget &target, RenderStates state) const;
};