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
#include <deque>
#include <string>

int main()
{
    std::deque<std::string> menge;    // Deque-Container f�r strings

    // Elemente jeweils vorn einf�gen
    menge.push_front("oefter");
    menge.push_front("immer");
    menge.push_front("aber");
    menge.push_front("immer");
    menge.push_front("nicht");

    // alle Elemente jeweils gefolgt von einem Leerzeichen ausgeben
    for (unsigned i=0; i<menge.size(); ++i) {
        std::cout << menge[i] << ' ';
    }

    // zum Abschluss ein Zeilenende ausgeben
    std::cout << std::endl;
}
