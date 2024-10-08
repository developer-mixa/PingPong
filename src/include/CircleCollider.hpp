#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class CircleCollider : public Collider {
public:
    CircleCollider(float x, float y, float radius);
    
    bool collide(Collider& other) override;
    bool collidesWithRect(sf::FloatRect& rect);

private:
    sf::Vector2f center;
    float radius;
};

#endif