

// int main() {
//         int a = 2;
//         switch(a << a) {
//         case 8 : a++;
//         case 4 : a++;
//         case 2 : break;
//         case 1 : a--;
//         }
//         cout << a;
//         return 0;
// }

// int main() {
//     float x = 3.14f, *p = &x;
//     p[0] = ++x;
//     cout << x;
//     return 0;

// }
    
#include <iostream>

using namespace std;

int main()
{
        int a = 0x02, b = 001;
        int c = a ^ b;
        int d = c | a;
        int e = d & 0;

        cout << e;
}


