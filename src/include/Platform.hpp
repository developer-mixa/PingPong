#ifndef PLATFORM_H
#define PLATFORM_H

#include "MonoBehavior.hpp"
#include "RectCollider.hpp"

using namespace sf;

class Platform : public MonoBehavior, public RectCollider {
private:
    const float speed = 10;
    float y = 0;
    Keyboard::Key leftMoveCode;
    Keyboard::Key rightMoveCode;
    RectangleShape rectanglePlatform;
    Vector2f velocity;
    bool movingLeft = false;
    bool movingRight = false;
    void start(RenderWindow &window) override;
    void update(RenderWindow &window) override;
    void eventTrigger(Event event, RenderWindow &window) override;
public:
    const int height = 50;
    void goLeft(RenderWindow &window);
    void goRight(RenderWindow &window);
    void setY(float height);
    Vector2f getVelocity();
    Platform(Keyboard::Key leftMoveCode, Keyboard::Key rightMoveCode);
};

#endif