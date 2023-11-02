#include <iostream>
using namespace std;
#ifndef BIGREAL_BIGREAL_H
#define BIGREAL_BIGREAL_H


class BigReal {
    char sign;
    string integer, fraction;
    bool isValid(string realNumber);

public:
    BigReal(double number = 0.0);
    BigReal(string realNumber);
    BigReal(const BigReal &other);
    BigReal &operator=(BigReal &other);
    void setNum(string number);
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);
    void print(BigReal&);

    bool operator<(BigReal &other);
    bool operator>(BigReal &other);
    bool operator==(BigReal &other);
    bool operator>=(BigReal &other);
    bool operator<=(BigReal &other);

    friend ostream &operator<<(ostream &out, BigReal num);
    friend istream &operator>>(istream &in, BigReal num);
};
#endif//BIGREAL_BIGREAL_H
