#pragma once
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <string>

using namespace std;

class CommandManager {
  private:
    map<string, function<void(vector<string>)>> commands;

  public:
    void add(string name, function<void(vector<string>)> fn);

    // run shall read a line from stdin in a loop, split it by whitespaces.
    // the first word will be the command name. if no word has been found, it will do nothing
    // then it will search the map for the name, and it will invoke the callback if it founds it
    // or it will show a message if it can't find it
    // the args for the callback will not contain the command name
    // if the `stop` command is found, the function will return
    // try doing this yourself; if you spent too much time on this, look at
    // https://gist.github.com/xTachyon/9e698a20ce6dfcae9a483b28778af9fb
    void run();
};


class MyException : public std::exception {
    std::string excp;
public:
    MyException(std::string excp) : excp(excp) {}
    const char* what() const noexcept override {
        return excp.c_str();
    }
};

class OpenFileException : public MyException {
  public:
    OpenFileException(string file_name) : MyException("can't open file " + file_name) {}
};


class ReadFileException : public MyException {
  public:
    ReadFileException(string file_name) : MyException("can't read file " + file_name) {}
};


class WriteFileException : public MyException {
  public:
    WriteFileException(string file_name) : MyException("can't write file " + file_name) {
    }
};