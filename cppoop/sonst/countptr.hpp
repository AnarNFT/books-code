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
#ifndef COUNTED_PTR_HPP
#define COUNTED_PTR_HPP

/* Klassentemplate f�r Smart-Pointer mit Referenz-Semantik
 * - zerst�rt das Objekt, auf das verwiesen wird, wenn der letzte CountedPtr
 *     der darauf verweist, zerst�rt wird
 */
template <class T>
class CountedPtr {
  private:
    T* ptr;        // Zeiger auf das eigentliche Objekt
    long* count;   // Verweis auf die Anzahl der darauf verweisenden Zeiger

  public:
    // mit herk�mmlichem Zeiger initialisieren
    // - p muss ein von new zur�ckgelieferter Wert sein
    explicit CountedPtr (T* p=0)
     : ptr(p), count(new long(1)) {
    }

    // Copy-Konstruktor
    CountedPtr (const CountedPtr<T>& p) throw()
     : ptr(p.ptr), count(p.count) {  // Objekt und Z�hler �bernehmen
        ++*count;                    // Anzahl der Verweise inkrementieren
    }

    // Destruktor
    ~CountedPtr () throw() {
        freigabe();             // als letzter Verweis Objekt zerst�ren
    }

    // Zuweisung
    CountedPtr<T>& operator= (const CountedPtr<T>& p) throw() {
        if (this != &p) {       // falls keine Zuweisung an sich selbst
            freigabe();         // als letzten Verweis altes Objekt zerst�ren
            ptr = p.ptr;        // neues Objekt �bernehmen
            count = p.count;    // Z�hler vom neuen Objekt �bernehmen
            ++*count;           // Anzahl der Verweise inkrementieren
        }
        return *this;
    }

    // Zugriff auf das Objekt
    T& operator*() const throw() {
        return *ptr;
    }

    // Zugriff auf eine Komponente des Objekts
    T* operator->() const throw() {
        return ptr;
    }

  private:
    void freigabe() {
        if (--*count == 0) {    // falls letzter Verweis
             delete count;      // Z�hler zerst�ren
             delete ptr;        // Objekt zerst�ren
        }
    }
};

#endif /*COUNTED_PTR_HPP*/
