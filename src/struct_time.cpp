#include <iostream>

using namespace std;

int main(void) {

	struct time {
        int hour, minute;
    };

    struct time event = {};

    int runtime, hours = 0, minutes = 0;

    cin >> event.hour >> event.minute >> runtime;

    if(runtime >= 60){
        hours = runtime / 60;
    }

    minutes = runtime % 60;
    event.minute += minutes;

    if(event.minute >= 60){
        event.minute %= 60;
        event.hour++;
    }

    event.hour += hours % 24;
    if(event.hour >= 24){
        event.hour %= 24;
    }


	cout << event.hour << ':' << event.minute << endl;
	return 0;
}
