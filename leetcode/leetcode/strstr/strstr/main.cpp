#include <iostream>

using namespace std;

int strstr(std::string haystack, std::string needle){

    int first = -1;
    int index = 0;
    int needle_size = needle.length();
    bool flag = false;

    if(needle.empty()) return 0;

    for(int i = 0;;i++){

        if(i + needle_size > haystack.length()) break;
        if(index + 1 > needle_size) break;

        for(int j = i; j < (i + needle_size); j++){

            if(haystack[j] == needle[index]){
                index++;
                if(!flag){
                    first = j;
                    flag = true;
                }
            }
            else{
                first = -1;
                flag = false;
                index = 0;
                break;
            }
        }
    }

    return first;
}

int main(){

    std::cout << strstr("heoss", "ll");
    return 0;
}
