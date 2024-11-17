/* 
Let's define a pattern-matching system for such situations. Here are the rules for our system:

a pattern will consist of non-whitespace characters;
the letter 'D' will match any decimal digit, so the pattern "DDDD" will match for strings "1234", "2309" etc.;
the letter 'A' will match any character of the English alphabet (upper and lower-case), so the pattern "AAA" will match for strings "CAT", "dog", "ToC" etc.;
lower-case letters in a pattern will match according to the letters of the English alphabet, so the pattern "cat" will match for strings "Cat", "cat" "CAT", etc.;
the character "?" will match every character, including whitespace, so the pattern "a?b" will match for strings "A+B", "a0b", "Acb", "a B", etc.;
any punctuation except "?" will match exactly the same punctuation in a string, so the pattern "AA-DDD" will match for strings "NE-785", "am-236", etc.;
*/

#include <iostream>
#include <string>
#include <vector>

bool matchPattern(char &pattern, char &c){
    if(pattern == 'D')
        return isdigit(c);
    if(pattern == 'A')
        return isalpha(c);
    if(pattern == '?')
        return true;
    if(ispunct(pattern))
            return pattern == c;
    if(islower(pattern))
        return pattern == tolower(c);

    return false;
}

int main(){
    std::string pattern;
    std::getline(std::cin, pattern);

    std::string sentence;
    std::getline(std::cin, sentence);
    // match pattern against sentence
    // std::cerr << "pattern.length(): " << pattern.length() << '\n';
    // std::cerr << "sentence.length(): " << sentence.length() << '\n';



    std::vector<std::string> result;
    int counter = 0, len = pattern.length();

    try{
        for(size_t i = 0; i < sentence.length(); i++){
            //Debug
            if (i >= sentence.length() || counter >= pattern.length()) {
                std::cerr << "Out of range: i = " << i << ", counter = " << counter << '\n';
                break; // Stop the loop or handle the error
            }

            if (counter >= pattern.length()) {
                std::cerr << "Error: counter out of bounds: " << counter << '\n';
                break; // Exit loop or reset counter
            }

            if(!matchPattern(pattern.at(counter), sentence.at(i))){
                counter = 0;
                continue;
            }

            counter++;
            if(counter == len){
                result.push_back(sentence.substr(i - len + 1, len));
                counter--;
            }
        }
    }
    catch (const std::out_of_range& e) {
        std::cerr << "Out of range error: " << e.what() << '\n';
    }
    catch(const std::exception& e){
        std::cerr << e.what() << '\n';
    }

    if(!len)
        return 0;
    
    for(std::string const &value : result)
        std::cout << value << '\n';

    std::cout << std::endl;
    return 0;
}