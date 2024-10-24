#include <iostream>

using namespace std;

int main(){

    unsigned short int num;

    cin >> num;

    const bool DEBUG = true;
    unsigned short int rev = 0;


    for(int i = 0; i < 16; i++){
        int bit = num & (1 << i);

		if(bit)
			rev |= (1 << (15-i));
    }


    if(rev == num)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
