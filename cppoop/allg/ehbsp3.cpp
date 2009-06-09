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
#include <iostream>    // Headerdatei f�r I/O
#include <string>      // Headerdatei f�r Strings
#include <cstdlib>     // Headerdatei f�r EXIT_FAILURE
#include <exception>   // Headerdatei f�r Ausnahmen

void processException()
{
    try {
        throw;    // zu behandelnde Ausnahme nochmal ausl�sen, damit sie
                  // hier ausgewertet werden kann
    }
    catch (const std::bad_alloc& e) {
        // Spezielle Ausnahme: Speicherplatz alle
        std::cerr << "Speicherplatz alle" << std::endl;
    }
    catch (const std::exception& e) {
        // sonstige Standard-Ausnahmen
        std::cerr << "Standard-Exception: " << e.what() << std::endl;
    }
    catch (...) {
        // alle (bisher nicht behandelten) Ausnahmen
        std::cerr << "unerwartete sonstige Ausnahme" << std::endl;
    }
}

int main()
{
    try {
        // zwei Strings anlegen
        std::string vorname("bjarne");      // kann std::bad_alloc ausl�sen
        std::string nachname("stroustrup"); // kann std::bad_alloc ausl�sen
        std::string name;

        // Strings manipulieren
        vorname.at(20) = 'B';    // l�st std::out_of_range aus
        nachname[30] = 'S';      // FEHLER: undefiniertes Verhalten

        // Strings verketten
        name = vorname + " " + nachname;  // k�nnte std::bad_alloc ausl�sen
    }
    catch (...) {
        // alle Ausnahmen in Hilfsfunktion behandeln
        processException();
        return EXIT_FAILURE;    // main() mit Fehlerstatus beenden
    }

    std::cout << "OK, bisher ging alles gut" << std::endl;
}
