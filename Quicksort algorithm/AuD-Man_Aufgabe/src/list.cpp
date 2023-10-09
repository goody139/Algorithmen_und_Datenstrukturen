#include "list.h"
#include "element.h"
#include "field.h"

/**
 * Konstruktor für eine Liste
 * @brief List::List
 */
List::List() {
    head = nullptr;
    tail = nullptr;
}

/**
 * Prüfung, on Liste leer ist
 * @brief List::isEmpty
 * @return true, falls die Liste leer ist
 */
bool List::isEmpty() {

    return (head == nullptr);
}

/**
 * Einfügen eines Elements vor dem aktuellen Element
 * @brief List::prepend
 * @param data Einzufügende Daten
 */
void List::prepend(Field *data) {

    Element *neu = new Element(data);

    neu->setNext(head);
    head = neu;

    if ( tail == nullptr ) {
        tail = neu;
    }
}

/**
 * Einfügen eines Elements hinter dem aktuellen Element
 * @brief List::append
 * @param data Einzufügende Daten
 */
void List::append(Field *data) {

    Element *neu = new Element(data);

    if ( tail != nullptr ) {
        tail->setNext(neu);
    }

    tail = neu;

    if ( head == nullptr ) {
        head = neu;
    }
}

/**
 * Löschen des ersten Elements der Liste
 * @brief List::removeHead
 * @return das gelöschte Feld
 */
Field* List::removeHead() {

    Element *e = head;

    if ( e == nullptr ) {
        return nullptr;
    }

    head = e->getNext();
    e->setNext(nullptr);

    Field *d = e->getData();

    return d;
}

//*******************************************************
//******************Getter & Setter**********************
//*******************************************************

Field* List::getHead() {

    if ( head == nullptr ) {
        return nullptr;
    }

    return head->getData();
}

Field* List::getTail() {

    if ( tail == nullptr ) {
        return nullptr;
    }

    return tail->getData();
}
