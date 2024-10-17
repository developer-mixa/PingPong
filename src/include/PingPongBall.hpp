#ifndef PING_PONG_BALL_H
#define PING_PONG_BALL_H

#include <SFML/Graphics.hpp>
#include "MonoBehavior.hpp"
#include "Platform.hpp"
#include "CircleCollider.hpp"
#include "CollisionType.hpp"

class PingPongBall : public sf::Drawable, public MonoBehavior, public CircleCollider {
private:
    sf::CircleShape circle;
    Platform* topPlatform;
    Platform* bottomPlatform;
    sf::Vector2f velocity;
    float speed = 2;
    float angle;
    CollisionType lastTouch = CollisionType::NONE;
    std::function<void()> topCollisionCallback;
    std::function<void()> bottomCollisionCallback;
    sf::RenderWindow* window;
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void start(sf::RenderWindow& window) override;
    void move();
    void randomRefresh();
    void refresh();
    void setTopCollisionCallback(std::function<void()> callback);
    void setBottomCollisionCallback(std::function<void()> callback);
    float calculateAngle();
    bool checkAndSetLastTouch(bool collideValue, CollisionType checkCollisionType);
    PingPongBall(Platform &topPlatform, Platform &bottomPlatform);
};

#endif