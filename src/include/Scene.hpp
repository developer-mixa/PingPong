#ifndef ENGINE_H
#define ENGINE_H

#include <vector>
#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>

class Scene {
private:
    void start();
    void update(sf::RenderWindow &window);
public:
    std::vector<MonoBehavior*> behaviors;
    void addMonoBehavior(MonoBehavior *behavior);
    void run();
};

#endif