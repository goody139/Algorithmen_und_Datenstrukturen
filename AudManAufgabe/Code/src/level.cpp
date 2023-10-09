/**
 *  Diese Klasse enthält alle Informationen zu einem Level.
 **/

#include "level.h"
#include "ofAuDApp.h"

// Ein Beispiellevel
int level_1[20][20] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
    { 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1 },
    { 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1 },
    { 1, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 1 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
   };


/**
 * @brief Level::Level
 */
Level::Level()
{
    width = 20;
    height = 20;
    size = 20;
    init();
}

/**
 * @brief Level::Level
 * @param s
 */
Level::Level(int s) {
    width = 20;
    height = 20;
    size = s;
    init();
}

/**
 * @brief Level::init
 */
void Level::init() {
   points = 0;
   for ( int row = 0; row < height; row=row+1 ) {
      for ( int column = 0; column < width; column=column+1 ) {
         field[column][row] = level_1[column][row];
         if ( field[column][row] == 0 ) {
            field[column][row] = 2;
            points = points+1;
         }
      }
   }
}

/**
 * @brief Level::getField
 * @param x
 * @param y
 * @return
 */
int Level::getField(int x, int y) {
    return field[x][y];
}

/**
 * @brief Level::setField
 * @param x
 * @param y
 * @param value
 */
void Level::setField(int x, int y, int value) {
    if ( (x>=0) && (x<width) && (y>=0) &&(y<height)) {
        field[x][y] = value;
    }
}

/**
 * @brief Level::draw
 */
void Level::draw() {
    int row = 0;
    int column = 0;

    // Durchlaufe alle Einträge der Matrix field
    for ( row = 0; row < height; row = row+1 ) {
        for ( column = 0; column < width; column = column+1 ) {
            // Je nach wert, zeichne die entsprechende Komponente
            if ( field[column][row] == 1 ) {
                // Eine Wand
                ofSetColor(0,0,255);
                ofDrawRectangle(column*size,row*size,(column+1)*size,(row+1)*size);
            } else if ( field[column][row] == 2 ) {
                // Eine Sammelpunkt
                ofSetColor(0,0,0);
                ofDrawRectangle(column*size,row*size,(column+1)*size,(row+1)*size);
                ofSetColor(255,255,255);
                ofDrawCircle((0.5+column)*size, (0.5+row)*size,2);
            } else if (field[column][row] == 6){
                // Die Taler
                ofSetColor(0,0,0);
                ofDrawRectangle(column*size,row*size,(column+1)*size,(row+1)*size);
                ofSetColor(255,255,255);
                ofDrawCircle((0.5+column)*size, (0.5+row)*size,4);
            } else {
                // Nix
                ofSetColor(0,0,0);
                ofDrawRectangle(column*size,row*size,(column+1)*size,(row+1)*size);
            }
        }
    }
}

/**
 * @brief Level::getWidth
 * @return
 */
int Level::getWidth() {
    return width;
}

/**
 * @brief Level::getHeight
 * @return
 */
int Level::getHeight() {
    return height;
}

/**
 * @brief Level::getSize
 * @return
 */
int Level::getSize() {
    return size;
}

/**
 * @brief Level::getNumberOfPoints
 * @return
 */
int Level::getNumberOfPoints() {
    return points;
}
