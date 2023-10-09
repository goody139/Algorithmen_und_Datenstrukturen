#include "grantelbart.h"
#include "ofAuDApp.h"
#include "present.h"

Grantelbart::Grantelbart()
{
    posX = 0;
    posY = 0;
}

int Grantelbart::getPosX()
{
    return posX;
}

void Grantelbart::setPosX(int value)
{
    posX = value;
}

int Grantelbart::getPosY()
{
    return posY;
}

void Grantelbart::setPosY(int value)
{
    posY = value;
}

void Grantelbart:: setPosition(int x, int y){
    posX = x;
    posY = y;
}

void Grantelbart::draw() {
    ofFill();
    ofSetColor(255,255,255);
    ofDrawCircle(posX, posY, 100);
}
