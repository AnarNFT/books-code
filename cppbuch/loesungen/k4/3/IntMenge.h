/* cppbuch/loesungen/k4/3/IntMenge.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Klasse zur Implementierung eines Datentyps f�r Mengen mit int-Elementen
#ifndef IntMenge_h
#define IntMenge_h
#include<vector>

class IntMenge {
 public:
   IntMenge();
   void hinzufuegen(int el);
   void entfernen(int el);
   bool istMitglied(int el) const;
   size_t size() const;
   void anzeigen() const;
   void loeschen();    // alle Elemente l�schen
   int getMax() const; // gr��tes Element
   int getMin() const; // kleinstes Element
 private:
   size_t anzahl;
   std::vector<int> vec;
   // Die Hilfsfunktion finden() gibt die Position des 
   // Elements zur�ck. -1 bedeutet nicht vorhanden
   int finden(int el) const;
};
#endif
