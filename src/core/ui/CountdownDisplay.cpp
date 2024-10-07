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

void CountdownDisplay::doRun(std::function<void()> finishCallback){
    while (count > 0)
    {
        text.setString(std::to_string(count));
        sf::sleep(sf::milliseconds(1000));
        count -= 1;
    }
    finishCallback();
    finish = true;
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

void CountdownDisplay::run(std::function<void()> finishCallback){
    countdownThread = std::thread(&CountdownDisplay::doRun, this, finishCallback);
    countdownThread.detach();
}