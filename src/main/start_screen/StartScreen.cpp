#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "StartScreen.hpp"

sf::CircleShape shape(100.f,3); 

void StartScreen::start(){
    shape = sf::CircleShape(100.f, 3);
}

void StartScreen::update(sf::RenderWindow &window){
    sf::Vector2f p = shape.getPosition();
    shape.setPosition(p.x+1, p.y+1);           
    shape.setFillColor(sf::Color::Magenta);
    window.draw(shape);
}
