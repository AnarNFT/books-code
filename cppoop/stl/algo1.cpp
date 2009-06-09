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
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> menge;             // Vektor-Container f�r ints
    std::vector<int>::iterator pos;     // Iterator

    // Elemente 1 bis 6 unsortiert in die Menge einf�gen
    menge.push_back(2);
    menge.push_back(5);
    menge.push_back(4);
    menge.push_back(1);
    menge.push_back(6);
    menge.push_back(3);

    // kleinstes und gr��tes Element ausgeben
    pos = std::min_element (menge.begin(), menge.end());
    std::cout << "min: " << *pos << std::endl;
    pos = std::max_element (menge.begin(), menge.end());
    std::cout << "max: " << *pos << std::endl;

    // alle Elemente aufsteigend sortieren
    std::sort (menge.begin(), menge.end());

    // Reihenfolge der Elemente umkehren
    std::reverse (menge.begin(), menge.end());

    // alle Elemente ausgeben
    for (pos=menge.begin(); pos!=menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
