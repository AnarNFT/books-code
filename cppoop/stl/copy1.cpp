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
#include <list>
#include <algorithm>

int main()
{
    std::list<int>   menge1;
    std::vector<int> menge2;

    // Elemente 1 bis 6 in die erste Menge einf�gen
    for (int i=1; i<=6; i++) {
        menge1.push_back(i);
    }

    /* LAUFZEITFEHLER:
     * - Elemente in die zweite Menge kopieren
     */
    std::copy (menge1.begin(), menge1.end(),    // Quellbereich
               menge2.begin());                 // Zielbereich
}
