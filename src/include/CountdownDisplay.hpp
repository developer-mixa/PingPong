#ifndef COUNTDOWN_DISPLAY_H
#define COUNTDOWN_DISPLAY_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>

using namespace sf;
using namespace std;

class CountdownDisplay : public Drawable {
private:
    Font font;
    int count;
    int initialCount;
    Text text;
    thread countdownThread;
    void doRun();
public:
    bool finish = false;
    CountdownDisplay(const string& fontPath, int startCount=3);
    virtual void draw(RenderTarget& target, RenderStates states) const override;
    void reset();
    void run();
    void centerByWindow(const RenderWindow& window);
};

#endif