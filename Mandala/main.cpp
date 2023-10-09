/**
 ** Algorithmen und Datenstrukturen
 ** OpenFrameworks App
 **
 ** <Mandala>
 **
 ** <Testatgruppe 2>
 ** <Lisa Golla; Neele Friederike Reiners>
 **/

#include "ofAuDApp.h"

//========================================================================

int main( ){


    // Mit dieser Anweisung wird ein Fenster in der angegebenen Größe
    // geöffnet und die App gestartet. Dabei wird im Grunde das folgende
    // Programm ausgeführt:
    //
    // setup();
    // while ( 1 == 1 ) {
    //    draw();
    // }
    //
    startAuDApp(1000,1000);
}

//========================================================================

// Die Initialisierung
void setup() {
    // Diese Operation wird beim Start der Applikation einmal ausgeführt.
    ofBackground(245,200,245);
}

//========================================================================

// Die Hauptschleife
void loop() {
    // Diese Operation wird fortlaufend wiederholt.
    ofNoFill();
    ofSetColor(0,0,0);

    //große Außenkreise
    ofDrawCircle(500, 500, 390);
    ofDrawCircle(500, 500, 360);

    //kleine untere Kreise
    ofDrawCircle(500, 740, 120);
    ofDrawCircle(500, 740, 90);

    //kleine obere Kreise
    ofDrawCircle(500, 260, 120);
    ofDrawCircle(500, 260, 90);

    //großer der kleinen mittleren Kreise
    ofDrawCircle(500, 500, 120);

    //kleiner gefüllter Kreis
    ofFill();
    ofSetColor(255, 20, 190);
    ofDrawCircle(500, 500, 90);
    ofSetColor(0,0,0);
    ofNoFill();

    //kleine linke Kreise
    ofDrawCircle(260, 500, 120);
    ofDrawCircle(260, 500, 90);

    //kleine rechte Kreise
    ofDrawCircle(740, 500, 120);
    ofDrawCircle(740, 500, 90);

    //coole farbverlauf Kreise
    for (int i=0; i<60; i++) {
        ofSetColor(i*4, 250-i*4, i*4);
        ofDrawCircle(500, 500, 390+i);
    }


}
