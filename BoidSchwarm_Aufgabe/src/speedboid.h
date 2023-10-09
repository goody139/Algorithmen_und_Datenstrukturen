#ifndef SPEEDBOID_H
#define SPEEDBOID_H
#include "ofAuDApp.h"


class SpeedBoid {
    protected:
        int vx;
        int vy;
        int posX;
        int posY;
        int size;
        int nummer;
        ofVec2f positionvektor; //jeder speedboid hat einen positionvektor
        ofVec2f geschwindigkeitsvektor; //jeder speedboid hat einen geschwindigkeitsvektor

    public:
        SpeedBoid();

        int getX();
        int getY();
        int getSpeedX();
        int getSpeedY();

        void setPosition(int x, int y);
        void setSpeed(int x, int y);
        void move();
        void draw();

        ofVec2f getPositionvektor() const;
        void setPositionvektor(const ofVec2f &value);
        ofVec2f getGeschwindigkeitsvektor() const;
        void setGeschwindigkeitsvektor(const ofVec2f &value);
        int getNummer() const;
        void setNummer(int value);
};

#endif // SPEEDBOID_H
