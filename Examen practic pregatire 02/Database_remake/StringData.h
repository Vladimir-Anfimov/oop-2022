#pragma once
#include "Entry.h"

class StringData: public Entry 
{
    std::string value;

  public:
    StringData(std::string name, std::string value);
    void Add(std::string toAdd) override;
    bool Substract(int toSubstract) override;
    void Print() override;
};
