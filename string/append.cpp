#include <iostream>

#include <string>

using namespace std;

int main(void) {
    string the_string = "content";
    string new_string;
    new_string.append(the_string);
    new_string.append(the_string, 0, 3);
    new_string.append(2, '!');
    cout << new_string << endl;

    string quote = "Whyserious?", anyword = "monsoon";
    quote.insert(3, 2, ' ').insert(4, anyword, 3, 2);
    cout << quote << endl;

    string to_do = "I'll think about that in one hour";
    string schedule = "today yesterday tomorrow";

    to_do.replace(22, 12, schedule, 16, 8);
    cout << to_do << endl;

    string where_are_we = "I've got a feeling we're not in Kansas anymore";

    where_are_we.erase(38, 8).erase(25, 4);
    cout << where_are_we << endl;
    return 0;
}