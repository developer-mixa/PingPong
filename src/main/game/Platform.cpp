#include "Platform.hpp"

Platform::Platform(sf::Keyboard::Key leftMoveCode, sf::Keyboard::Key rightMoveCode){
    this->leftMoveCode = leftMoveCode;
    this->rightMoveCode = rightMoveCode;
}

void Platform::start(sf::RenderWindow &window){
    rectanglePlatform = sf::RectangleShape(sf::Vector2f(100, 100));
    rectanglePlatform.setFillColor(sf::Color::White);
    rectanglePlatform.setPosition(100, 100);
    std::cout << "start";
}

void Platform::goLeft(sf::RenderWindow &window){
    sf::Vector2f currentPosition = rectanglePlatform.getPosition();
    rectanglePlatform.setPosition(currentPosition.x - speed, currentPosition.y);
}

void Platform::goRight(sf::RenderWindow &window){
    sf::Vector2f currentPosition = rectanglePlatform.getPosition();
    rectanglePlatform.setPosition(currentPosition.x + speed, currentPosition.y);
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