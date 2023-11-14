#include "VoleMachine.h"
vector<string> Lines;

void Machine::loadFile(const string &filename) {
    ifstream file(filename);
    fillMemory(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            Lines.push_back(line);
        }
        file.close();
    }
}
void Machine::fillMemory(const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
         PC = "00";
        while (getline(file, line)) {
            mem[PC] = line;
            int pcValue = stoi(PC, nullptr, 16);// Convert the hex string to an integer
            pcValue += 2;                       // Increment the value
            stringstream ss;
            ss << std::hex << pcValue;// Convert the integer back to hex
            PC = ss.str();
            while (PC.size() < 2) {
                PC = "0" + PC;// Ensure two characters in PC
            }
            if(PC[1]>=97 and PC[1]<=122){
                PC[1]-=32;
            }

        }
        file.close();
    }
}

void Machine::processInstruction() {
    string ins;
    for (int i = 0; i < Lines.size(); ++i) {
        ins = Lines[i].substr(3);
        if (ins[0] == '1') {
            string ss = ins.substr(2, 2);
            if (ss.size() == 1) {
                ss = "0" + ss;
            }
            if (mem[ss].size() > 2)
                mem[ss].erase(0, 2);
            if (mem[ss][0] == ' ')
                mem[ss].erase(0, 1);
            reg[ins[1] - '0'] = mem[ss];
        } else if (ins[0] == '2') {
            reg[ins[1] - '0'] = ins.substr(2, 2);
        } else if (ins[0] == '3') {
            if (ins.substr(2, 2) == "00") cout << "Register " << ins[1] - '0' << ": " << reg[ins[1] - '0'] << endl;
            else {
                string ss = ins.substr(2, 2);
                if (ss.size() == 1) {
                    ss = "0" + ss;
                }
                if (mem[ss].size() > 2)
                    mem[ss].erase(0, 2);
                mem[ss] = reg[ins[1] - '0'];
            }
        } else if (ins[0] == '4') {
            reg[ins[3] - '0'] = reg[ins[2] - '0'];
            reg[ins[2] - '0'] = "";
        } else if (ins[0] == 'B') {
            if (reg[0] == reg[ins[1] - '0']) {
                string ss = ins.substr(2, 2);
                PC = ss;
                for (int j = 0; j < Lines.size(); ++j) {
                    if (Lines[j].substr(0, 2) == PC) {
                        i = j - 1;
                        break;
                    }
                }
            }
        }
        if (ins == "C000") {
            cout << "Closing ...";
            return;
        }
    }
}
