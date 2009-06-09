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
// Headerdatei f�r den New-Handler
#include <new>

// Standard-Headerdateien
#include <iostream>
#include <cstdlib>

/* eigenerNewHandler()
 * - gibt Fehlermeldung aus und beendet das Programm
 */
void eigenerNewHandler ()
{
    // Fehlermeldung auf Standard-Fehlerkanal ausgeben
    std::cerr << "Speicherplatz alleeeeeeeeee..." << std::endl;

    // entsprechende Exception ausl�sen
    throw std::bad_alloc();
}

int main()
{
    try {
        // eigenen New-Handler installieren
        std::set_new_handler(&eigenerNewHandler);

        // und mit Endlosschleife, die Speicherplatz anfordert, testen
        for (;;) {
            new char[1000000];
        }

        // kein Rechner kann unendlich Speicherplatz haben
        std::cout << "Huch, Zauberei!" << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
