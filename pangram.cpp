#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string pan;
    getline(cin, pan);

    int letters[26];
    for (int i = 0; i < 26; i++){
        letters[i] = 0; 
    }

    for (int i = 0; i < pan.length(); i++){
        if(pan[i] <= 32)
            continue;
        letters[pan[i] - 'a']++;
    }

    for (int i = 0; i < 26; i++){
        cout << (char)('a' + i) << ": " << letters[i] << '\n'; 
    }
    return 0;
}