#include <iostream>
#include <string>
using namespace std;

std::string simple_compression(std::string input){

    std::string compressed_string = "";
    if(input.empty()) return input;

    int frequency = 0;
    char previous_character;

    for(int i = 0; i < input.length(); i++){

        if(i == 0){
            previous_character = input[i];
            frequency++;
        }
        else{
            if(input[i] == previous_character) frequency++;
            else{
                compressed_string += previous_character + std::to_string(frequency);
                previous_character = input[i];
                frequency = 1;
                if(compressed_string.length() > input.length()) return input;
            }
        }

    }

    compressed_string += previous_character + std::to_string(frequency);
    if(compressed_string.length() > input.length()) return input;
    else return compressed_string;
}


int main(){

    simple_compression("aabcccccaaa");
    return 0;
}
