#ifndef GRANTELBART_H
#define GRANTELBART_H
#include "ofAuDApp.h"


class Grantelbart
{

private:
    int posX;       // Der Ort
    int posY;
public:
    Grantelbart();                   // Der Standardkonstruktor
    Grantelbart(int x, int y);       // Ein Konstruktor, dem der Ort übergeben wird.
    void setPosition(int x, int y);
    void draw();
    int getPosX();
    void setPosX(int value);
    int getPosY();
    void setPosY(int value);
};

#endif // GRANTELBART_H
