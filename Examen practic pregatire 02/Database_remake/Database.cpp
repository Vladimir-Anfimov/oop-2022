#include "Database.h"

Database& Database::operator+=(Entry* ent) {
    entries.push_back(ent);
    return *this;
}

Database& Database::operator-=(std::string name) {
    entries.erase(std::remove_if(entries.begin(), entries.end(), [name](Entry*& ent) {
        return ent->GetName() == name;
    }), entries.end());

    return *this;
}

std::vector<Entry*>::iterator Database::begin() {
    return entries.begin();
}

std::vector<Entry*>::iterator Database::end() {
    return entries.end();
}

void Database::Print() {
    for (auto ent : entries) {
        ent->Print();
    }
    std::cout << '\n';
}
