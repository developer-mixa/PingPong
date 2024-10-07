#include "PingPongBall.hpp"

void PingPongBall::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(circle, states);
};

void PingPongBall::move(){
    circle.setPosition(circle.getPosition().x+1, circle.getPosition().y+1);
}

PingPongBall::PingPongBall(Platform &topPlatform, Platform &bottomPlatform){
    this->topPlatform = &topPlatform;
    this->bottomPlatform = &bottomPlatform;
    this->circle = sf::CircleShape(15);
    this->circle.setFillColor(sf::Color::White);
}