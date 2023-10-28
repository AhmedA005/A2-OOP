#include <iostream>
#include <vector>
#include <deque>
#include "domino.h"
using namespace std;

domino::domino(int left , int right){
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

bool FormsDominoChain(vector <domino> v )
{
    int c = 0;
    if(v.size()>1) {
        for (int i = 1; i < v.size(); ++i) {
            if (v[0] == v[i]){
                v.erase(v.begin());
                c++;
                i=1;
            }
        }
        if(c == 0 and v.size() > 1)
            return false;
        else if(v.size()==1 or c>0)
            return true;
        else
            return true*FormsDominoChain(v);
    }
}
