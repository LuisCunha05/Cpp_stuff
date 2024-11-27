#include <string>
#include <iostream>
#include<vector>
using namespace std;

std::vector<std::string> splitString(std::string &s, char c = ' '){
    std::vector<std::string> w;
    int l_index = 0, index = 0;

    do{
        index = s.find(c, l_index);
        index = index != std::string::npos ? index : s.length();
        std::string seg = s.substr(l_index, index - l_index);
        w.push_back(seg);
        l_index = l_index + seg.length() + 1;
    }while(index != s.length());

    return w;
}

std::string toLowerCase(std::string &s){
    std::string n;

    for(char c : s){
        c = tolower(c);
        n.push_back(c);
    }
    return n;
}
int removeFiltered(){
    string stop_words;
    getline(cin, stop_words);

    string sentence;
    getline(cin, sentence);
    
    int l_index = 0, index = 0;

    vector<string> f_words = splitString(stop_words, ',');

    vector<string> splited = splitString(sentence);
    sentence.clear();

    bool contain = false;

    for(string w : splited){
        //cout << w << " test" <<endl;
        contain = false;
        for(string s: f_words){
            if(toLowerCase(w).compare(s) == 0){
                contain = true;
                break;
            }
        }

        if(!contain){
            w += ' ';
            sentence.append(w);
        }
    }
    //bitch stop
    cout << sentence << "\n";
    return 0;
}