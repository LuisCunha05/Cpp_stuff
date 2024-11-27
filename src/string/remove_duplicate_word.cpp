#include <string>
#include <iostream>
#include<map>
using namespace std;

int main(){
    string sentence;
    getline(cin, sentence);

    map<string, int> word;
    int last_index = 0, index = 0;

    while (sentence.find_first_of(' ', last_index) != string::npos){
        index = sentence.find_first_of(' ', last_index);
        string temp = sentence.substr(last_index, index - last_index);

        bool point = false;

        if(temp.find('.') != string::npos){
            temp.erase(temp.find('.'));
            point = true;
        }
        if(temp.find(',') != string::npos){
            temp.erase(temp.find(','));
            point = true;
        }
        if(word.count(temp)){
            sentence.erase(last_index, temp.length() + 1);
        }else{
            word.insert({temp, 1});
        }

        if(point)
            word.clear();
        last_index = ++index;
    }
    cout << sentence << "\n";
}