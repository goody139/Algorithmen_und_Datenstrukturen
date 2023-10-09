#ifndef GHOST_H
#define GHOST_H

#include "level.h"

class GHOST
{
    // Die Attribute
    private:
        int posX;       // Der Ort
        int posY;
        Level *level;   // Der Level in dem sich die Figur bewegt
        int count;

    public:
    GHOST();                    // Der Standardkonstruktor
    GHOST(int x, int y);       // Ein Konstruktor, dem der Ort übergeben wird.

    void setLevel(Level *lvl);  // Versetzt die Figur in den jeweiligen Level

    void setPosition(int x, int y); // Setzt die Figur an eine bestimmte Position im Level
    void move();    // Bewegt die Figur im Level
    void draw();                    // Zeichnet die Figur am aktuellen Ort
    int getPosX() const;            // Gibt zurück, wo die posX liegt
    void setPosX(int value);        //Setzt die posX an eine bestimmte Position
    int getPosY() const;            // Gibt zurück, wo die posY liegt
    void setPosY(int value);        // Setzt die posY auf eine bestimmte Position
};

#endif // GHOST_H
