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
#include <cstddef>

void BspKlasse::operator delete (void* p)
{
    // Meldung ausgeben
    std::cout << "BspKlasse::delete aufgerufen" << std::endl;

    // globales delete aufrufen
    ::delete [] p;
}

void BspKlasse::operator delete[] (void* p)
{
    // Meldung ausgeben
    std::cout << "BspKlasse::delete[] aufgerufen" << std::endl;

    // globales delete aufrufen
    ::delete [] p;
}

