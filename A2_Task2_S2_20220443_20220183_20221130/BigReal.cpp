// This is a personal academic project. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <iostream>
#include <regex>
using namespace std;
#include "BigReal.h"
bool BigReal::isValid(const string &realNumber) {
    if (regex_match(realNumber,regex("[+-]?\\d*.?\\d+")))
        return true;
    else return false;
}
BigReal::BigReal(string realNumber):sign{} {
    if (isValid(realNumber)) {
        if (realNumber[0] == '-' || realNumber[0] == '+') {
            sign = realNumber[0];
            realNumber.erase(0, 1);
        } else if (realNumber[0] - '0' >= 0 && realNumber[0] - '0' <= 9) {
            sign = '+';
        }
        integer = realNumber.substr(0, realNumber.find('.'));
        if (realNumber.find('.') != string::npos) {
            fraction = realNumber.substr(integer.size() + 1, realNumber.size() - 1);
        } else
            fraction = '0';
    }
    if (integer.size() == 0) integer = '0';
    if (fraction.size() == 0) fraction = '0';
    Modify(*this);
}

ostream &operator<<(ostream &out, const BigReal &num) {
    out << num.sign << num.integer << '.' << num.fraction;
    return out;
}

bool BigReal::operator==(BigReal &other) {
    if (sign == other.sign) {
        while (integer.size() > other.integer.size()) {
            other.integer = '0' + other.integer;
        }
        while (integer.size() < other.integer.size()) {
            integer = '0' + integer;
        }
        while (fraction.size() > other.fraction.size()) {
            other.fraction += '0';
        }
        while (fraction.size() < other.fraction.size()) {
            fraction += '0';
        }
        if (integer != other.integer or fraction != other.fraction) {
            return false;
        } else
            return true;
    } else
        return false;
}

bool BigReal::operator<(BigReal &other) {
    if (sign == '-' and other.sign == '+')
        return true;
    else if (sign == '+' and other.sign == '-')
        return false;
    while (integer.size() > other.integer.size()) {
        other.integer = '0' + other.integer;
    }
    while (integer.size() < other.integer.size()) {
        integer = '0' + integer;
    }
    while (fraction.size() > other.fraction.size()) {
        other.fraction += '0';
    }
    while (fraction.size() < other.fraction.size()) {
        fraction += '0';
    }

    if (integer == other.integer and fraction == other.fraction)
        return false;

    if (sign == '+' and other.sign == '+') {
        for (int i = 0; i < integer.size(); ++i) {
            if (integer[i] > other.integer[i])
                return false;
            else if (integer[i] < other.integer[i])
                return true;
        }

        for (int i = 0; i < fraction.size(); ++i) {
            if (fraction[i]  > other.fraction[i])
                return false;
            else if(fraction[i] < other.fraction[i])
                return true;

        }
    }

    if (sign == '-' and other.sign == '-') {

        for (int i = 0; i < integer.size(); ++i) {
            if (integer[i] < other.integer[i])
                return false;
            else if(integer[i] > other.integer[i])
                return true;
        }

        for (int i = 0; i < fraction.size(); ++i) {
            if (fraction[i] < other.fraction[i])
                return false;
            else if(fraction[i] > other.fraction[i])
                return true;
        }
    }
    return true;
}

bool BigReal::operator>(BigReal &other) {
    BigReal one(sign+integer+'.'+fraction);
    if(one < other or one == other)
        return false;
    else
        return true;
}

