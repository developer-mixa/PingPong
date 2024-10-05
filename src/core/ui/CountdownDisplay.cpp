#include "CountdownDisplay.hpp"
#include <iostream>
#include <future>
#include <thread>

CountdownDisplay::CountdownDisplay(const std::string& fontPath, int startCount){
    font.loadFromFile(fontPath);
    count = startCount;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setOutlineColor(sf::Color::Black);
    text.setOutlineThickness(2);
}

void CountdownDisplay::doRun(){
    while (count > 0)
    {
        text.setString(std::to_string(count));
        sf::sleep(sf::milliseconds(1000));
        count -= 1;
    }
    text.setString("");
}

void CountdownDisplay::centerByWindow(sf::RenderWindow& window){
    auto windowSize = window.getSize();
    auto bounds = text.getLocalBounds();
    
    text.setPosition(
        windowSize.x / 2 + bounds.width,

        // i dont know why it does not work
        windowSize.y / 2 - bounds.height
    );
}

void CountdownDisplay::run(){
    std::future<void> * f = new std::future<void>(std::async(std::launch::async, &CountdownDisplay::doRun, this));
}