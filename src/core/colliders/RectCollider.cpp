#include "RectCollider.hpp"
#include "CircleCollider.hpp"

RectCollider::RectCollider(sf::Vector2f size, sf::Vector2f position)
    : bounds(position, size) {}

bool RectCollider::collide(Collider& other) {
    if (auto* other_rect = dynamic_cast<RectCollider*>(&other)) {
        return bounds.intersects(other_rect->bounds);
    }
    if (auto* circle = dynamic_cast<CircleCollider*>(&other)) {
        return circle->collidesWithRect(bounds);
    }
    return false;
}