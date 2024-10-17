#include <vector>
#include "MonoBehavior.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <typeinfo>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void Scene::start(sf::RenderWindow &window){
    for (auto behavior : behaviors){
        behavior->start(window);
    }
}

void Scene::update(sf::RenderWindow &window){
    for (auto behavior : this->behaviors){
        behavior->update(window);
    }
}

void Scene::handleEvent(sf::Event event, sf::RenderWindow &window){
    for (auto behavior : this->behaviors){
        behavior->eventTrigger(event, window);
    }
}

Scene& Scene::addComponent(MonoBehavior *behavior){
    this->behaviors.push_back(behavior);
    return *this;
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
            handleEvent(event, window);

            if (event.type == sf::Event::Closed){
                Engine::getInstance().destroy();               
                window.close();
            }
            
        }
        
        window.clear();
        this->update(window);
        window.display();
    }
}