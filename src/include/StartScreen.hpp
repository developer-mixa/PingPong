#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextButton.hpp"

using namespace sf;

class StartScreen : public MonoBehavior {
private:
    void initBackground();
    void initStartButton(RenderWindow& window);
    Sprite background;
    Texture backgroundTexture;
    TextButton startButton;
    TextButton quitButton;
    Font font;

public:
    StartScreen() {};
    void update(RenderWindow& window) override;
    void start(RenderWindow& window) override;
    void eventTrigger(Event event, RenderWindow &window) override;
};

#endif