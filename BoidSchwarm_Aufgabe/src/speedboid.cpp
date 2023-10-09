#include "speedboid.h"
#include "ofAuDApp.h"


ofVec2f SpeedBoid::getPositionvektor() const
{
    ofVec2f helperposition;
    helperposition.set(posX,posY);
    return helperposition;
}

void SpeedBoid::setPositionvektor(const ofVec2f &value)
{
    positionvektor = value;
}

ofVec2f SpeedBoid::getGeschwindigkeitsvektor() const
{
    ofVec2f hilfsgeschwindigkeit;
    hilfsgeschwindigkeit.set(vx,vy);
    return hilfsgeschwindigkeit;
}

void SpeedBoid::setGeschwindigkeitsvektor(const ofVec2f &value)
{
    geschwindigkeitsvektor = value;
}

/**
 * Standardkonstruktor
 *
 * @brief SpeedBoid::SpeedBoid
 */
int SpeedBoid::getNummer() const
{
    return nummer;
}

void SpeedBoid::setNummer(int value)
{
    nummer = value;
}

SpeedBoid::SpeedBoid() {
    posX = 0;
    posY = 0;
    vx = 0;
    vy = 0;
    size = 20;
}

/**
 * Setzt den Boid auf eine bestimmte Position
 * @brief SpeedBoid::setPosition
 * @param x x-Koordinate
 * @param y y-Koordinate
 */
void SpeedBoid::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

/**
 * Setzt die Geschwindigkeit des Boids
 * @brief SpeedBoid::setSpeed
 * @param x x-Anteil der Geschwindigkeit
 * @param y y-Anteil der Geschwindigkeit
 */
void SpeedBoid::setSpeed(int x, int y) {
    vx = x;
    vy = y;
}

/**
 * Zeichnet den Boid
 * @brief SpeedBoid::draw
 */
void SpeedBoid::draw() {
    ofSetColor(0,1,0);

    if ( (vx == 0) && (vy == 0) ) {
        ofDrawCircle(posX,posY,size/4);

    } else {
        float dist = sqrt(vx*vx + vy*vy);

        float dirX = vx/dist;
        float dirY = vy/dist;

        float aX = posX + size*dirX;
        float aY = posY + size*dirY;

        float bX = posX - size/4*dirY;
        float bY = posY + size/4*dirX;

        float cX = posX + size/4*dirY;
        float cY = posY - size/4*dirX;

        ofDrawTriangle(aX,aY,bX,bY,cX,cY);
    }
}

/**
 * Bewegt den Boid entsprechend seiner Geschwindigkeit
 * @brief SpeedBoid::move
 */
void SpeedBoid::move() {
    posX = posX + vx;
    posY = posY + vy;
}

//========================================================================
//=====================   Getter und Setter   ============================
//========================================================================

int SpeedBoid::getX() {
    return posX;
}


int SpeedBoid::getY() {
    return posY;
}

int SpeedBoid::getSpeedX() {
    return vx;
}

int SpeedBoid::getSpeedY() {
    return vy;
}
