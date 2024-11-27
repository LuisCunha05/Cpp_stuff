#include <string>
#include <iostream>
#include <map>

using namespace std;

/**
 * @brief Returns a map containing key, value pairs of strings divided by a assigner 'asgn' and separated by separator 'sep'.
 * @param s String containing the templates.
 * @param asgn Character used to assign value to the key 
 * @param sep Character used to separate different key, value pairs.
 * @returns Map<string, string> with templates strings.
 */
map<string, string> templateBuilder(string &s, char &asgn, char &sep){
    map<string, string> result;

    size_t last_sep = 0, last_asgn = 0, pos = 0;


    do{
        pos = s.find(',', last_sep) == string::npos ? s.length() : s.find(',', last_sep);

        string sub = s.substr(last_sep, pos - last_sep);

        last_asgn = sub.find('=');
        /* cout <<
            "key: " << sub.substr(0, last_asgn) <<
            "\nvalue: " << sub.substr(last_asgn + 1) << // sub.length() - last_asgn - 1
            endl; */

        result.insert({sub.substr(0, last_asgn), sub.substr(last_asgn + 1)});//sub.length() - last_asgn - 1

        last_sep = pos + 1;
        // cout << "new_sap: " << last_sep << endl;
    }while (pos != s.length());
    
    
    /* for(auto const &element : result){
        cout << "key: " << element.first << " | value: " << element.second << endl;
    } */

    return result;
}

void replaceTemplates(string &s, map<string, string> &decode){
    size_t ini = 0, end = 0, len = 0;

    while (s.find('[') != string::npos){
        ini = s.find('[');
        end = s.find(']');
        len = end - ini + 1;
        cout << "len: " << len << endl;

        string key = s.substr(ini + 1, len - 2);
        cout << "key: " << key << endl;

        s.replace(ini, len, decode.at(key));

    }
    
}

int main(){
    string values;
    getline(cin, values);
    char assigner = '=', separator = ',';

    map<string, string> mapped_template = templateBuilder(values, assigner, separator);

    string sentence;
    getline(cin, sentence);

    replaceTemplates(sentence, mapped_template);

    cout << sentence << "\n";
}