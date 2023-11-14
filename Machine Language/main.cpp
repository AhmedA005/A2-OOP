#include <bits/stdc++.h>
using namespace std;
#include "VoleMachine.cpp"
int main() {
    vector <string> operations = {
            "Load a new program",
            "Display the PC",
            "Display the IR",
            "Display the memory",
            "Display the final screen"};

    for (int i = 0; i < operations.size(); ++i) {
        cout << i + 1 << " - " << operations[i] << endl;
    }

    Machine x;
    while (true){
        cout << "Please select an operation to perform or 0 to exit: " << endl;
        int choice;
        cin >> choice;
        if(choice==1){
            cout<<"Please enter the file's name: " << endl;
            string filename;
            cin>>filename;
            filename += ".txt";
            x.loadFile(filename);
            x.processInstruction();
        }
        else if(choice==2){}
        else if(choice==3){}
        else if(choice==4){}
        else if(choice==5){}
        else if(choice==0){
            return 0;
        }
    }
}
