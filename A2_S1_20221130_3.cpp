// File: A2_S2_20221130_3.cpp
// Purpose: Split a string separated by a delimiter
// Author: Mohamed Mahmoud Abdelaal
// Section: S1,2
// ID: 20221130
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <bits/stdc++.h>
using namespace std;
vector<string>ans;

vector<string> split(string target, string delimiter){
    int sz=target.size();
    string check="";
    for (int i = 0; i < sz; ++i) {
        if (target.substr(i,delimiter.size())==delimiter){
            ans.push_back(check);
            check="";
        }
        else{
            check+=target[i];
        }
    }
    if (check!="") ans.push_back(check);
    return ans;
}
int main(){
    string target,delimiter;
    cout<<"Enter your target string: ";
    getline(cin,target);
    cout<<"Enter your delimiter: ";
    getline(cin,delimiter);
    split(target,delimiter);
    for(auto x:ans){
        cout<<x<<' ';
    }
}