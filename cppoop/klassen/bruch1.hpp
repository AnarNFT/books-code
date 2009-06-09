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
#ifndef BRUCH_HPP
#define BRUCH_HPP

// **** BEGINN Namespace Bsp ********************************
namespace Bsp {

/* Klasse Bruch
 */
class Bruch {

  /* privat: kein Zugriff von au�en
   */
  private:       
    int zaehler;
    int nenner;

  /* �ffentliche Schnittstelle
   */
  public:
    // Default-Konstruktor
    Bruch();

    // Konstruktor aus int (Z�hler)
    Bruch(int);

    // Konstruktor aus zwei ints (Z�hler und Nenner)
    Bruch(int, int);

    // Ausgabe
    void print();
};

} // **** ENDE Namespace Bsp ********************************

#endif    /* BRUCH_HPP */
