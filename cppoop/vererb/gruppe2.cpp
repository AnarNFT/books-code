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
#include "gruppe.hpp"
#include <algorithm>

namespace Geo {

/* add
 * - Element einf�gen
 */
void GeoGruppe::add (GeoObj& obj)
{
    // Adresse vom geometrischen Objekt eintragen
    elems.push_back(&obj);
}

/* remove
 * - Element l�schen
 */
bool GeoGruppe::remove (GeoObj& obj)
{
    // erstes Element mit dieser Adresse finden
    std::vector<GeoObj*>::iterator pos;
    pos = std::find(elems.begin(),elems.end(),
                    &obj);
    if (pos != elems.end()) {
        elems.erase(pos);
        return true;
    }
    else {
        return false;
    }
}

/* draw
 * - alle Elemente unter Ber�cksichtigung des Referenzpunktes ausgeben
 */
void GeoGruppe::draw () const
{
    for (unsigned i=0; i<elems.size(); ++i) {
        elems[i]->move(refpunkt);   // Offset f�r den Referenzpunkt addieren
        elems[i]->draw();           // Element ausgeben
        elems[i]->move(-refpunkt);  // Offset wieder entfernen
    }
}

}  // namespace Geo
