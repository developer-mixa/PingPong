#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class StartScreen : public MonoBehavior {
public:
    void update(sf::RenderWindow& window) override;
    void start(sf::RenderWindow& window) override;
    sf::CircleShape shape; 
    sf::Sprite background;
    sf::Texture backgroundTexture;
};

#endif