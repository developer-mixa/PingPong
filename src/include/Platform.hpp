#ifndef PLATFORM_H
#define PLATFORM_H

#include "MonoBehavior.hpp"
#include "RectCollider.hpp"
#include "PlatformMovingType.hpp"

using namespace sf;

class Platform : public MonoBehavior, public RectCollider {
private:
    float y = 0;
    Keyboard::Key leftMoveCode;
    Keyboard::Key rightMoveCode;
    RectangleShape rectanglePlatform;
    PlatrormMovingType movingType;
    bool moveLeft = false;
    bool moveRight = false;
    void start(RenderWindow &window) override;
    void update(RenderWindow &window) override;
    void eventTrigger(Event event, RenderWindow &window) override;
public:
    const float speed = 10;
    const int height = 50;
    void goLeft();
    void goRight(RenderWindow &window);
    void setY(float height);
    Platform(Keyboard::Key leftMoveCode, Keyboard::Key rightMoveCode);
    PlatrormMovingType getMovingType() const;
};

#endif