// File: A2_S2_20220443_6b.cpp
// Purpose: Generate all possible binary numbers of length k with a given prefix
// Author: Ahmed Ahmed Mostafa
// Section: S1,2
// ID: 20220443
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <bits/stdc++.h>
using namespace std;

void numbers(string prefix,int k) {
    if (k == 0) {
        cout << prefix << endl;
        return;
    }
    numbers(prefix + '0', k - 1);
    numbers(prefix + '1', k - 1);
}
int main() {
    string prefix;
    int k;
    cout << "Please enter your prefix: ";
    cin >> prefix;
    cout << "Please enter the size of the suffix you want: ";
    cin >> k;
    numbers(prefix, k);
}