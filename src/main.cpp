#include <SFML/Graphics.hpp>
#include "include/Scene.hpp"
#include "include/Engine.hpp"
#include "include/StartScreen.hpp"
#include "include/GameScreen.hpp"
#include "include/Platform.hpp"
#include "include/PingPongBall.hpp"

int main()
{
    Scene startScene = Scene();
    Scene gameScene = Scene();

    StartScreen* screen = new StartScreen();
    startScene.addComponent(screen);

    GameScreen* gameScreen = new GameScreen();

    Platform* upPlatform = new Platform(sf::Keyboard::A, sf::Keyboard::D);
    Platform* downPlatform = new Platform(sf::Keyboard::Left, sf::Keyboard::Right);
    PingPongBall* pingPongBall = new PingPongBall(*upPlatform, *downPlatform);
    
    gameScene
        .addComponent(gameScreen)
        .addComponent(upPlatform)
        .addComponent(downPlatform)
        .addComponent(pingPongBall);

    Engine::create(startScene);

    Engine::getInstance()
        .registerScene(1, gameScene)
        .build();

    return 0;
}