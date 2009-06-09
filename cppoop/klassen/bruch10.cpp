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
/* Default-Konstruktor, Konstruktor aus ganzer Zahl,
 * Konstruktor aus Z�hler und Nenner
 * - Default f�r z: 0
 * - Default f�r n: 1
 */
Bruch::Bruch (int z, int n)
{
    /* Z�hler und Nenner wie �bergeben initialisieren
     * - 0 als Nenner ist allerdings nicht erlaubt
     * - ein negatives Vorzeichen des Nenners kommt in den Z�hler
     */
    if (n == 0) {
        // Ausnahme: Fehlerobjekt f�r 0 als Nenner ausl�sen
        throw NennerIstNull();
    }
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}

/* scanFrom
 * - Bruch von Stream strm einlesen
 */
void Bruch::scanFrom (istream& strm)
{
    int z, n;

    // Z�hler einlesen
    strm >> z;

    // optionales Trennzeichen und Nenner '/' einlesen
    if (strm.peek() == '/') {
        strm.get();
        strm >> n;
    }
    else {
        n = 1;
    }

    // Lesefehler?
    if (! strm) {
        // Ausnahme mit Fehlerobjekt f�r Lesefehler ausl�sen
        throw Lesefehler();
    }

    // Nenner == 0?
    if (n == 0) {
        // Ausnahme mit Fehlerobjekt f�r 0 als Nenner ausl�sen
        throw NennerIstNull();
    }

    // OK, eingelesene Zahlen zuweisen
    if (n < 0) {
        zaehler = -z;
        nenner  = -n;
    }
    else {
        zaehler = z;
        nenner  = n;
    }
}
