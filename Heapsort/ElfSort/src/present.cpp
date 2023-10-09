#include "present.h"
#include "ofAuDApp.h"


Present::Present()
{
    posX = 0;
    posY = 0;
    number = 0;
}

Present::Present(int x, int y, int nummer) {
    posX = x;
    posY = y;
    number = nummer;
}

int Present::getNumber() const
{
    return number;
}

void Present::setNumber(int value)
{
    number = value;
}

void Present::setPosY(int value)
{
    posY = value;
}

void Present::setPosX(int value)
{
    posX = value;
}

int Present::getPosY() const
{
    return posY;
}

int Present::getPosX() const
{
    return posX;
}

void Present::drawPresent(int x, int y) {

    // Kasten
    ofSetColor(255,0,0);
    ofFill();
    ofDrawRectangle(x, y, 10, 10);

    // Geschenkband
    ofSetColor(0,255,0);
    ofNoFill();
    ofDrawLine(x + 5, y, x + 5, y + 10);
    ofDrawBezier(x + 5, y, x - 2, y - 2, x + 3, y - 3, x + 5, y);
    ofDrawBezier(x + 5, y, x + 12, y - 2, x + 7, y - 3, x + 5, y);

    // Nummern
    ofSetColor(0,0,255);
    ofDrawBitmapString (number, (x+(size/2)), (y+ (size/2)));
}

// Pfeile
void Present::drawArrowRed(int x, int y) {
    ofSetColor(255, 0, 0);
    ofVec3f arrowspitze (x+(size/2),y+(2+size),0);
    ofVec3f arrowende (x+(size/2),y+size,0);
    ofDrawArrow(arrowspitze, arrowende, 10);
}

void Present::drawArrowgreen(int x, int y) {
    ofSetColor(255, 255, 255);
    ofVec3f arrowspitze (x+(size/2),y+(2+size),0);
    ofVec3f arrowende (x+(size/2),y+size,0);
    ofDrawArrow(arrowspitze, arrowende, 10);
}
