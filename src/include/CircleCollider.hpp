#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class CircleCollider : public Collider {
public:
    sf::CircleShape* circle;
    CircleCollider(sf::CircleShape& circle);
    
    bool collide(Collider& other) override;
    bool collidesWithRect(sf::RectangleShape& rectangle);

private:
    sf::Vector2f center;
    float radius;
};

#endif