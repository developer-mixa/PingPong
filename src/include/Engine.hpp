#ifndef ENGINE_H
#define ENGINE_H

#include "Scene.hpp"

class Engine {
private:
    std::map<int, Scene> scenes;
    static Engine* instance;
    Scene currentScene;
    Engine(Scene &firstScene);
    bool isDestroy;
public:
    static Engine& getInstance();
    static void create(Scene scene);
    Scene& getActiveScene();
    void setActiveScene(int indexScene);
    Engine& registerScene(int index, Scene scene);
    void build();
    void destroy();
};

#endif