/* cppbuch/k1/case.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
    int j, zahl = 0;
    cout << "Zahl eingeben:";
    cin >> zahl;

    switch (zahl) {
        case 1 : cout << "1 gew�hlt\n"; // siehe Text unten
        case 2 : cout << "2 gew�hlt\n";
        case 3 : cout << "3 gew�hlt\n"; break;
        case 4 : cout << "4 gew�hlt\n"; break;
        case 5 : cout << "5 gew�hlt\n"; break;

        // geschachteltes switch
        case 6 : j = 2*zahl;
                 switch(j) {  // j = 12
                    case 12 : cout << "j==12 !\n"; break;
                    default : cout << "merkw�rdig!\n"; break;
                 } break;
        case 7:
        case 8:
        case 9: cout << "7, 8 oder 9 gew�hlt\n";break;
        default : cout << "keine �bereinstimmung gefunden\n";
    }
}
