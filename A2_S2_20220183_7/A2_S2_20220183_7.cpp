// File: A2_S2_20220183_7.cpp
// Purpose: see if the dominos forms a dominochain or not in a recursive way
// Author: Abdelrahman Wael
// Section: S1,2
// ID: 20220183
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include "domino.cpp"
using namespace std;




int main(){
    int n;
    cin>>n;
vector <domino> v;
    for (int i = 0; i < n; ++i) {
        domino d;
        cin>>d;
        v.push_back(d);
    }
    if(FormsDominoChain(v)){

        for (int i = 0; i < n-1; ++i) {
            cout<<v[i]<<" - ";
        }
        cout<<v[v.size()-1];
    }
    else
        cout<<"dose not form a domino chain";

    return 0;
}