#include <iostream>

using namespace std;

int main(void) {

	int matrix[10][10] = { };

	int rows = sizeof matrix / sizeof matrix[0];
    int columns = sizeof matrix[0] / sizeof matrix[0][0];

    int *pos, *posNow;

    pos = posNow = matrix[0];

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            posNow = pos + j;
            *posNow = (i + 1) * (j + 1);
        }
        pos += columns;
    }

	for(int i = 0; i < 10; i++) {
		for(int j = 0; j < 10; j++) {
			cout.width(4);
			cout << matrix[i][j];
		}
		cout << endl;
	}
	return 0;
}