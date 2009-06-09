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
#include "string.hpp"  // C++-Headerdatei f�r Strings

int main ()
{
    typedef Bsp::String string;

    // zwei Strings anlegen
    string vorname = "Jicolai";
    string nachname = "Nosuttis";
    string name;

    // die ersten Zeichen der Strings vertauschen
    char c = vorname[0];
    vorname[0] = nachname[0];
    nachname[0] = c;

    std::cout << vorname << ' ' << nachname << std::endl;
}
