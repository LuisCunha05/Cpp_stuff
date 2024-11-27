#include <iostream>
using namespace std;

int main(){

    int *ptr1, *ptr2, array[3] = {0, 1, 3}, i;

    ptr1 = array;
    ptr2 = ptr1;

    if(ptr2 == ptr1) {
        cout << "Yep!\n";
    }

    ptr2 += 2;

    if(ptr2 != ptr1) {
        cout << "Nope!\n";
    }
    cout << *ptr2 << '\n';

    i = ptr2 - ptr1;

    cout << i << '\n';


    return 0;
}
