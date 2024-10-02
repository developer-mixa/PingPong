#include <vector>
#include "MonoBehavior.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void Scene::start(sf::RenderWindow &window){
    for (auto behavior : this->behaviors){
        behavior->start(window);
    }
}

void Scene::update(sf::RenderWindow &window){
    for (auto behavior : this->behaviors){
        behavior->update(window);
    }
}

void Scene::handleEvent(sf::Event event){
    for (auto behavior : this->behaviors){
        behavior->eventTrigger(event);
    }
}

void Scene::addMonoBehavior(MonoBehavior *behavior){
    this->behaviors.push_back(behavior);
}

void Scene::run(){
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PingPong");

    this->start(window);

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
        
        window.clear();
        this->update(window);
        window.display();
    }
}