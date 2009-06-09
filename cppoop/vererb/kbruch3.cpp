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
// Headerdatei f�r min() und abs()
#include <algorithm>
#include <cstdlib>

// Headerdatei der eigenen Klasse einbinden
#include "kbruch.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* ggt()
 * - gr��ter gemeinsamer Teiler von Z�hler und Nenner
 */
unsigned KBruch::ggt () const
{
    if (zaehler == 0) {
        return nenner;
    }

    /* Gr��te Zahl ermitteln, die sowohl Z�hler als auch
     * Nenner ohne Rest teilt
     */
    unsigned teiler = std::min(std::abs(zaehler),nenner);
    while (zaehler % teiler != 0  ||  nenner % teiler != 0) {
        teiler--;
    }
    return teiler;
}

/* kuerzen()
 */
void KBruch::kuerzen ()
{
    // falls k�rzbar, Z�hler und Nenner durch GGT teilen
    if (kuerzbar) {
        int teiler = ggt();

        zaehler /= teiler;
        nenner  /= teiler;

        kuerzbar = false;       // damit nicht mehr k�rzbar
    }
}

/* Operator *=
 * - zum �berschreiben mit Typen der Basisklasse neu implementiert
 */
const KBruch& KBruch::operator*= (const Bruch& b)
{
    /* Implementierung der Basisklasse aufrufen
     * - auf nicht�ffentliche Komponenten von b besteht kein Zugriff
     */
    Bruch::operator*= (b);

    // weiterhin gek�rzt ?
    if (!kuerzbar) {
        kuerzbar = (ggt() > 1);
    }

    return  *this;
}

/* scanFrom()
 */
void KBruch::scanFrom (std::istream& strm)
{
    Bruch::scanFrom (strm);   // scanFrom() der Basisklasse aufrufen

    kuerzbar = (ggt() > 1);   // K�rzbarkeit testen
}

} // **** ENDE Namespace Bsp ********************************
