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
static char* reserveSpeicherplatz;

void initNewHandler ()
{
    // je nach Bedarf Speicherplatz allokieren
    reserveSpeicherplatz = new char[100000];

    // New-Handler installieren
    std::set_new_handler(&eigenerNewHandler);
}

static void eigenerNewHandler ()
{
    // Reserve-Speicherplatz freigeben
    delete [] reserveSpeicherplatz;

    // Fehlermeldung auf Standard-Fehlerkanal ausgeben
    std::cerr << "Speicherplatz alle (Restspeicher freigegeben)"
              << std::endl;

    // entsprechende Exception ausl�sen
    throw std::bad_alloc();
}
