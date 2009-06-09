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
#include "person.hpp"

int main ()
{
    Bsp::Person nico("Josuttis","Nicolai");

    /* Variable vom Typ Anrede der Klasse Bsp::Person deklarieren
     * und mit dem Wert leer der Klasse Bsp::Person initialisieren
     */
    Bsp::Person::Anrede keineAnrede = Bsp::Person::leer;
    //...
    if (nico.anrede() == keineAnrede) {
        std::cout << "Anrede von Nico wurde nicht gesetzt"
                  << std::endl;
    }
}
