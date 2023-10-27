#include <iostream>
#include <vector>
#include "domino.h"
using namespace std;

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
    return (d.rightdots==d1.leftdots);
}

bool FormsDominoChain(vector <domino> v )
{
    int x = 0;
    if(v.size()>1) {
        for (int i = 0; i < v.size(); ++i) {
            if (v[0] == v[i]){
                v.erase(v.begin());
                x++;
            }
        }
        if(x == 0)
            return false;
        else if(v.size()==1)
            return true;
        else
            return true*FormsDominoChain(v);

    }
}
