#include "Compare.h"
#include <utility>
#include <string>

using std::pair;
using std::string;


bool Compare::operator()(const pair<string, int>& perOne, const pair<string, int>& perTwo) {
    if (perOne.second != perTwo.second)
        return perOne.second < perTwo.second;
    for (int i = 0; i < perOne.first.size() && perTwo.first.size(); i++) {
        if (perOne.first[i] > perTwo.first[i])
            return true;
        else if (perOne.first[i] < perTwo.first[i])
            return false;
    }

    return perOne.first.size() > perTwo.first.size();
        
}