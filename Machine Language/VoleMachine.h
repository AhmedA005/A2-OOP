#include <bits/stdc++.h>
using namespace std;
#ifndef MACHINE_LANGUAGE_VOLEMACHINE_H
#define MACHINE_LANGUAGE_VOLEMACHINE_H

class Register {
    vector<string> reg;
public:
    Register(int size);
    const string &getValue(int index);
    void setValue(int index, const std::string &value);
};

class Memory {
    map<string, string> mem;

public:
    const string &getMemory(const string &address);
    map<string, string> getMemory() const;
    void setMemory(const std::string &address, const std::string &value);
};

class Machine {
    Register reg{16};
    Memory mem;
    string PC = "00";

public:
    void loadFile(const string &filename);
    void fillMemory(const string &filename);
    void processInstruction();
    void displayMemory();
};

#endif//MACHINE_LANGUAGE_VOLEMACHINE_H
