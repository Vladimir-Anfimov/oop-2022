#include "Revista.h"

Revista::Revista(const std::string titlu,int nrArticole) : titlu(titlu), nrArticole(nrArticole) {
}

std::string Revista::GetInfo() {
    return "Revista " + this->titlu + " cu " + std::to_string(this->nrArticole) + " articole";
}
