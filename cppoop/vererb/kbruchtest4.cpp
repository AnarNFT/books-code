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
// Headerdateien
#include <iostream>
#include "kbruch.hpp"

int main()
{
    // KBruch deklarieren
    Bsp::KBruch x(7,3);

    /* x mit 3 multiplizieren
     * ABER: Operator der Basisklasse Bruch verwenden
     */
    x.Bsp::Bruch::operator *= (3);

    // x ausgeben
    std::cout << x;
    std::cout << (x.istKuerzbar() ? " (kuerzbar)" : " (unkuerzbar)")
              << std::endl;
}
