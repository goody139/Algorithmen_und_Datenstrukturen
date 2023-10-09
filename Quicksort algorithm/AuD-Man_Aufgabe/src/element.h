#ifndef ELEMENT_H
#define ELEMENT_H

#include "field.h"

class Element {
    private:
        Element *next;  // Zeiger auf das nächste Element
        Field *data;

    public:
        Element(Field *data);                   // Konstruktor
        Element(Field *data, Element *next);    // ... mit gegebenen Wert


        // Getter und Setter für next und den Wert
        Field *getData();
        Element *getNext();

        void setData(Field *data);
        void setNext(Element *next);
};

#endif // ELEMENT_H
