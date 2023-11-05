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
    BigReal operator+(BigReal &other);
    BigReal operator-(BigReal &other);

    bool operator<(BigReal &other);
    bool operator>(BigReal &other);
    bool operator==(BigReal &other);
    BigReal Modify(BigReal &other);

    friend ostream &
    operator<<(ostream &out, BigReal num);
};
#endif//BIGREAL_BIGREAL_H
