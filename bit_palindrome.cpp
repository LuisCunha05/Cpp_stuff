#include <iostream>

using namespace std;

int main(){

    unsigned short int num;

    cin >> num;

    const bool DEBUG = true;
    const int BITS_TO_CHECK = 15;
    unsigned short int checker = 1 << BITS_TO_CHECK;
    bool palindrome = true;
    int counter = 0;
    int bit_left, bit_right = 0;
    int left = 16;


    while(true){
        bit_left = num & checker;

        if(!bit_left){
            counter++;
            checker >>= 1;
            continue;
        }

        left -= counter;
        break;
    }

    int interation = left / 2;
    for (int i = 0; i < interation; i++){
        if(i != 0){
            bit_left = num & checker;
        }
        bit_right = num & (1 << i);
        bit_right <<= (left - i - 1);

        /* if(DEBUG){
            cout << "Counter: " << counter << ", Checker: " << checker << ", bit_left: " << bit_left << ", right: " << bit_right << ", left: " << left << '\n';
        } */

        if(bit_left != bit_right){
            palindrome = false;
            break;
        }
        left--;
        checker >>= 1;
    }

    if(palindrome)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
