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
while (! (std::cin >> x)) {
    char c;

    if (std::cin.bad()) {
        // fataler Eingabefehler: Programmabbruch
        std::cerr << "fataler Fehler bei Bruch-Eingabe" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    if (std::cin.eof()) {
        // End-Of-File: Programmabbruch
        std::cerr << "EOF bei Bruch-Eingabe" << std::endl;
        std::exit(EXIT_FAILURE);
    }
    /* nicht fataler Fehler:
     * - Failbit zur�cksetzen
     * - alles bis zum Zeilenende auslesen und
     *     nochmal probieren (Schleife!)
     */
    std::cin.clear();
    while (std::cin.get(c) && c != '\n') {
    }
    std::cerr << "Fehler bei Bruch-Eingabe, probier es nochmal: "
              << std::endl;
}
