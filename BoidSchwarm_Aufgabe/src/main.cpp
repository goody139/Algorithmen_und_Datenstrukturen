/**
 ** Algorithmen und Datenstrukturen
 ** OpenFrameworks App
 **
 ** <Beschreibung>
 **
 ** <Autoren>
 **/

#include "ofAuDApp.h"
#include "speedboid.h"

//=== Globale Variablen ==================================================

int anzahl = 20;

SpeedBoid boids[20];

//========================================================================

int main( ){
    startAuDApp(1024,768);
}

//ofVec2f ist eine Klasse, um einen zweidimensionalen Vektor zu speichern

// ein boid ist immer genau in der mitte von mehreren Boids
ofVec2f zusammenhalt(SpeedBoid b){
    ofVec2f zusammenhaltvec;
    int zaehler = 0;

    //zaehlt durch von 0-19 um durch das array zu gehen
    for(int i = 0; i<anzahl; i++){

        //position von 2 boids darf nicht gleich sein
        if(b.getNummer() != boids[i].getNummer()){

            // addiert die position auf zusammenhaltvec
            zusammenhaltvec = zusammenhaltvec + boids[i].getPositionvektor();
        }
    }
    //Mittelpunkt
    zusammenhaltvec = zusammenhaltvec/(anzahl-1);
    // return berechnet den Vektor
    return (zusammenhaltvec-b.getPositionvektor())/150;
}

ofVec2f seperation(SpeedBoid b){
    ofVec2f seperationvec;
    for(int i = 0; i<anzahl; i++){
        if(b.getNummer() != boids[i].getNummer()){
            // Um eine Ballung zu vermeiden wird ein Abstand festgelegt
            if((b.getPositionvektor() - boids[i].getPositionvektor()).length() < 20){
                seperationvec = seperationvec - (boids[i].getPositionvektor() - b.getPositionvektor());
            }
        }
    }
    return seperationvec;
}

ofVec2f angleichung(SpeedBoid b){
    ofVec2f angleichungvec;
    int zaehler = 0;

    for(int i = 0; i<anzahl; i++){
        if(b.getNummer() != boids[i].getNummer()){

            angleichungvec = angleichungvec + boids[i].getGeschwindigkeitsvektor();

        }
    }
    angleichungvec = angleichungvec/(anzahl-1);
    return (angleichungvec-b.getGeschwindigkeitsvektor())/10;
}

// verhindert, dass Boids den Bildschirm verlassen
ofVec2f stayscreen(SpeedBoid b){
    ofVec2f v;
    if(b.getPositionvektor().x<30){
        v.x = 10;
    }
    if(b.getPositionvektor().x>ofGetWidth()-30){
        v.x = -10;
    }
    if(b.getPositionvektor().y<30){
        v.y = 10;
    }
    if(b.getPositionvektor().y>ofGetHeight()-30){
        v.y = -10;
    }
    return v;
}



//========================================================================

// Die Initialisierung
void setup() {
    for ( int i = 0; i < anzahl; i=i+1 ) {
        boids[i].setPosition(ofGetWindowWidth()/2,ofGetWindowHeight()/2);
        boids[i].setSpeed(ofRandom(-5,5),ofRandom(-5,5));
        boids[i].setNummer(i);
    }
}

//========================================================================

// Die Hauptschleife
void loop() {
    //damit Regeln v1 bis v4 angewandt werden können, wird hier totalvektor deklariert
    ofVec2f vtotal,v1,v2,v3,v4;

    for ( int i = 0; i < anzahl; i=i+1 ) {
        v1 = zusammenhalt(boids[i]);
        v2 = seperation(boids[i]);
        v3 = angleichung(boids[i]);
        v4 = stayscreen(boids[i]);

        // totalgeschwindigkeit
        vtotal = boids[i].getGeschwindigkeitsvektor() + v1 + v2 + v3 + v4;
        vtotal.normalize();
        // multipliziert mit 10, da sonst der Wert deines floats in einem integer gesp. wird und kommastellen weggelassen werden, sodass Vektoren 0 wären
        vtotal = vtotal * 10;
        boids[i].setSpeed(vtotal.x, vtotal.y);
        boids[i].move();
        boids[i].draw();
    }
}



