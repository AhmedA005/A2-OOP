#include <iostream>
#include "domino.h"
using namespace std;
deque<domino>ans;
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
//overloading the operator >> to take the dominos as input from the user
istream & operator>>(istream & input,domino & d)
{
    input >> d.leftdots >>d.rightdots;
    return input;
}
//overloading the operator << to print each domino
ostream & operator<<(ostream & out,domino & d)
{
    out<<d.leftdots<<"|"<<d.rightdots;
    return out;
}
//Overloading the operator == To take two dominoes and return them can either form a chain or not
bool  operator==(domino d, domino d1)
{
    return (d.rightdots == d1.leftdots);
}

bool FormsDominoChain(vector <domino> v,deque <domino>& ans )
{
    //check every time if the vector is empty
    if (v.empty()) return true;
    //loop on the vector and see if each domino has a match
    //and store them in vector ans
    for (int i = 0; i < v.size(); ++i) {
        if (ans.empty() || ans.back()==v[i]){
                ans.push_back(v[i]);
                domino tmp = v[i];
                v.erase(v.begin() + i);
                if (FormsDominoChain(v, ans)) return true;

                v.insert(v.begin() + i, tmp);
                ans.pop_back();
            }
            else if(v[i] == ans.back()) {
                ans.push_front(v[i]);
                domino tmp = v[i];
                v.erase(v.begin() + i);
                if (FormsDominoChain(v, ans)) return true;

                v.insert(v.begin() + i, tmp);
                ans.pop_front();
            }
        }
    return false;
}
void print_domino(deque <domino> ans) {
    for (int i = 0; i < ans.size(); ++i) {
        cout<<ans[i].leftdots<<'|'<<ans[i].rightdots;
        if (i!=ans.size()-1) cout<<" - ";
    }
}
