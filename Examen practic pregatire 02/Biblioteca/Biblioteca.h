#pragma once
#include <vector>
#include <string>
#include "Carte.h"
#include <iostream>
#include <functional>
#include "BibliotecaIterator.h"

class Biblioteca {
    int count;
    Carte** carti; 

  public:
    Biblioteca();
    ~Biblioteca();
    Biblioteca& operator+=(Carte* crt);
    BibliotecaIterator begin();
    BibliotecaIterator end();
    operator int();
    void PrintFilter( std::function<bool(Carte*)> func);
};