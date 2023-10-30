// File: A2_S2_20220183_11.cpp
// Purpose: find all the prime numbers up to some upper limit N.
// Author: Abdelrahman Wael
// Section: S1,2
// ID: 20220183
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <fstream>
using namespace std;

void characters_compare(string f1,string f2);
void words_compare(string f1,string f2);


int main()
{
    string f1,f2;
    cout<<"enter the first file name: "<<endl;
    cin>>f1;
    cout<<"enter the second file name: "<<endl;
    cin>>f2;
    cout<<"choose how do you want to compare the files:\n1-character by character\n2-word by word\n";
    int comp; cin>>comp;
    if(comp == 1) {
        characters_compare(f1,f2);
    }
    else if(comp == 2){
        words_compare(f1,f2);
    }
}


void characters_compare(string f1,string f2) {
    fstream file_1, file_2;
    file_1.open(f1 + ".txt");
    file_2.open(f2 + ".txt");
    string s1, s2;
    bool identical= true;
    int line_number = 1;
    string line;
    while(getline(file_1, s1),getline(file_2, s2)){
        line = s1;
        if(s1==s2)
            line_number++;
        else {
            identical = false;
            break;
        }
    }
    if(identical)
        cout<<"the files are identical";
    else
    {
        cout<<"the number of the first diffrent line is: "<<line_number<<" and it's content is: "<<line;
    }
}

void words_compare(string f1,string f2)
{
    fstream file_1,file_2;
    file_1.open(f1+".txt");
    file_2.open(f2+".txt");
    string s1,s2,word1,word2;
    string dif_word="";
    int line_number = 1;
    bool identical = true;
    while(getline(file_1,s1), getline(file_2,s2))
    {
        if(s1==s2)
            line_number++;
        else {
            for (int i = 0; i < s1.size(); ++i) {
                if (s1[i] == ' ') {
                    word1 = s1.substr(0, i);
                    s1.erase(0, i + 1);
                    i = 0;
                }
                if (s2[i] == ' ') {
                    word2 = s2.substr(0, i);
                    s2.erase(0, i + 1);
                    i = 0;
                }
                if(word1!=word2)
                    dif_word = word1;
                word1=s1;
                word2=s2;
                if(word1!=word2)
                    dif_word = word1;
            }
            identical = false;
        }
    }
    if(identical)
        cout<<"the files are identical";
    else{
        cout<<"the first different word is: "<<dif_word<<" in line number: "<<line_number;
    }
}