#include "audman.h"
#include "ofAuDApp.h"
#include "level.h"
#include "ghost.h"


int AuDMan::getPoints(){
    return points;
}

/**
 * Der Standardkonstruktor.
 *
 * @brief AuDMan::AuDMan
 */
int AuDMan::getPosX() const{
    return posX;
}


void AuDMan::setPosX(int value){
    posX = value;
}

int AuDMan::getPosY() const{
    return posY;
}

void AuDMan::setPosY(int value){
    posY = value;
}

void AuDMan::setPoints(int value){
    points = value;
}

AuDMan::AuDMan(){
    posX = 0;
    posY = 0;
    points = 0;
}

/**
 * Mit diesem Konstruktor setzt man die Position.
 *
 * @brief AuDMan::AuDMan
 * @param x
 * @param y
 */
AuDMan::AuDMan(int x, int y){
    posX = x;
    posY = y;
    points = 0;
}

/**
 * Setzt die Figur in den Level und setzt die Punkte auf 0.
 *
 * @brief AuDMan::setLevel
 * @param lvl
 */
void AuDMan::setLevel(Level *lvl) {
    level = lvl;
    points = 0;
}

/**
 * Setzt die Position der Figur im Level.
 *
 * @brief AuDMan::setPosition
 * @param x
 * @param y
 */
void AuDMan::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

/**
 * Bewegt die Figur um die angegebenen Koordinaten.
 * Dabei werden die Punkte am neuen Ort "gefressen"
 * @brief AuDMan::moveBy
 * @param dx
 * @param dy
 */
void AuDMan::moveBy(int dx, int dy) {
    int breite = level->getWidth();
    int hoehe = level->getHeight();

    posX = (posX + dx + breite) % breite;
    posY = (posY + dy + hoehe) % hoehe;



    // verhindert, dass der AuD-Man durch "Wände" geht
    if (level->getField(posX,posY) == 1) {
        posX = posX - dx;
        posY = posY - dy;
    }


    if ( level->getField(posX,posY) == 2 ) {
        level->setField(posX,posY,0);
        points = points + 1;
    }

    if(level->getField(posX,posY) == 6 ){
        level->setField(posX,posY,0);
        points = points + 10;
    }
}



/**
 * Zeichne die Figur an der aktuellen Position.
 * Muss in loop() aufgerufen werden, damit die Figur zu sehen ist.
 *
 * @brief AuDMan::draw
 */
void AuDMan::draw() {
    int groesse = level->getSize();

    ofSetColor(255,255,127);
    ofDrawCircle((0.5+posX)*groesse,(0.5+posY)*groesse,groesse*0.4);

    ofSetColor(255,255,255);
    ofDrawBitmapString(points,5,ofGetHeight()-5);
}

