/* cppbuch/k1/menu.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
using namespace std;

int main() {
    char c;
    while(true) {
        cout << "W�hlen Sie: a, b, x = Ende : ";
        cin >> c;

        if (c == 'a') {
           cout << "Programm a\n";
           continue;                 // zur�ck zur Auswahl
        }

        if (c == 'b') {
           cout << "Programm b\n";
           continue;                 // zur�ck zur Auswahl
        }

        if (c == 'x') {
            break;           //  Schleife verlassen
        }
        cout << "Falsche Eingabe! Bitte wiederholen!\n";
    }
    cout << "\n Programmende mit break\n";
}
