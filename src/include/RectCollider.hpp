#ifndef RECT_COLLIDER_H
#define RECT_COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class RectCollider : public Collider {
public:
    sf::FloatRect bounds;

    RectCollider(sf::Vector2f size, sf::Vector2f position);
    
    bool collide(Collider& other) override;
};

#endif