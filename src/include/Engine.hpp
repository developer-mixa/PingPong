#ifndef ENGINE_H
#define ENGINE_H

#include "Scene.hpp"

class Engine {
private:
    std::map<int, Scene> scenes;
    static Engine* instance;
    Scene currentScene;
    void build();
    Engine(Scene &firstScene);
public:
    static Engine& getInstance();
    static void create(Scene &scene);
    Scene& getActiveScene();
    void setActiveScene(int indexScene);
    void registerScene(int index, Scene &scene);
};

#endif