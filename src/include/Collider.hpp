#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Collider{
public:
    virtual bool collide(Collider &other) = 0;
    virtual ~Collider() = default;
};

#endif