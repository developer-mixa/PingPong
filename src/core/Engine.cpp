#include <vector>
#include "MonoBehavior.hpp"
#include "Engine.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

void Engine::start(){
    for (auto behavior : this->behaviors){
        behavior->start();
    }
}

void Engine::update(sf::RenderWindow &window){
    std::cout << this->behaviors.size();
    for (auto behavior : this->behaviors){
        behavior->update(window);
    }
}

void Engine::addMonoBehavior(MonoBehavior *behavior){
    this->behaviors.push_back(behavior);
}

void Engine::run(){
    this->start();

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "PingPong");

    window.setVerticalSyncEnabled(true);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        
        window.clear(sf::Color::Black);
        this->update(window);
        window.display();
    }
}