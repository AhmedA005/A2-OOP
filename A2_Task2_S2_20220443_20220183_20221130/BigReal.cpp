#include <iostream>
#include <regex>
using namespace std;
#include "BigReal.h"
bool BigReal::isValid(string realNumber) {
    if (regex_match(realNumber,regex("[+-]?\\d*.?\\d+")))
        return true;
    else return false;
}

BigReal::BigReal(string realNumber) {
    if (isValid(realNumber)){
        if (realNumber[0]=='-' || realNumber[0]=='+'){
            sign=realNumber[0];
            realNumber.erase(0,1);
        }
        else if (realNumber[0]-'0' >= 0 && realNumber[0]-'0' <= 9){
            sign='+';
        }
        integer=realNumber.substr(0,realNumber.find('.'));
        if (realNumber.find('.')!=string::npos){
            fraction=realNumber.substr(integer.size()+1,realNumber.size()-1);
        }
        else fraction='0';
    }
    if (integer.size()==0) integer='0';
    if (fraction.size()==0) fraction='0';
}

ostream &operator<<(ostream &out, BigReal num) {
    out << num.sign << num.integer << '.' << num.fraction;
    return out;
}

bool BigReal::operator==(BigReal &other) {
    if(sign==other.sign) {
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
    }
    else
        return false;
}

bool BigReal::operator<(BigReal &other) {
    if(sign == '-' and other.sign == '+')
        return true;
    else if(sign == '+' and other.sign == '-')
        return false;

    while (integer.size() > other.integer.size()){
        other.integer = '0'+other.integer;
    }
    while (integer.size() < other.integer.size()){
        integer = '0'+integer;
    }
    while (fraction.size() > other.fraction.size()){
        other.fraction += '0';
    }
    while (fraction.size() < other.fraction.size()){
        fraction += '0';
    }
    if(integer == other.integer and fraction == other.fraction)
        return false;

    if(sign == '+' and other.sign == '+'){

        for (int i = 0; i < integer.size(); ++i) {
            if(integer[i] > other.integer[i])
                return false;
        }

        for (int i = 0; i < fraction.size(); ++i) {
            if(fraction[i] > other.fraction[i])
                return false;
        }

    }

    if(sign == '-' and other.sign == '-'){

        for (int i = 0; i < integer.size(); ++i) {
            if(integer[i] < other.integer[i])
                return false;
        }

        for (int i = 0; i < fraction.size(); ++i) {
            if(fraction[i] < other.fraction[i])
                return false;
        }

    }
    return true;
}

bool BigReal::operator>(BigReal &other) {
    BigReal one(integer+'.'+fraction);
    if(one < other or one == other)
        return false;
    else
        return true;
}
bool BigReal::operator>=(BigReal &other) {
    BigReal one(integer+'.'+fraction);
    if (one < other)
        return false;
    else
    return true;
}

bool BigReal::operator<=(BigReal &other) {
    BigReal one(integer+'.'+fraction);
    if (one > other)
        return false;
    else
    return true;
}
