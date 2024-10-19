#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include "UiElement.hpp"
#include <SFML/Graphics.hpp>

using namespace sf;

class TextButton : UiElement {
private:
    RectangleShape rectangleButton;
    Text buttonText;
    bool mouseInButton(RenderWindow &window);
public:
    TextButton(
        char* text,
        float width,
        float height,
        Font& font,
        Color fillColor,
        float startPositionX = 0,
        float startPositionY = 0
    );

    TextButton(){};

    Vector2f getPosition();
    void setPosition(float x, float y);
    virtual void draw(RenderWindow &window) override;
    bool isPressed(Event event, RenderWindow &window);
    bool isMouseOver(Event event, RenderWindow &window);

    float thickness = 2;
    Color outlineColor = Color::Black;
    int textSize = 24;
    Color textColor = Color::White;

    float textMarginX = 10;
    float textMarginY = 10;
};

#endif