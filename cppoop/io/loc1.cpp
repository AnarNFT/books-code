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
#include <iostream>
#include <locale>

int main()
{
    // verwende die klassische Sprachumgebung, um Daten
    // von der Standard-Eingabe zu lesen
    std::cin.imbue(std::locale::classic());

    // verwende eine deutsche Sprachumgebung, um Daten zu schreiben
    std::cout.imbue(std::locale("de_DE"));

    // Gleitkommawerte in einer Schleife lesen und ausgeben
    double wert;
    while (std::cin >> wert) {
        std::cout << wert << std::endl;
    }
}
