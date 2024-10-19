#include "CountdownDisplay.hpp"
#include <iostream>
#include <future>
#include <thread>

#define TEXT_SIZE 50

CountdownDisplay::CountdownDisplay(const std::string& fontPath, int startCount){
    font.loadFromFile(fontPath);
    initialCount = startCount;
    count = startCount;
    text.setFont(font);
    text.setCharacterSize(TEXT_SIZE);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
}

void CountdownDisplay::reset(){
    finish = false;
    count = initialCount;
}

void CountdownDisplay::doRun(){
    while (count > 0)
    {
        text.setString(std::to_string(count));
        sf::sleep(sf::milliseconds(1000));
        count -= 1;
    }
    finish = true;
}

void CountdownDisplay::centerByWindow(sf::RenderWindow const &window){
    auto windowSize = window.getSize();
    text.setPosition(windowSize.x / 2, windowSize.y / 2 - TEXT_SIZE);
}

void CountdownDisplay::draw(RenderTarget& target, RenderStates states) const {
    target.draw(text, states);
}

void CountdownDisplay::run(){
    countdownThread = std::thread(&CountdownDisplay::doRun, this);
    countdownThread.detach();
}