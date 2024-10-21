#ifndef MONO_BEHAVIOR_H
#define MONO_BEHAVIOR_H
#include <SFML/Graphics.hpp>

class MonoBehavior
{
public:
    void fitToScreen(sf::Sprite& sprite, const sf::RenderWindow& window);
    virtual void start([[maybe_unused]] sf::RenderWindow &window){};
    virtual void update([[maybe_unused]] sf::RenderWindow &window){};
    virtual void eventTrigger([[maybe_unused]] sf::Event event, [[maybe_unused]] sf::RenderWindow &window){};
    MonoBehavior() = default;
    virtual ~MonoBehavior() = default;
};


#endif