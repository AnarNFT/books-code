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
#ifndef KBRUCH_HPP
#define KBRUCH_HPP

// Headerdatei der Basisklasse
#include "bruch.hpp"

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Klasse KBruch
 * - abgeleitet von Bruch
 * - der Zugriff auf geerbte Komponenten wird nicht
 *     eingeschr�nkt (public bleibt public)
 * - zur Weiter-Vererbung geeignet
 */
class KBruch : public Bruch {
  protected:
    bool kuerzbar;        // true: Bruch ist k�rzbar

    // Hilfsfunktion: gr��ter gemeinsamer Teiler von Z�hler und Nenner
    unsigned ggt() const;

  public:
    /* Default-Konstruktor, Konstruktor aus Z�hler
     * und Konstruktor aus Z�hler und Nenner
     * - Parameter werden an Bruch-Konstruktor durchgereicht
     */
    KBruch (int z = 0, int n = 1) : Bruch(z,n) {
        kuerzbar = (ggt() > 1);
    }

    // multiplikative Zuweisung (neu implementiert)
    virtual const KBruch& operator*= (const Bruch&);

    // Eingabe mit Streams (neu implementiert)
    virtual void scanFrom (std::istream&);

    // Bruch k�rzen
    virtual void kuerzen();

    // K�rzbarkeit testen
    virtual bool istKuerzbar() const {
        return kuerzbar;
    }
};

} // **** ENDE Namespace Bsp ********************************

#endif    // KBRUCH_HPP
