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

sf::Vector2f TextButton::getPosition(){
    return rectangleButton.getPosition();
}

void TextButton::draw(sf::RenderWindow &window){
    window.draw(rectangleButton);
    window.draw(buttonText);
}

bool TextButton::mouseInButton(sf::RenderWindow &window){
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    return rectangleButton.getGlobalBounds().contains(mousePos.x, mousePos.y);
}

bool TextButton::isPressed(const sf::Event event, sf::RenderWindow &window) {
    if (event.type != sf::Event::MouseButtonPressed || event.mouseButton.button != sf::Mouse::Left) {
        return false;
    }
    return mouseInButton(window);
}

bool TextButton::isMouseOver(const sf::Event event, sf::RenderWindow &window) {
    return mouseInButton(window);
}