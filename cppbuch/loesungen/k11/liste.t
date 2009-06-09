/* cppbuch/loesungen/k11/liste.t
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  Listen-Template f�r einfach-verkettete Liste
// T ist ein Platzhalter f�r den Datentyp eines Listenelements
// Unvollst�ndig! - auch mit den L�sungen zu den �bungsaufgaben!
// D.h. danach besser std::list verwenden
#ifndef LISTE_T
#define LISTE_T
template<typename T>
class Liste {
 public:
   Liste() : anfang(0), anzahl(0) {
   }

      /*******  Die L�sungen zu den �bungsaufgaben befinden
        sich am Ende  **/
 
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
         friend class Liste;
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

   /*******  L�sungen  zu den �bungsaufgaben  *************/
   // Kopierkonstruktor
   Liste(const Liste& liste) {
      anzahl = 0;
      anfang = 0;
      if(liste.size() > 0) {
        iterator I = liste.begin();
        push_front(*I++);  // erstes Element anlegen
        ListElement *letztes = anfang;
        while(I != liste.end()) {
          // Elemente am Ende einf�gen, damit die 
          // Reihenfolge erhalten bleibt
          letztes->naechstes = new ListElement(*I++, 0);
          letztes = letztes->naechstes;
          ++anzahl;         
        }
      }
   }

   // Zuweisungsoperator
    Liste& operator=(const Liste& sl) {
      Liste temp(sl);
      // Verwaltungsinformationen vertauschen. Danach hat *this die richtigen 
      // Daten und das tempor�re Objekt wird korrekt vom Destruktor zerst�rt
      // ...
      // Alternativ: Nutzung der C++-Bibliothek
      std::swap(temp.anfang, anfang);
      std::swap(temp.anzahl, anzahl);
     return *this;
    }

   // Destruktor
   ~Liste() {
      clear();
   }

   // erase
   iterator erase(iterator p) {
      if(empty()) {
          return iterator(); // leere Liste
      }
      ListElement* zuLoeschen = p.aktuellesElement;
      // Vorg�nger suchen
      ListElement* vorgaenger = anfang;
      if(zuLoeschen != anfang) {
         while( vorgaenger->naechstes != zuLoeschen) {
            vorgaenger = vorgaenger->naechstes;
         }
         // Zeiger verbiegen
         vorgaenger->naechstes = zuLoeschen->naechstes;
      }
      else {  // am Anfang l�schen
         anfang = zuLoeschen->naechstes; // Zeiger verbiegen
      }
      delete zuLoeschen;
      --anzahl; 
      return ++p;   // Nachfolger zur�ckgeben
   }

   // pop_front
   void pop_front() {
      erase(begin());
   }

   // clear
   void clear() {
      while(!empty()) {
         pop_front();
      }
   }

   // empty
   bool empty() const { 
      return anfang == 0; 
   }

   // size
   size_t size() const { 
      return anzahl;
   }
   /*******  Ende der L�sungen  zu den �bungsaufgaben *************/

};

#endif 
