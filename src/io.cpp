#include <iostream>
#include <cmath>

using namespace std;

int main(void) 
{
        int value, square;

        cout << "Give me a number and I will square it!\n";
        cin >> value;
        square = value * value;
        cout << "You've given " << value << endl;
        cout << "The squared value is " << square << endl;

        float squareroot;

        cout << "Give me a number and I will find its square root:" << endl;
        cin >> value;
        if(value >= 0.0) {
	        squareroot = sqrtf(value);
	        cout << "You have given: " << value << endl;
	        cout << "The square root is: " << squareroot << endl;
        }
        return 0;
}