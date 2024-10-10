#include "CircleCollider.hpp"
#include "RectCollider.hpp"
#include <iostream>
#include <cmath>

using namespace std;

CircleCollider::CircleCollider(sf::CircleShape& circle) {
    this->circle = &circle;
}

bool CircleCollider::collide(Collider& other) {
    if (auto* other_circle = dynamic_cast<CircleCollider*>(&other)) {
        sf::Vector2f distance = center - other_circle->center;
        return distance.x * distance.x + distance.y * distance.y <= 
               (radius + other_circle->radius) * (radius + other_circle->radius);
    }
    if (auto* other_rect = dynamic_cast<RectCollider*>(&other)) {
        return collidesWithRect(*other_rect->rectangle);
    }
    return false;
}

bool CircleCollider::collidesWithRect(sf::RectangleShape& rectangle) {
    return rectangle.getGlobalBounds().intersects(circle->getGlobalBounds());
}