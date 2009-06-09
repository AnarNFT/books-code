/* cppbuch/k5/wmatrix.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Schreiben einer Matrix als ASCII- und als bin�re Datei
// (siehe auch �bungsaufgabe)
#include<cstdlib>
#include<fstream>
#include<iostream>

using namespace std;

int main() {
    const int ZEILEN  = 10,
              SPALTEN =  8;

    double matrix[ZEILEN][SPALTEN];

    // Matrix mit Werten f�llen
    for(int i = 0; i < ZEILEN; ++i)
        for(int j = 0; j < SPALTEN; ++j)
            matrix[i][j] =  i+1 + (j+1)/1000.0;

    // Schreiben als ASCII-Datei (lesbar mit Editor)
    ofstream ziel;
    ziel.open("matrix.asc");
    if (!ziel) {
        cerr << "Datei kann nicht ge�ffnet werden!\n";
        exit(-1);
    }

    // formatiertes Schreiben
    for(int i = 0; i < ZEILEN; ++i)
    {   for(int j = 0; j < SPALTEN; ++j) {
             ziel.width(8);
             ziel << matrix[i][j];
        }
        ziel << endl;
    }

    // Datei schlie�en, damit {\tt ziel} wiederverwendet werden kann:
    ziel.close();

    // Schreiben als bin�re Datei
    ziel.open("matrix.bin",ios::binary|ios::out);
    if (!ziel) {
        cerr << "Datei kann nicht ge�ffnet werden!\n";
        exit(-1);
    }
    ziel.write(reinterpret_cast<const char*>(matrix), sizeof(matrix));
}   // automatisches {\tt close()}
