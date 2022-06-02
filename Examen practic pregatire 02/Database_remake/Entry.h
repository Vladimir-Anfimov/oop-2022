#pragma once
#include <string>
#include <iostream>

class Entry {
  protected:
    std::string name;

  public:
    Entry(std::string name);
    std::string GetName();
    virtual void Add(std::string toAdd) = 0;
    virtual bool Substract(int toSubstract) = 0;
    virtual void Print()                    = 0;
};
