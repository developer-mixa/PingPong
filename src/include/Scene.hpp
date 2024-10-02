#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>

class Scene {
private:
    void start(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void handleEvent(sf::Event event);
public:
    std::vector<MonoBehavior*> behaviors;
    bool isActive = false;
    void addMonoBehavior(MonoBehavior *behavior);
    void run();
};

#endif