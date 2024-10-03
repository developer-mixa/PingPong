#ifndef UI_ELEMENT_H
#define UI_ELEMENT_H

#include <SFML/Graphics.hpp>

class UiElement{
public:
    virtual void draw(sf::RenderWindow &window) = 0;
    virtual ~UiElement() = default;
};

#endif