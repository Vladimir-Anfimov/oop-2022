#include "StringData.h"

StringData::StringData(std::string name, std::string value) : Entry(name) {
    this->value = value;
}

void StringData::Add(std::string toAdd) {
    value += toAdd;
}

bool StringData::Substract(int toSubstract) {
    if (toSubstract > value.size()) {
        std::cout << "StringData: len(" << this->value << ") < " << toSubstract << "\n";
        return false;
    }
    value.erase(value.size() - toSubstract);
    return true;
}

void StringData::Print() {
    std::cout << this->name << " = " << this->value << ";";
}
