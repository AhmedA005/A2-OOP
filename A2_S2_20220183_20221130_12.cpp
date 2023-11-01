// File: A2_S2_20220183_20221130_12.cpp
// Purpose: Detect the commonly found words in a pishing messages.
// Author: Abdelrahman Wael & Mohamed Mahmoud
// Section: S1,2
// ID: 20220183 , 20221130
// TA: Maya Ahmed Kamal
// Date: 30 Oct 2023

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

void is_phishing(string s);

int main()
{
    string file_name;
    cout<<"enter file name: \n";
    cin>>file_name;
    is_phishing(file_name);
}


void is_phishing(string s) {

    map <string , int> phishing_list = {{"amazon",1}, {"official",2}, {"bank",3}, {"security",2}, {"urgent",2}, {"alert",1} , {"important",2},
                                        {"information",3}, {"ebay",1}, {"password",3}, {"credit",3}, {"verify",3}, {"confirm",2}, {"account",3},
                                        {"bill",1}, {"immediately",1}, {"address",2}, {"telephone",3}, {"ssn",1}, {"charity",2}, {"check",2},
                                        {"secure",1}, {"personal",3}, {"confidential",1}, {"atm",3}, {"warning",2}, {"fraud",1}, {"citibank",2},
                                        {"irs",1}, {"paypal",3} };
    map <string , int> frequency = {{"amazon",0}, {"official",0}, {"bank",0}, {"security",0}, {"urgent",0}, {"alert",0} , {"important",0},
                                    {"information",0}, {"ebay",0}, {"password",0}, {"credit",0}, {"verify",0}, {"confirm",0}, {"account",0},
                                    {"bill",0}, {"immediately",0}, {"address",0}, {"telephone",0}, {"ssn",0}, {"charity",0}, {"check",0},
                                    {"secure",0}, {"personal",0}, {"confidential",0}, {"atm",0}, {"warning",0}, {"fraud",0}, {"citibank",0},
                                    {"irs",0}, {"paypal",0} };


    fstream email;
    email.open(s + ".txt");
    string line;
    vector <string> found_words;
    int total_points = 0;
    while (getline(email, line)){
        string word;
        for (int i = 0; i < line.size(); ++i) {
            if (line[i] == ' ') {
                if((int)line[i-1]<97 or (int)line[i-1]>122)
                    word = line.substr(0, i-1);
                else
                    word = line.substr(0,i);
                line.erase(0, i + 1);
                i = 0;
                total_points += phishing_list[word];
                if(phishing_list[word]){
                    if(find(found_words.begin(),found_words.end(),word) == found_words.end())
                    found_words.push_back(word);
                    frequency[word]++;
                }
            }
        }
        if((int)line[line.size()-1]<97 or (int)line[line.size()-1]>122)
            line.erase(line.size()-1,1);
        total_points += phishing_list[line];
        if(phishing_list[line]) {
            if(find(found_words.begin(),found_words.end(),line) == found_words.end())
            found_words.push_back(line);
            frequency[line]++;
        }
    }
    for (int i = 0; i < found_words.size(); ++i) {
        cout<<found_words[i]<<" "<<frequency[found_words[i]]<<" "<<frequency[found_words[i]] * phishing_list[found_words[i]]<<endl;
    }
    cout<<"the total phishing points is: "<<total_points;
}