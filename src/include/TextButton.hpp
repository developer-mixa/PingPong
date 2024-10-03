#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include "UiElement.hpp"
#include <SFML/Graphics.hpp>

class TextButton : UiElement {
private:
    sf::RectangleShape rectangleButton;
    sf::Text buttonText;
    bool mouseInButton(sf::RenderWindow &window);
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

    sf::Vector2f getPosition();
    void setPosition(float x, float y);
    virtual void draw(sf::RenderWindow &window) override;
    bool isPressed(sf::Event event, sf::RenderWindow &window);
    bool isMouseOver(sf::Event event, sf::RenderWindow &window);

    float thickness = 2;
    sf::Color outlineColor = sf::Color::Black;
    int textSize = 24;
    sf::Color textColor = sf::Color::White;

    float textMarginX = 10;
    float textMarginY = 10;
};

#endif