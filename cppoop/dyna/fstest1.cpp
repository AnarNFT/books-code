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
// Headerdatei f�r I/O
#include <iostream.h>

// Headerdatei f�r die Klasse FarbString
#include "fstring.hpp"

int main ()
{
    Bsp::FarbString f("hallo");              // FarbString mit Default-Farbe
    Bsp::FarbString r("rot","red");          // FarbString mit Rot als Farbe

    std::cout << f << " " << r << std::endl; // FarbStrings ausgeben

    f.farbe("green");                        // Farbe von f auf Gr�n setzen

    std::cout << f << " " << r << std::endl; // FarbStrings ausgeben

    std::cout << "Summenstring: " << f + r << std::endl;
}
