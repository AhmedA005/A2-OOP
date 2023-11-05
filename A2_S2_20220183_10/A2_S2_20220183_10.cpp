// File: A2_S2_20220183_10.cpp
// Purpose: Message Altering to Avoid Censorship.
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
    //Repeat the same algorithm for every line
    while(getline(infile,line)){
        for (int i = 0; i < line.size(); ++i) {
            //See the first space index. all letters before it is considered one word
            if(line[i] == ' '){
                word = line.substr(0,i);
                //erase the first word and start the loop from i = 0 again
                line.erase(0,i+1);
                i=0;
                //Alterning the word if it is censored and store it in the output file
                outfile << filter(word)<<' ';
            }
        }
        outfile<<filter(line)<<endl;
    }
    infile.close();
    outfile.close();
    return 0;
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
            //compare the word with every censored word in the table  file
            //if the word is equal to any censored word replace it with an alternative
            string band_word = line.substr(0,spacepos);
            if(word == band_word){
                alternative = line.substr(spacepos+1,line.size()-1);
            }
        }
    }
censored_table.close();
    return alternative;
}
