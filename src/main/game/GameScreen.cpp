#include "GameScreen.hpp"

#define LOOSE_SOUND_PATH "assets/sounds/finish_sound.flac"

#include "GameObject.hpp"
#include "Platform.hpp"
#include "CountdownDisplay.hpp"
#include "PingPongBall.hpp"
#include "Engine.hpp"
#include <iostream>
#include <SFML/Audio.hpp>
#include "MusicManager.hpp"

#define PLATFORM_OFFSET 100

MusicManager gameMusic;

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

    gameMusic.loadSingleMusic(LOOSE_SOUND_PATH);
};

void GameScreen::finish() const {
    Engine::getInstance().setActiveScene(0);
    gameMusic.playSingleMusic();
}

void GameScreen::eventTrigger(Event event, RenderWindow &window){
    if (event.type == sf::Event::Resized) {
        window.setView(sf::View(sf::FloatRect(0, 0, event.size.width, event.size.height)));
        platforms[1]->setY(window.getSize().y - PLATFORM_OFFSET - platforms[1]->height);
    }
}

void GameScreen::update(sf::RenderWindow& window){
    if(!countdownDisplay.finish) window.draw(countdownDisplay);
    else {
        pingPongBall->move();
        window.draw(*pingPongBall);
    }
};