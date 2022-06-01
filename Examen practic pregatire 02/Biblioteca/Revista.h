#pragma once
#include "Carte.h"
#include <iostream>
#include <string>

class Revista: public Carte {
    std::string titlu;
    int nrArticole;

  public:
    Revista(const std::string titlu, int nrArticole);
    std::string GetInfo();
};
