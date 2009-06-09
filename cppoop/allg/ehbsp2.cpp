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
char f1 (const std::string s, int idx)
{
    std::string tmp = s;  // lokales Objekt, das bei einer Ausnahme
    //...                     //  automatisch zerst�rt wird
    char c = s.at(idx);   // k�nnte Ausnahme ausl�sen
    //...
    return c;
}

void foo()
{
    try {
        std::string s("hallo");  // wird bei einer Ausnahme zerst�rt
        f1(s,11);    // l�st eine Ausnahme aus
        f2();        // wird bei einer Ausnahme in f1() nicht aufgerufen
    }
    catch (...) {
        std::cerr << "Exception, wir machen aber weiter" << std::endl;
    }

    // hier geht es nach der Ausnahme in f1() weiter
    //...
}
