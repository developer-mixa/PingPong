#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "MonoBehavior.hpp"

class GameScreen : public MonoBehavior{
private:
    sf::Sprite background;
    sf::Texture backgroundTexture;
public:
    GameScreen(){}
    void start(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
    void initBackground();
};

#endif