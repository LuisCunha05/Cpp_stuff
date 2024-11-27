#include <iostream>
using namespace std;

int main(void) {

	int vector[] = { 3, -5, 7, 10, -4, 14, 5, 2, -13 };
	int n = sizeof(vector) / sizeof(vector[0]);

	int *pos, *lowest;
    pos = lowest = vector;

    while ((pos - vector) < n){
        if(*pos < *lowest)
            lowest = pos;
        pos++;
    }

    cout << "lowest: " << *lowest << endl;

	return 0;
}