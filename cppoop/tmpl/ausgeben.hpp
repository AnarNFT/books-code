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
#include <iostream>

// Elemente eines STL-Containers ausgeben
template <typename T>
void ausgeben (const T& menge)
{
    // Anzahl der Elemente ausgeben
    std::cout << "Anzahl Elemente: " << menge.size() << std::endl;

    // Elemente selbst ausgeben
    std::cout << "Elemente: ";
    typename T::const_iterator pos;
    for (pos=menge.begin(); pos!=menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}


