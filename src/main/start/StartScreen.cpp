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

void StartScreen::initBackground(){

    backgroundTexture.loadFromFile(START_SCREEN_PATH);
    background = sf::Sprite(backgroundTexture);
}

void StartScreen::initStartButton(sf::RenderWindow& window){
    const auto windowSize = window.getSize();
    const int offset = windowSize.x / OFFSET_DIVIDER;

    startButton = sf::RectangleShape(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    buttonTextStart = sf::Text(PLAY_TEXT, font, FONT_SIZE);
    startButton.setFillColor(sf::Color::Green);
    startButton.setOutlineThickness(2);
    startButton.setOutlineColor(sf::Color::Black);
    buttonTextStart.setCharacterSize(FONT_SIZE);
    buttonTextStart.setFillColor(sf::Color::White);
    startButton.setPosition(windowSize.x-BUTTON_WIDTH-offset, BUTTON_HEIGHT);
    buttonTextStart.setPosition(startButton.getPosition().x + FONT_OFFSET, startButton.getPosition().y + FONT_OFFSET);
}

void StartScreen::start(sf::RenderWindow &window){
    font.loadFromFile(FONT_PATH);
    initBackground();
    initStartButton(window);
    fitToScreen(background, window);
}

void StartScreen::update(sf::RenderWindow &window){
    window.draw(background);
    window.draw(startButton);
    window.draw(buttonTextStart);
}