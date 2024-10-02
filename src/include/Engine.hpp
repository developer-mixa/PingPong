#ifndef ENGINE_H
#define ENGINE_H

#include "Scene.hpp"

class Engine {
public:
    std::map<int, Scene> scenes;
    Scene currentScene;
    Scene& getActiveScene();
    void setActiveScene(int indexScene);
    void registerScene(int index, Scene &scene);
    void build();
    Engine(Scene &firstScene);
};

#endif