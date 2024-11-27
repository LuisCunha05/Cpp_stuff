#include <iostream>

using namespace std;

struct Date {
	int year;
	int month;
	int day;
};

bool isLeap(int year) { 
	if(!(year % 4) && (year % 100))
        return true;

    if(!(year % 400))
        return true;

    return false;
}

int monthLength(int year, int month) {
    int days = 30;

	if((month < 8 && month & 1) || (month >= 8 && !(month & 1)))
	    days++;
	else if(month == 2){
            days -= 2;
            if(isLeap(year))
                days++;
        }

    return days;
}

int dayOfYear(Date date) {
    int sum = 0;

    for(int i = 1; i < date.month; i++){
        sum += monthLength(date.year, i);
    }

    return (sum + date.day);
}

int main(void) {

	Date d;
	cout << "Enter year, month, day: ";
	cin >> d.year >> d.month >> d.day;
	cout << dayOfYear(d) << endl;
	return 0;
}