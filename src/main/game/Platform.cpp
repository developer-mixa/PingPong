#include "Platform.hpp"

Platform::Platform(sf::Keyboard::Key leftMoveCode, sf::Keyboard::Key rightMoveCode){
    this->leftMoveCode = leftMoveCode;
    this->rightMoveCode = rightMoveCode;
}

void Platform::setY(float height){
    this->y = height;
}

void Platform::start(sf::RenderWindow &window){
    rectanglePlatform = sf::RectangleShape(sf::Vector2f(200, height));
    rectanglePlatform.setFillColor(sf::Color::White);
    rectanglePlatform.setPosition(window.getSize().x / 2 - rectanglePlatform.getSize().x / 2, y);
}

void Platform::goLeft(sf::RenderWindow &window){
    sf::Vector2f currentPosition = rectanglePlatform.getPosition();
    auto newPosition = std::max(0.f, currentPosition.x - speed);
    rectanglePlatform.setPosition(newPosition, currentPosition.y);
}

void Platform::goRight(sf::RenderWindow &window){
    sf::Vector2f currentPosition = rectanglePlatform.getPosition();
    auto newPosition = std::min((float)window.getSize().x - rectanglePlatform.getSize().x, currentPosition.x + speed);
    rectanglePlatform.setPosition(newPosition, currentPosition.y);
}

void Platform::eventTrigger(sf::Event event, sf::RenderWindow &window){
    switch (event.type)
    {
    case sf::Event::KeyPressed:
        if(event.key.code == leftMoveCode) movingLeft = true;
        else if(event.key.code == rightMoveCode) movingRight = true;
        break;
    case sf::Event::KeyReleased:
        if(event.key.code == leftMoveCode) movingLeft = false;
        else if(event.key.code == rightMoveCode) movingRight = false;
        break;
    }
}

void Platform::update(sf::RenderWindow &window){
    if(movingLeft) goLeft(window);
    if(movingRight) goRight(window);
    window.draw(rectanglePlatform);
}