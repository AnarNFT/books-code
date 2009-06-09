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
// **** BEGINN Namespace Bsp ********************************
namespace Bsp {
//...

/* neu: scanFrom()
 * - Bruch von Stream strm einlesen
 */
void Bruch::scanFrom (std::istream& strm)
{
    int z, n;

    // Z�hler einlesen
    strm >> z;

    // optionales Trennzeichen '/' und Nenner einlesen
    if (strm.peek() == '/') {
        strm.get();
        strm >> n;
    }
    else {
        n = 1;
    }

    // Lesefehler?
    if (! strm) {
        return;
    }

    // Nenner == 0?
    if (n == 0) {
        // Fail-Bit setzen
        strm.clear (strm.rdstate() | std::ios::failbit);
        return;
    }

    /* OK, eingelesene Werte zuweisen
     * - ein negatives Vorzeichen des Nenners kommt in den Z�hler
     */
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}

} // **** ENDE Namespace Bsp ********************************
