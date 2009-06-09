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
#include <map>
#include <string>

int main()
{
    // Datentyp der Menge
    typedef std::multimap<int,std::string> IntStringMMap;

    IntStringMMap menge;    // Multimap-Container f�r int/string-Wertepaare

    // einige Elemente ungeordnet einf�gen
    // - zwei Werte haben den Schl�ssel 1
    menge.insert(std::make_pair(5,"feucht"));
    menge.insert(std::make_pair(2,"besten"));
    menge.insert(std::make_pair(1,"Die"));
    menge.insert(std::make_pair(4,"sind:"));
    menge.insert(std::make_pair(5,"lang"));
    menge.insert(std::make_pair(3,"Parties"));

    /* die Werte aller Elemente ausgeben
     * - ein Iterator wandert �ber alle Elemente
     * - mit second wird auf den Wert der Elemente zugegriffen
     */
    IntStringMMap::iterator pos;
    for (pos = menge.begin(); pos != menge.end(); ++pos) {
        std::cout << pos->second << ' ';
    }
    std::cout << std::endl;
}
