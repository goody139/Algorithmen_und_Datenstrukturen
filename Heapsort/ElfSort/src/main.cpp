/**
 ** Algorithmen und Datenstrukturen
 ** OpenFrameworks App
 **
 ** <Beschreibung>
 **
 ** <Autoren>
 **/

#include "ofAuDApp.h"
#include "present.h"


int anzahl = 10;
Present *presents[10];
int number[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
int rechts = 1;  // Index
bool done = false;  // gibt an, ob die Zahlen sortiert wurden

//========================================================================

int main(){

    startAuDApp(1024,768);
}

//========================================================================

// Die Initialisierung
void setup() {

    int x = 0;

    // die Nummern werden zufällig und nicht in der geordneten Reihenfolge angegeben
    std::random_shuffle(std::begin(number), std::end(number));

    // legt die Position der Geschenke fest
    for ( int i = 0; i < anzahl; i = i+1 ) {

        x = 100 + x;
        int y = 300;

        presents[i] = new Present(x, y, number[i]);

    }

    // setzt die Geschwindigkeit der Ausführung herunter
    ofSetFrameRate(3);
}

//========================================================================

// Die Hauptschleife
void loop() {

    // zeichnet die Geschenke
    for ( int i = 0; i < anzahl; i = i+1 ) {

        int a = presents[i]->getPosX();
        int b = presents[i]->getPosY();

        presents[i]->drawPresent(a,b);
    }

    // Abhängigkeit von rechts
    int links = rechts -1;

    if(!done){

        if (presents[rechts]->getNumber() >= presents[links]->getNumber() ) {
            // Zeichnet die Pfeile unter den Geschenken
            presents[rechts]->drawArrowgreen(presents[rechts]->getPosX(),presents[rechts]->getPosY());
            presents[links]->drawArrowRed(presents[links]->getPosX(),presents[links]->getPosY());
            rechts ++;
        } else {
            presents[links]->drawArrowgreen(presents[links]->getPosX(),presents[links]->getPosY());
            presents[rechts]->drawArrowRed(presents[rechts]->getPosX(),presents[rechts]->getPosY());

            // die beiden betrachteten Geschenke werden vertauscht
            int x = presents[links]->getNumber();
            int y = presents [rechts]->getNumber();
            presents[links]->setNumber(y);
            presents[rechts]->setNumber(x);
            rechts --;

            // verhindert, dass der Index links auf kein Geschenk zeigt
            if ( rechts == 0) {
                rechts = 1;
            }
          }

        // verhindert, dass der Index rechts auf kein Geschenk zeigt
        if (rechts == 10){
          rechts = 9;
        }

        // legt fest, wann das Sortieren abgeschlossen ist
        if (rechts == 9 && links == 8){
            presents[links]->drawArrowgreen(presents[links]->getPosX(),presents[links]->getPosY());
            presents[rechts]->drawArrowRed(presents[rechts]->getPosX(),presents[rechts]->getPosY());
            done = true;
        }
    }
}






