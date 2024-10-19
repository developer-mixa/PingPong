#include "CircleCollider.hpp"
#include "RectCollider.hpp"
#include <iostream>
#include <cmath>

using namespace std;

CircleCollider::CircleCollider(sf::CircleShape& circle) {
    this->circle = &circle;
}

bool CircleCollider::collide(Collider &other) {
    if (auto* other_circle = dynamic_cast<CircleCollider*>(&other)) {
        return other_circle->circle->getGlobalBounds().intersects(circle->getGlobalBounds());
    }
    if (auto* other_rect = dynamic_cast<RectCollider*>(&other)) {
        return collidesWithRect(*other_rect->rectangle);
    }
    return false;
}

bool CircleCollider::collidesWithRect(sf::RectangleShape& rectangle) const {
    return rectangle.getGlobalBounds().intersects(circle->getGlobalBounds());
}