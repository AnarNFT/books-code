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
#ifndef LINIE_HPP
#define LINIE_HPP

// Headerdatei f�r I/O
#include <iostream>

// Headerdatei der Basisklasse
#include "geoobj.hpp"

namespace Geo {

/* Klasse Linie
 * - abgeleitet von GeoObj
 * - ein Linie besteht aus:
 *     - einem Anfangspunkt (Referenzpunkt, geerbt)
 *     - einem Endpunkt (neu)
 */
class Linie : public GeoObj {
  protected:
    Koord p2;    // zweiter Punkt, Endpunkt

  public:
    // Konstruktor f�r Anfangs- und Endpunkt
    Linie (const Koord& a, const Koord& b)
         : GeoObj(a), p2(b) {
    }

    // Ausgabe (jetzt auch implementiert)
    virtual void draw () const;

    // Verschieben (neu implementiert)
    virtual void move (const Koord&);

    // virtueller Destruktor
    virtual ~Linie () {
    }
};

/* Ausgabe
 * - inline definiert
 */
inline void Linie::draw () const
{
    std::cout << "Linie von " << refpunkt
              << " bis " << p2 << std::endl;
}

/* Verschieben
 * - inline neu implementiert
 */
inline void Linie::move (const Koord& offset)
{
    refpunkt += offset;    // entspricht GeoObj::move(offset);
    p2 += offset;
}

}  // namespace Geo

#endif // LINIE_HPP
