#include "GameScreen.hpp"

#define GAME_SCREEN_PATH ""

#include "GameObject.hpp"
#include "Platform.hpp"
#include "CountdownDisplay.hpp"
#include "PingPongBall.hpp"
#include "Engine.hpp"
#include <iostream>

#define PLATFORM_OFFSET 100

void GameScreen::start(sf::RenderWindow& window){

    countdownDisplay.reset();

    platforms = GameObject::FindObjectsOfType<Platform>();
    pingPongBall = GameObject::FindObjectOfType<PingPongBall>();

    platforms[0]->setY(PLATFORM_OFFSET);
    platforms[1]->setY(window.getSize().y - PLATFORM_OFFSET - platforms[1]->height);
    
    pingPongBall->setTopCollisionCallback([this](){
        finish();
    });
    pingPongBall->setBottomCollisionCallback([this](){
        finish();
    });

    countdownDisplay.centerByWindow(window);
    countdownDisplay.run();
};

void GameScreen::finish() const {
    Engine::getInstance().setActiveScene(0);
}

void GameScreen::update(sf::RenderWindow& window){
    if(!countdownDisplay.finish) window.draw(countdownDisplay);
    else {
        pingPongBall->move();
        window.draw(*pingPongBall);
    }
};