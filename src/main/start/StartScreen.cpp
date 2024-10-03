#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StartScreen.hpp"

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50
#define OFFSET_DIVIDER 24
#define FONT_SIZE 24
#define FONT_OFFSET 10
#define PLAY_TEXT "Play"
#define START_SCREEN_PATH "assets/images/start_screen.jpg"
#define FONT_PATH "assets/fonts/Roboto-Black.ttf"
#include "TextButton.hpp"

void StartScreen::initBackground(){

    backgroundTexture.loadFromFile(START_SCREEN_PATH);
    background = sf::Sprite(backgroundTexture);
}

void StartScreen::initStartButton(sf::RenderWindow& window){
    const auto windowSize = window.getSize();
    const int offset = windowSize.x / OFFSET_DIVIDER;

    startButton = TextButton(
        PLAY_TEXT,
        BUTTON_WIDTH,
        BUTTON_HEIGHT,
        font,
        sf::Color::Green,
        windowSize.x-BUTTON_WIDTH-offset,
        BUTTON_HEIGHT
    );
}

void StartScreen::eventTrigger(sf::Event event, sf::RenderWindow &window){
    if(startButton.isPressed(event, window)){
        // Turn on new scene
    }
}

void StartScreen::start(sf::RenderWindow &window){
    font.loadFromFile(FONT_PATH);
    initBackground();
    initStartButton(window);
    fitToScreen(background, window);
}

void StartScreen::update(sf::RenderWindow &window){
    window.draw(background);
    startButton.draw(window);
}