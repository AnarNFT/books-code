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
#include <string>

int main()
{
    std::vector<std::string> menge;            // Container f�r Strings
    std::vector<std::string>::iterator pos;    // Iterator

    // Verschiedene St�dtenamen einf�gen
    menge.push_back("Hamburg");
    menge.push_back("M�nchen");
    menge.push_back("Berlin");
    menge.push_back("Braunschweig");
    menge.push_back("Duisburg");
    menge.push_back("Leipzig");

    // alle Elemente aufsteigend sortieren
    std::sort (menge.begin(), menge.end());

    /* "Hannover" vor "Hamburg" einf�gen
     * - Position von "Hamburg" suchen
     * - "Hannover" davor einf�gen
     */
    pos = find (menge.begin(), menge.end(),    // Bereich
                "Hamburg");                    // Suchkriterium
    if (pos != menge.end()) {
        menge.insert(pos,"Hannover");
    }
    else {
        std::cerr << "Huch, Hamburg ist gar nicht vorhanden"
                  << std::endl;
        menge.push_back("Hannover");
    }

    // alle Elemente ausgeben
    for (pos=menge.begin(); pos!=menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }
    std::cout << std::endl;
}
