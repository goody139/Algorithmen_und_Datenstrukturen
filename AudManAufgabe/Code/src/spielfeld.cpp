#include "spielfeld.h"
#include "ofAuDApp.h"

Spielfeld::Spielfeld()
{
    size = 20;
    width = 20;
    height = 20;
}

Spielfeld::Spielfeld(int sz)
{
    size = sz;
    width = 20;
    height = 20;
}


int Spielfeld::getWidth() {
    return width;
}


int Spielfeld::getHeight() {
    return height;
}


void Spielfeld::draw() {
    int reihe = 0;
    int spalte = 0;

    // Durchlaufe alle Einträge der Matrix spielfeld
    for ( reihe = 0; reihe < height; reihe = reihe+1 ) {
        for ( spalte = 0; spalte < width; spalte = spalte+1 ) {
            // Je nach wert, zeichne die entsprechende Komponente
            if ( field[spalte][reihe] == 1 ) {
                // Eine Wand
                ofSetColor(0,0,255);
                ofDrawRectangle(spalte*size,reihe*size,(spalte+1)*size,(reihe+1)*size);
            } else if ( field[spalte][reihe] == 2 ) {
                // Eine Sammelpunkt
                ofSetColor(0,0,0);
                ofDrawRectangle(spalte*size,reihe*size,(spalte+1)*size,(reihe+1)*size);
                ofSetColor(255,255,255);
                ofDrawCircle((0.5+spalte)*size, (0.5+reihe)*size,2);
            } else {
                // Nix
                ofSetColor(0,0,0);
                ofDrawRectangle(spalte*size,reihe*size,(spalte+1)*size,(reihe+1)*size);
            }
        }
    }
}
