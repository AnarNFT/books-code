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
#include <iostream>
#include <limits>
#include <string>

int main()
{
   using namespace std;

   // textuelle Darstellung f�r bool verwenden
   cout << boolalpha;

   // Maxima der ganzzahligen Datentypen ausgeben
   cout << "max(short): " << numeric_limits<short>::max() << endl;
   cout << "max(int):   " << numeric_limits<int>::max() << endl;
   cout << "max(long):  " << numeric_limits<long>::max() << endl;
   cout << endl;

   // Maxima der Gleitkommadatentypen ausgeben
   cout << "max(float):       "
        << numeric_limits<float>::max() << endl;
   cout << "max(double):      "
        << numeric_limits<double>::max() << endl;
   cout << "max(long double): "
        << numeric_limits<long double>::max() << endl;
   cout << endl;

   // Ist char vorzeichenbehaftet?
   cout << "is_signed(char): "
        << numeric_limits<char>::is_signed << endl;
   cout << endl;

   // Existieren numerische Limits zum Datentyp string?
   cout << "is_specialized(string): "
        << numeric_limits<string>::is_specialized << endl;
}
