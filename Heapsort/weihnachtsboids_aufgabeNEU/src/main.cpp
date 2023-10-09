/**
 ** Algorithmen und Datenstrukturen
 ** OpenFrameworks App
 **
 ** Diese Programm lässt zwei Geschenke auf zufällige
 ** Bewegen.
 **
 ** Michael Brinkmeier <mbrinkmeier@uni-osnabrueck.de>
 ** Laura Hembrock <lhembrock@uni-osnabrueck.de>
 **/

#include "ofAuDApp.h"
#include "present.h"
#include "grantelbart.h"

//========================================================================

int anzahl = 10;
Present *presents[10];  // Die Boids als Pointer
Grantelbart *grantelbart;
//========================================================================

// Verschiebt den Zielpunkt des Boids, sobald er diesen erreicht hat
void verschiebeZiel(Present *present) {
    if ( ( present->getTargetX() == present->getX()) &&
         ( present->getTargetY() == present->getY()) ) {
        present->setTarget(ofRandomWidth(),ofRandomHeight());
    }
}

//========================================================================

int main( ){
    startAuDApp(1024,768);
}

//========================================================================

// Die Initialisierung
void setup() {
    int x = 0;
    int y = 0;

    for ( int i = 0; i < anzahl; i = i+1 ) {
        x = ofRandomWidth();
        y = ofRandomHeight();

        presents[i] = new Present(x,y,3);
        presents[i]->setTarget(x,y);
    }

    grantelbart = new Grantelbart ();
    grantelbart->setPosition(ofGetWidth()/2, ofGetHeight()/2);
}

//========================================================================

// Die Hauptschleife
void loop() {
    for ( int i = 0; i < anzahl; i = i+1 ) {
        verschiebeZiel(presents[i]);
        presents[i]->move();
        presents[i]->draw();
    }

    grantelbart ->draw();


    //  Closest-Neigbours-Algorithmus angewandt
    for (int i = 0; i < anzahl; i = i+1){
        float distanzX = presents[i]->getX() - grantelbart->getPosX();
        float distanzY = presents[i]->getY() - grantelbart->getPosY();
        float totaldisi = sqrt((distanzX*distanzX)+(distanzY*distanzY));
        int minimumdis = 100;
        if( minimumdis > totaldisi) {
            minimumdis = totaldisi;
        }
        // lässt Geschenke, die "zu nah" an Grantelbart sind verschwinden
        if (minimumdis < 98) {
            presents[i] = presents[anzahl-1];
            anzahl = anzahl -1;
        }
    }
}
