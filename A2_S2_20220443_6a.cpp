// File: A2_S2_20220443_6a.cpp
// Purpose: Convert decimal numbers to binary using recursion
// Author: Ahmed Ahmed Mostafa
// Section: S1,2
// ID: 20220443
// TA: Maya Ahmed Kamal
// Date: 28 Oct 2023
#include <bits/stdc++.h>
using namespace std;
string s="";
void binary(int n){
    if (n==0)
        return;
    if (n%2) s+='1';
    else s+='0';
    binary(n/2);
}
int main(){
    int n;
    cin>>n;
    binary(n);
    reverse(s.begin(),s.end());
    cout<<s;
}


