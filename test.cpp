
#include <iostream>
using namespace std;
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
    
int *make(int v) {
    int *p = new int;
    *p = v + 1;
    return p;
}
int *play(int &v) {
    cout << ++v;
    return &v;
}
    
void remove(int *v) {
    delete v;
}
    int main() {
    remove(play(*make(3)));
    return 0;
}

