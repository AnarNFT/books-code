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
// Headerdatei f�r I/O
#include <iostream>

// Headerdateien f�r verwendete Klassen
#include "linie.hpp"
#include "kreis.hpp"
#include "gruppe.hpp"

int main()
{
    Geo::Linie l1 (Geo::Koord(1,2), Geo::Koord(3,4));
    Geo::Linie l2 (Geo::Koord(7,7), Geo::Koord(0,0));
    Geo::Kreis k (Geo::Koord(3,3), 11);

    Geo::GeoGruppe g;

    g.add(l1);            // GeoGruppe enth�lt: - Linie l1
    g.add(k);             //     - Kreis k
    g.add(l2);            //     - Linie l2

    g.draw();             // GeoGruppe ausgeben
    std::cout << std::endl;

    g.move(Geo::Koord(3,-3));  // GeoGruppen-Offset verschieben
    g.draw();                  // GeoGruppe nochmal ausgeben
    std::cout << std::endl;

    g.remove(l1);         // GeoGruppe enth�lt nur noch k und l2
    g.draw();             // GeoGruppe nochmal ausgeben
}
