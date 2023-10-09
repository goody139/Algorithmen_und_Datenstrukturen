#include "element.h"
#include "field.h"

/**
 * Konstruktor fuer ein Element ohne Nachfolger
 * @brief Element::Element
 * @param data Daten, die im Element gespeichert werden sollen
 */
Element::Element(Field *data) {
    this->data = data;
    this->next = nullptr;
}

/**
 * Konstruktor fuer ein Element ohne Nachfolger
 * @brief Element::Element
 * @param data Daten, die im Element gespeichert werden sollen
 * @param next nachfolgendes Element
 */
Element::Element(Field *data, Element *next) {
    this->data = data;
    this->next = next;
}

//*******************************************************
//******************Getter & Setter**********************
//*******************************************************

Field* Element::getData() {
    return data;
}

Element* Element::getNext() {
    return next;
}

void Element::setData(Field *data) {
    this->data = data;
}

void Element::setNext(Element *next) {
    this->next = next;
}
