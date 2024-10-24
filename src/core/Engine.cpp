#include "Engine.hpp"
#include "Scene.hpp"

Engine* Engine::instance = nullptr;

Scene& Engine::getActiveScene(){
    return this->currentScene;
}

void Engine::setActiveScene(int indexScene){
    this->currentScene.isActive = false;
    this->currentScene = this->scenes[indexScene];
};

Engine& Engine::registerScene(int index, Scene scene){
    this->scenes[index] = scene;
    return *this;
};

void Engine::destroy(){
    isDestroy = true;
}

void Engine::build(){
    this->setActiveScene(0);
    Scene* scenePtr = &this->currentScene;
    if(scenePtr == NULL){
        throw std::runtime_error(
        "Attempted access to uninitialized scene object. "
        "Ensure that the current scene was properly initialized."
        );
    }

    while (true)
    {
        
        if(this->currentScene.isActive){
            
            currentScene.run();
        }

        if(isDestroy) break;

        this->currentScene.isActive = true;
    }
}

Engine::Engine(Scene &scene){
    this->registerScene(0, scene);
}

void Engine::create(Scene firstScene){
    instance = new Engine(firstScene);
}

Engine& Engine::getInstance() {
    return *instance;
}