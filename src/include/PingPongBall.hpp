#ifndef PING_PONG_BALL_H
#define PING_PONG_BALL_H

#include <SFML/Graphics.hpp>
#include "MonoBehavior.hpp"
#include "Platform.hpp"
#include "CircleCollider.hpp"
#include "CollisionType.hpp"

using namespace sf;
using namespace std;

class PingPongBall : public Drawable, public MonoBehavior, public CircleCollider {
private:
    CircleShape circle;
    Platform* topPlatform;
    Platform* bottomPlatform;
    Vector2f velocity;
    float speed = 2;
    float angle;
    CollisionType lastTouch = CollisionType::NONE;
    function<void()> topCollisionCallback;
    function<void()> bottomCollisionCallback;
    RenderWindow* window;
    int getRandomAngles(int min, int max) const;
    void randomRefresh();
    float calculateAngle() const;
    bool checkAndSetLastTouch(bool collideValue, CollisionType checkCollisionType);
    void handlePlatformCollision(Platform* platform);
    void refresh();
    void start(RenderWindow& window) override;
public:
    virtual void draw(RenderTarget& target, RenderStates states) const override;
    void move();
    void setTopCollisionCallback(function<void()> callback);
    void setBottomCollisionCallback(function<void()> callback);
    PingPongBall(Platform &topPlatform, Platform &bottomPlatform);
};

#endif