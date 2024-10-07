#ifndef PING_PONG_BALL_H
#define PING_PONG_BALL_H

#include <SFML/Graphics.hpp>
#include "MonoBehavior.hpp"
#include "Platform.hpp"

class PingPongBall : public sf::Drawable, public MonoBehavior {
private:
    sf::CircleShape circle;
    Platform* topPlatform;
    Platform* bottomPlatform;
public:
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    void start(sf::RenderWindow& window) override;


    PingPongBall(Platform &topPlatform, Platform &bottomPlatform);

    void move();
};

#endif