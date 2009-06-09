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
  protected:
    int zaehler;
    int nenner;

  public:
    /* Fehlerklasse
     */
    class NennerIstNull {
    };

    /* Default-Konstruktor, Konstruktor aus Z�hler und
     * Konstruktor aus Z�hler und Nenner
     */
    Bruch (int = 0, int = 1);

    /* Multiplikation
     * - globale Friend-Funktion, damit eine automatische
     *     Typumwandlung des ersten Operanden m�glich ist
     */
    friend Bruch operator * (const Bruch&, const Bruch&);
    
    // multiplikative Zuweisung
    const Bruch& operator *= (const Bruch&);
    
    /* Vergleich
     * - globale Friend-Funktion, damit eine automatische
     *     Typumwandlung des ersten Operanden m�glich ist
     */
    friend bool operator < (const Bruch&, const Bruch&);

    // Ein- und Ausgabe mit Streams
    void printOn (std::ostream&) const;
    void scanFrom (std::istream&);

    // Typumwandlung nach double
    double toDouble () const;
};

/* Operator *
 * - globale Friend-Funktion
 * - inline definiert
 */
inline Bruch operator * (const Bruch& a, const Bruch& b)
{
    /* Z�hler und Nenner einfach multiplizieren
     * - das K�rzen sparen wir uns
     */
    return Bruch (a.zaehler * b.zaehler, a.nenner * b.nenner);
}

/* Standard-Ausgabeoperator
 * - global �berladen und inline definiert
 */
inline
std::ostream& operator << (std::ostream& strm, const Bruch& b)
{
    b.printOn(strm);    // Elementfunktion zur Ausgabe aufrufen
    return strm;        // Stream zur Verkettung zur�ckliefern
}

/* Standard-Eingabeoperator
 * - global �berladen und inline definiert
 */
inline
std::istream& operator >> (std::istream& strm, Bruch& b)
{
    b.scanFrom(strm);   // Elementfunktion zur Eingabe aufrufen
    return strm;        // Stream zur Verkettung zur�ckliefern
}

} // **** ENDE Namespace Bsp ********************************

#endif  // BRUCH_HPP
