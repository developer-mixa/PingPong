#ifndef MONO_BEHAVIOR_H
#define MONO_BEHAVIOR_H
#include <SFML/Graphics.hpp>

class MonoBehavior
{
public:
    virtual void start(){};
    virtual void update(sf::RenderWindow &window){};
};


#endif