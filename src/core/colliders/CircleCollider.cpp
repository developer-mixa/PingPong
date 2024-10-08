#include "CircleCollider.hpp"
#include "RectCollider.hpp"

CircleCollider::CircleCollider(float x, float y, float radius)
    : center(x, y), radius(radius) {}

bool CircleCollider::collide(Collider& other) {
    if (auto* other_circle = dynamic_cast<CircleCollider*>(&other)) {
        sf::Vector2f distance = center - other_circle->center;
        return distance.x * distance.x + distance.y * distance.y <= 
               (radius + other_circle->radius) * (radius + other_circle->radius);
    }
    if (auto* other_rect = dynamic_cast<RectCollider*>(&other)) {
        return collidesWithRect(other_rect->bounds);
    }
    return false;
}

bool CircleCollider::collidesWithRect(sf::FloatRect& rect) {
    float dx = std::abs(center.x - rect.left);
    float dy = std::abs(center.y - rect.top);
    
    if (dx > rect.width || dy > rect.height) {
        return false;
    }
    
    float x = std::max(0.f, std::min(dx, rect.width - dx));
    float y = std::max(0.f, std::min(dy, rect.height - dy));
    
    return x <= radius && y <= radius;
}