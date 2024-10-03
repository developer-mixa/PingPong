#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include "UiElement.hpp"
#include <SFML/Graphics.hpp>

class TextButton : UiElement {
private:
    sf::RectangleShape rectangleButton;
    sf::Text buttonText;
public:
    TextButton(
        char* text,
        float width,
        float height,
        sf::Font& font,
        sf::Color fillColor,
        float startPositionX = 0,
        float startPositionY = 0
    );

    TextButton(){};

    void setPosition(float x, float y);
    virtual void draw(sf::RenderWindow &window) override;

    float thickness = 2;
    sf::Color outlineColor = sf::Color::Black;
    int textSize = 24;
    sf::Color textColor = sf::Color::White;

    float textMarginX = 10;
    float textMarginY = 10;
};

#endif