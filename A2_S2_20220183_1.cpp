// File: A2_S2_20220183_1.cpp
// Purpose: reads in a sentence of up to 100 characters and outputs the sentence with spacing
// corrected and with letters corrected for capitalization.
// Author: Abdelrahman Wael
// Section: S1,2
// ID: 20220183
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
using namespace std;

void sentence_correction(string S) {
    string s=S;

    //removing all extra spaces from the string
    for (int i = 0; i < s.size(); ++i)
    {
        if(s[i] == 32 and s[i+1] == 32) {
            s.erase(i, 1);
            i--;
        }
    }

    //makingthe firstletter uppercase
    s[0] = toupper(s[0]);

    //making any other uppercase letter lowercass
    for(int i = 1; i < s.size(); i++){
        if(s[i] >= 'A' and s[i] <= 'Z')
            s[i] = tolower(s[i]);
    }

    cout<<s;
}

int main(){
    string S;
    getline(cin,S);
    sentence_correction(S);
    return 0;
}
