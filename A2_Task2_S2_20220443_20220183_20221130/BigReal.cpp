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
