#include <bits/stdc++.h>
using namespace std;
#include "InclusiveSpeech.h"

void InclusiveSpeech::setSpeech(string speech) {
    Speech=speech;
}

void InclusiveSpeech::modifySpeech(string& Speech){
        map<string, string> replacements = {
            {"he", "he or she"},
            {"his", "his or hers"},
            {"him", "him or her"},
            {"himself", "himself or herself"},
            {"He", "He or she"},
            {"His", "His or hers"},
            {"Him", "Him or her"},
            {"Himself", "Himself or herself"} ,
            {"he?", "he or she?"},
            {"his?", "his or hers?"},
            {"him?", "him or her?"},
            {"himself?", "himself or herself?"},
            {"He?", "He or she?"},
            {"His?", "His or hers?"},
            {"Him?", "Him or her?"},
            {"Himself?", "Himself or herself?"}
    };

    stringstream ss(Speech);
    string word, ModifiedSpeech = "";
    while (ss >> word) {
        if (replacements.find(word) != replacements.end()) {
            ModifiedSpeech += replacements[word] + " ";
        } else {
            ModifiedSpeech += word + " ";
        }
    }
    Speech = ModifiedSpeech;
}

void InclusiveSpeech::print(string speech) {
    cout<<speech<<endl;
}
