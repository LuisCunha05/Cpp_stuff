#include <iostream>
#include <string>
#include<map>
using namespace std;

int main(){
    string first;
    getline(cin, first);

    string second;
    getline(cin, second);

    if(first.length() != second.length()){
        cout << "not anagrams" << endl;
        return 0;
    }

    map<char, int> lettersF, lettersS;

    for (int i = 0; i < first.length(); i++){
        char f = first.at(i);
        char s = second.at(i);

        //Primeira string
        try{
            lettersF.at(f) += 1;
        }
        catch(const std::out_of_range& e){
            std::cerr << e.what() << '\n';
            lettersF.insert({f, 1});
            cout << "Creating key: " << f << endl;
        }

        //Segunda string
        try{
            lettersS.at(s) += 1;
        }
        catch(const std::out_of_range& e){
            std::cerr << e.what() << '\n';
            lettersS.insert({s, 1});
            cout << "Creating key: " << s << endl;
        }
    }

    for(auto const& element: lettersF){
        try{
            char f = element.second;
            char s = lettersS.at(element.first);

            if(f != s){
                cout << "not anagrams" << endl;
                return 0;
            }
        }
        catch(const std::out_of_range& e){
            std::cerr << e.what() << '\n';
            cout << "not anagrams" << endl;
            return 0;
        }
    }

    cout << "anagrams" << endl;
    cout << first << "\n" << second << endl;
    return 0;
}