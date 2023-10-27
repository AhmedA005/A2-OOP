// File: A2_S2_20220443_8.cpp
// Purpose: Implementing the fractal pattern in a recursive way
// Author: Ahmed Ahmed Mostafa
// Section: S1,2
// ID: 20220443
// TA: Maya Ahmed Kamal
// Date: 26 Oct 2023

#include <iostream>
using namespace std;

void pattern(int n, int i) {
    if (n > 0) {
        // Recursive call for the upper half of the pattern
        pattern(n / 2, i);

        for (int j = 0; j < i; ++j) {
            cout<<' ';
        }
        for(int j = 0; j < n; j++) {
            cout << "* ";
        }
        cout << "\n";

        // Recursive call for the lower half of the pattern
        pattern(n / 2, i + n);
    }
}

int main() {
    pattern(8, 0);
    return 0;
}

