#pragma once
#include "Carte.h"

class BibliotecaIterator {
  public:
    Carte** iterator;
    BibliotecaIterator& operator++();
    bool operator!=(const BibliotecaIterator& carteIterator);
    Carte* operator*();
};
