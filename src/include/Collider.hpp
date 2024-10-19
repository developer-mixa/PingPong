#ifndef COLLIDER_H
#define COLLIDER_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Collider{
public:
    Vector2f position;
    void setPosition(Vector2f const newPos) noexcept {
        position = newPos;
    }
    virtual bool collide(Collider &other) = 0;
    virtual ~Collider() = default;
};

#endif