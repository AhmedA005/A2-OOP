// File: A2_S2_20220443_2.cpp
// Purpose: To convert male speech to inclusive speech that includes both male and female
// Author: Ahmed Ahmed Mostafa
// Section: S1,2
// ID: 20220443
// TA: Maya Ahmed Kamal
// Date: 26 Oct 2023
#include <bits/stdc++.h>
using namespace std;
#include "InclusiveSpeech.cpp"
int main() {
    InclusiveSpeech x;
    string s;
    getline(cin, s);
    x.setSpeech(s);
    x.modifySpeech(s);
    x.print(s);
}