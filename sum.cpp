#include <iostream>
using namespace std;

long long sequenceSum(int start = 1, int amount = 10, int step = 1){
    return static_cast<long long>(amount / 2) * static_cast<long long>(2 * start + (amount - 1) * step);
}

bool is_close(double a, double b, double tolerance){
    if(a > b){
        return a - b <= tolerance;
    }else{
        return b - a <= tolerance;
    }

    return false;
}

int main(){
    int N;

    cin >> N;
    if (N < 0 || N > 100000){
        cout << "Valor fora dos limetes! 0 < N < 100.000";
        return 0;
    }

    cout << "Soma dos valore de 1 a " << N << " é: " << sequenceSum(1, N, 2) << endl;
    
    return 0;
}
