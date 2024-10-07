#include "GameScreen.hpp"

#define GAME_SCREEN_PATH ""

#include "Engine.hpp"
#include "Platform.hpp"
#include "CountdownDisplay.hpp"
#include <iostream>

void GameScreen::initBackground(){
    
}

std::vector<Platform*> platforms;
CountdownDisplay countdownDisplay("assets/fonts/Roboto-Black.ttf");    

void GameScreen::start(sf::RenderWindow& window){
    platforms = Engine::getInstance().getActiveScene().FindObjectsOfType<Platform>();
    platforms[0]->setY(100);
    platforms[1]->setY(window.getSize().y - 100 - platforms[1]->height);
    
    countdownDisplay.centerByWindow(window);
    countdownDisplay.run([](){
        
    });
};

void GameScreen::update(sf::RenderWindow& window){
    if(!countdownDisplay.finish)window.draw(countdownDisplay);
};