#include "Platform.hpp"

Platform::Platform(sf::Keyboard::Key leftMoveCode, sf::Keyboard::Key rightMoveCode){
    this->leftMoveCode = leftMoveCode;
    this->rightMoveCode = rightMoveCode;
}

void Platform::start(sf::RenderWindow &window){
    rectanglePlatform = sf::RectangleShape(sf::Vector2f(200, 50));
    rectanglePlatform.setFillColor(sf::Color::White);
    rectanglePlatform.setPosition(window.getSize().x / 2 - rectanglePlatform.getSize().x / 2, 100);
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
    if(event.type == sf::Event::KeyPressed){
        if(event.key.code == leftMoveCode) goLeft(window);
        else if(event.key.code == rightMoveCode) goRight(window);
    }
}

void Platform::update(sf::RenderWindow &window){
    window.draw(rectanglePlatform);
}