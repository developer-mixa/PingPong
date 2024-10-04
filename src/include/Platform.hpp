#ifndef PLATFORM_H
#define PLATFORM_H

#include "MonoBehavior.hpp"

class Platform : public MonoBehavior {
private:
    float speed = 5;
    sf::Keyboard::Key leftMoveCode;
    sf::Keyboard::Key rightMoveCode;
    sf::RectangleShape rectanglePlatform;
    
public:
    void start(sf::RenderWindow &window) override;
    void update(sf::RenderWindow &window) override;
    void eventTrigger(sf::Event event, sf::RenderWindow &window) override;
    void goLeft(sf::RenderWindow &window);
    void goRight(sf::RenderWindow &window);
    Platform(sf::Keyboard::Key leftMoveCode, sf::Keyboard::Key rightMoveCode);
};

#endif