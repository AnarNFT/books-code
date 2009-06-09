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
#include <deque>
#include <string>

namespace Bsp {  // ******** Beginn Namensbereich Bsp::

template<>
class Stack<std::string> {
  private:
    std::deque<std::string> elems;    // Elemente

  public:
    Stack() {                      // Konstruktor
    }
    void push(const std::string&);  // Element einkellern
    std::string pop();              // Element auskellern
    std::string top() const;        // oberstes Element
};

void Stack<std::string>::push (const std::string& elem)
{
    elems.push_back(elem);    // Kopie einkellern
}

std::string Stack<std::string>::pop ()
{
    if (elems.empty()) {
        throw "Stack<std::string>::pop(): der Stack ist leer";
    }
    std::string elem = elems.back();  // oberstes Element merken
    elems.pop_back();                 // oberstes Element auskellern
    return elem;                      // gemerktes oberstes Element zur�ckliefern
}

std::string Stack<std::string>::top () const
{
    if (elems.empty()) {
        throw "Stack<std::string>::top(): der Stack ist leer";
    }
    return elems.back();              // oberstes Element als Kopie zur�ckliefern
}

}  // ******** Ende Namensbereich Bsp::
