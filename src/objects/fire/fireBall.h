#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

/*
    Class with fire ball
*/

class FireBall : public Drawable
{
private:
    CircleShape shape;
    float fireBallRadius{5};
    Vector2f velocity;
    bool isFromEnemy;
    bool shooted{false};
    int numberInSeries;
    void draw(RenderTarget &target, RenderStates state) const;

public:
    FireBall(float speedY, bool isFromEnemy);
    FireBall() = delete;
    ~FireBall() = default;

    Vector2f getPosition();
    bool getAuthor();
    void update(Vector2f startPosition);
    float top();
    float bottom();
    float left();
    float right();
    void isShooted(bool state);
};