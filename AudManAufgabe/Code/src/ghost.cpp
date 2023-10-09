#include "ghost.h"
#include "ofAuDApp.h"
#include "level.h"


int GHOST::getPosX() const {
    return posX;
}

void GHOST::setPosX(int value) {
    posX = value;
}

int GHOST::getPosY() const {
    return posY;
}

void GHOST::setPosY(int value) {
    posY = value;
}

GHOST::GHOST() {
    posX = 0;
    posY = 0;
}

GHOST::GHOST(int x, int y) {
    posX = x;
    posY = y;
}


void GHOST::setLevel(Level *lvl) {
    level = lvl;
}


void GHOST::setPosition(int x, int y) {
    posX = x;
    posY = y;
}

void GHOST::move() {
    int breite = level->getWidth();
    int hoehe = level->getHeight();

    // lässt den Geist zufällig über das Spielfeld bewegen
    posX = (posX + (int) ofRandom(-2,2) + breite) % breite;
    posY = (posY + (int) ofRandom(-2,2) + hoehe) % hoehe;

}


void GHOST::draw() {
    int groesse = level->getSize();

    ofSetColor(255,255,255);
    ofDrawCircle((0.5+posX)*groesse,(0.5+posY)*groesse,groesse*0.4);

}

