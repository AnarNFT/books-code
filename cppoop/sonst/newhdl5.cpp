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

// Vorw�rtsdeklaration
static void eigenerNewHandler();

// Reserve-Speicherplatz
static char* reserveSpeicherplatz1;
static char* reserveSpeicherplatz2;

void initNewHandler ()
{
    // je nach Bedarf Reserve-Speicherplatz anfordern
    reserveSpeicherplatz1 = new char[1000000];
    reserveSpeicherplatz2 = new char[100000];

    // New-Handler installieren
    std::set_new_handler(&eigenerNewHandler);
}

static void eigenerNewHandler ()
{
    static bool firstKiss = true;

    // - beim ersten Mal:  Reserve-Speicherplatz bereitstellen
    // - beim zweiten Mal: Ausnahme ausl�sen
    if (firstKiss) {
        // Programm l�uft weiter bis zum zweiten Aufruf
        firstKiss = false;

        // ersten Speicherplatz f�r New-Handler freigeben
        delete [] reserveSpeicherplatz1;

        // Warnung auf Standard-Fehlerkanal ausgeben
        std::cerr << "Warnung: Speicherplatz bald alle" << std::endl;
    }
    else {
        // zweiten Reserve-Speicherplatz f�r New-Handler freigeben
        delete [] reserveSpeicherplatz2;

        // Fehlermeldung auf Standard-Fehlerkanal ausgeben
        std::cerr << "Speicherplatz endgueltig alle" << std::endl;

        // entsprechende Exception ausl�sen
        throw std::bad_alloc();
    }
}
