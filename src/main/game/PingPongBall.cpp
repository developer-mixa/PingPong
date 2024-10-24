#include "PingPongBall.hpp"
#include <cmath>
#include <cstdlib>
#include <random>
#include "CircleCollider.hpp"
#include "RectCollider.hpp"
#include "CollisionType.hpp"
#include "PlatformMovingType.hpp"
#include <SFML/Audio.hpp>
#include "MusicManager.hpp"

#define _USE_MATH_DEFINES
#define CIRCLE_RADUIS 30
#define MIN_ANGLE 30
#define MAX_SPEED 10.f
#define MIN_SPEED 2.f
#define MAX_ANGLE 150

#define PING_PONG_SOUNDS_PATH "assets/sounds/ping_pong"

using namespace sf;
using namespace std;

MusicManager musicManager;

void PingPongBall::start(RenderWindow& window) {

    const float radius = static_cast<float>(circle.getRadius());
    auto windowSize = window.getSize();
    this->window = &window;

    speed = MIN_SPEED;
    
    float centerX = static_cast<float>(windowSize.x) / 2;
    float centerY = static_cast<float>(windowSize.y) / 2;
    
    circle.setPosition(centerX - radius, centerY - radius);
    randomRefresh();
    musicManager.loadMusics(PING_PONG_SOUNDS_PATH);
}

void PingPongBall::draw(RenderTarget& target, RenderStates states) const {
    target.draw(circle, states);
};

void PingPongBall::setTopCollisionCallback(function<void()> callback){
    topCollisionCallback = callback;
}

void PingPongBall::setBottomCollisionCallback(function<void()> callback){
    bottomCollisionCallback = callback;
}

void PingPongBall::move(){
    auto currentPosition = circle.getPosition();

    auto windowSize = window->getSize();

    bool collideLeftWall = currentPosition.x <= 0;
    bool collideRightWall = currentPosition.x + CIRCLE_RADUIS >= windowSize.x;
    bool collideTopWall = currentPosition.y <= 0;
    bool collideBottomWall = currentPosition.y + CIRCLE_RADUIS >= windowSize.y;
    bool colliideBottomPlatform = collide(*bottomPlatform);
    bool colliideTopPlatform = collide(*topPlatform);

    if (collideRightWall || collideLeftWall) {
        velocity.x *= -1;
        velocity.y *= -1;
    }

    if(collideTopWall && topCollisionCallback) topCollisionCallback();
    if(collideBottomWall && bottomCollisionCallback) bottomCollisionCallback();

    if(colliideBottomPlatform) handlePlatformCollision(bottomPlatform);
    if(colliideTopPlatform) handlePlatformCollision(topPlatform);

    if(
        checkAndSetLastTouch(colliideBottomPlatform, CollisionType::PLAYER_1) ||
        checkAndSetLastTouch(colliideTopPlatform, CollisionType::PLAYER_2) ||
        checkAndSetLastTouch(collideLeftWall, CollisionType::LEFT_SIDE) ||
        checkAndSetLastTouch(collideRightWall, CollisionType::RIGHT_SIDE) ||
        checkAndSetLastTouch(collideTopWall, CollisionType::TOP_SIDE) ||
        checkAndSetLastTouch(collideBottomWall, CollisionType::BOTTOM_SIDE)
    ){
        refresh();
    }

    circle.setPosition(
        clamp(currentPosition.x + velocity.x * speed, 0.F, (float) windowSize.x - CIRCLE_RADUIS),
        clamp(currentPosition.y + velocity.y * speed, 0.F, (float) windowSize.y - CIRCLE_RADUIS)
    );
}

void PingPongBall::handlePlatformCollision(Platform* platform) {
    auto ballVelocityX = velocity.x;
    auto platformMovingType = platform->getMovingType();
    float angle = cos(platform->speed * M_PI / 180.0);
    if(
        (platformMovingType == PlatrormMovingType::RIGHT && ballVelocityX < 0) ||
        (platformMovingType == PlatrormMovingType::LEFT && ballVelocityX >= 0)){
        velocity.x *= -angle;
    } else {
        velocity.x *= angle;
    }
}

bool PingPongBall::checkAndSetLastTouch(bool collideValue, CollisionType checkCollisionType){
    bool result = collideValue && lastTouch != checkCollisionType;
    if(collideValue) lastTouch = checkCollisionType;
    if(result) speed = min(speed + 1, MAX_SPEED);
    return result;
}


float PingPongBall::calculateAngle() const {
    float angle = atan2(-velocity.y, velocity.x) * 180 / M_PI;
    if (angle < 0.f)
        angle += 360.f;
    return angle;
}

int PingPongBall::getRandomAngles(int min, int max) const{
    auto rnd = std::random_device{};
    auto gen = std::mt19937_64{rnd()};
    auto dis = std::uniform_int_distribution<int>{min, max};
    return dis(gen);
}

void PingPongBall::randomRefresh(){
    int randomAngleDegrees = getRandomAngles(MIN_ANGLE, MAX_ANGLE);
    angle = randomAngleDegrees * M_PI / 180.0;

    float sideFactor = (rand() % 2 == 0) ? 1 : -1;

    velocity.x = cos(angle) * sideFactor;
    velocity.y = sin(angle) * sideFactor;
}


void PingPongBall::refresh(){
    angle = calculateAngle();
    velocity.x = cos(angle * M_PI / 180);
    velocity.y = sin(angle * M_PI / 180);
    musicManager.playRandomMusic();
}

PingPongBall::PingPongBall(Platform &topPlatform, Platform &bottomPlatform) : CircleCollider(circle) {
    this->topPlatform = &topPlatform;
    this->bottomPlatform = &bottomPlatform;

    circle = CircleShape(CIRCLE_RADUIS);
    circle.setFillColor(Color::White);
}