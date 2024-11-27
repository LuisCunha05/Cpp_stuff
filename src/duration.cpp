#include<iostream>
using namespace std;

struct TIME{
    int h, m;
};


int main(){
    TIME start, end;
	int  dur;

	start.h = start.m = end.h = end.m = -1; 	// set all data to invalid value (to force the while loop to start)
	while(start.h < 0 || start.h > 23) {cout << "Enter hour: ";
		cin >> start.h;
		if(start.h < 0 || start.h > 23)
			cout << "Invalid hour: " << start.h << endl;
	}
	while(start.m < 0 || start.m > 59) {
		cout << "Enter minute: ";
		cin >> start.m;
		if(start.m < 0 || start.h > 59)
			cout << "Invalid minute: " << start.m << endl;
	}

    while(end.h < 0 || end.h > 23) {cout << "Enter hour: ";
		cin >> end.h;
		if(end.h < 0 || end.h > 23 || end.h < start.h)
			cout << "Invalid hour: " << end.h << endl;
	}
	while(end.m < 0 || end.m > 59) {
		cout << "Enter minute: ";
		cin >> end.m;
		if(end.m < 0 || end.h > 59 || ((end.h == start.h) && end.m < start.m))
			cout << "Invalid minute: " << end.m << endl;
	}
	

    int h, m;

    h = end.h - start.h;
    if(end.m < start.m){
        h--;
        m = (60 - start.m) + end.m;
    }else{
        m = end.m - start.m;
    }


    if(h < 10)
		cout << 0;
	cout << h << ":";
	if(m < 10)
		cout << 0;
	cout << m << endl;
    return 0;
}
