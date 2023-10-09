#ifndef LIST_H
#define LIST_H

#include "element.h"

class List {
    private:
        Element *head;
        Element *tail;
    public:
        List();

        bool isEmpty();
        void prepend(Field *data);
        void append(Field *data);
        Field *removeHead();

        Field *getHead();
        Field *getTail();
};

#endif // LIST_H
