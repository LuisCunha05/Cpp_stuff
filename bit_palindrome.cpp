#include <iostream>

using namespace std;

int main(){

    unsigned short int num;

    cin >> num;

    const bool DEBUG = true;
    const int BITS_TO_CHECK = 15;
    unsigned short int checker = 1 << BITS_TO_CHECK;
    bool palindrome = true;

    //cout << (1 << 0) << '\n';

    for (int i = 0; i < BITS_TO_CHECK / 2; i++){
        int left_c = num & checker;
        int left = left_c >> (BITS_TO_CHECK - i);
        int right_c = num & (1 << i);
        int right = right_c >> i;

        if(DEBUG){
            cout << "I: " << i << ", Checker: " << checker << '\n';
            cout << "l_c: " << left_c << ", l: " << left << ", r_c: " << right_c << ", R: " << right << '\n';
        }

        if(left != right){
            palindrome = false;
            break;
        }
        checker >>= 1;
    }

    if(palindrome)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
