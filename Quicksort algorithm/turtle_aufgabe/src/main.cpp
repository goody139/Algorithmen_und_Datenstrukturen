/**
 ** Algorithmen und Datenstrukturen
 ** OpenFrameworks App
 **
 ** Ein Demoprogramm für die Turtle
 **
 ** Michael Brinkmeier <mbrinkmeier@uni-osnabrueck.de>
 **/

#include "ofAuDApp.h"
#include "ofaudturtle.h"

ofAuDTurtle turtle;

// die Winkel, um die sich gedreht wird
double rechts = 60;
double links = 120;

//========================================================================

int main(){
    startAuDApp(1024, 768);
}

//========================================================================

// Die Initialisierung
void setup() {
    turtle.reset();
}

//========================================================================

// Zeichnet rekursiv eine Kochsche Schneeflocke mit der ofAuDTurtle
// Ändern Sie diesen
void koch(ofAuDTurtle *turtle, double len, int depth) {

    if (depth > 1) {
        // mit jeder rekursionstiefe wird len durch 3 geteilt
        len = len / 3;
        koch(turtle,len, depth-1);
        turtle->turn(-rechts);
        koch(turtle,len, depth-1);
        turtle->turn(links);
        koch(turtle,len, depth-1);
        turtle->turn(-rechts);
        koch(turtle,len, depth-1);
    }
    else {
        turtle->move(len);
    }
}



//========================================================================

// Die Hauptschleife
void loop() {

    // ruft die Operation koch auf
    koch(& turtle, 300, 5);
    turtle.turn(120);


    turtle.draw();

}
