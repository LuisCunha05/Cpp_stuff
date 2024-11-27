#include <iostream>

using namespace std;

void increment(int &num, int amount = 1){
    num += amount;
}

void increment(float &num, float amount = 1.0f){
    num += amount;
}

int main(void) {
	int var = 0;

	for(int i = 0; i < 10; i++)
		if(i % 2)
			increment(var);
		else
			increment(var,i);
	cout << var << endl;
	return 0;
}