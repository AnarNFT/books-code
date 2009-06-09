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
// Headerdatei der Klasse einbinden
#include "bruch.hpp"

// Standard-Headerdateien einbinden
#include <cstdlib>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* neu: Default-Konstruktor, Konstruktor aus ganzer Zahl und
 * Konstruktor aus Z�hler und Nenner in einem
 * - Default f�r z: 0
 * - Default f�r n: 1
 */
Bruch::Bruch (int z, int n)
{
    /* Z�hler und Nenner wie �bergeben initialisieren
     * - 0 als Nenner ist allerdings nicht erlaubt
     * - ein negatives Vorzeichen des Nenners kommt in den Z�hler
     */
    if (n == 0) {
        // Programm mit Fehlermeldung beenden
        std::cerr << "Fehler: Nenner ist 0" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}

/* Operator *=
 */
Bruch Bruch::operator *= (Bruch b)
{
    // "x *= y"  ==>  "x = x * y"
    *this = *this * b;

    // Objekt (erster Operand) wird zur�ckgeliefert
    return *this;
}

/* Operator <
 */
bool Bruch::operator < (Bruch b)
{
    // da die Nenner nicht negativ sein k�nnen, reicht:
    return zaehler * b.nenner < b.zaehler * nenner;
}

} // **** ENDE Namespace Bsp ********************************
