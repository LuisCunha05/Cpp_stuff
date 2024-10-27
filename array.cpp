#include <iostream>

using namespace std;

int main(void) {

	int vec1[7] = {4, 7, 2, 8, 1, 3, 0};
	int left[7], right[7];
    int size;

	size = sizeof(vec1) / sizeof(vec1[0]);

	for (int i = 0; i < size; i++){
        left[i] = vec1[(i + 1) % size];
		right[(i + 1) % size] = vec1[i];
    }
    

	for(int i = 0; i < size; i++)
		cout << left[i] << ' ';
	
	cout << '\n';

	for(int i = 0; i < size; i++)
		cout << right[i] << ' ';
	cout << endl;
	return 0;
}
