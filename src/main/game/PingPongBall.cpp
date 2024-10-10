#include "PingPongBall.hpp"
#include <cmath>
#include <cstdlib>
#include <random>
#include "CircleCollider.hpp"
#include "RectCollider.hpp"
#include "CollisionType.hpp"

#define _USE_MATH_DEFINES
#define CIRCLE_RADUIS 30
#define MIN_ANGLE 30
#define MAX_SPEED 10.f
#define MAX_ANGLE 150

void PingPongBall::start(sf::RenderWindow& window) {

    const float radius = static_cast<float>(circle.getRadius());
    auto windowSize = window.getSize();
    this->window = &window;
    
    float centerX = static_cast<float>(windowSize.x) / 2;
    float centerY = static_cast<float>(windowSize.y) / 2;
    
    circle.setPosition(centerX - radius, centerY - radius);
    randomRefresh();
}

void PingPongBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circle, states);
};

void PingPongBall::move(){
    auto currentPosition = circle.getPosition();
    setPosition(currentPosition);

    auto windowSize = window->getSize();

    bool collideLeftWall = currentPosition.x <= 0;
    bool collideRightWall = currentPosition.x + CIRCLE_RADUIS >= windowSize.x;
    bool collideTopWall = currentPosition.y <= 0;
    bool collideBottomWall = currentPosition.y + CIRCLE_RADUIS >= windowSize.y;

    if (collideRightWall || collideLeftWall) {
        velocity.x *= -1;
        velocity.y *= -1;
    }
    
    if(
        checkAndSetLastTouch(collide(*bottomPlatform), CollisionType::PLAYER_1) ||
        checkAndSetLastTouch(collide(*topPlatform), CollisionType::PLAYER_2) ||
        checkAndSetLastTouch(collideLeftWall, CollisionType::LEFT_SIDE) ||
        checkAndSetLastTouch(collideRightWall, CollisionType::RIGHT_SIDE) ||
        checkAndSetLastTouch(collideTopWall, CollisionType::TOP_SIDE) ||
        checkAndSetLastTouch(collideBottomWall, CollisionType::BOTTOM_SIDE)
    ){
        refresh();
    }

    circle.setPosition(velocity.x * speed + currentPosition.x, velocity.y * speed + currentPosition.y);
}

bool PingPongBall::checkAndSetLastTouch(bool collideValue, CollisionType checkCollisionType){
    bool result = collideValue && lastTouch != checkCollisionType;
    if(collideValue) lastTouch = checkCollisionType;
    if(result) speed = std::min(speed + 1, MAX_SPEED);
    return result;
}


float PingPongBall::calculateAngle()
{
    float angle = std::atan2(-velocity.y, velocity.x) * 180 / M_PI;
    if (angle < 0.f)
        angle += 360.f;
    return angle;
}

int GetRandomNumber(int min, int max)
{
    auto rnd = std::random_device{};
    auto gen = std::mt19937_64{rnd()};
    auto dis = std::uniform_int_distribution<int>{min, max};
    return dis(gen);
}

void PingPongBall::randomRefresh(){
    int randomAngleDegrees = GetRandomNumber(MIN_ANGLE, MAX_ANGLE);
    angle = randomAngleDegrees * M_PI / 180.0;

    float sideFactor = (rand() % 2 == 0) ? 1 : -1;

    velocity.x = cos(angle) * sideFactor;
    velocity.y = sin(angle) * sideFactor;
}


void PingPongBall::refresh(){
    angle = calculateAngle();
    velocity.x = std::cos(angle * M_PI / 180);
    velocity.y = std::sin(angle * M_PI / 180);
}

PingPongBall::PingPongBall(Platform &topPlatform, Platform &bottomPlatform) : CircleCollider(circle) {
    this->topPlatform = &topPlatform;
    this->bottomPlatform = &bottomPlatform;

    circle = sf::CircleShape(CIRCLE_RADUIS);
    circle.setFillColor(sf::Color::White);
}