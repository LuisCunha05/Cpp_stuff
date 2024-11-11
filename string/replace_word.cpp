#include <string>
#include <iostream>
using namespace std;

int main(){
    string from;
    getline(cin, from);

    string to;
    getline(cin, to);

    string sentence;
    getline(cin, sentence);

    int l_index = 0, index = 0;

    while (sentence.find(from, l_index) != string::npos){
        index = sentence.find(from, l_index);
        sentence.replace(index, from.length(), to);
        l_index = index + from.length();
    }

    cout << sentence << "\n";
}