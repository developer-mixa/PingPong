#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StartScreen.hpp"
#include "Engine.hpp"
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define OFFSET_DIVIDER 24
#define FONT_SIZE 24
#define QUIT_BUTTON_MARGIN_BOTTOM 30
#define FONT_OFFSET 10
#define PLAY_TEXT "Play"
#define QUIT_TEXT "Quit"
#define START_SCREEN_PATH "assets/images/start_screen.jpg"
#define FONT_PATH "assets/fonts/Roboto-Black.ttf"
#define START_SOUND "assets/sounds/lee_sound.flac"
#include "TextButton.hpp"
#include "MusicManager.hpp"

using namespace sf;

void StartScreen::initBackground(){
    backgroundTexture.loadFromFile(START_SCREEN_PATH);
    background = Sprite(backgroundTexture);
}

TextButton createButton(const char* text, Color fill, Font& font){
    return TextButton(
        text,
        BUTTON_WIDTH,
        BUTTON_HEIGHT,
        font,
        fill
    );
}

void StartScreen::initStartButton(sf::RenderWindow& window){
    const auto windowSize = window.getSize();
    const int offset = windowSize.x / OFFSET_DIVIDER;

    startButton = createButton(PLAY_TEXT, sf::Color::Green, font);
    startButton.setPosition(windowSize.x-BUTTON_WIDTH-offset, BUTTON_HEIGHT);
    quitButton = createButton(QUIT_TEXT, sf::Color::Red, font);
    sf::Vector2f startButtonPosition = startButton.getPosition();
    quitButton.setPosition(startButtonPosition.x, startButtonPosition.y + BUTTON_HEIGHT + QUIT_BUTTON_MARGIN_BOTTOM);
}

void StartScreen::eventTrigger(sf::Event event, sf::RenderWindow &window){
    if(startButton.isPressed(event, window)){
        Engine::getInstance().setActiveScene(1);
    }

    if(quitButton.isPressed(event, window)){
        window.close();
    }

    if(quitButton.isMouseOver(window)){
        auto windowSize = window.getSize();

        float randomX = static_cast<float>(rand()) / RAND_MAX * (windowSize.x - BUTTON_WIDTH);
        float randomY = static_cast<float>(rand()) / RAND_MAX * (windowSize.y - BUTTON_HEIGHT);
        quitButton.setPosition(randomX, randomY);
    }
}

MusicManager music;

void StartScreen::start(RenderWindow &window){
    font.loadFromFile(FONT_PATH);
    initBackground();
    initStartButton(window);
    fitToScreen(background, window);
    
    music.loadSingleMusic(START_SOUND);
    music.playSingleMusic();
}

void StartScreen::update(RenderWindow &window){
    window.draw(background);
    startButton.draw(window);
    quitButton.draw(window);
}