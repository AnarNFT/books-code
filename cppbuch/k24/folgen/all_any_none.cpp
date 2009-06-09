/* cppbuch/k24/folgen/all_any_none.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
//#include<algorithm>
#include<vector>
#include<iostream>
#include<showSequence.h>
using namespace std;

/// Sobald Ihr Compiler all-of, none_of und any_of unterst�tzt,
// alle Zeilen bis /// Ende // l�schen und #include<algorithm>
// einbinden.
template<class Iterator, class Predicate>
bool all_of(Iterator first, Iterator last, Predicate pred) {
   bool result = true;
   while(first != last) {
      if(!pred(*first)) {
         result = false;
         break;
      }
      ++first;
   }
   return result;
}

template<class Iterator, class Predicate>
bool none_of(Iterator first, Iterator last, Predicate pred) {
   bool result = true;
   while(first != last) {
      if(pred(*first)) {
         result = false;
         break;
      }
      ++first;
   }
   return result;
}

template<class Iterator, class Predicate>
bool any_of(Iterator first, Iterator last, Predicate pred) {
   return !none_of(first, last, pred);
}
///////////////////  Ende //////////////////////////////


struct istPositiv {
   bool operator()(int x) {
      return x >= 0;
   }
};

int main() {
   vector<int> folge(12);
   for(size_t i = 0; i < folge.size(); ++i) {
      folge[i] = -i-1; // ggf. ver�ndern
   }
   cout << "Folge = ";
   showSequence(folge);
   if(all_of(folge.begin(), folge.end(), istPositiv())) {
      cout << "Bedingung >=0 gilt f�r alle Elemente" << endl;
   }
   else {
      cout << "Bedingung >=0 gilt nicht f�r alle Elemente" << endl;
   }
   if(none_of(folge.begin(), folge.end(), istPositiv())) {
      cout << "Bedingung >= 0 gilt f�r kein Element" << endl;
   }
   else {
      cout << "Bedingung  >=0 gilt f�r mindestens ein Element" << endl;
   }
   if(any_of(folge.begin(), folge.end(), istPositiv())) {
      cout << "Bedingung >= 0 gilt f�r wenigstens ein Element" << endl;
   }
   else {
      cout << "Bedingung >=0 gilt f�r kein Element" << endl;
   }
}
