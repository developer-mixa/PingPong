#include "TextButton.hpp"


TextButton::TextButton(
    char* text,
    float width,
    float height,
    sf::Font& font,
    sf::Color fillColor,
    float startPositionX,
    float startPositionY
){

    rectangleButton = sf::RectangleShape(sf::Vector2f(width, height));
    buttonText = sf::Text(text, font);
    rectangleButton.setFillColor(fillColor);
    rectangleButton.setOutlineThickness(thickness);
    rectangleButton.setOutlineColor(outlineColor);

    buttonText.setCharacterSize(textSize);
    buttonText.setFillColor(sf::Color::White);

    setPosition(startPositionX, startPositionY);
}

void TextButton::setPosition(float x, float y){
    rectangleButton.setPosition(x, y);
    sf::Vector2f buttonPosition = rectangleButton.getPosition();
    buttonText.setPosition(buttonPosition.x, buttonPosition.y);
}

void TextButton::draw(sf::RenderWindow &window){
    window.draw(rectangleButton);
    window.draw(buttonText);
}