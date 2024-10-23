#include <vector>
#include "MonoBehavior.hpp"
#include "Scene.hpp"
#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <typeinfo>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080
#define GAME_NAME "PingPong"

using namespace sf;
using namespace std;

void Scene::start(RenderWindow &window){
    for (auto behavior : behaviors){
        behavior->start(window);
    }
}

void Scene::update(RenderWindow &window){
    for (auto behavior : this->behaviors){
        behavior->update(window);
    }
}

void Scene::handleEvent(Event event, RenderWindow &window){
    for (auto behavior : this->behaviors){
        behavior->eventTrigger(event, window);
    }
}

Scene& Scene::addComponent(MonoBehavior *behavior){
    this->behaviors.push_back(behavior);
    return *this;
}

float currentScreenWidth = SCREEN_WIDTH;
float currentScreenHeight = SCREEN_HEIGHT;

void Scene::run(){

    auto window = RenderWindow(VideoMode(currentScreenWidth, currentScreenHeight), GAME_NAME);

    window.setSize(Vector2u(currentScreenWidth, currentScreenHeight));

    this->start(window);

    window.setVerticalSyncEnabled(true);

    while (window.isOpen() && this->isActive)
    {
        auto windowSize = window.getSize();
        currentScreenWidth = windowSize.x;
        currentScreenHeight = windowSize.y;
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