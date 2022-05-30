#pragma once
#include "Punct.h"
#include "CercInterator.h"
#include <string>

class Circle {
    Punct centru, patrat[4];
    int raza;
  public:
    Circle(int centruX, int centruY, int raza);
    CercInterator begin();
    CercInterator end();
    bool operator==(const Punct& punct);
    bool operator>(const Punct& punct);
    operator int();
    int operator[](const std::string str);
    Circle operator()(const std::string add, int val);
};
