#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class Enemy : public Drawable
{
public:
    Enemy(float t_X, float t_Y, int EnemyLevel);
    Enemy() = delete;
    ~Enemy() = default;

    Vector2f getPosition();

    void update();

    float top();
    float bottom();
    float left();
    float right();

    void destroy();
    void EnemyLossLife();
    bool isDestroyed();

private:
    RectangleShape shape;
    float enemyWidth;
    float enemyHeight;
    float enemySpeed;
    float enemyMovment;
    bool destoyed{false};
    int enemyHP;
    Vector2f enemyStartPosition;
    Vector2f velocity;
    void draw(RenderTarget &target, RenderStates state) const;
};