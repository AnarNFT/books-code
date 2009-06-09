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
/* Konstruktor aus Nachname und Vorname
 * - Default f�r Vorname: ""
 */
Person::Person (const std::string& nn, const std::string& vn)
  : nname(nn), vname(vn)    // Vor- und Nachname anhand �bergebener
                            // Parameter initialisieren
{
    // mehr ist nicht zu tun
}
