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
void fFahrzeug (const Bsp::Fahrzeug& a)
{
    std::cout << "    als Fahrzeug: "
              << static_cast<const void*>(&a) << std::endl;
}

void fAuto (const Bsp::Auto& a)
{
    std::cout << "&a  als Auto: "
              << static_cast<const void*>(&a) << std::endl;
    fFahrzeug(a);
}

void fBoot (const Bsp::Boot& a)
{
    std::cout << "&a  als Boot: "
              << static_cast<const void*>(&a) << std::endl;
    fFahrzeug(a);
}

int main ()
{
    Bsp::Amph a;

    fAuto(a);
    fBoot(a);
}
