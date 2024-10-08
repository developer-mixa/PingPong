#include "RectCollider.hpp"
#include "CircleCollider.hpp"

#include <iostream>

RectCollider::RectCollider(sf::RectangleShape& rectangle) {
    this->rectangle = &rectangle;
}

bool RectCollider::collide(Collider& other) {
    if (auto* other_rect = dynamic_cast<RectCollider*>(&other)) {
        return false;
    }

    if (auto* circle = dynamic_cast<CircleCollider*>(&other)) {
        return circle->collidesWithRect(*this->rectangle);
    }
    
    return false;
}