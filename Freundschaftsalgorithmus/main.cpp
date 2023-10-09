/**
 ** Einführung in Algorithmen und Datenstrukturen
 ** Vorlage für ein Konsolenprogramm
 **
 ** <Freundschaftsalgorithmus>
 **
 ** <Testatgruppe 2>
 ** <Lisa Golla; Neele Friederike Reiners>
 **/

#include <iostream>		// Importiere die Standard Ein- und Ausgabe
#include <string>			// Importiere die String Klasse

using namespace std;  // Verwende den Standard Namensraum std

//========================================================================

bool dieantwoord(){         //am ende wollen wir einen wahrheitswert, um die abfrage im main zu vereifachen
    string antwort;

    cout << "j = Ja!" << endl << "n = Nein." << endl;
    cin >> antwort;

    while(!(antwort == "j" || antwort == "n")) {        //solang die antwort nicht richtig ist, wird cin gelöscht und die schleife wiederholt
        antwort.clear();
        cout << "Gib bitte ein j oder ein n als deine Antwort ein!" << endl;
        cin >> antwort;
    }

    if(antwort == "j"){
        return true;
    }
    return false;
}


void dieterminvergabe(){
    string termin;

    cout << "Ich habe am Montag um 18 Uhr Zeit,"
            " am Dienstag gegen 19 Uhr und am Donnerstag passt es mir super um 18 Uhr! Wann kannst Du?" << endl;
    cout << "MO = Montag um 18 Uhr" << endl << "DI = Dienstag um 19 Uhr" << endl << "DO = Donnerstag um 18 Uhr" << endl;

    cin >> termin;

    while (!(termin == "MO" || termin == "DI" || termin == "DO")){      //Wenn nicht einer der tage eingegeben wird, muss termin neu eingegeben werden
        cout << "Gib bitte ein MO, ein DI oder ein DO als Antwort ein!" << endl;
        termin.clear();
        cin >> termin;
    }

    if (termin == "MO"){
        cout << "Bis Montag! Ich freue mich." << endl;
        return;
    }

    if (termin == "DI"){
        cout << "Bis Dienstag! Ich freue mich." << endl;
        return;
    }

    if (termin == "DO"){
        cout << "Bis Donnerstag! Ich freue mich." << endl;
        return;
    }
}

string termin;
string getraenk;
int x;
int n;

// Das Hauptprogramm
int main(){

    //Telefonanruf

    cout << "Ring Ring, hast Du Zeit fuer ein kurzes Gespraech?" << endl;

    if(dieantwoord()){      //dieantwoord gibt true und false aus, daher sieht der computer nur true oder false, wenn true führt der aus, wenn false nicht
        cout << "Hallo, ich bin Sheldon Cooper. Ich wuerde gerne Dein Freund sein!" << endl;
        cout << "Wollen wir gemeinsam etwas Essen gehen?" << endl;

        if (dieantwoord()){
            dieterminvergabe();
        }       //dieantwoord wird abgefragt, wenn true, dann wird dieterminvergabeabgefragt bis zum ende des programmes

        //Heissgetraenk abfrage

        else{
            cout << "Wollen wir stattdessen ein Heissgetraenk trinken gehen?" << endl;

            if (dieantwoord()){
                cout << "Schoen, wollen wir einen Kakao, einen Tee oder einen Kaffee trinken gehen?" << endl;
                cout << "Kakao = Kakao" << endl << "Tee = Tee" << endl << "Kaffee = Kaffee" << endl;
                cin >> getraenk;

                while (!(getraenk == "Kaffee" || getraenk == "Kakao" || getraenk == "Tee")){        //Wenn ungültige Antwort eingegeben, dann wird immer neu nach getraenk abgefragt
                    cout << "Gib bitte Tee, Kaffee oder Kakao als deine Antwort ein!"<< endl;
                    getraenk.clear();
                    cin >> getraenk;
                }

                if (getraenk == "Kaffee" || getraenk == "Kakao" || getraenk == "Tee"){
                    cout << "Toll, dann treffen wir uns auf einen "<< getraenk << "." << endl;
                    dieterminvergabe();
                }
            }

            // Interessen von Person erfragen

            else {
                cout << "Was interessiert Dich?" << endl;
                int bisherKleinstes = 8;
                for (int n=0; n<4; n++){
                    cout << "1 = Zuege anschauen" << endl << "2 = Technik Neuheiten shoppen gehen" << endl << "3 = Star Wars schauen" << endl;
                    cout << "4 = kochen" << endl << "5 = toepfern" << endl << "6 = klettern" << endl << "7 = schwimmen" << endl;
                    cout <<"8 = Voegel anschauen" << endl;
                    cin >> x;

                    //für die Fehlerbehebung
                    while(x<1 || x > 8){


                        fflush(stdin);
                        cin.clear();
                        cout << "Gib bitte eine Zahl von 1 bis 8 ein" << endl;


                        cin >> x;


                    }

                    //pruefen ob richtige zahl
                    //wenn x > 3 ist
                    if(x > 3){
                        if(x < bisherKleinstes){
                            bisherKleinstes = x;
                        }
                    }
                    //gucken ob x kleiner als bisher kleinstes
                    switch (x){
                    case 1:
                        cout << "Toll, wir gehen Zuege anschauen!" << endl;
                        dieterminvergabe();
                        return 0;
                    case 2:
                        cout << "Klasse, ich muss mich noch zwischen der X-Box und der Playstation entscheiden!" << endl;
                        dieterminvergabe();
                        return 0;
                    case 3:
                        cout << "Super, ich habe alle Filme zuhause!" << endl;
                        dieterminvergabe();
                        return 0;
                    default:
                        if(n != 3){
                            cout << "das mache ich nicht so gerne, kannnst du dir noch etwas anderes aussuchen?" << endl;
                        }
                        break;
                    }
                }
                cout << "Ok, wir haben keine gemeinsamen Interessen gefunden." << endl;
                switch(bisherKleinstes){
                case 4:
                    cout << "Lass uns einfach kochen." << endl;
                    break;
                case 5:
                    cout << "Lass uns einfach toepfern." << endl;
                    break;
                case 6:
                    cout << "Lass uns einfach klettern gehen." << endl;
                    break;
                case 7:
                    cout << "Lass uns einfach schwimmen gehen." << endl;
                    break;
                case 8:
                    cout << "Lass uns einfach Voegel anschauen." << endl;
                    break;
                }
                dieterminvergabe();
            }
        }
    }
    else{
        cout << "Ruf mich bitte zurueck!" << endl;
        if (dieantwoord()){
            return main();
        }
    }
}






