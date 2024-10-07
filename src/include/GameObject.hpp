#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <vector>
#include "Engine.hpp"

class GameObject{
public:
    template<typename T> static T* FindObjectOfType(){
        return Engine::getInstance().getActiveScene().FindObjectOfType<T>();
    }

    template<typename T> static std::vector<T*> FindObjectsOfType(){
        return Engine::getInstance().getActiveScene().FindObjectsOfType<T>();
    }
};

#endif