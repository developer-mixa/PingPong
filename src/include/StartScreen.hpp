#ifndef START_SCREEN_H
#define START_SCREEN_H

#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

class StartScreen : public MonoBehavior {
    void update(sf::RenderWindow& window) override;
};

#endif