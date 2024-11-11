#include<iostream>
#include<string>
using namespace std;

void removeDuplicateWhiteSpace(string &s){
    bool lastCharIsSpace = false;
    string s_new;

    for(int i = 0; i < s.length(); i++){
        if(!(s[i] <= ' ')){
            s_new.append(&s[i], 1);
            lastCharIsSpace = false;
            continue;
        }
        
        if(lastCharIsSpace){
            continue;
        }

        s_new.append(&s[i], 1);
        lastCharIsSpace = true;
    }
    s = s_new;
}

int main(){
    string s;
    getline(cin, s);

    removeDuplicateWhiteSpace(s);

    cout << s << endl;
    return 0;
}
