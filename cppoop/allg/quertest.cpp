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
// Headerdatei mit der Deklaration von quersumme() einbinden
#include "quer.hpp"

// Headerdatei f�r I/O einbinden
#include <iostream>

// Vorw�rtsdeklaration von gibQuersummeAusVon()
void gibQuersummeAusVon(long);

// Implementierung von main()
int main()
{
    gibQuersummeAusVon(12345678);
    gibQuersummeAusVon(0);
    gibQuersummeAusVon(13*77);
}

// Implementierung von gibQuersummeAusVon()
void gibQuersummeAusVon (long zahl)
{
    std::cout << "Die Quersumme von " << zahl
              << " ist " << quersumme(zahl) << std::endl;
}
