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
// Headerdatei f�r die Klasse Amph
#include "amph.hpp"

int main ()
{
    /* Amphibienfahrzeug anlegen und mit
     * 7 Kilometer und 42 Seemeilen initialisieren
     */
    Bsp::Amph a(7,42);

    // gefahrene Kilometer und Seemeilen ausgeben
    a.printGefahren();
}
