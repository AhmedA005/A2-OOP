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

int characters_compare(string f1,string f2);



int main()
{
    string f1,f2;
    cout<<"enter the first file name: "<<endl;
    cin>>f1;
    cout<<"enter the second file name: "<<endl;
    cin>>f2;
    int n = characters_compare(f1,f2);
    if(n)
    {
        cout<<"the number and the content of the first line that is different: "<<n;
    }
    else
        cout<<"the files are identical";
}

int characters_compare(string f1,string f2)
{
    fstream file_1,file_2;
    file_1.open(f1+".txt");
    file_2.open(f2+".txt");
    string s1,s2;
    getline(file_1,s1);
    getline(file_2,s2);
    int count =0;
        int size;
        if(s2.size()>s1.size())
            size = s2.size();
        else
            size = s1.size();
        if(s1!=s2){
            for (int i = 0; i < size; ++i) {
                if(s1[i]!=s2[i])
                    count++;
            }
        }

    return count;
}
