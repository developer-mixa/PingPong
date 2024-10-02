#include <SFML/Graphics.hpp>
#include "include/Scene.hpp"
#include "include/Engine.hpp"
#include "include/StartScreen.hpp"

int main()
{
    Scene scene = Scene();
    StartScreen* screen = new StartScreen();
    scene.addMonoBehavior(screen);

    Engine engine = Engine(scene);
    engine.build();

    return 0;
}