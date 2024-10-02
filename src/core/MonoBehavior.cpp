#include "MonoBehavior.hpp"

void MonoBehavior::fitToScreen(sf::Sprite& sprite, const sf::RenderWindow& window){
    float widthRatio = window.getSize().x / sprite.getLocalBounds().width;
    float heightRatio = window.getSize().y / sprite.getLocalBounds().height;    
    sprite.setScale(widthRatio, heightRatio);
}