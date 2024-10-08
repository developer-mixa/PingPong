#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

class Collider{
public:
    sf::Vector2f position;
    void setPosition(sf::Vector2f newPos){
        position = newPos;
    }
    virtual bool collide(Collider &other) = 0;
    virtual ~Collider() = default;
};

#endif