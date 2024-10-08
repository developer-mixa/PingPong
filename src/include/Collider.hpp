#ifndef COLLIDER_H
#define COLLIDER_H

class Collider{
public:
    virtual bool collide(Collider &other) = 0;
    virtual ~Collider() = default;
};

#endif