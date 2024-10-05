#ifndef COUNTDOWN_DISPLAY_H
#define COUNTDOWN_DISPLAY_H

#include <SFML/Graphics.hpp>

class CountdownDisplay : public sf::Drawable {
private:
    sf::Font font;
    int count;
    sf::Text text;
public:
    CountdownDisplay(const std::string& fontPath, int startCount=3);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(text, states);
    }
    void doRun();

    void centerByWindow(sf::RenderWindow& window);

    void run();
};

#endif