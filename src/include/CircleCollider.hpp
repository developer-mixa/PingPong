#ifndef CIRCLE_COLLIDER_H
#define CIRCLE_COLLIDER_H

#include <SFML/Graphics.hpp>
#include "Collider.hpp"

using namespace sf;

class CircleCollider : public Collider {
public:
    CircleShape* circle;
    CircleCollider(CircleShape& circle);
    
    bool collide(Collider &other) override;
    bool collidesWithRect(RectangleShape& rectangle) const;

private:
    Vector2f center;
    float radius;
};

#endif