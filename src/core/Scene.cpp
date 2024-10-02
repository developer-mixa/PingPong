#include <vector>
#include "MonoBehavior.hpp"
#include "Scene.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void Scene::start(){
    for (auto behavior : this->behaviors){
        behavior->start();
    }
}

void Scene::update(sf::RenderWindow &window){
    std::cout << this->behaviors.size();
    for (auto behavior : this->behaviors){
        behavior->update(window);
    }
}

void Scene::addMonoBehavior(MonoBehavior *behavior){
    this->behaviors.push_back(behavior);
}

void Scene::run(){
    this->start();

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PingPong");

    window.setVerticalSyncEnabled(true);

    while (window.isOpen() && this->isActive)
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed){
                this->isActive = false;
                window.close();
            }
                
        }
        
        window.clear(sf::Color::Black);
        this->update(window);
        window.display();
    }
}