#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void drawBalls(int max_ball_number = 1, int draws = 1){

    int *storage;
    storage = new int[draws];

    for (int i = 0; i < draws; i++){
        storage[i] = 0;
        int random = rand() % max_ball_number + 1;
        bool present = false;
        for(int j = 0; j < i; j++){
            if(storage[j] == random){
                present = true;
                break;
            }
        if(!present){
            storage[i] = random;
        }
        }
    }

    for(int i = 0;i < draws; i++){
        
        if(storage[i])
            cout << storage[i] << " ";
    }
    cout << endl;


}

int main(void) {
	int maxball;
	int ballsno;

	cout << "Max ball number? ";
	cin >> maxball;
	cout << "How many balls? ";
	cin >> ballsno;
	srand(time(NULL));

    drawBalls(maxball, ballsno);

	return 0;
}