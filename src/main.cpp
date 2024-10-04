#include <SFML/Graphics.hpp>
#include "include/Scene.hpp"
#include "include/Engine.hpp"
#include "include/StartScreen.hpp"
#include "include/GameScreen.hpp"
#include "include/Platform.hpp"

int main()
{
    Scene startScene = Scene();
    Scene gameScene = Scene();

    StartScreen* screen = new StartScreen();
    startScene.addMonoBehavior(screen);

    GameScreen* gameScreen = new GameScreen();
    Platform* platform = new Platform(sf::Keyboard::A, sf::Keyboard::D);
    gameScene.addMonoBehavior(gameScreen);
    gameScene.addMonoBehavior(platform);

    Engine::create(startScene);

    Engine::getInstance()
        .registerScene(1, gameScene)
        .build();

    return 0;
}