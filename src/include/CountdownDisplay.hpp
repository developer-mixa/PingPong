#ifndef COUNTDOWN_DISPLAY_H
#define COUNTDOWN_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

class CountdownDisplay : public sf::Drawable {
private:
    sf::Font font;
    int count;
    sf::Text text;
public:
    bool finish = false;
    std::thread countdownThread;
    CountdownDisplay(const std::string& fontPath, int startCount=3);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(text, states);
    }
    void centerByWindow(sf::RenderWindow& window);
    void doRun();
    void run();
};

#endif