#include "present.h"
#include "ofAuDApp.h"
#include <cmath>

/**
 * Der Standardkonstruktor
 * @brief Present::Present
 */
Present::Present() {
    posX = 0;
    posY = 0;
    speed = 0;
}

/**
 * Dieser Konstruktor setzt die Position.
 * @brief Present::Present
 * @param x x-Koordinate des Geschenks
 * @param y y-Koordinate des Geschenks
 * @param spd Tempo des Geschenks
 */
Present::Present(int x, int y, int spd) {
    posX = x;
    posY = y;
    speed = spd;
}

/**
 * Berechnet die Koordinaten des neuen Standpunktes,
 * ruft die Operation zum Zeichnen des Pakets auf
 * @brief Present::draw
 */
void Present::draw() {
    float deltaX = targetX - posX;
    float deltaY = targetY - posY;
    float dist = sqrt(deltaX*deltaX + deltaY*deltaY);

    float dirX = deltaX/dist;
    float dirY = deltaY/dist;

    ofSetColor(255,255,255);

    float x = posX + size*dirX;
    float y = posY + size*dirY;

    drawPresent(x, y);

}

/**
 * Bewege das Geschenk um speed auf das aktuelle Ziel zu.
 *
 * @brief Present::move
 */
void Present::move() {
    float deltaX = targetX - posX;
    float deltaY = targetY - posY;
    float dist = sqrt(deltaX*deltaX + deltaY*deltaY);

    // Ist das Ziel weit genug entfernt?
    if ( dist > size ) {
        posX = posX + speed*deltaX/dist;
        posY = posY + speed*deltaY/dist;
    } else {
        posX = posX + deltaX;
        posY = posY + deltaY;
    }
}

/**
 * Zeichnet das Geschenk.
 * @brief Present::drawPresent
 * @param x x-Koordinate des Geschenks
 * @param y y-Koordinate des Geschenks
 */
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
}

/**
 * Ein Setter für das Ziel
 *
 * @brief Present::setTarget
 * @param tx Ziel-x-Koordinate
 * @param ty Ziel-y-Koordinate
 */
void Present::setTarget(int tx, int ty) {
    targetX = tx;
    targetY = ty;
}


/**
 * Ein Setter für die Position
 *
 * @brief Present::setPosition
 * @param x x-Koordinate
 * @param y y-Koordinate
 */
void Present::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

/**
 * Ein Setter für die Geschwindigkeit
 *
 * @brief Present::setSpeed
 * @param s
 */
void Present::setSpeed(int s) {
    speed = s;
}

/**
 * Ein Getter für die x-Koordinate
 * @brief Present::getX
 * @return
 */
int Present::getX() {
    return posX;
}

/**
 * Ein Getter für die y-Koordinate
 * @brief Present::getY
 * @return
 */
int Present::getY() {
    return posY;
}

/**
 * Ein Getter für die Geschwindigkeit
 * @brief Present::getSpeed
 * @return
 */
int Present::getSpeed() {
    return speed;
}

/**
 * Ein Getter für die Ziel-x-Koordinate
 * @brief Present::getTargetX
 * @return
 */
int Present::getTargetX() {
    return targetX;
}

/**
 * Ein Getter für die Ziel-y-Koordinate
 * @brief Present::getTargetY
 * @return
 */
int Present::getTargetY() {
    return targetY;
}
