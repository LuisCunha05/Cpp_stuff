#include <iostream>

using namespace std;

int main(void) {

	int vec1[7] = {4, 7, 2, 8, 1, 3, 0};
	int vec2[7];
    int last, size;

	size = sizeof(vec1) / sizeof(vec1[0]);

	for (int i = 1; i < size; i++){
        vec2[i % (size - 1)] = vec1[i - 1];
    }
    

	for(int i = 0; i < 7; i++)
		cout << vec2[i] << ' ';
	cout << endl;
	return 0;
}
