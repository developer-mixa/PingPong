#ifndef PLATFORM_H
#define PLATFORM_H

#include "MonoBehavior.hpp"
#include "RectCollider.hpp"

class Platform : public MonoBehavior, public RectCollider {
private:
    const float speed = 10;
    float y = 0;
    sf::Keyboard::Key leftMoveCode;
    sf::Keyboard::Key rightMoveCode;
    sf::RectangleShape rectanglePlatform;
    bool movingLeft = false;
    bool movingRight = false;
    
public:
    const int height = 50;
    void start(sf::RenderWindow &window) override;
    void update(sf::RenderWindow &window) override;
    void eventTrigger(sf::Event event, sf::RenderWindow &window) override;
    void goLeft(sf::RenderWindow &window);
    void goRight(sf::RenderWindow &window);
    void setY(float height);
    Platform(sf::Keyboard::Key leftMoveCode, sf::Keyboard::Key rightMoveCode);
};

#endif