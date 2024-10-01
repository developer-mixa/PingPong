#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StartScreen.hpp"

void StartScreen::update(sf::RenderWindow &window){
    sf::CircleShape shape(100.f,3); 
    shape.setPosition(100, 100);           
    shape.setFillColor(sf::Color::Magenta);
    window.draw(shape);
}
