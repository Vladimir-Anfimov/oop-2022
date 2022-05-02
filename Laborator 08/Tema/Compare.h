#pragma once
#include <utility>
#include <string>

using std::pair;
using std::string;

class Compare {
  public:
    bool operator()(const pair<string, int>& perOne, const pair<string, int>& perTwo);
};
