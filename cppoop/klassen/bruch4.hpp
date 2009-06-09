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
#ifndef BRUCH_HPP
#define BRUCH_HPP

// Standard-Headerdateien einbinden
#include <iostream>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

class Bruch {

  private:
    int zaehler;
    int nenner;

  public:
    /* Default-Konstruktor, Konstruktor aus Z�hler und
     * Konstruktor aus Z�hler und Nenner
     */
    Bruch (int = 0, int = 1);

    // Ausgabe (inline definiert)
    void print () const {
        std::cout << zaehler << '/' << nenner << std::endl;
    }

    // Multiplikation
    Bruch operator * (const Bruch&) const;
    
    // multiplikative Zuweisung
    const Bruch& operator *= (const Bruch&);
    
    // Vergleich
    bool operator < (const Bruch&) const;
};


/* Operator *
 * - inline definiert
 */
inline Bruch Bruch::operator * (const Bruch& b) const
{
    /* Z�hler und Nenner einfach multiplizieren
     * - das K�rzen sparen wir uns
     */
    return Bruch (zaehler * b.zaehler, nenner * b.nenner);
}

} // **** ENDE Namespace Bsp ********************************

#endif  // BRUCH_HPP
