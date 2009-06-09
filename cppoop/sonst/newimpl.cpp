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
// m�gliche Implementierung von Operator new
void* operator new (std::size_t size)
{
    void* p;        // Zeiger f�r neuen Speicher

    // solange es nicht klappt, neuen Speicher zu bekommen,
    // New-Handler aufrufen oder Ausnahme ausl�sen
    while ((p = holSpeicher(size)) == 0) {
        // kein ausreichender Speicherplatz verf�gbar
        if (MyNewHandler != 0) {
              // New-Handler aufrufen
              (*myNewHandler)();
        }
        else {
              // Ausnahme ausl�sen
              throw std::bad_alloc();
        }
    }

    // OK, neuen Speicherplatz zur�ckliefern
    return p;
}
