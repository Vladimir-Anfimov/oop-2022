#pragma once
#include "Punct.h"

class CercInterator {
  public:
    Punct* it;
    bool operator!=(const CercInterator& cerc);
    CercInterator& operator++();
    Punct operator*();
};
