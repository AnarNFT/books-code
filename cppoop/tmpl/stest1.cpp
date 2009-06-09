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
#include <string>
#include <cstdlib>
#include "stack.hpp"

int main()
{
    try {
        Bsp::Stack<int>         intStack;       // Stack f�r Integer
        Bsp::Stack<std::string> stringStack;    // Stack f�r Strings

        // Integer-Stack manipulieren
        intStack.push(7);
        std::cout << intStack.pop() << std::endl;

        // String-Stack manipulieren
        std::string s = "hallo";
        stringStack.push(s);
        std::cout << stringStack.pop() << std::endl; 
        std::cout << stringStack.pop() << std::endl;
    }
    catch (const char* msg) {
        std::cerr << "Exception: " << msg << std::endl;
        return EXIT_FAILURE;
    }
}
