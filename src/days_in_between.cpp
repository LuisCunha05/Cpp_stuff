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

int daysBetween(Date start, Date end) {
    //Validate dates
    if(start.year > end.year)
        return -1;
    if((start.year == end.year) && (start.month > end.month))
        return -1;
    if((start.month == end.month) && (start.day > end.day))
        return -1;

    int total = 0;

    for(int year = start.year; year < end.year; year++){//Não roda se start.year == end.year
        if(isLeap(year))
            total += 366;
        else
            total += 365;
    }

    if(start.year != end.year){
        total -= dayOfYear(start); //Removendo dias iniciais antes do start
        total += dayOfYear(end);
        return total;
    }

    total += dayOfYear(end) - dayOfYear(start);
    return total;
}

int main(void) {

	Date since,to;
	cout << "Enter first date (y m d): ";
	cin >> since.year >> since.month >> since.day;
	cout << "Enter second date (y m d): ";
	cin >> to.year >> to.month >> to.day;
	cout << daysBetween(since,to) << endl;
	return 0;
}