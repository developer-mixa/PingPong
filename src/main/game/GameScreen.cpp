#include "GameScreen.hpp"

#define GAME_SCREEN_PATH ""

void GameScreen::initBackground(){
    //backgroundTexture.loadFromFile(GAME_SCREEN_PATH);
    //background = sf::Sprite(backgroundTexture);
}

void GameScreen::start(sf::RenderWindow& window){
    initBackground();
    fitToScreen(background, window);
};

void GameScreen::update(sf::RenderWindow& window){
    //window.draw(background);
};