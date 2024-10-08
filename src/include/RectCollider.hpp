#ifndef RECT_COLLIDER_H
#define RECT_COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class RectCollider : public Collider {
public:
    sf::RectangleShape* rectangle;
    RectCollider(sf::RectangleShape& rectangle);
    
    bool collide(Collider& other) override;
};

#endif