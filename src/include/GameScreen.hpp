#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "MonoBehavior.hpp"
#include "CountdownDisplay.hpp"

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