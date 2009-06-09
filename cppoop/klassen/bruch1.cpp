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
// Headerdatei mit der Klassen-Deklaration einbinden
#include "bruch.hpp"

// Standard-Headerdateien einbinden
#include <iostream>
#include <cstdlib>

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Default-Konstruktor
 */
Bruch::Bruch ()
 : zaehler(0), nenner(1)    // Bruch mit 0 initialisieren
{
    // keine weiteren Anweisungen
}

/* Konstruktor aus ganzer Zahl
 */
Bruch::Bruch (int z)
 : zaehler(z), nenner(1)    // Bruch mit z 1tel initialisieren
{
    // keine weiteren Anweisungen
}

/* Konstruktor aus Z�hler und Nenner
 */
Bruch::Bruch (int z, int n)
 : zaehler(z), nenner(n)    // Z�hler und Nenner wie �bergeben initialisieren
{
    // 0 als Nenner ist allerdings nicht erlaubt
    if (n == 0) {
        // Programm mit Fehlermeldung beenden
        std::cerr << "Fehler: Nenner ist 0" << std::endl;
        std::exit(EXIT_FAILURE);
    }
}

/* print
 */
void Bruch::print ()
{
    std::cout << zaehler << '/' << nenner << std::endl;
}

} // **** ENDE Namespace Bsp ********************************
