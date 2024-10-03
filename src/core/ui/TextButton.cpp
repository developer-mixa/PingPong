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
bool TextButton::isPressed (const sf::Event event, sf::RenderWindow &window) {
    if (event.type != sf::Event::MouseButtonPressed || event.mouseButton.button != sf::Mouse::Left) {
        return false;
    }

    sf::Vector2i mousePos = sf::Mouse::getPosition(window);

    sf::Vector2f buttonPos = rectangleButton.getPosition();

    return
        mousePos.x > buttonPos.x &&
        mousePos.x < buttonPos.x + rectangleButton.getSize().x &&
        mousePos.y > buttonPos.y &&
        mousePos.y < buttonPos.y + rectangleButton.getSize().y;
}