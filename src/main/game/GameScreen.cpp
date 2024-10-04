#include "GameScreen.hpp"

#define GAME_SCREEN_PATH ""

#include "Engine.hpp"
#include "Platform.hpp"

void GameScreen::initBackground(){
    
}

Platform* platform = nullptr;

void GameScreen::start(sf::RenderWindow& window){
    platform = Engine::getInstance().getActiveScene().FindObjectOfType<Platform>();
};

void GameScreen::update(sf::RenderWindow& window){
};