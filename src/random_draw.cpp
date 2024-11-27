#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool hasItem( int *arr, int size, int num){
    bool contain = false;

    for (int i = 0; i < size; i++){
        if(arr[i] == num){
            contain = true;
            break;
        }
    }
    return contain;
}

void printArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main(void) {
	int maxball;
	int draw_amount;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> draw_amount;
	srand(time(NULL));

    if(maxball < draw_amount){
        cout << "Número de draw não pode ser maior que max ball." << endl;
        return 1;
    }

    int *storage;
    storage = new int[draw_amount];

    for (int i = 0; i < draw_amount; i++){
        storage[i] = 0;
        int random;

        do{
            random = rand() % maxball + 1;
        } while (hasItem(storage, i, random));
        
        storage[i] = random;
    }

    printArray(storage, draw_amount);

    delete[] storage;
	return 0;
}