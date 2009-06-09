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
#include <fstream>
#include <iostream>
using namespace std;

/* f�r alle in der Kommandozeile �bergebenen Dateinamen
 * - Datei �ffnen, Inhalt ausgeben und Datei schlie�en
 */
int main (int argc, char* argv[])
{
    // Datei-Stream zum Lesen anlegen (ohne eine Datei zu �ffnen)
    std::ifstream datei;

    // f�r alle Argumente aus der Kommandozeile
    for (int i=1; i<argc; ++i) {

        // Datei �ffnen
        datei.open(argv[i]);

        // Inhalt der Datei ausgeben
        char c;
        while (datei.get(c)) {
            std::cout.put(c);
        }

        // eofbit und failbit l�schen (wurden wegen EOF gesetzt)
        datei.clear();

        // Datei schlie�en
        datei.close();
    }
}
