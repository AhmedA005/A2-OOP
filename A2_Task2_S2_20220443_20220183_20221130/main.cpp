// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

// File: main.cpp
// Purpose: Store big numbers that are not supported in c++, and perform some operations on it.
// Author: Abdelrahman Wael & Mohamed Mahmoud & Ahmed Ahmed
// Section: S1,2
// ID: 20220183 , 20221130 , 20220443
// TA: Maya Ahmed Kamal
// Date: 01 Nov 2023
#include <iostream>
using namespace std;
#include "BigReal.cpp"
int main() {
    BigReal R1("-5.123"),R2("6.3213");
    cout<<R1+R2;
}
