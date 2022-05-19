#define _CRT_SECURE_NO_WARNINGS
#include "CommandManager.h"
#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void CommandManager::add(string name, function<void(vector<string>)> fn) {
    commands[name] = fn;
}

void CommandManager::run() {
    
    string input;
    vector<string> args;

    std::getline(cin, input);
    while (input != "stop") {
        char* token = strtok(&input[0], " ");
        string command_name;

        if (commands.count(token)) {
            command_name = token;
            token        = strtok(NULL, " ");
            while (token != nullptr) {
                args.push_back(token);
                token = strtok(NULL, " ");
            }
            try {
                commands[command_name](args);
            } catch (exception& ex) {
                printf("%s\n", ex.what());
            }
        }

        cin >> input;
    }
}