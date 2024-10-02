#include <SFML/Graphics.hpp>
#include "include/Scene.hpp"
#include "include/Engine.hpp"
#include "include/StartScreen.hpp"

int main()
{
    Scene startScene = Scene();
    StartScreen* screen = new StartScreen();
    startScene.addMonoBehavior(screen);

    Engine::create(startScene);

    return 0;
}