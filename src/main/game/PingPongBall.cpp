#include "PingPongBall.hpp"

#define CIRCLE_RADUIS 30

void PingPongBall::start(sf::RenderWindow& window) {
    const float radius = static_cast<float>(circle.getRadius());
    auto windowSize = window.getSize();
    
    float centerX = static_cast<float>(windowSize.x) / 2;
    float centerY = static_cast<float>(windowSize.y) / 2;
    
    circle.setPosition(centerX - radius, centerY - radius);
}

void PingPongBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circle, states);
};

void PingPongBall::move(){
    circle.setPosition(circle.getPosition().x+1, circle.getPosition().y+1);
}

PingPongBall::PingPongBall(Platform &topPlatform, Platform &bottomPlatform){
    this->topPlatform = &topPlatform;
    this->bottomPlatform = &bottomPlatform;

    circle = sf::CircleShape(CIRCLE_RADUIS);
    circle.setFillColor(sf::Color::White);
}