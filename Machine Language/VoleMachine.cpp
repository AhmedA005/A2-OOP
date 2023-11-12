#include "VoleMachine.h"

void Machine::loadFile(const string &filename) {
    ifstream file(filename);
    fillMemory(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            processInstruction(line);
        }
        file.close();
    }
}

void Machine::fillMemory(const string &filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        string PC = "00";
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
            cout<<PC<<endl;
        }
        file.close();
    }
}

void Machine::processInstruction(string &instruction) {
    instruction = instruction.substr(3);
    if (instruction[0] == '1') {
        int location;
        stringstream ss(instruction.substr(2, 2));

        if (ss.str().size() == 1) {
            ss.str("0" + ss.str());
        }
       if (mem[ss.str()].size() > 2)
            mem[ss.str()].erase(0, 2);
       if(mem[ss.str()][0] == ' ')
           mem[ss.str()].erase(0,1);
        reg[instruction[1] - '0'] = mem[ss.str()];

    }
    else if (instruction[0] == '2') {
        reg[instruction[1] - '0'] = instruction.substr(2, 2);
    }
    else if (instruction[0] == '3') {
        if (instruction.substr(2, 2) == "00") cout << "Register " << instruction[1] - '0' << ": " << reg[instruction[1] - '0'] << endl;
        else {
            stringstream ss(instruction.substr(2, 2));
            if (ss.str().size() == 1) {
                ss.str("0" + ss.str());
            }
            if (mem[ss.str()].size() > 2)
                mem[ss.str()].erase(0, 2);
             mem[ss.str()] = reg[instruction[1] - '0'];
        }
    }
    if (instruction == "C000") {
        cout << "Closing ...";
        return;
    }
}
