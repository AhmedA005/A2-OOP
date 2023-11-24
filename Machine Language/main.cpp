// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com
#include <bits/stdc++.h>
using namespace std;
#include "VoleMachine.cpp"
int main() {
    string operations[4] = {
            "Load a new program",
            "Display the memory",
            "Display the registers",
            "Display the final screen"};

    for (int i = 0; i < 4; ++i) {
        cout << i + 1 << " - " << operations[i] << endl;
    }

    Machine x;
    while (true) {
        cout << "Please select an operation to perform or 0 to exit: " << endl;
        int choice;
        cin >> choice;
        if (choice == 1) {
            cout << "Please enter the file's name: " << endl;
            string filename;
            cin >> filename;
            filename += ".txt";
            x.loadFile(filename);
            x.processInstruction();
        } else if (choice == 2) {
            x.displayMemory();
        } else if (choice == 3) {
            for (int i = 0; i < 16; ++i) {
                cout << "register " << i << ": " << registers[i] << endl;
            }
        } else if (choice == 4) {
            for (int i = 0; i < screen.size(); i++) {
                cout << "Register " << screen[i].first << ": " << screen[i].second << endl;
            }
        } else if (choice == 0) {
            return 0;
        }
    }
}
