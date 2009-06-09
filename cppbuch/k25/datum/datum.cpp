/* cppbuch/k25/datum/datum.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
#include"datum.h"
#include<ctime>
#include<cassert>
#include<limits>

Datum::Datum()  { aktuell();}

void Datum::set(int t, int m, int j) {
   assert(istGueltigesDatum(t, m, j));
    tag_ = t;
    monat_ = m;
    jahr_ = j;
}

void Datum::aktuell() {   // Systemdatum eintragen
    // {\tt time\_t, time(), tm, localtime()} sind in <ctime> deklariert
    time_t now = time(NULL);
    tm *z = localtime(&now);           // Zeiger auf struct tm
    jahr_  = z->tm_year + 1900;
    monat_ = z->tm_mon+1;               // localtime liefert 0..11
    tag_   = z->tm_mday;
}

Datum& Datum::operator++() {     // Datum um 1 Tag erh�hen
   ++tag_;
   // Monatsende erreicht?
   if(!istGueltigesDatum(tag_, monat_, jahr_)) {
     tag_ = 1;
     if (++monat_ > 12) {
        monat_ = 1;
        ++jahr_;
     }
   }
   return *this;
}

Datum Datum::operator++(int) {        // Datum um 1 Tag erh�hen
   Datum temp = *this;
   ++*this;                           // Pr�fix ++ aufrufen
   return temp;
}

void Datum::maxDatum() {   // maximales Systemdatum ermitteln
    time_t maxSekunden =  std::numeric_limits<time_t>::max();
    tm *z = localtime(&maxSekunden);
    jahr_ = z->tm_year + 1900;
    monat_= z->tm_mon+1;               // localtime liefert 0..11
    tag_  = z->tm_mday;
}

std::string Datum::toString() {
    std::string temp("tt.mm.jjjj");
    temp[0] = char(tag_/10)+'0';
    temp[1] = char(tag_%10)+'0';
    temp[3] = char(monat_/10)+'0';
    temp[4] = char(monat_%10)+'0';
    int pos = 9;                 // letzte Jahresziffer
    int j = jahr_;
    while(j > 0) {
       temp[pos] = j % 10 + '0';  // letzte Ziffer
       j = j/10;                  // letzte Ziffer abtrennen
       --pos;
    }
    return temp;
}

// globale Funktionen + Operatoren
bool istGueltigesDatum(int t, int m, int j) {
     // Tage pro Monat(static vermeidet Neuinitialisierung):
     static int tmp[]={31,28,31,30,31,30,31,31,30,31,30,31};

     tmp[1] = istSchaltjahr(j) ? 29 : 28;

     return     m >= 1    && m <= 12
            && j  >= 1583 && j  <= 2399  // oder mehr
            && t  >= 1    && t   <= tmp[m-1];
}


std::ostream& operator<<(std::ostream& os, const Datum& d) {
   os << d.tag() << '.' << d.monat() << '.' << d.jahr();
   return os;
}

bool operator==(const Datum& a, const Datum& b) {
   return    a.tag()   == b.tag()
          && a.monat() == b.monat()
          && a.jahr()  == b.jahr();
}

bool operator!=(const Datum& a, const Datum& b) {
   return !(a == b);
}

bool operator<(const Datum& a, const Datum& b) {
   return    a.jahr() < b.jahr()
      || (a.jahr() == b.jahr() && a.monat() < b.monat() )
      || (a.jahr() == b.jahr()
          && a.monat() == b.monat() && a.tag() < b.tag() );
}

int datumDifferenz(const Datum& a, const Datum& b) {
   if(a == b)         // kurzer Proze� bei Gleichheit
      return 0;

   bool richtigeReihenfolge = a < b;

   Datum frueher = a, spaeter = b;
   if(!richtigeReihenfolge)    {// ggf. vertauschen
      frueher = b; spaeter = a;
   }
   int differenz = 0;
   // Achtung! nicht optimiert! (tageweises Hochz�hlen)
   while(frueher != spaeter) {
      ++differenz;
      ++frueher;
   }

   if(richtigeReihenfolge)
     return differenz;
   else
     return -differenz;
}

// neu:
std::istream& operator>>(std::istream &eingabe, Datum &d) {
// Einlese-Operator f�r ein Datum
// erlaubte Formate: Tag.Monat.Jahr oder Tag/Monat/Jahr
    char c = '\0';
    int tag, monat, jahr;
    eingabe >> tag >> c;             // Tag und 1. Trennzeichen
    if(c !='.' && c !='/') {
        eingabe.setstate(std::ios::failbit); // Status setzen
    }
    else {
         eingabe >> monat >> c;      // Monat und 2. Trennzeichen
         if(c !='.' && c !='/') {
             eingabe.setstate(std::ios::failbit); // Status setzen
         }
         else {
             eingabe >> jahr;
         }
         if(jahr < 100) {
            jahr += 2000;
         }
         // Datum g�ltig?
         if(istGueltigesDatum(tag, monat, jahr)) {  // nur dann
             d.set(tag, monat, jahr);
         }
         else {
             eingabe.setstate(std::ios::failbit);
         }
    }
    if(!eingabe.good()) {
        throw "kein g�ltiges Datum!";
    }
    return eingabe;
}
