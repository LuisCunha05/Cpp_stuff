#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool validateString(string &s){
    for (int i = 0; i < s.size(); i++){
        if(!(s[i] == '.' || isdigit(s[i]))){
            cout << "Only digits and dots allowed: " << s << endl;
            return false;
        }
    }

    if(s.size() > 3){
        cout << "Too many characters in a part: " << s << endl;
        return false;
    }

    if(stoi(s) > 255){
        cout << "Too big a value of a part: " << s << endl;
        return false;
    }
    return true;
}

int main(){
    
    string ip;
    getline(cin, ip);

    int last_index = 0;
    int index;
    short count = 0;

    do
    {
        count++;
        if(count > 4){
            cout << "Too big a value of a part!: " << endl;
            return 0;
        }

        index = ip.find_first_of('.', last_index);
        index = index != string::npos ? index : ip.length();

        string sub = ip.substr(last_index, index - last_index);

        if(!validateString(sub))
            return 0;

        last_index = index + 1;
    } while (index != ip.length());

    cout << "Ip: " << ip << " é válido!" << endl;
    return 0;
}
