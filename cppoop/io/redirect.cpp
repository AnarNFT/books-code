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
#include <fstream>
#include <string>

void redirect(std::ostream&,const std::string&);

int main()
{
    std::cout << "erste Zeile" << std::endl;

    redirect(std::cout, "redirect.txt"); // cout nach redirect.txt umleiten

    std::cout << "letzte Zeile" << std::endl;
}

void redirect (std::ostream& strm, const std::string& dateiname)
{
    // Datei (mit dazugeh�rigem Puffer) zum Schreiben �ffnen
    std::ofstream datei(dateiname.c_str());
    
    // Ausgabepuffer des �bergebenen Streams merken
    std::streambuf* strm_puffer = strm.rdbuf();

    // Ausgaben in die Datei umlenken
    strm.rdbuf(datei.rdbuf());

    datei << "direkt in die Datei geschriebene Zeile" << std::endl;
    strm  << "auf den umgelenkten Stream geschriebene Zeile"
          << std::endl;

    // alten Ausgabepuffer des �bergebenen Streams restaurieren
    strm.rdbuf(strm_puffer);

}  // schlie�t die Datei und den dazugeh�rigen Puffer
