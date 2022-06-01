#include "Biblioteca.h"

Biblioteca::Biblioteca() {
    carti = new Carte*[100];
    count = 0;
}

Biblioteca::~Biblioteca() {
    delete[] carti;
}

Biblioteca& Biblioteca::operator+=(Carte* crt) {
    carti[count++] = crt;
    return *this;
}

BibliotecaIterator Biblioteca::begin() {
    BibliotecaIterator tmp;
    tmp.iterator = &carti[0];
    return tmp;
}

BibliotecaIterator Biblioteca::end() {
    BibliotecaIterator tmp;
    tmp.iterator = &carti[count];
    return tmp;
}

Biblioteca::operator int() {
    return count;
}

void Biblioteca::PrintFilter(std::function<bool(Carte*)> func) {
    for (auto carte: carti) {
        if (func(carte))
                std::cout << carte->GetInfo() << "\n";
    }

    /*for (int i = 0; i < count; i++) {
        if (func(carti[i]))
            std::cout << carti[i]->GetInfo() << "\n";
    }*/
    
}

