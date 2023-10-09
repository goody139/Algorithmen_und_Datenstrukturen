#ifndef PRESENT_H
#define PRESENT_H
#include"ofAuDApp.h"

class Present {

// Die Attribute
protected:
    int posX;
    int posY;
    int speed;
    int targetX;
    int targetY;
    int size = 20;

public:
    Present();
    Present(int x, int y, int spd);

    void virtual draw();
    void virtual move();
    void drawPresent(int x, int y);
    void setTarget(int tx, int ty);
    void setPosition(int x, int y);
    void setSpeed(int s);

    int getX();
    int getY();
    int getTargetX();
    int getTargetY();
    int getSpeed();
};

#endif // PRESENT_H
