#include "GameScreen.hpp"

#define GAME_SCREEN_PATH ""

#include "GameObject.hpp"
#include "Platform.hpp"
#include "CountdownDisplay.hpp"
#include "PingPongBall.hpp"
#include "Engine.hpp"
#include <iostream>

void GameScreen::initBackground(){
    
} 

void GameScreen::start(sf::RenderWindow& window){

    countdownDisplay.reset();

    platforms = GameObject::FindObjectsOfType<Platform>();
    pingPongBall = GameObject::FindObjectOfType<PingPongBall>();

    platforms[0]->setY(100);
    platforms[1]->setY(window.getSize().y - 100 - platforms[1]->height);
    
    pingPongBall->setTopCollisionCallback([](){
        Engine::getInstance().setActiveScene(0);
    });
    pingPongBall->setBottomCollisionCallback([](){
        Engine::getInstance().setActiveScene(0);
    });

    countdownDisplay.centerByWindow(window);
    countdownDisplay.run();
};

void GameScreen::update(sf::RenderWindow& window){
    if(!countdownDisplay.finish) window.draw(countdownDisplay);
    else {
        pingPongBall->move();
        window.draw(*pingPongBall);
    }
};