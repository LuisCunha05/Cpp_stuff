#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string str = "12345";
    int pos = 1;
    cout << str.substr(pos).substr(pos).substr(pos).size() << endl;
    string S = "ABC";

    cout << S.substr(2, 2) << endl;

    cout << S.compare(1, 1, "BC") + S.compare(2, 1, S, 2, 2) << endl;
    return 0;
}