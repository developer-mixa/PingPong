#include "GameScreen.hpp"

#define GAME_SCREEN_PATH ""

#include "Engine.hpp"
#include "Platform.hpp"

void GameScreen::initBackground(){
    
}

std::vector<Platform*> platforms;

void GameScreen::start(sf::RenderWindow& window){
    platforms = Engine::getInstance().getActiveScene().FindObjectsOfType<Platform>();
    platforms[0]->setY(100);
    platforms[1]->setY(window.getSize().y - 100 - platforms[1]->height);
};

void GameScreen::update(sf::RenderWindow& window){
};