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
/* Das erste C++-Programm
 * - gibt einfach nur "Hallo, Welt!" aus
 */

#include <iostream>    // Deklarationen f�r Ein-/Ausgaben

int main ()            // Hauptfunktion main()
{
    /* "Hallo, Welt!" auf Standard-Ausgabekanal std::cout
     * gefolgt von einem Zeilenende (std::endl) ausgeben
     */
    std::cout << "Hallo, Welt!" << std::endl;
}
