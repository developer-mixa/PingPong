#include "PingPongBall.hpp"
#include <cmath>
#include <cstdlib>
#include <random>

#define _USE_MATH_DEFINES
#define CIRCLE_RADUIS 30
#define MIN_ANGLE 30
#define MAX_ANGLE 150

void PingPongBall::start(sf::RenderWindow& window) {
    const float radius = static_cast<float>(circle.getRadius());
    auto windowSize = window.getSize();
    
    float centerX = static_cast<float>(windowSize.x) / 2;
    float centerY = static_cast<float>(windowSize.y) / 2;
    
    circle.setPosition(centerX - radius, centerY - radius);
    refresh();
}

void PingPongBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circle, states);
};

void PingPongBall::move(){
    auto currentPosition = circle.getPosition();
    circle.setPosition(
        currentPosition.x + (directionIsBottom ? randomAngleX : -randomAngleX),
        currentPosition.y + (directionIsBottom ? randomAngleY : -randomAngleY)
    );
}

int GetRandomNumber(int min, int max)
{
    auto rnd = std::random_device{};
    auto gen = std::mt19937_64{rnd()};
    auto dis = std::uniform_int_distribution<int>{min, max};
    return dis(gen);
}

void PingPongBall::refresh(){
    int randomAngleDegrees = GetRandomNumber(MIN_ANGLE, MAX_ANGLE);
    double randomAngle = randomAngleDegrees * M_PI / 180.0;

    randomAngleX = cos(randomAngle);
    randomAngleY = sin(randomAngle);

    directionIsBottom = rand() % 2 == 0;
}

PingPongBall::PingPongBall(Platform &topPlatform, Platform &bottomPlatform){
    this->topPlatform = &topPlatform;
    this->bottomPlatform = &bottomPlatform;

    circle = sf::CircleShape(CIRCLE_RADUIS);
    circle.setFillColor(sf::Color::White);
}