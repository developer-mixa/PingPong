#include "Platform.hpp"
#include "RectCollider.hpp"

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
    movingLeft = false;
    movingRight = false;
    rectanglePlatform = RectangleShape(Vector2f(200, height));
    rectanglePlatform.setFillColor(Color::White);
    rectanglePlatform.setPosition(window.getSize().x / 2 - rectanglePlatform.getSize().x / 2, y);
}

void Platform::goLeft(RenderWindow &window){
    Vector2f currentPosition = rectanglePlatform.getPosition();
    auto newPosition = max(0.f, currentPosition.x - speed);
    velocity = Vector2f(newPosition, currentPosition.y);
    rectanglePlatform.setPosition(velocity);
}

void Platform::goRight(RenderWindow &window){
    Vector2f currentPosition = rectanglePlatform.getPosition();
    auto newPosition = min((float)window.getSize().x - rectanglePlatform.getSize().x, currentPosition.x + speed);
    velocity = Vector2f(newPosition, currentPosition.y);
    rectanglePlatform.setPosition(velocity);
}

Vector2f Platform::getVelocity(){
    return velocity;
}

void Platform::eventTrigger(Event event, RenderWindow &window){
    switch (event.type)
    {
        case Event::KeyPressed:
            if(event.key.code == leftMoveCode) movingLeft = true;
            else if(event.key.code == rightMoveCode) movingRight = true;
            break;
        case Event::KeyReleased:
            if(event.key.code == leftMoveCode) movingLeft = false;
            else if(event.key.code == rightMoveCode) movingRight = false;
            break;
    }
}

void Platform::update(RenderWindow &window){
    if(movingLeft) goLeft(window);
    if(movingRight) goRight(window);
    setPosition(rectanglePlatform.getPosition());
    window.draw(rectanglePlatform);
}