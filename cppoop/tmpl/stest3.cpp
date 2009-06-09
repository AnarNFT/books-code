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
#include <deque>
#include <cstdlib>
#include "stack.hpp"

int main()
{
    try {
        Bsp::Stack<int>         intStack;       // Stack f�r Integer
        Bsp::Stack<double,std::deque<double> >
                                dblStack;       // Stack f�r Gleitkommawerte

        // Integer-Stack manipulieren
        intStack.push(7);
        std::cout << intStack.pop() << std::endl;

        // Gleitkommawerte-Stack manipulieren
        dblStack.push(42.42);
        std::cout << dblStack.pop() << std::endl; 
        std::cout << dblStack.pop() << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
        return EXIT_FAILURE;
    }
}
