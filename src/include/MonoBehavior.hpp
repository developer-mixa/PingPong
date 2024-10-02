#ifndef MONO_BEHAVIOR_H
#define MONO_BEHAVIOR_H
#include <SFML/Graphics.hpp>
#include <iostream>

class MonoBehavior
{
public:
    void fitToScreen(sf::Sprite& sprite, const sf::RenderWindow& window);
    virtual void start(sf::RenderWindow &window){};
    virtual void update(sf::RenderWindow &window){};
    virtual void eventTrigger(sf::Event event){};
    virtual ~MonoBehavior() = default;
};


#endif