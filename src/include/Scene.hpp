#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>

class Scene {
private:
    void start(sf::RenderWindow &window);
    void update(sf::RenderWindow &window);
    void handleEvent(sf::Event event, sf::RenderWindow &window);
public:
    std::vector<MonoBehavior*> behaviors;
    bool isActive = false;
    Scene& addComponent(MonoBehavior *behavior);
    void run();

    template<typename T> T* FindObjectOfType(){
        for (auto behavior : behaviors){
            if(dynamic_cast<T*>(behavior)){
                return static_cast<T*>(behavior);
            }
        }
        return nullptr;
    }

    template<typename T> std::vector<T*> FindObjectsOfType(){
        std::vector<T*> result;
        for (auto behavior : behaviors){
            if(dynamic_cast<T*>(behavior)){
                result.push_back(static_cast<T*>(behavior));
            }
        }
        return result;
    }
};

#endif