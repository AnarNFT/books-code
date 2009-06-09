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
// Headerdateien f�r verwendete Klassen
#include "linie.hpp"
#include "kreis.hpp"
#include "geoobj.hpp"

// Vorw�rtsdeklaration
void geoObjAusgeben (const Geo::GeoObj&);

int main()
{
    Geo::Linie l1 (Geo::Koord(1,2), Geo::Koord(3,4));
    Geo::Linie l2 (Geo::Koord(7,7), Geo::Koord(0,0));
    Geo::Kreis k (Geo::Koord(3,3), 11);

    // inhomogene Menge von geometrischen Objekten:
    Geo::GeoObj* menge[10];

    menge[0] = &l1;     // Menge enth�lt: - Linie l1
    menge[1] = &k;      //     - Kreis k
    menge[2] = &l2;     //     - Linie l2

    /* Elemente in der Menge ausgeben und verschieben
     * - es wird automatisch die richtige Funktion aufgerufen
     */
    for (int i=0; i<3; i++) {
        menge[i]->draw();
        menge[i]->move(Geo::Koord(3,-3));
    }

    // Linien einzeln �ber Hilfsfunktion ausgeben
    geoObjAusgeben(l1);
    geoObjAusgeben(k);
    geoObjAusgeben(l2);
}

void geoObjAusgeben (const Geo::GeoObj& obj)
{
    /* es wird automatisch die richtige Funktion aufgerufen
     */
    obj.draw();
}
