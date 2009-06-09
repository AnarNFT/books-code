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
#ifndef KREIS_HPP
#define KREIS_HPP

// Headerdatei f�r I/O
#include <iostream>

// Headerdatei der Basisklasse
#include "geoobj.hpp"

namespace Geo {

/* Klasse Kreis
 * - abgeleitet von GeoObj
 * - ein Kreis besteht aus:
 *     - Mittelpunkt (Referenzpunkt, geerbt)
 *     - Radius (neu)
 */
class Kreis : public GeoObj {
  protected:
    unsigned radius;    // Radius

  public:
    // Konstruktor f�r Mittelpunkt und Radius
    Kreis (const Koord& m, unsigned r)
         : GeoObj(m), radius(r) {
    }

    // Ausgabe (jetzt auch implementiert)
    virtual void draw () const;

    // virtueller Destruktor
    virtual ~Kreis () {
    }
};

/* Ausgabe
 * - inline definiert
 */
inline void Kreis::draw () const
{
    std::cout << "Kreis um Mittelpunkt " << refpunkt
              << " mit Radius " << radius << std::endl;
}

}  // namespace Geo

#endif // KREIS_HPP
