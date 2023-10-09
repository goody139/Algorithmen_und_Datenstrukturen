/**
 ** Algorithmen und Datenstrukturen
 ** OpenFrameworks App
 **
 ** Dies ist eine Implementierung einer einfachen Variante eines
 ** Spieleklassikers. Dabei verwenden wir Klassen und Objekte.
 **
 ** Michael Brinkmeier <mbrinkmeier@uni-osnabrueck.de>
 **/

#include "ofAuDApp.h"
#include "level.h"
#include "audman.h"
#include "ghost.h"

//=== Die globalen Variablen =============================================

AuDMan *audMan;     // Ein Objekt der Klasse AuDMan
Level *level;       // Ein Objekt der Klasse Level
GHOST *ghost;       // Ein Objekt der Klasse GHOST

//========================================================================

int main( ){
    level = new Level(20);
    audMan = new AuDMan();
    audMan->setLevel(level);
    ghost = new GHOST();
    ghost->setLevel(level);

    startAuDApp(level->getWidth()*level->getSize(),level->getWidth()*level->getSize());

}

//========================================================================

// Die Initialisierung
void setup() {
    level->init();
    audMan->setPosition(1,1);
    audMan->setLevel(level);
    ghost->setPosition(10,1);
    ghost->setLevel(level);

}

//========================================================================

// Die Hauptschleife
int zaehl = 0;
void loop() {
    level->draw();
    audMan->draw();
    ghost->draw();

    zaehl++;
    // nur jedes 15. Mal, das Loop geöffnet wird, wird die darunter liegende if
    if((zaehl % 15) == 0){
        ghost->move();
        // dem AuDMan werden 4 Punkte abgezogen, wenn der Geist den AuDMan berührt
        if (ghost -> getPosX() == audMan -> getPosX() && ghost -> getPosY() == audMan -> getPosY()) {
            audMan -> setPoints((audMan -> getPoints() -4 ));
        }
    }
}



//=========================================================================


void keyPressed(int key) {
    if ( key == OF_KEY_RIGHT ) {
        audMan->moveBy(1,0);
    } else if ( key == OF_KEY_LEFT ) {
        audMan->moveBy(-1,0);
    } else if ( key == OF_KEY_UP ) {
        audMan->moveBy(0,-1);
    } else if ( key == OF_KEY_DOWN ) {
        audMan->moveBy(0,1);
    }

    // dem AuDMan werden 4 Punkte abgezogen, wenn er in den Geist läuft
    if(audMan->getPosX() == ghost ->getPosX() && audMan -> getPosY() == ghost -> getPosY()) {
        audMan -> setPoints((audMan -> getPoints()-4));
    }


}