BigReal BigReal::operator+(BigReal &other) {
    BigReal sum("0.0");
    if (sign == other.sign) {
        while (integer.size() > other.integer.size()) {
            other.integer = '0' + other.integer;
        }
        while (integer.size() < other.integer.size()) {
            integer = '0' + integer;
        }
        while (fraction.size() > other.fraction.size()) {
            other.fraction += '0';
        }
        while (fraction.size() < other.fraction.size()) {
            fraction += '0';
        }
        sum = other;
        int carry = 0;
        for (int i = fraction.size() - 1; i >= 0; --i) {
            int x = fraction[i] - '0';
            int y = other.fraction[i] - '0';
            int z = x + y + carry;
            if (z >= 10) {
                carry = 1;
                z -= 10;
            } else
                carry = 0;
            z += '0';
            sum.fraction[i] = z;
            if (i > 0) sum.fraction[i - 1] += (carry + '0');
        }

        for (int i = integer.size() - 1; i >= 0; --i) {
            int x = integer[i] - '0';
            int y = other.integer[i] - '0';
            int z = x + y + carry;
            if (z >= 10) {
                carry = 1;
                z -= 10;
            } else
                carry = 0;
            z += '0';
            sum.integer[i] = z;
            if (i > 0) sum.integer[i - 1] += (carry + '0');
        }
        if (carry == 1) {
            sum.integer = '1' + sum.integer;
            carry = 0;
        }
    } else {
        if (sign == '-') {
            BigReal A = *this;
            A.sign = '+';
            return other - A;
        } else {
            BigReal A = other;
            A.sign = '+';
            return *this - A;
        }
    }
    return sum;
}

BigReal BigReal::operator-(BigReal &other) {
    while (integer.size() > other.integer.size()) {
        other.integer = '0' + other.integer;
    }
    while (integer.size() < other.integer.size()) {
        integer = '0' + integer;
    }
    while (fraction.size() > other.fraction.size()) {
        other.fraction += '0';
    }
    while (fraction.size() < other.fraction.size()) {
        fraction += '0';
    }

    BigReal one("0.0");
    one.sign = sign;
    one.integer = integer;
    one.fraction = fraction;
    BigReal A("0.0"), B("0.0");
    bool bridge = false;//To subtract from the integer part if the fraction is negative

    if (sign == '+' and other.sign == '-') { // Then it is sum operation
        other.sign = '+';
        A = one + other;
        return A;
    } else if (sign == '-' and other.sign == '+') { // Then it is sum operation
        other.sign = '-';
        A = one + other;
        return A;
    }
    //Detecting which number is bigger to sub from and assigning the result's sign
    if (one > other) {
        if (one.sign == '-' and other.sign == '-'){
            A = other;
            B = one;
            A.sign = '+';
        }
        else {
            A = one;
            B = other;
        }
    }
    else {
        if (one.sign == '-' and other.sign == '-'){
            A = one;
            B = other;
        }
        else {
            A = other;
            B = one;
            A.sign = '-';
        }
    }
    for (int i = 0; i < A.integer.size(); ++i) {//Subtracting the integer part

        int sub = int(A.integer[i] - '0') - int(B.integer[i] - '0');
        if (sub < 0) {
            int val = i;
            sub += 10;
            A.integer[i] = (sub + '0');
            while (A.integer[i - 1] == '0') {
                A.integer[i - 1] = 9 + '0';
                i--;
            }
            A.integer[i - 1] -= 1;
            i = val;
        } else {
            A.integer[i] = (sub + '0');
        }
    }


    for (int i = 0; i < A.fraction.size(); ++i) {//Subracting the fraction part
        int sub = int(A.fraction[i] - '0') - int(B.fraction[i] - '0');
        if (sub < 0) {
            int val = i;
            sub += 10;
            A.fraction[i] = (sub + '0');
            if (i == 0) {
                bridge = true;
            }
            else {
                while (A.fraction[i - 1] == '0') {
                    A.fraction[i - 1] = 9 + '0';
                    i--;
                }
                if(i==0){
                    A.fraction[i] = 9 + '0';
                    bridge = true;
                }
                else {
                    A.fraction[i - 1] -= 1;
                }
                i = val;
            }
        } else {
            A.fraction[i] = (sub + '0');
        }
    }

    if (bridge) {
        int i = A.integer.size();
        while (A.integer[i - 1] == '0') {
            A.integer[i - 1] = 9 + '0';
            i--;
        }
        A.integer[i - 1] -= 1;
    }

    return A;
}
BigReal BigReal::Modify(BigReal &other) {
    while (other.integer[0]=='0'){
        other.integer.erase(0,1);
    }
    while (other.fraction[fraction.size()-1]=='0'){
        other.fraction.erase(fraction.size()-1,1);
    }
    return other;
}
