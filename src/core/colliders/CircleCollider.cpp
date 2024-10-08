#include "CircleCollider.hpp"
#include "RectCollider.hpp"
#include <iostream>

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

    auto circlePos = circle->getPosition(); 
    auto rectPos = rectangle.getPosition();
    auto rectBounds = rectangle.getLocalBounds();

    auto x = abs(circlePos.x - rectPos.x);
    auto y = abs(circlePos.y - rectPos.y);
    auto circleRaduis = circle->getRadius();

    if (x > (rectBounds.width/2 + circleRaduis)) { return false; }
    if (y > (rectBounds.height/2 + circleRaduis)) { return false; }

    if (x <= (rectBounds.width/2)) { return true; } 
    if (y <= (rectBounds.height/2)) { return true; }

    auto cornerDistance_sq = (x - rectBounds.width/2)*(x - rectBounds.width/2) +
                         (y - rectBounds.height/2)*(y - rectBounds.height/2);
                         
    auto r2 = circleRaduis*circleRaduis;
    return cornerDistance_sq <= r2;
}