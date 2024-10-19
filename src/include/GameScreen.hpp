#ifndef GAME_SCREEN_H
#define GAME_SCREEN_H

#include "MonoBehavior.hpp"
#include "CountdownDisplay.hpp"
#include "PingPongBall.hpp"
#include "Platform.hpp"

#define COUNTDOWN_FONT "assets/fonts/Roboto-Black.ttf"

class GameScreen : public MonoBehavior {
private:
    sf::Sprite background;
    sf::Texture backgroundTexture;
    std::vector<Platform*> platforms;
    PingPongBall* pingPongBall;
    CountdownDisplay countdownDisplay = CountdownDisplay(COUNTDOWN_FONT);   
    void finish() const;

public:
    GameScreen(){}
    void start(sf::RenderWindow& window) override;
    void update(sf::RenderWindow& window) override;
};

#endif