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
#include <list>

int main()
{
    std::list<char> menge;    // List-Container f�r chars

    // Elemente mit den Werten 'a' bis 'z' einf�gen
    for (char c='a'; c<='z'; ++c) {
        menge.push_back(c);
    }

    // alle Elemente jeweils gefolgt von einem Leerzeichen ausgeben
    // - Iterator wandert dazu �ber alle Elemente
    std::list<char>::iterator pos;
    for (pos = menge.begin(); pos != menge.end(); ++pos) {
        std::cout << *pos << ' ';
    }

    // zum Abschluss ein Zeilenende ausgeben
    std::cout << std::endl;
}
