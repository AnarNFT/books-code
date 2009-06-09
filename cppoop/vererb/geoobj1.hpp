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
#ifndef GEOOBJ_HPP
#define GEOOBJ_HPP

// Headerdatei f�r Koord
#include "koord.hpp"

namespace Geo {

/* abstrakte Basisklasse GeoObj
 * - gemeinsame Basisklasse f�r geometrische Objekte
 * - zur Vererbung vorgesehen
 */
class GeoObj {
  protected:
    // Jedes GeoObj hat einen Referenzpunkt
    Koord refpunkt;

    /* Konstruktor f�r Startwert vom Referenzpunkt
     * - nicht�ffentlich
     * - damit ist kein Default-Konstruktor vorhanden
     */
    GeoObj (const Koord& p) : refpunkt(p) {
    }

  public:
    // GeoObj um relativen Offset verschieben
    virtual void move (const Koord& offset) {
        refpunkt += offset;
    }

    /* GeoObj ausgeben
     * - rein virtuelle Funktion
     */
    virtual void draw () const = 0;

    // virtueller Destruktor
    virtual ~GeoObj () {
    }
};

}  // namespace Geo

#endif  // GEOOBJ_HPP
