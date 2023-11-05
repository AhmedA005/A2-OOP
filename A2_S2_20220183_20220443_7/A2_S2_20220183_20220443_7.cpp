// File: A2_S2_20220183_7.cpp
// Purpose: see if the dominos forms a domino chain or not in a recursive way
// Authors: Abdelrahman Wael & Ahmed Ahmed Mostafa
// Section: S1,2
// ID: 20220183,20220443
// TA: Maya Ahmed Kamal
// Date: 30 Oct 2023

#include <iostream>
#include "domino.cpp"
#include <vector>
#include <deque>
using namespace std;



int main(){
    cout<<"enter the number of dominos: ";
    int n;
    cin>>n;
    cout<<"enter the number of left dots and right dots for each domino: \n";
    vector <domino> v;
    for (int i = 0; i < n; ++i) {
        domino d;
        cin>>d;
        v.push_back(d);
    }
    if(FormsDominoChain(v,ans)){
        print_domino(ans);
    }
    else
        cout<<"Can't form a chain"<<endl;

    return 0;
}
