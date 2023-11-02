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
        fraction=realNumber.substr(integer.size()+1,realNumber.size()-1);
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
