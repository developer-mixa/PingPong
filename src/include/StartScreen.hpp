#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "TextButton.hpp"

class StartScreen : public MonoBehavior {
private:
    void initBackground();
    void initStartButton(sf::RenderWindow& window);
    void initQuitButton();
    sf::CircleShape shape; 
    sf::Sprite background;
    sf::Texture backgroundTexture;
    TextButton startButton;
    sf::Font font;

public:
    StartScreen() {};
    void update(sf::RenderWindow& window) override;
    void start(sf::RenderWindow& window) override;
};

#endif