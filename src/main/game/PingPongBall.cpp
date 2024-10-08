#include "PingPongBall.hpp"
#include <cmath>
#include <cstdlib>
#include <random>
#include "CircleCollider.hpp"
#include "RectCollider.hpp"

#define _USE_MATH_DEFINES
#define CIRCLE_RADUIS 30
#define MIN_ANGLE 30
#define SPEED 2
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

    if((directionIsBottom && collide(*bottomPlatform)) || (!directionIsBottom && collide(*topPlatform))) {
        refresh();
    }

    auto windowSize = window->getSize();

    if(currentPosition.x <= 0 || currentPosition.x >= windowSize.x || currentPosition.y <= 0 || currentPosition.y >= windowSize.y){
        refresh();
    }

    circle.setPosition(
        currentPosition.x + (directionIsBottom ? randomAngleX : -randomAngleX) * SPEED,
        currentPosition.y + (directionIsBottom ? randomAngleY : -randomAngleY) * SPEED
    );
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
    double randomAngle = randomAngleDegrees * M_PI / 180.0;

    randomAngleX = cos(randomAngle);
    randomAngleY = sin(randomAngle);

    directionIsBottom = rand() % 2 == 0;
}

void PingPongBall::refresh(){
    int randomAngleDegrees = GetRandomNumber(MIN_ANGLE, MAX_ANGLE);
    double randomAngle = randomAngleDegrees * M_PI / 180.0;

    randomAngleX = cos(randomAngle);
    randomAngleY = sin(randomAngle);

    directionIsBottom = !directionIsBottom;
}

PingPongBall::PingPongBall(Platform &topPlatform, Platform &bottomPlatform) : CircleCollider(circle) {
    this->topPlatform = &topPlatform;
    this->bottomPlatform = &bottomPlatform;

    circle = sf::CircleShape(CIRCLE_RADUIS);
    circle.setFillColor(sf::Color::White);
}