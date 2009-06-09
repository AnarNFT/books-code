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
#include "quer.hpp"

// Funktion, die die Quersumme aus einer ganzen Zahl berechnet
int quersumme (long zahl)
{
    int quer = 0;

    while (zahl > 0) {
        quer += zahl % 10;    // Einer auf Quersumme addieren
        zahl = zahl / 10;     // weiter mit restlichen Ziffern
    }

    return quer;
}
