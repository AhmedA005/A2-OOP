// File: A2_S2_20221130_9.cpp
// Purpose: Teddy Bear Picnic
// Author: Mohamed Mahmoud Abdelaal
// Section: S1,2
// ID: 20221130
// TA: Maya Ahmed Kamal
// Date: 29 Oct 2023


#include <bits/stdc++.h>
using namespace std;
bool bear(int n){
    if (n==42) {
        return true;
    }

    else if(n%5==0 and (n-42)>=42){
        bear(n-42);
    }

    else if(n%2==0 and (n/2)>=42){
        bear(n/2);
    }

    else if(n%3==0 or n%4==0){
        if((n-(n%10)*(n%100/10))>=42)
            bear(n - (n % 10) * ((n % 100) / 10));
        else
            return false;
    }

    else{
        return false;
    }
}

int main() {
    int n=1;
    while (n) {
        cout<<"Enter the number of bears or 0 to exit: "<<endl;
        cin >> n;
        if (bear(n))
            cout << "True"<<endl;
        else
            cout<< "False"<<endl;
    }
}