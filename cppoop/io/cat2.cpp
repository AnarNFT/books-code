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
#include <fstream>
#include <string>

void dateiZweimalAusgeben (const std::string& dateiname)
{
    char c;

    // Datei zum Lesen �ffnen
    std::ifstream datei(dateiname.c_str());

    // Inhalt der Datei zum ersten Mal ausgeben
    while (datei.get(c)) {
        std::cout.put(c);
    }

    // eofbit und failbit l�schen (wurden wegen EOF gesetzt)
    datei.clear();

    // Leseposition auf den Dateianfang setzen
    datei.seekg(0);

    // Inhalt der Datei zum zweiten Mal ausgeben
    while (datei.get(c)) {
        std::cout.put(c);
    }
}

int main (int argc, char* argv[])
{
    // alle in der Kommandozeile �bergebenen Dateien zweimal ausgeben
    for (int i=1; i<argc; ++i) {
        dateiZweimalAusgeben(argv[i]);
    }
}
