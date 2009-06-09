/* cppbuch/k6/meinstring/meinstring.h
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//  einfache String-Klasse. Erste, nicht vollst�ndige Version
#ifndef MEINSTRING_H
#define MEINSTRING_H
#include<cstddef>                    // {\tt size\_t}
#include<iostream>                   // {\tt ostream}

class MeinString {
  public:
   MeinString();                     // Default-Konstruktor
   MeinString(const char *);         // allg. Konstruktor
   MeinString(const MeinString&);    // Kopierkonstruktor
   ~MeinString();                    // Destruktor
   MeinString& assign(const MeinString&); // Zuweisung eines {\tt MeinString}
   MeinString& assign(const char *);      // Zuweisung eines {\tt char*}
   const char& at(size_t position) const; // Zeichen holen
   char& at(size_t position);          // Zeichen holen,
                     //  die Referenz erlaubt �ndern des Zeichens
   size_t length() const { return len;}  // Stringl�nge zur�ckgeben
   const char* c_str() const { return start;} // C-String zur�ckgeben
  private:
   size_t len;                         // L�nge
   char *start;                        // Zeiger auf den Anfang
};

void anzeigen(std::ostream& os, const MeinString& m); // Version 2

#endif
