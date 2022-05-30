#include "CercInterator.h"

bool CercInterator::operator!=(const CercInterator& cerc) {
    return it != cerc.it;
}

CercInterator& CercInterator::operator++() {
    it++;
    return *this;
}

Punct CercInterator::operator*() {
    return *it;
}
