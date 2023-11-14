#include <bits/stdc++.h>
using namespace std;
#ifndef MACHINE_LANGUAGE_VOLEMACHINE_H
#define MACHINE_LANGUAGE_VOLEMACHINE_H

class Machine {
    vector<string> reg{16};
    map<string, string> mem;
    string PC = "00";

public:
    void loadFile(const string &filename);
    void fillMemory(const string &filename);
    void processInstruction();
};

#endif//MACHINE_LANGUAGE_VOLEMACHINE_H
