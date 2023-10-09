/**
 *  Diese Klasse enthält alle Informationen zu einem Level.
 *
 *  0 - Weg
 *  1 - Wand
 *  2 - Kreuzer (1 Punkt)
 *  3 - Taler (10 Punkte)
 **/

#include "level.h"
#include "ofAuDApp.h"

// Zwei Beispiellevel
int level_1[20][20] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1 },
    { 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
   };

int level_2[20][20] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 2, 2, 2, 2, 2, 3, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1 },
    { 1, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 2, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1 },
    { 1, 3, 2, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
   };

/**
 * Standardkonstruktor
 *
 * @brief Level::Level
 */
Level::Level() {
    width = 20;
    height = 20;
    size = 20;
    init();
}

/**
 * In diesem Konstruktor kann der Skalierungsfaktor verändert werden
 *
 * @brief Level::Level
 * @param s Skalierungsfaktor
 */
Level::Level(int s) {
    width = 20;
    height = 20;
    size = s;
    init();
}

/**
 * Initialisiert ein Level
 *
 * @brief Level::init
 */
void Level::init() {
   points = 0;
   for ( int row = 0; row < height; row=row+1 ) {
      for ( int column = 0; column < width; column=column+1 ) {
         fields[column][row] = Field(column, row, level_2[column][row]);
         if ( fields[column][row].getValue() == 2 ) {
            points = points + 1;
         } else if ( fields[column][row].getValue() == 3 ) {
            points = points + 10;
         }
      }
   }
}

/**
 * @brief Level::getField
 * @param x x-Koordinate
 * @param y y-Koordinate
 * @return
 */
Field* Level::getField(int x, int y) {
    return &fields[x][y];
}

/**
 * Setzt den Wert einer bestimmten Zelle
 *
 * @brief Level::setField
 * @param x x-Position
 * @param y y-Position
 * @param value 0 - Weg, 1 - Wand, 2 - Kreuzer, 3 - Taler
 */
void Level::setField(int x, int y, int value) {
    if ( ( x >= 0) && (x < width) && (y >= 0) && (y < height) ) {
        fields[x][y].setValue(value);
    }
}

/**
 * Zeichnet das Level
 * Muss in loop() aufgerufen werden, damit das Level zu sehen ist.
 *
 * @brief Level::draw
 */
void Level::draw() {
    // Durchlaufe alle Einträge der Matrix field
    for ( int row = 0; row < height; row = row + 1 ) {
        for ( int column = 0; column < width; column = column + 1 ) {
            // Je nach wert, zeichne die entsprechende Komponente
            if ( fields[column][row].getValue() == 1 ) {
                // Eine Wand
                ofSetColor(0, 0, 255);
                ofDrawRectangle(column * size, row * size, (column + 1) * size, (row + 1) * size);
            } else if ( fields[column][row].getValue() == 2 ) {
                // Ein Kreuzer
                ofSetColor(0, 0, 0);
                ofDrawRectangle(column * size, row * size, (column + 1) * size,(row + 1) * size);
                ofSetColor(255, 255, 255);
                ofDrawCircle((0.5 + column) * size, (0.5 + row) * size, 2);
            } else if ( fields[column][row].getValue() == 3 ) {
                // Ein Taler
                ofSetColor(0, 0, 0);
                ofDrawRectangle(column * size, row * size, (column + 1) * size,(row + 1) * size);
                ofSetColor(255, 255, 255);
                ofDrawCircle((0.5 + column) * size, (0.5 + row) * size, 5);
            } else {
                // Nix
                ofSetColor(0, 0, 0);
                ofDrawRectangle(column * size, row * size, (column + 1) * size, (row + 1) * size);
            }
        }
    }
}

/**
 * Gibt die Berite des Levels
 *
 * @brief Level::getWidth
 * @return Level-Breite
 */
int Level::getWidth() {
    return width;
}

/**
 * Gibt die Höhe des Levels
 *
 * @brief Level::getHeight
 * @return Level-Höhe
 */
int Level::getHeight() {
    return height;
}

/**
 * Gibt den Skalierungsfaktor des Levels
 *
 * @brief Level::getSize
 * @return Skalierungsfaktor
 */
int Level::getSize() {
    return size;
}

/**
 * Gibt die Punkte des Levels
 *
 * @brief Level::getNumberOfPoints
 * @return Punkte
 */
int Level::getNumberOfPoints() {
    return points;
}
