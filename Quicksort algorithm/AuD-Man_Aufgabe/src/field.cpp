#include "field.h"

/**
 * Standartkonstruktor
 * @brief Field::Field
 */
Field::Field() {
    this->setX(0);
    this->setY(0);
    this->setValue(0);
}

/**
 * Konstruktor für ein bestimmtes Feld
 * @brief Field::Field
 * @param x x-Koordinate des Feldes
 * @param y y-Koordinate das Feldes
 * @param value Wert des Feldes (0 - Weg, 1 - Wand, 2 - Kreuzer, 3 - Taler)
 */
Field::Field(int x, int y, int value) {
    this->setX(x);
    this->setY(y);
    this->setValue(value);
}

//*******************************************************
//******************Getter & Setter**********************
//*******************************************************

int Field::getX() {
   return x;
}

int Field::getY() {
   return y;
}

int Field::getValue() {
    return value;
}

void Field::setX(int x) {
    if(x >= 0) {
        this->x = x;
    }
}

void Field::setY(int y) {
    if(y >= 0) {
        this->y = y;
    }
}

void Field::setValue(int value) {
    if(value >= 0 && value <= 3) {
        this->value = value;
    }
}
