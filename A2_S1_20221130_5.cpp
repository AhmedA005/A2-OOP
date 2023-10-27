// File: A2_S1_20221130_5.cpp
// Purpose: Managing a list of top 10 high scores
// Author: Mohamed Mahmoud Abdelaal
// Section: S1,2
// ID: 20221130
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023
#include "bits/stdc++.h"
using namespace std;
int main(){
    vector <pair<int,string>> v={};
    while(true){
        cout<<"Enter 1 to add a new player , 2 to print the list , 3 to search for a player , 0 to exit"<<endl;
        int a;
        cin>>a;
        if(a==1) {
            string name;
            int score;
            cin >> name >> score;
            if (v.size()==10) {
                if(score>v[9].first) {
                    v.pop_back();
                    v.push_back(make_pair(score,name));
                }
            }
            else
                v.push_back(make_pair(score,name));
        }
        else if(a==2) {
            for (int i = 0; i < v.size(); i++)
                cout<<v[i].second<<" "<<v[i].first<<endl;
        }
        else if(a==3){
            string s;
            cin>>s;
            bool flag = true;
            for(int i=0;i<v.size();i++) {
                if (s == v[i].second) {
                    cout << v[i].first << endl;
                    flag = false;
                    break;
                }
            }
            if(flag)
                cout<<"The player isn't in the list"<<endl;
        }
        else if(a==0) {
            return 0;
        }
        sort(v.rbegin(),v.rend());
    }
}