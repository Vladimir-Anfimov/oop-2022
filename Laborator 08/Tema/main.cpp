#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <queue>
#include <map>
#include <fstream>
#include <errno.h>
#include <utility>
#include "Compare.h"
#include <vector>

#define FILE_NAME "data.txt"
#define DELIMITER  " ,!?.\n"

using std::string;
using std::map;
using std::priority_queue;
using std::pair;
using std::vector;

inline void handle_error(const char *msg) 
{
    perror(msg);
    exit(EXIT_FAILURE);
}

void toLowerCase(string &str)
{
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
}

size_t custom_find(const string str, size_t index, bool reverse = false) {
    for (index; index < str.size(); index++) {
        const char* result = strchr(DELIMITER, str[index]);
        if (!reverse && result != nullptr || reverse && result == nullptr)
            return index;
    }
    return string::npos;
}

int main()
{
    FILE* fp;
    if (nullptr == (fp = fopen(FILE_NAME, "r")))
        handle_error("Eroare la deschiderea fisierului.");

    string str;
    struct stat sb;
    stat(FILE_NAME, &sb);
    str.resize(sb.st_size);

    if(-1 == fread(const_cast<char*>(str.data()), 1, sb.st_size, fp))
        handle_error("Eroare la citirea din fisier.");
    
    fclose(fp);
    map<string, int> words;
    size_t start = 0;
    size_t end   = custom_find(str, 0);
    while (end != string::npos) {
        string sub = str.substr(start, end - start);
        toLowerCase(sub);
        words[sub]++;
        start = custom_find(str, end+1, true);
        end   = custom_find(str, start);
    }
    
    //map<string, int>::iterator it;
    priority_queue < pair<string, int>, vector<pair<string, int>>, Compare> priority;
    for (auto it = words.begin(); it != words.end(); it++) {
        priority.push(pair<string, int>{ it->first, it->second });
    }

    while (!priority.empty()) {
        std::cout << priority.top().first << " => " << priority.top().second << "\n";
        priority.pop();
    }
}