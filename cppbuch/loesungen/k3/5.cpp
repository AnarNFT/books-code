/* cppbuch/loesungen/k3/5.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include<iostream>
#include<cctype>
using namespace std;

// ********** Funktionsprototypen **********
long zahl(char& c);
long ausdruck(char& c);
long summand(char& c);
long faktor(char& c);

// ********** Hauptprogramm **********
int main() {
    char ch;
    do {
        cout << "\n>>";
        cin.get(ch);
        if (ch != 'e')
            cout << ausdruck(ch);
    } while(ch != 'e');
}

// ********** Funktionsdefinitionen **********
long ausdruck(char& c) {         // �bergabe per Referenz!
    long a;                      // Hilfsvariable f�r Ausdruck
    if (c == '-') {
        cin.get(c);              // {\tt -} im Eingabestrom �berspringen
        a = -summand(c);            // Rest an {\tt summand()} �bergeben
    }
    else {
        if (c == '+')
            cin.get(c);          // {\tt +} �berspringen
        a = summand(c);
    }
    while(c == '+' || c == '-')
        if (c == '+') {
           cin.get(c);           // {\tt +} �berspringen
           a += summand(c);
        }
        else {
           cin.get(c);           // {\tt -} �berspringen
           a -= summand(c);
        }
    return a;
}

long summand(char& c) {
    long s = faktor(c);
    while(c == '*' || c == '/')
        if (c == '*') {
            cin.get(c);          // {\tt *} �berspringen
            s *= faktor(c);
        }
        else {
           cin.get(c);           // {\tt /} �berspringen
           s /= faktor(c);
        }
    return s;
}

long faktor(char& c) {
    long f;

    if (c == '(') {
        cin.get(c);                    // {\tt (} �berspringen
        f = ausdruck(c);
        if (c != ')' )
           cout << "Rechte Klammer fehlt!\n"; //*** s.u.
        else cin.get(c);               // {\tt )} �berspringen
    }
    else f = zahl(c);
    return f;
}

long zahl(char& c) {
    long z = 0;
    while (isdigit(c)) {
        z = 10*z + long(c-'0');
        cin.get(c);
    }
    return z;
}

