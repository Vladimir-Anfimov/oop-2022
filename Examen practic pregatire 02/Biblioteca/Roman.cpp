#include "Roman.h"

Roman::Roman(const std::string nume, const std::string autor) : nume(nume), autor(autor) {
}

std::string Roman::GetInfo() {
    return "Roman " + this->nume + " de " + this->autor;
}
