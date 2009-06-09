/* cppbuch/k11/liste/liste.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Listen-Template f�r einfach-verkettete Liste
// T ist ein Platzhalter f�r den Datentyp eines Listenelements
// Unvollst�ndig! (nur f�r das Beispiel notwendige Funktionen sind implementiert)
#ifndef LISTE_T
#define LISTE_T
template<typename T>
class Liste {
 public:
   Liste() : anfang(0), anzahl(0) {
   }
   // Kopierkonstruktor, Destruktor und Zuweisungsoperator fehlen!

   // {\tt push\_front()} erzeugt ein neues Listenelement und 
   // f�gt es am Anfang der Liste ein:
   void push_front(const T& wert)  { 
      anfang =  new ListElement(wert, anfang);
      ++anzahl;
   }
 private:
    struct ListElement {
       T daten;
       ListElement *naechstes;
       ListElement(const T& wert, ListElement* p)
            : daten(wert), naechstes(p) {}
    };
    ListElement *anfang;
    size_t anzahl;
 public:
    class iterator {
      public:
         // von find() geforderte Schnittstelle: 
         typedef std::forward_iterator_tag iterator_category;
         typedef T value_type;
         typedef T* pointer;
         typedef T& reference;
         typedef ptrdiff_t difference_type;

         iterator(ListElement* init = 0)
            : aktuellesElement(init){}

            T& operator*() {             // Dereferenzierung
               return aktuellesElement->daten;
            }

            const T& operator*() const { // Dereferenzierung
               return aktuellesElement->daten;
            }

            iterator& operator++() {     // Pr�fix
               if(aktuellesElement) //  noch nicht am Ende angelangt?
                  aktuellesElement = aktuellesElement->naechstes;
               return *this;
            }

            iterator operator++(int) {   // Postfix
               iterator temp = *this;
               ++*this;
               return temp;
            }

            bool operator==(const iterator& x) const {
               return aktuellesElement == x.aktuellesElement;
            }

            bool operator!=(const iterator& x) const {
               return aktuellesElement != x.aktuellesElement;
            }
      private:        
            ListElement* aktuellesElement; // Verweis auf aktuelles Element 
      }; // iterator      
   //   Einige Methoden der Klasse {\tt Liste} benutzen die Klasse
   //   {\tt iter\-ator} (siehe unten):
   iterator begin() const { return iterator(anfang);}
   iterator end()   const { return iterator();}
};

#endif 
