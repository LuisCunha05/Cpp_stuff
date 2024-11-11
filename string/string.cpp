#include <iostream>

#include <string>

using namespace std;

void print_info(string & s) {
    cout << "length = " << s.length() << endl;
    cout << "capacity = " << s.capacity() << endl;
    cout << "max size = " << s.max_size() << endl;
    cout << "---------" << endl;
}

int main(void) {
    string the_string = "content";
    print_info(the_string);

    for (int i = 0; i < 10; i++)
        the_string += the_string;

    print_info(the_string);
    cout << '1' << endl;
    the_string.reserve(100);

    print_info(the_string);
    cout << '2' << endl;
    the_string.reserve(0);
    print_info(the_string);

    for (int i = 0; i < the_string.length(); i++)
        the_string[i] = the_string[i] - 'a' + 'A';
    cout << the_string << endl;
    return 0;
}