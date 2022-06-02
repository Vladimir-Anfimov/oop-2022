#pragma once
#include "Entry.h"
#include <vector>

class Database
{
    std::vector<Entry*> entries;

  public:
    Database& operator+=(Entry* ent);
    Database& operator-=(std::string name);
    std::vector<Entry*>::iterator begin();
    std::vector<Entry*>::iterator end();
    void Print();
};
