/* cppbuch/k1/mathexpr.cpp
   Beispiel zum Buch von Ulrich Breymann: Der C++ Programmierer; Hanser Verlag
   Diese Software ist freie Software. Website zum Buch: http://www.cppbuch.de/ 
*/
// Berechnung mathematischer Ausdr�cke

#include<iostream>
#include<cmath>

using namespace std;

int main() {
    float x;
    cout << "x eingeben:";
    cin >> x;
    cout << " x       = " << x       << endl;
    cout << " fabs(x) = " << fabs(x) << endl;
    cout << " sqrt(x) = " << sqrt(x) << endl;
    cout << " sin(x)  = " << sin(x)  << endl; // x im Bogenma�
    cout << " exp(x)  = " << exp(x)  << endl;
    cout << " log(x)  = " << log(x)  << endl;
}
