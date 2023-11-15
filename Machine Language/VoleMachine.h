#include <bits/stdc++.h>
using namespace std;
#ifndef MACHINE_LANGUAGE_VOLEMACHINE_H
#define MACHINE_LANGUAGE_VOLEMACHINE_H
class Register {
    vector<string> reg;

public:
    Register(int size);
    const string &getValue(int index);
    void setValue(int index, const string& value);

};

class Memory {
    map<string, string> mem;

public:
    const string& getMemory(const string& address);
    void setMemory(const string& address, const string& value);
};
class Machine {
    Register reg{16};
    Memory mem;
    string PC = "00";

public:
    void loadFile(const string &filename);
    void fillMemory(const string &filename);
    void processInstruction();
    friend void printMem();
    friend void printReg(Register&reg);

};

#endif//MACHINE_LANGUAGE_VOLEMACHINE_H
