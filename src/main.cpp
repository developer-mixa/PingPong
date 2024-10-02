#include <SFML/Graphics.hpp>
#include "include/Scene.hpp"
#include "include/StartScreen.hpp"

int main()
{
    Scene scene = Scene();
    StartScreen* screen = new StartScreen();
    scene.addMonoBehavior(screen);
    scene.run();
    return 0;
}