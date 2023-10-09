/**
** Algorithmen und Datenstrukturen
** OpenFrameworks App
**
** Die Spielfigur für AuD-Man.
**
** Ein Objekt dieser Klasse repräsentiert eine vom Nutzer
** steuerbare Figur, die Punkte aufsammelt.
**
** Michael Brinkmeier <mbrinkmeier@uni-osnabrueck.de>
**/

#ifndef AUDMAN_H
#define AUDMAN_H

#include "level.h"

class AuDMan
{
// Die Attribute
private:
    int posX;       // Der Ort
    int posY;
    int points = 0;     // Die bislang gesammelten Punkte
    Level *level;   // Der Level in dem sich die Figur bewegt

public:

    AuDMan();                   // Der Standardkonstruktor
    AuDMan(int x, int y);       // Ein Konstruktor, dem der Ort übergeben wird.

    void setLevel(Level *lvl);  // Versetzt die Figur in den jeweiligen Level

    void setPosition(int x, int y); // Setzt die Figur an eine bestimmte Position im Level
    void moveBy(int dx, int dy);    // Bewegt die Figur im Level
    void draw();                    // Zeichnet die Figur am aktuellen Ort

    int getPoints();                // Gibt zurück, wieviele Punkte bereits gesammelt wurden.
    int getPosX() const;            // Gibt zurück, wo die posX liegt
    void setPosX(int value);        // Setzt die posX an eine bestimmte Position
    int getPosY() const;            // Gibt zurück, wo PosY liegt
    void setPosY(int value);        // Setzt die posY an eine bestimmte Position
    void setPoints(int value);      // Setzt die points auf einen bestimmten Wert
};

#endif // AUDMAN_H
