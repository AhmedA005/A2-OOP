#include <iostream>
#include <vector>
#include <deque>
using namespace std;

#ifndef A2_S2_20220183_7_DOMINO_H
#define A2_S2_20220183_7_DOMINO_H


class domino{
    int leftdots;
    int rightdots;
public:
    domino();
    domino(int left , int right);
    friend istream & operator>>(istream & input,domino & d);
    friend ostream & operator<<(ostream & out,domino & d);
    friend bool  operator==(domino d , domino d1);
    friend bool FormsDominoChain(vector <domino> v,deque <domino>& ans );
    friend void print_domino( deque <domino> v);
};


#endif //A2_S2_20220183_7_DOMINO_H
