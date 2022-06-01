#pragma once
#include "Carte.h"
#include <string>
#include <iostream>

class Roman: public Carte {
    std::string nume, autor;

  public:
    Roman(const std::string nume, const std::string autor);
    std::string GetInfo();
};
