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
#include <string>       // f�r Strings
#include <iostream>     // f�r I/O
#include <fstream>      // f�r Datei-I/O
#include <iomanip>      // f�r setw()
#include <cstdlib>      // f�r EXIT_FAILURE

// Vorw�rtsdeklarationen
void zeichensatzInDateiSchreiben (const std::string& dateiname);
void dateiAusgeben (const std::string& dateiname);


int main ()
{
    try {
        zeichensatzInDateiSchreiben("charset.out");
        dateiAusgeben("charset.out");
    }
    catch (const std::string& msg) {
        std::cerr << "Exception: " << msg << std::endl;
        return EXIT_FAILURE;
    }
}


void zeichensatzInDateiSchreiben (const std::string& dateiname)
{
    // Datei zum Schreiben �ffnen
    std::ofstream datei(dateiname.c_str());

    // wurde die Datei wirklich ge�ffnet?
    if (! datei) {
        // NEIN, Ausnahme ausl�sen
        throw "kann Datei \"" + dateiname
              + "\" nicht zum Schreiben oeffnen";
    }

    // Zeichensatz in Datei schreiben
    for (int i=32; i<127; ++i) {
        // Wert als Zahl und als Zeichen ausgeben:
        datei << "Wert: " << std::setw(3) << i << "   "
              << "Zeichen: " << static_cast<char>(i) << std::endl;
    }

}   // schlie�t die Datei automatisch

void dateiAusgeben (const std::string& dateiname)
{
    // Datei zum Lesen �ffnen
    std::ifstream datei(dateiname.c_str());

    // wurde die Datei wirklich ge�ffnet?
    if (! datei) {
        // NEIN, Ausnahme ausl�sen
        throw "kann Datei \"" + dateiname
              + "\" nicht zum Lesen oeffnen";
    }

    // alle Zeichen der Datei nach std::cout kopieren
    char c;
    while (datei.get(c)) {
        std::cout.put(c);
    }

}   // schlie�t die Datei automatisch
