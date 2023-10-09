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
#include "list.h"
#include "field.h"

//=== Die globalen Variablen =============================================

AuDMan *audMan;     // Ein Objekt der Klasse AuDMan
Level *level;       // Ein Objekt der Klasse Level
List *liste = nullptr;
Field *field;



//========================================================================

int main() {
    level = new Level(20);
    audMan = new AuDMan();
    audMan->setLevel(level);

    startAuDApp((level->getWidth() * level->getSize()), (level->getWidth() * level->getSize()));
}

//========================================================================
void setup() {
    level->init();
    audMan->setPosition(1, 1);
    audMan->setLevel(level);
    field = new Field();
    liste = new List();
    Field *head = new Field(1,1,0);
    liste->prepend(head);
    ofSetFrameRate(10);
}

void bewegen(){

    // Er geht nach rechts
    if(((level->getField(audMan->getPosX() + 1,audMan->getPosY()))->getValue() == 2)
            || ((level->getField(audMan->getPosX() + 1,audMan->getPosY()))->getValue() == 3)) {
        audMan->moveBy(1,0);
        liste->prepend(level->getField(audMan->getPosX(),audMan->getPosY()));
        audMan->draw();
    }
    // Er geht nach links
    else if(((level->getField(audMan->getPosX() - 1,audMan->getPosY()))->getValue() == 2)
            || ((level->getField(audMan->getPosX() - 1,audMan->getPosY()))->getValue() == 3)) {
        audMan->moveBy(-1,0);
        liste->prepend(level->getField(audMan->getPosX(),audMan->getPosY()));
        audMan->draw();
    }
    // Er geht nach unten
    else  if(((level->getField(audMan->getPosX(),audMan->getPosY()+1))->getValue() == 2)
             || (level->getField(audMan->getPosX(),audMan->getPosY()+1)->getValue() == 3)) {
        audMan->moveBy(0,1);
        liste->prepend(level->getField(audMan->getPosX(),audMan->getPosY()));
        audMan->draw();
    }

    // Er geht nach oben
    else if ((level->getField(audMan->getPosX(),audMan->getPosY()-1)->getValue() == 2)
             || ((level->getField(audMan->getPosX(),audMan->getPosY()-1))->getValue() == 3)){
        audMan->moveBy(0,-1);
        liste->prepend(level->getField(audMan->getPosX(),audMan->getPosY()));
        audMan->draw();
    }

    // Er muss seinen Weg zurückgehen

    else  {
        if(liste->getHead()!=liste->getTail()){
            liste->removeHead();
            audMan->setPosition(liste->getHead()->getX(),liste->getHead()->getY());
            audMan->draw();
        }
        else {
            ofSetColor(255,255,255);
            ofDrawBitmapString("Alle Punkte eingesammelt", ofGetWidth()/4, ofGetWidth()/3,0);
        }
    }
}








//========================================================================

// Die Hauptschleife
void loop() {
    level->draw();
    bewegen();
}
