#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StartScreen.hpp"

void initBackground(){
    
}

void StartScreen::start(sf::RenderWindow &window){
    shape = sf::CircleShape(100.f, 3);

    if (!backgroundTexture.loadFromFile("assets/images/start_screen.jpg")) {
        std::cout << "Ошибка загрузки текстуры фона!" << std::endl;
        shape = sf::CircleShape(500.f, 3);
        return;
    }
    background = sf::Sprite(backgroundTexture);
    fitToScreen(background, window);
}

void StartScreen::update(sf::RenderWindow &window){
    window.draw(background);
}