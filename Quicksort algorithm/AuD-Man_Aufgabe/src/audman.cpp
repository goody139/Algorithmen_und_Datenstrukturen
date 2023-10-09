#include "audman.h"
#include "ofAuDApp.h"
#include "level.h"

/**
 * Der Standardkonstruktor.
 *
 * @brief AuDMan::AuDMan
 */
AuDMan::AuDMan() {
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
AuDMan::AuDMan(int x, int y) {
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

    if ( !( level->getField(x, y)->getValue() == 1 ) ) {
        posX = x;
        posY = y;
    } else {
        cout << "Ich kann nicht in Wänden stehen!" << endl;
    }
}

int AuDMan :: getPosY () {
    return posY;
}
int AuDMan :: getPosX () {
    return posX;
}

/**
 * Bewegt die Figur um die angegebenen Koordinaten.
 * Dabei werden die Punkte am neuen Ort "gefressen"
 *
 * @brief AuDMan::moveBy
 * @param dx
 * @param dy
 */
void AuDMan::moveBy(int dx, int dy) {
    int breite = level->getWidth();
    int hoehe = level->getHeight();

    int tempX = (posX + dx + breite) % breite;
    int tempY = (posY + dy + hoehe) % hoehe;

    if ( !( level->getField(tempX,tempY)->getValue() == 1 ) ) {
        posX = tempX;
        posY = tempY;

        if ( level->getField(posX, posY)->getValue() == 2 ) {
            level->setField(posX, posY, 0);
            points = points + 1;
        } else if ( level->getField(posX, posY)->getValue() == 3 ) {
            level->setField(posX, posY, 0);
            points = points + 10;
        }
    } else {
        cout << "Ich kann nicht in Wänden stehen!" << endl;
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

    ofSetColor(255, 255, 127);
    ofDrawCircle((0.5 + posX) * groesse, (0.5 + posY) * groesse, groesse * 0.4);

    ofSetColor(255, 255, 255);
    ofDrawBitmapString(points, 5, ofGetHeight() - 5);
}

