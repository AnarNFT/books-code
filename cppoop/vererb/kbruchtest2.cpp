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
// Headerdateien
#include <iostream>
#include "kbruch.hpp"
#include "bruch.hpp"

int main()
{
    // KBruch deklarieren
    Bsp::KBruch x(7,3);

    // Bruch mit Kehrwert von x deklarieren
    Bsp::Bruch b(3,7);

    // Zeiger auf Bruch zeigt darauf
    Bsp::Bruch* xp = &x;

    *xp *= b;         // PROBLEM: ruft Bruch::operator*=() auf

    // x ausgeben
    std::cout << x;
    std::cout << (x.istKuerzbar() ? " (kuerzbar)" : " (unkuerzbar)")
              << std::endl;

    std::cout << "Bruch eingeben (zaehler nenner): ";

    std::cin >> x;    // PROBLEM: ruft indirekt Bruch::scanFrom() auf

    // x ausgeben
    std::cout << x;
    std::cout << (x.istKuerzbar() ? " (kuerzbar)" : " (unkuerzbar)")
              << std::endl;
}
