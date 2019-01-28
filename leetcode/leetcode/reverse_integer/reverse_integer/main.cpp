#include <iostream>
#include <limits.h>
using namespace std;

int reverse(int x){
    int reversed = 0;
    while(x != 0){
        int digit = x % 10;
        x = x/10;

        if((reversed > INT_MAX/10) || (reversed == INT_MAX && digit > 7)) return 0;
        if((reversed < INT_MIN/10) || (reversed == INT_MIN && digit < -8)) return 0;

        reversed = reversed * 10 + digit;
    }
    return reversed;
}


int main(){

    std::cout << reverse(5423) << std::endl;
    return 0;
}
