#include "ofaudturtle.h"
#include <cmath>

#define PI 3.14159265

/**
 * Der Standardkonstruktor erzeugt eine
 * neue Turtle. Damit gezeichnet werden kann muss
 * in setup() noch reset() aufgerufen werden.
 *
 * @brief ofAuDTurtle::ofAuDTurtle
 */
ofAuDTurtle::ofAuDTurtle() {
    lines = new ofPolyline();
    x = 0.0;
    y = 0.0;
    dir = 0.0;
}

/**
 * reset() setzt die Turtle in die Mitte des Fensters
 * und lässt sie nach rechts schauen. Die Operation
 * darf erst nach Initialisierung des Fensters aufgerufen
 * werden.
 *
 * @brief ofAuDTurtle::reset
 */
void ofAuDTurtle::reset() {
    x = ofGetWidth() / 2;
    y = ofGetHeight() / 2;
    dir = 0.0;

    lines->clear();
    lines->addVertex(x, y);
}

/**
 * reset() setzt die Turtle auf die angegebene Position
 * und lässt sie nach rechts schauen. Die Operation
 * darf erst nach Initialisierung des Fensters aufgerufen
 * werden.

 * @brief ofAuDTurtle::reset
 * @param sx Die x-Koordinate der Position
 * @param sy Die y-Koordinat der Position
 */
void ofAuDTurtle::reset (int sx, int sy) {
    x = sx;
    y = sy;
    dir = 0.0;

    lines->clear();
    lines->addVertex(sx, sy);
}

/**
 * Bewegt die Turtle von ihrer aktuellen zur angegebenen
 * Position. Dabei wird eine Linie gezeichnet. Die Richtung
 * der Turtle ändert sich nicht.
 *
 * @brief ofAuDTurtle::moveTo
 * @param tx Die x-Koordinate der Zielposition
 * @param ty Die y-Koordinate der Zielposition
 */
void ofAuDTurtle::moveTo(int tx, int ty) {
    lines->addVertex(tx, ty);
}

/**
 * Bewegt die Turtle um die angegebene Zahl von Pixel in die
 * aktuelle Richtung.
 *
 * @brief ofAuDTurtle::move
 * @param dist Die Distanz
 */
void ofAuDTurtle::move(double dist) {
    double dx = dist * cos( (dir / 360.0) * 2.0 * PI );
    double dy = dist * sin( (dir / 360.0) * 2.0 * PI );

    x = x + dx;
    y = y + dy;

    lines->addVertex(x, y);
}

/**
 * Setzt die Richtung der Turtle auf den angegebenen Wert
 * in Grad. 0 Grad zeigt nach rechts und der Winkel wird im
 * Uhrzeigersin gemessen.
 *
 * @brief ofAuDTurtle::setDirection
 * @param angle Der Winkel in Grad
 */
void ofAuDTurtle::setDirection(double angle) {
    dir = angle;

    while ( dir < 0 ) {
        dir = dir + 360.0;
    }

    while ( dir > 360.0 ) {
        dir = dir - 360.0;
    }
}

/**
 * Dreht die Schildkröte um die angegebene Gradzahl.
 * Positive Winkel drehen sie mit dem Uhrzeigersin, negative
 * gegen.
 *
 * @brief ofAuDTurtle::turn
 * @param angle Der Winkel
 */
void ofAuDTurtle::turn(double angle) {
    dir = (dir + angle);

    while ( dir < 0 ) {
        dir = dir + 360.0;
    }

    while ( dir > 360.0 ) {
        dir = dir - 360.0;
    }
}

/**
 * Setzt die Farbe der gezeichneten Linie.
 *
 * @brief ofAuDTurtle::setColor
 * @param r Die Rot-Komponente
 * @param g Die Grün-Komponente
 * @param b Die Blau-Komponente
 */
void ofAuDTurtle::setColor(int r, int g, int b){
    color.set(r, g, b);
}

/**
 * Setzt die Farbe der gezeichneten Linie
 *
 * @brief ofAuDTurtle::setColor
 * @param col Die Farbe
 */
void ofAuDTurtle::setColor(ofColor col) {
    color.set(col);
}

/**
 * Zeichnet den Linienzug, den die Turtle gelaufen ist.
 * Muss einmal in loop() aufgerufen werden.
 *
 * @brief ofAuDTurtle::draw
 */
void ofAuDTurtle::draw() {
    ofSetColor(color);
    lines->draw();
}

