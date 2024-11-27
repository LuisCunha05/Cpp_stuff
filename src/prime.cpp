#include <iostream>
#include <cmath>

using namespace std;

/**
 * @brief Tests if a number is prime.
 * @param num Number to test.
 */
bool isPrime(int num) {
    if(num & 1){//Fast Odd checking
        for(int i = 3; i * i <= num; i += 2){
            if(!(num % i))
                return false;
        }
        return true;
    }

    if(num == 2)
        return true;
    return false;
}

int main(void) {
	for(int i = 0; i <= 21; i++)
		if(isPrime(i))
			cout << i << " ";
	cout << endl;
	return 0;
}