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
// C-Headerdatei f�r I/O
#include <stdio.h>

// C-Headerdatei f�r die String-Behandlung
#include <string.h>

void f()
{
    const char* k = "Eingabe: "; // String-Konstante
    char        text[81];        // String-Variable f�r 80 Zeichen
    char        s[81];           // String-Variable f�r die Eingabe (bis 80 Zeichen)

    /* String s einlesen
     * - aus Platzgr�nden nicht mehr als 80 Zeichen
     */
    if (scanf ("%80s", s) != 1) {
        // Einlesefehler
        //...
    }

    // String mit Leerstring vergleichen
    if (strcmp(s,"") == 0) {
        /* String-Literal an String text zuweisen
         * - VORSICHT: text muss ausreichend gro� sein
         */
        strcpy (text, "keine Eingabe");
    }
    else {
        /* String-Konstante k, gefolgt von eingelesenem String,
         * an text zuweisen
         * - VORSICHT: text muss ausreichend gro� sein
         */
        if (strlen(k)+strlen(s) <= 80) {
            strcpy (text, k);
            strcat (text, s);
        }
    }
    //...
}
