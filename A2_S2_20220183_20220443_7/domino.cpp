#include <iostream>
#include <vector>
#include <deque>
#include "domino.h"
using namespace std;
vector<domino>ans;
domino ::domino()
{
    leftdots = 0;
    rightdots = 0;
}

domino::domino(int left , int right)
{
    leftdots = left;
    rightdots = right;
}

istream & operator>>(istream & input,domino & d)
{
    input >> d.leftdots >>d.rightdots;
    return input;
}

ostream & operator<<(ostream & out,domino & d)
{
    out<<d.leftdots<<"|"<<d.rightdots;
    return out;
}

bool  operator==(domino d, domino d1)
{
    return (d.rightdots == d1.leftdots or d.leftdots == d1.rightdots);
}

bool FormsDominoChain(vector <domino> v,vector <domino>& ans )
{
    if (v.empty()) return true;
    for (int i = 0; i < v.size(); ++i) {
        if (ans.empty()||ans.back()==v[i]){
            ans.push_back(v[i]);
            domino tmp=v[i];
            v.erase(v.begin()+i);
            if (FormsDominoChain(v,ans)) return true;

            v.insert(v.begin()+i,tmp);
            ans.pop_back();
        }
    }
    return false;
}
void print_domino(vector<domino> ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i].leftdots<<'|'<<ans[i].rightdots;
        if (i!=ans.size()-1) cout<<" - ";
    }
}
