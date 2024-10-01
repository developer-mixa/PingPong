#include <SFML/Graphics.hpp>
#include "include/Engine.hpp"
#include "include/StartScreen.hpp"

int main()
{
    Engine engine = Engine();
    StartScreen* screen = new StartScreen();
    engine.addMonoBehavior(screen);
    engine.run();
    return 0;
}