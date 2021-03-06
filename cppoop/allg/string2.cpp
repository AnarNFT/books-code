/* Die folgenden Code-Beispiele stammen aus dem Buch:
 *  Objektorientiertes Programmieren in C++
 *   Ein Tutorial f�r Ein- und Umsteiger
 * von Nicolai Josuttis, Addison-Wesley M�nchen, 2001
 *
 * (C) Copyright Nicolai Josuttis 2001.
 * Diese Software darf kopiert, verwendet, modifiziert und verteilt
 * werden, sofern diese Copyright-Angabe in allen Kopien vorhanden ist.
 * Diese Software wird "so wie sie ist" zur Verf�gung gestellt.
 * Es gibt keine explizite oder implizite Garantie �ber ihren Nutzen.
 */
#include <iostream>    // C++-Headerdatei f�r I/O
#include <string>      // C++-Headerdatei f�r Strings

int main ()
{
    const std::string k = "Eingabe: ";  // String-Konstante
    std::string text;                   // String-Variable
    std::string s;                      // String-Variable f�r Eingabe

    // String s einlesen
    if (! (std::cin >> s)) {
        // Einlesefehler
        //...
    }

    // String mit Leerstring vergleichen
    if (s == "") {
        // String-Literal an String text zuweisen
        text = "keine Eingabe";
    }
    else {
        /* String-Konstante k, gefolgt von eingelesenem String,
         * an text zuweisen
         */
        text = k + s;
    }
    //...
}
