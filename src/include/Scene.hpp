#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "MonoBehavior.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Scene {
private:
    vector<MonoBehavior*> behaviors;
    void start(RenderWindow &window);
    void update(RenderWindow &window);
    void handleEvent(Event event, RenderWindow &window);
public:
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

    template<typename T> vector<T*> FindObjectsOfType(){
        vector<T*> result;
        for (auto behavior : behaviors){
            if(dynamic_cast<T*>(behavior)){
                result.push_back(static_cast<T*>(behavior));
            }
        }
        return result;
    }

};

#endif