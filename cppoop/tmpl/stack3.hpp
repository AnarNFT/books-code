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
#include <vector>

namespace Bsp {  // ******** Beginn Namensbereich Bsp::

template <typename T, typename CONT = std::vector<T> >
class Stack {
  private:
    CONT elems;    // Elemente

  public:
    Stack();              // Konstruktor
    void push(const T&);  // Element einkellern
    T pop();              // Element auskellern
    T top() const;        // oberstes Element
};

// Konstruktor
template <typename T, typename CONT>
Stack<T,CONT>::Stack ()
{
    // nichts mehr zu tun
}

template <typename T, typename CONT>
void Stack<T,CONT>::push (const T& elem)
{
    elems.push_back(elem);    // Kopie einkellern
}

template <typename T, typename CONT>
T Stack<T,CONT>::pop ()
{
    if (elems.empty()) {
        throw "Stack<>::pop(): der Stack ist leer";
    }
    T elem = elems.back();    // oberstes Element merken
    elems.pop_back();         // oberstes Element auskellern
    return elem;              // gemerktes oberstes Element zur�ckliefern
}

template <typename T, typename CONT>
T Stack<T,CONT>::top () const
{
    if (elems.empty()) {
        throw "Stack<>::top(): der Stack ist leer";
    }
    return elems.back();      // oberstes Element als Kopie zur�ckliefern
}

}  // ******** Ende Namensbereich Bsp::
