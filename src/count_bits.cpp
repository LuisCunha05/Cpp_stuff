#include <iostream>

using namespace std;

int main(){
    
    unsigned long i, copy;

    cin >> i;
    copy = i;

    int counter = 0;

    while(i){
        if( i & 1)
            counter++;

        i >>= 1;
    }

    cout << "Amount of bits in " << copy << ": " << counter << endl;
    
    return 0;
}
