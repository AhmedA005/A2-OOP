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

   int x= v.size();
   if(v[x-2]==v[x-1]){
       v.pop_back();
       FormsDominoChain(v);
   }
   else
       return false;

    return true;
}