#include "BibliotecaIterator.h"

BibliotecaIterator& BibliotecaIterator::operator++() {
    iterator++;
    return *this;
}

bool BibliotecaIterator::operator!=(const BibliotecaIterator& carteIterator) {
    return this->iterator != carteIterator.iterator;
}

Carte* BibliotecaIterator::operator*() {
    return *iterator;
}
