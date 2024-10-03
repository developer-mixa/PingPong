#include <SFML/Graphics.hpp>
#include "include/Scene.hpp"
#include "include/Engine.hpp"
#include "include/StartScreen.hpp"
#include "include/GameScreen.hpp"

int main()
{
    Scene startScene = Scene();
    Scene gameScene = Scene();

    StartScreen* screen = new StartScreen();
    startScene.addMonoBehavior(screen);

    GameScreen* gameScreen = new GameScreen();
    gameScene.addMonoBehavior(gameScreen);

    Engine::create(startScene);

    Engine::getInstance().registerScene(1, gameScene);

    return 0;
}