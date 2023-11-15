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
            mem.setMemory(PC, line);
            int pcValue = stoi(PC, nullptr, 16);
            pcValue += 2;
            stringstream ss;
            ss << hex << pcValue;
            PC = ss.str();
            while (PC.size() < 2) {
                PC = "0" + PC;
            }
            if (PC[1] >= 97 and PC[1] <= 122) {
                PC[1] -= 32;
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
            if (mem.getMemory(ss).size() > 2) {
                string temp = mem.getMemory(ss);
                temp.erase(0, 2);
                mem.setMemory(ss, temp);
            }

            if (mem.getMemory(ss)[0] == ' ') {
                string temp = mem.getMemory(ss);
                temp.erase(0, 1);
                mem.setMemory(ss, temp);
            }
            reg.setValue(ins[1] - '0', mem.getMemory(ss));
        } else if (ins[0] == '2') {
            reg.setValue(ins[1] - '0', ins.substr(2, 2));
        } else if (ins[0] == '3') {
            if (ins.substr(2, 2) == "00")
                cout << "Register " << ins[1] - '0' << ": " << reg.getValue(ins[1] - '0') << endl;
            else {
                string ss = ins.substr(2, 2);
                if (ss.size() == 1) {
                    ss = "0" + ss;
                }
                if (mem.getMemory(ss).size() > 2) {
                    string temp = mem.getMemory(ss);
                    temp.erase(0, 2);
                    mem.setMemory(ss, temp);
                }
                mem.setMemory(ss, reg.getValue(ins[1] - '0'));
            }
        } else if (ins[0] == '4') {
            reg.setValue(ins[3] - '0', reg.getValue(ins[2] - '0'));
            reg.setValue(ins[2] - '0', "");
        } else if (ins[0] == '5') {
            int x = stoi(reg.getValue(ins[2] - '0'), nullptr, 16);
            int y = stoi(reg.getValue(ins[3] - '0'), nullptr, 16);
            int sum = x + y;
            string s = bitset<64>(sum).to_string();
            reverse(s.begin(), s.end());
            string s2 = s.substr(0, 8);
            reverse(s2.begin(), s2.end());
            int final = stoi(s2, 0, 2);
            stringstream hex_sum;
            hex_sum << hex << final;
            string ans = hex_sum.str();

            while (ans.size() < 2) {
                ans = "0" + ans;
            }
            if (ans[1] >= 97 and ans[1] <= 122) {
                ans[1] -= 32;
            }
            reg.setValue(ins[1] - '0', ans);
        } else if (ins[0] == 'B') {
            if (reg.getValue(0) == reg.getValue(ins[1] - '0')) {
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
            cout << "Closing ...\n";
            return;
        }
    }
}

const string &Memory::getMemory(const string &address) {
    return mem.at(address);
}

void Memory::setMemory(const string &address, const string &value) {
    mem[address] = value;
}

const string &Register::getValue(int index) {
    return reg[index];
}

Register::Register(int size): reg(size,"") {}

void Register::setValue(int index, const string &value) {
    reg[index] = value;
}
