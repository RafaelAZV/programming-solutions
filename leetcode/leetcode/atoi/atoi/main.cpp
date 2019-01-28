#include <iostream>
#include <cctype>
#include <cmath>
#include <climits>

using namespace std;


int number_table(char c){

    switch(c){
        case '0':
            return 0;
            break;

        case '1':
            return 1;
            break;

        case '2':
            return 2;
            break;

        case '3':
            return 3;
            break;

        case '4':
            return 4;
            break;

        case '5':
            return 5;
            break;

        case '6':
            return 6;
            break;

        case '7':
            return 7;
            break;

        case '8':
            return 8;
            break;

        case '9':
            return 9;
            break;
    }

    return 0;
}

int convert(std::string str, int start){

    int s_size = 0;
    int base = 10;
    int result = 0;
    int current = 0;

    for(int i = start; i < str.length(); i++){
        if(isdigit(str[i])) s_size++;
        else break;
    }

    int auxiliar = s_size;
    for(int i = start; i < (start + s_size); i++){
        current = number_table(str[i]) * pow(base, (auxiliar - 1));
        if(result > INT_MAX - current) return INT_MAX;
        result += current;
        auxiliar--;
    }

    return result;
}

int myAtoi(std::string str){

    int one = 1;
    int result = 0;

    for(int i = 0; i < str.length(); i++){
        if(str[i] == ' ') continue;
        else{
            if(str[i] == '-' && isdigit(str[i+1])) one = one * -1;
            if(isdigit(str[i])){
                result = one*convert(str, i);
                if(abs(result) == INT_MAX && result < 0) result = result - 1;
                return result;
            }
            if(!isdigit(str[i]) && (str[i] != '-' && str[i] != '+')) return 0;
        }
    }

    return 0;
}


int main(){

    std::string str = "-91283472332";
    std::cout << myAtoi(str);

    return 0;
}
