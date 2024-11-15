/* 
Let's define a pattern-matching system for such situations. Here are the rules for our system:

a pattern will consist of non-whitespace characters;
the letter 'D' will match any decimal digit, so the pattern "DDDD" will match for strings "1234", "2309" etc.;
the letter 'A' will match any character of the English alphabet (upper and lower-case), so the pattern "AAA" will match for strings "CAT", "dog", "ToC" etc.;
lower-case letters in a pattern will match according to the letters of the English alphabet, so the pattern "cat" will match for strings "Cat", "cat" "CAT", etc.;
the character "?" will match every character, including whitespace, so the pattern "a?b" will match for strings "A+B", "a0b", "Acb", "a B", etc.;
any punctuation except "?" will match exactly the same punctuation in a string, so the pattern "AA-DDD" will match for strings "NE-785", "am-236", etc.;
*/

#include <string>
#include <iostream>

bool matchPattern(char &pattern, char &c){
    switch (pattern){
    case 'D':
        return isdigit(c);
    case 'A':
        return isalpha(c);
    case '?':
        return true;
    default:
        if(pattern == c)
            return true;
        break;
    }
}

int main(){
    std::string pattern;
    std::getline(std::cin, pattern);

    std::string sentence;
    std::getline(std::cin, sentence);
    // match pattern against sentence

    std::cout << sentence << "\n";
}