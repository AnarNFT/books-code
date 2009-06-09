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
/* Zeichensatz ausgeben
 */

#include <iostream>    // Deklarationen f�r Ein-/Ausgaben

int main ()
{
    // f�r jedes Zeichen c mit einem Wert von 32 bis 126
    for (unsigned char c=32; c<127; ++c) {
        // Wert als Zahl und als Zeichen ausgeben:
        std::cout << "Wert: " << static_cast<int>(c)
                  << " Zeichen: " << c
                  << std::endl;
    }
}
