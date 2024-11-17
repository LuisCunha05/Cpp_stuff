#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

void upCase(string &s, size_t start, size_t length = 1){
    if(length == 0)
        raise(42);

    string cut = s.substr(start, length);
    //cout << "cut: " << cut << endl;

    transform(cut.begin(), cut.end(), cut.begin(),  ::toupper);
    s.replace(start, length, cut);
}

void separate(string &s, size_t start, size_t length = 1){
    string cut = s.substr(start, length);
    //cout << "cut: " << cut << endl;

    for (size_t i = 0; i < cut.length(); i++){
        if(cut.at(i) <= 32)
            continue;

        cut.insert(cut.begin() + i  + 1, ' ');
        i++;
    }

    s.replace(start, length, cut);
}


int main(){
    string sentence;
    getline(cin, sentence);

    bool star = false, under = false;
    size_t start = 0, len = 0;

    for (size_t i = 0; sentence[i] != '\0'; i++){
        if(sentence[i] == '*'){
            if(under){
                under = false;
            }

            if(star){
                sentence.erase(i, 1);
                len = i - start;
                star = false;
                upCase(sentence, start, len);
                start = len = 0;
                continue;
            }

            star = true;
            sentence.erase(i, 1);
            start = i - 1  == -1 ? 0 : i--;
        }
        if(sentence[i]  == '_'){
            if(star){
                star = false;
            }

            if(under){
                sentence.erase(i, 1);
                len = i - start;
                under = false;
                separate(sentence, start, len);
                start = len = 0;
                continue;
            }

            under = true;
            sentence.erase(i, 1);
            start = i - 1  == -1 ? 0 : i--;
        }
    }

    cout << sentence << "\n";
}