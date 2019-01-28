#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

int lengthOfLongestSubstring(std::string s){

    int low = 0;
    int high = 0;
    int answer = INT_MIN;
    std::vector<int> table((int)'z' - (int)'a' + 1, 0);

    if(s.empty()) return 0;
    int size = s.length();

    while(low < size && high < size){
        if(table[(int)s[high] - 'a'] >= 1){
            answer = max(answer, high - low);
            table[(int)s[low] - 'a'] = 0;
            low++;
        }
        else{
            table[(int)s[high] - 'a']++;
            high++;
        }
    }

    return answer;
}


int main(){

	std::cout << lengthOfLongestSubstring("abcabcbb");
    return 0;
}
