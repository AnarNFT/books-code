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
#include <iostream>
#include <string>
#include "max.hpp"

int main()
{
    int         a, b;  // zwei Variablen vom Datentyp int
    std::string s, t;  // zwei Variablen der Klasse std::string
    //...
    std::cout << max(a,b) << std::endl;    // max() f�r zwei ints
    std::cout << max(s,t) << std::endl;    // max() f�r zwei Strings
}
