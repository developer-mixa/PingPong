#include "Platform.hpp"
#include "RectCollider.hpp"
#include "PlatformMovingType.hpp"

using namespace sf;
using namespace std;

Platform::Platform(
    Keyboard::Key leftMoveCode,
    Keyboard::Key rightMoveCode
) : RectCollider(rectanglePlatform) {
    this->leftMoveCode = leftMoveCode;
    this->rightMoveCode = rightMoveCode;
}

void Platform::setY(float height){
    this->y = height;
}

void Platform::start(RenderWindow &window){
    movingType = PlatrormMovingType::IDLE;
    moveLeft = false;
    moveRight = false;
    rectanglePlatform = RectangleShape(Vector2f(200, height));
    rectanglePlatform.setFillColor(Color::White);
    rectanglePlatform.setPosition(window.getSize().x / 2 - rectanglePlatform.getSize().x / 2, y);
}

void Platform::goLeft(RenderWindow &window){
    Vector2f currentPosition = rectanglePlatform.getPosition();
    movingType = PlatrormMovingType::LEFT;
    auto newPosition = max(0.f, currentPosition.x - speed);
    rectanglePlatform.setPosition(newPosition, currentPosition.y);
}

void Platform::goRight(RenderWindow &window){
    Vector2f currentPosition = rectanglePlatform.getPosition();
    movingType = PlatrormMovingType::RIGHT;
    auto newPosition = min((float)window.getSize().x - rectanglePlatform.getSize().x, currentPosition.x + speed);
    rectanglePlatform.setPosition(newPosition, currentPosition.y);
}

PlatrormMovingType Platform::getMovingType() const {
    return movingType;
}

void Platform::eventTrigger(Event event, RenderWindow &window){
    switch (event.type)
    {
        case Event::KeyPressed:
            if(event.key.code == leftMoveCode) moveLeft = true;
            else if(event.key.code == rightMoveCode) moveRight = true;
            break;
        case Event::KeyReleased:
            if(event.key.code == leftMoveCode) moveLeft = false;
            else if(event.key.code == rightMoveCode) moveRight = false;
            break;
    }
}

void Platform::update(RenderWindow &window){
    if(moveLeft) goLeft(window);
    else if(moveRight) goRight(window);
    else movingType = PlatrormMovingType::IDLE;
    setPosition(rectanglePlatform.getPosition());
    window.draw(rectanglePlatform);
}