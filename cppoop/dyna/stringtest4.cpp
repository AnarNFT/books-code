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
int main()
{
    try {
        //...
    }
    catch (const String::RangeError& error) {
        // main() mit Fehlermeldung und Fehlerstatus beenden
        std::cerr << "FEHLER: fehlerhafter Index " << error.index
                  << " bei Zugriff auf String \"" << error.string
                  << "\"" << std::endl;
        return EXIT_FAILURE;
    }
}
