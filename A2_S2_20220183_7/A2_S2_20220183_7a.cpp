// File: A2_S2_20220183_7.cpp
// Purpose: see if the dominos forms a domino chain or not in a recursive way
// Author: Abdelrahman Wael
// Section: S1,2
// ID: 20220183
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include "domino.cpp"
using namespace std;




int main(){
    cout<<"enter the number of dominos: ";
    int n;
    cin>>n;
    cout<<"enter the number of left dots and right dots for each domino: ";
vector <domino> v;
    for (int i = 0; i < n; ++i) {
        domino d;
        cin>>d;
        v.push_back(d);
    }
    if(FormsDominoChain(v)){
        cout<<"True"<<endl;
    }
    else
        cout<<"false"<<endl;
    
    return 0;
}
