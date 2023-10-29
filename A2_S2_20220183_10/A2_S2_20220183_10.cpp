// File: A2_S2_20220183_10.cpp
// Purpose: find all the prime numbers up to some upper limit N.
// Author: Abdelrahman Wael
// Section: S1,2
// ID: 20220183
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <fstream>
using namespace std;
string filter(string s);



int main() {
    fstream infile,outfile;
    infile.open("in.txt");
    outfile.open("out.txt",ios::out | ios::trunc);
    string line;
    string word;
    //int space = 0;
    while(getline(infile,line)){
        for (int i = 0; i < line.size(); ++i) {
            if(line[i] == ' '){
                word = line.substr(0,i);
                line.erase(0,i+1);
                i=0;
                outfile << filter(word)<<' ';
            }
        }
        outfile<<filter(line)<<endl;
    }

}


string filter(string word){
    fstream censored_table;
    censored_table.open("censored table.txt");
    string line;
    string alternative = word;
    int spacepos=0;
    while(getline(censored_table,line)){
        for (int i = 0; i < line.size(); ++i) {
            if(line[i] == ' '){
                spacepos=i;
            }
            string band_word = line.substr(0,spacepos);
            if(word == band_word){
                alternative = line.substr(spacepos+1,line.size()-1);
            }
        }
    }

    return alternative;
}